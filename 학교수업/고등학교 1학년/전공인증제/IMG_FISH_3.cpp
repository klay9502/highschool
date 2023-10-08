#include "stdafx.h"

typedef enum _ANIME {LEFT, RIGHT} ANIME;

ANIME g_pAnimeState_3 = LEFT;

int Ani_Count_3 = 0;
SDL_Rect Step_3[10];
SDL_Rect Move_3;

FISH_3* Fish_3_Init(SDL_Renderer* pRenderer)
{
	FISH_3* pFish_3;
	pFish_3 = new FISH_3;

	pFish_3->pSurface = SDL_LoadBMP("Image/fish_3.bmp");
	pFish_3->colorKey = SDL_MapRGB(pFish_3->pSurface->format, 0, 0, 0);
	SDL_SetColorKey(pFish_3->pSurface, SDL_RLEACCEL, pFish_3->colorKey);
	
	pFish_3->pTexture = SDL_CreateTextureFromSurface(pRenderer, pFish_3->pSurface);

	for (int i = 0; i < 10; i++)
	{
		Step_3[i].x = i * 60;
		Step_3[i].y = 0;
		Step_3[i].w = 60;		// 스프라이트 표준 크기 80 * 80;
		Step_3[i].h = 60;
	}

	Move_3.x = 80;	// 스프라이트 위치 
	Move_3.y = 400;
	Move_3.w = 60;
	Move_3.h = 60;
	
	return pFish_3;
}

void Fish_3_Process (FISH_3* pFish_3, SDL_Renderer* pRenderer)
{
	if (++Ani_Count_3 >= 10)	// 애니메이션 카운터
	{
		Ani_Count_3 = 0;
	}

	switch (g_pAnimeState_3)
	{
	case LEFT:
		Move_3.x -= 3;
		break;

	case RIGHT:
		Move_3.x += 3;
		break;
	}

	if (Move_3.x < 10 && g_pAnimeState_3 == LEFT)
	{
		g_pAnimeState_3 = RIGHT;
	}

	if (Move_3.x > 560 && g_pAnimeState_3 == RIGHT)
	{
		g_pAnimeState_3 = LEFT;
	}

	SDL_Delay(15);
}

void Fish_3_Render (FISH_3* pFish_3, SDL_Renderer* pRenderer)
{
	switch (g_pAnimeState_3)
	{
	case LEFT:
		SDL_RenderCopyEx(pRenderer, pFish_3->pTexture, &Step_3[Ani_Count_3], &Move_3, 0, 0, SDL_FLIP_NONE);
		break;

	case RIGHT:
		SDL_RenderCopyEx(pRenderer, pFish_3->pTexture, &Step_3[Ani_Count_3], &Move_3, 0, 0, SDL_FLIP_HORIZONTAL);
		break;
	}
}

void Fish_3_Release (FISH_3* pFish_3)
{
	SDL_FreeSurface(pFish_3->pSurface);
	SDL_DestroyTexture(pFish_3->pTexture);

	delete pFish_3;
}