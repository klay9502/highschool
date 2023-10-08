#include "stdafx.h"

typedef enum _GAME_STATE { MENU, PLAY } GAME_STATE;
typedef enum _DOWN_STATE { STOP, DOWN } DOWN_STATE;
extern GAME_STATE g_enGameState;
 DOWN_STATE g_enDownState = STOP;

SDL_Rect smDest = { 0, 0, 120, 75 };
int Life = 3;

extern STEVE* g_pSteve;

SAMSUNG* SAMSUNG_Init(SDL_Renderer* pRenderer)
{
	SAMSUNG* pSamsung;
	pSamsung = new SAMSUNG;

	pSamsung->pSurface = IMG_Load("./Resource/IMG_SAMSUNG.png");
	pSamsung->pTexture = SDL_CreateTextureFromSurface(pRenderer, pSamsung->pSurface);

	return pSamsung;
}
void SAMSUNG_Process(SAMSUNG* pSamsung, SDL_Renderer* pRenderer)
{
	int random_x;
	int random_y;
	
	random_x = rand() % 640;
	random_y = rand() % 5 + 3;

	if (g_enDownState == STOP)
	{
		smDest.x = random_x;
		g_enDownState = DOWN;
	}

	if (g_enDownState == DOWN)
	{
		smDest.y += random_y;

		if (smDest.y >= 1136)
		{
			smDest.y = 0;
			g_enDownState = STOP;
		}
	}

	for (int Samsung_x = smDest.x - 120; Samsung_x < smDest.x + 120; Samsung_x++)
	{
		for (int Samsung_y = smDest.y - 75; Samsung_y < smDest.y + 75; Samsung_y++)
		{
			if (g_pSteve->xpos == Samsung_x && g_pSteve->ypos == Samsung_y)
			{
				smDest.y = 0;
				g_enDownState = STOP;
				Life--;
			}
		}
	}
}
void SAMSUNG_Render(SAMSUNG* pSamsung, SDL_Renderer* pRenderer)
{
	if (g_enGameState == PLAY)
	{
		if (g_enDownState == DOWN)
		{
			SDL_RenderCopyEx(pRenderer, pSamsung->pTexture, NULL, &smDest, 0, 0, SDL_FLIP_NONE);
		}
	}
}
void SAMSUNG_Release(SAMSUNG* pSamsung)
{
	SDL_FreeSurface(pSamsung->pSurface);

	SDL_DestroyTexture(pSamsung->pTexture);

	delete pSamsung;
}