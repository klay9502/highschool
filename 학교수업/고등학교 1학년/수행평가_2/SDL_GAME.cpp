#include "stdafx.h"

typedef enum _MOVING_STATE {DEFAULT, LEFT, RIGHT, L_STAND, R_STAND} MOVING_STATE;
typedef enum _GAME_STATE {MENU, PLAY} GAME_STATE;

extern MOVING_STATE g_enMovingState = DEFAULT;
extern GAME_STATE g_enGameState = PLAY;

extern SDL_Renderer* gRenderer;

BACKGROUND* g_pBG;
STEVE* g_pSteve;
SAMSUNG* g_pSamsung;
APPLE* g_pApple;
LOGO* g_pLogo;
GOOD* g_pGood;

extern int Score;
extern int Life;

_Image ImageFile[60];

SDL_Texture* LoadIMG(char *path)
{
	return IMG_LoadTexture(gRenderer, path);
}

// =========================================== ( X Y 인자값 Double)
// Note : 이미지 출력 함수 (이미지 , X , Y , 가로 크기 , 세로크기 , 활동 , 애니메이션 장수 )
// Date : 2014.11.20  (X 화면 축소 , Y 화면 축소 , 회전 값 , 밝기 조정)
// ===========================================
void DrawImageAni(SDL_Texture *texture, double x, double y, int w, int h, int act, int step,
	double xscale, double yscale, int angle, double alpha)
{
	SDL_Rect src, dst;
	SDL_Point point;

	point.x = w*xscale / 2;		// 중심점 초기화
	point.y = h*yscale / 2;		// 중심점 초기화

	src.x = step*w;
	src.y = act*h;
	src.w = w;
	src.h = h;

	dst.x = x - point.x;	// 출력 되는 이미지의 중심
	dst.y = y - point.y;	// 출력 되는 이미지의 중심
	dst.w = src.w*xscale;	// 이미지 확대 축소
	dst.h = src.h*yscale;	// 이미지 확대 축소 

	SDL_SetTextureAlphaMod(texture, alpha * 255);	// 이미지 투명도 조절 

	SDL_RenderCopyEx(gRenderer, texture, &src, &dst, angle, &point, SDL_FLIP_NONE);
}

// ===========================================
// Note : 7 자리 까지 숫자 출력
// Date : 2014.12.23
// ===========================================
void TextPrint(int x, int y, int num)
{
	int Seat[7];
	int count = 1000000;
	int length = 0;
	int CopyNum = num;

	memset(Seat, 0, 7);

	while (CopyNum > 0)
	{
		length++;
		CopyNum /= 10;
	}

	for (int i = 0; i < 7; i++)
	{
		if (i > 0)
		{
			count /= 10;
		}
		Seat[i] = num / count;
		num = num - Seat[i] * count;
	}

	for (int i = 0 + (7 - length); i < 7; i++)
	{
		DrawImageAni(ImageFile[39 + Seat[i]].Image, x + (i * 17), y, 20, 25, 0, 0, 1, 1, 0, 1);
	}
}

BOOL Game_Init(void)
{
	char buf[256];

	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	
	g_pBG = BG_Init(gRenderer);
	g_pLogo = LOGO_Init(gRenderer);
	g_pSteve = STEVE_Init(gRenderer);
	g_pSamsung = SAMSUNG_Init(gRenderer);
	g_pApple = APPLE_Init(gRenderer);
	g_pGood = GOOD_Init(gRenderer);

	for (int i = 0; i <= 9; i++)
	{
		sprintf(buf, "Resource/Number/%d.png", i);
		ImageFile[39 + i].Image = LoadIMG(buf);
	}

	return TRUE;
}

void Game_Loop(void)
{
	bool bIsQuit = false;
	SDL_Event evnt;

	while (!bIsQuit)
	{
		SDL_PollEvent(&evnt);

		if (evnt.type == SDL_KEYDOWN)
		{
			switch (evnt.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				bIsQuit = true;
				break;
			}

			if (g_enGameState == PLAY)
			{
				switch (evnt.key.keysym.sym)
				{
				case SDLK_LEFT:
					g_enMovingState = LEFT;
					break;
				case SDLK_RIGHT:
					g_enMovingState = RIGHT;
					break;
				}
			}
		}

	

		STEVE_Process(g_pSteve, gRenderer);
		SAMSUNG_Process(g_pSamsung, gRenderer);
		APPLE_Process(g_pApple, gRenderer);

		SDL_RenderClear(gRenderer);

		BG_Render(g_pBG, gRenderer);
		STEVE_Render(g_pSteve, gRenderer);
		SAMSUNG_Render(g_pSamsung, gRenderer);
		APPLE_Render(g_pApple, gRenderer);

		TextPrint(520, 20, Score);
		TextPrint(-90, 20, Life);

		if (Life <= 0)
		{
			LOGO_Render(g_pLogo, gRenderer);
			TextPrint(240, 560, Score);
		}

		if (Score >= 2000)
		{
			GOOD_Render(g_pGood, gRenderer);
			TextPrint(240, 560, Score);
		}

		SDL_RenderPresent(gRenderer);

		if (Life <= 0 || Score >= 2000)
		{
			SDL_Delay(3000);
			break;
		}
	}
}

void Game_Release(void)
{
	BG_Release(g_pBG);
	LOGO_Release(g_pLogo);
	GOOD_Release(g_pGood);
	STEVE_Release(g_pSteve);
	SAMSUNG_Release(g_pSamsung);
	APPLE_Release(g_pApple);
}