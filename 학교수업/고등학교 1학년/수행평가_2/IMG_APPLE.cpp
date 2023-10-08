#include "stdafx.h"

typedef enum _GAME_STATE { MENU, PLAY } GAME_STATE;
typedef enum _DOWN_STATE_1 { STOP_1, DOWN_1 } DOWN_STATE_1;
extern GAME_STATE g_enGameState;
DOWN_STATE_1 g_enDownState = STOP_1;

SDL_Rect apDest = { 0, 0, 100, 75 };
int Score = 0;

extern STEVE* g_pSteve;

APPLE* APPLE_Init(SDL_Renderer* pRenderer)
{
	APPLE* pApple;
	pApple = new APPLE;

	pApple->pSurface = IMG_Load("./Resource/IMG_APPLE.png");
	pApple->pTexture = SDL_CreateTextureFromSurface(pRenderer, pApple->pSurface);

	return pApple;
}
void APPLE_Process(APPLE* pApple, SDL_Renderer* pRenderer)
{
	int random_x;
	int random_y;

	random_x = rand() % 640;
	random_y = rand() % 5 + 2;

	if (g_enDownState == STOP_1)
	{
		apDest.x = random_x;
		g_enDownState = DOWN_1;
	}

	if (g_enDownState == DOWN_1)
	{
		apDest.y += random_y;

		if (apDest.y >= 1136)
		{
			apDest.y = 0;
			g_enDownState = STOP_1;
		}
	}

	for (int Apple_x = apDest.x - 100; Apple_x < apDest.x + 100; Apple_x++)
	{
		for (int Apple_y = apDest.y - 75; Apple_y < apDest.y + 75; Apple_y++)
		{
			if (g_pSteve->xpos == Apple_x && g_pSteve->ypos == Apple_y)
			{
				apDest.y = 0;
				g_enDownState = STOP_1;
				Score += 100;
			}
		}
	}

}
void APPLE_Render(APPLE* pApple, SDL_Renderer* pRenderer)
{
	if (g_enGameState == PLAY)
	{
		if (g_enDownState == DOWN_1)
		{
			SDL_RenderCopyEx(pRenderer, pApple->pTexture, NULL, &apDest, 0, 0, SDL_FLIP_NONE);
		}
	}
}
void APPLE_Release(APPLE* pApple)
{
	SDL_FreeSurface(pApple->pSurface);

	SDL_DestroyTexture(pApple->pTexture);

	delete pApple;
}