// SDL_GAME.cpp : 인게임의 코드들을 포함하고 있는 소스파일입니다.
//

#include "stdafx.h"

extern SDL_Renderer* gRenderer;

BACKGROUND* g_pBG;
MARIO* g_pMario;
MONSTER* g_pMonster;

BOOL Game_Init(void)
{
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	g_pBG = BG_Init(gRenderer);
	g_pMario = Mario_Init(gRenderer);
	g_pMonster = Monster_Init(gRenderer);

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
		}
		Mario_Process(g_pMario, gRenderer);
		Monster_Process(g_pMonster, gRenderer);

		SDL_RenderClear(gRenderer);

		BG_Render(g_pBG, gRenderer);
		Mario_Render(g_pMario, gRenderer);
		Monster_Render(g_pMonster, gRenderer);


		SDL_RenderPresent(gRenderer);
	}
}

void Game_Release(void)
{
	BG_Release(g_pBG);
	Mario_Release(g_pMario);
	Monster_Release(g_pMonster);
}