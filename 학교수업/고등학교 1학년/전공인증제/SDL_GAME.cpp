#include "stdafx.h"

typedef enum _MOVING {L_DEFAULT, R_DEFAULT, LEFT, RIGHT} MOVING;

extern SDL_Renderer* gRenderer;

MOVING g_pMovingState = L_DEFAULT;
BACKGROUND* g_pBG;

MERYL*		g_pMeryl;
FISH_1*		g_pFish_1;
FISH_2*		g_pFish_2;
FISH_3*		g_pFish_3;

BOOL Game_Init(void)
{
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	g_pBG = BG_Init(gRenderer);
	g_pMeryl = Meryl_Init(gRenderer);
	g_pFish_1 = Fish_1_Init(gRenderer);
	g_pFish_2 = Fish_2_Init(gRenderer);
	g_pFish_3 = Fish_3_Init(gRenderer);
	return TRUE;
}

void Game_Loop(void)
{
	bool bIsQuit = false;
	SDL_Event evnt;
	SDL_Color color = {255, 255, 255};

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
			case SDLK_LEFT:
				g_pMovingState = LEFT;
				printf("pushing LEFT butten\n");
				break;
			case SDLK_RIGHT:
				g_pMovingState = RIGHT;
				printf("pushing RIGHT butten\n");
				break;
			}
		}

		Meryl_Process(g_pMeryl, gRenderer);
		Fish_1_Process(g_pFish_1, gRenderer);
		Fish_2_Process(g_pFish_2, gRenderer);
		Fish_3_Process(g_pFish_3, gRenderer);
		SDL_RenderClear(gRenderer);

		BG_Render(g_pBG, gRenderer);
		Meryl_Render(g_pMeryl, gRenderer);
		Fish_1_Render(g_pFish_1, gRenderer);
		Fish_2_Render(g_pFish_2, gRenderer);
		Fish_3_Render(g_pFish_3, gRenderer);

		OutputTexts(gRenderer, "arial.ttf", 0, 0, color, 20, "1410 Kim Jong-Min");
		OutputHanTexts(gRenderer, "2002.ttf", 0, 30, color, 20, "1410 ±Ë¡æπŒ");
		SDL_RenderPresent(gRenderer);
	}
}

void Game_Release(void)
{
	BG_Release(g_pBG);
	Meryl_Release(g_pMeryl);
	Fish_1_Release(g_pFish_1);
	Fish_2_Release(g_pFish_2);
	Fish_3_Release(g_pFish_3);
}
