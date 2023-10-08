#include "stdafx.h"

typedef enum _ANIME {LEFT, RIGHT} ANIME;

ANIME g_pAnimeState_2 = LEFT;

int Ani_Count_2 = 0;
SDL_Rect Step_2[10];
SDL_Rect Move_2;

FISH_2* Fish_2_Init(SDL_Renderer* pRenderer)
{
	FISH_2* pFish_2;
	pFish_2 = new FISH_2;

	pFish_2->pSurface = SDL_LoadBMP("Image/fish_2.bmp");
	pFish_2->colorKey = SDL_MapRGB(pFish_2->pSurface->format, 0, 0, 0);
	SDL_SetColorKey(pFish_2->pSurface, SDL_RLEACCEL, pFish_2->colorKey);
	
	pFish_2->pTexture = SDL_CreateTextureFromSurface(pRenderer, pFish_2->pSurface);

	for (int i = 0; i < 10; i++)
	{
		Step_2[i].x = i * 80;
		Step_2[i].y = 0;
		Step_2[i].w = 80;		// 스프라이트 표준 크기 80 * 80;
		Step_2[i].h = 80;
	}

	Move_2.x = 150;	// 스프라이트 위치 
	Move_2.y = 100;
	Move_2.w = 80;
	Move_2.h = 80;
	
	return pFish_2;
}

void Fish_2_Process (FISH_2* pFish_2, SDL_Renderer* pRenderer)
{
	if (++Ani_Count_2 >= 10)	// 애니메이션 카운터
	{
		Ani_Count_2 = 0;
	}

	switch (g_pAnimeState_2)
	{
	case LEFT:
		Move_2.x -= 4;
		break;

	case RIGHT:
		Move_2.x += 4;
		break;
	}

	if (Move_2.x < 10 && g_pAnimeState_2 == LEFT)
	{
		g_pAnimeState_2 = RIGHT;
	}

	if (Move_2.x > 560 && g_pAnimeState_2 == RIGHT)
	{
		g_pAnimeState_2 = LEFT;
	}

	SDL_Delay(15);
}

void Fish_2_Render (FISH_2* pFish_2, SDL_Renderer* pRenderer)
{
	switch (g_pAnimeState_2)
	{
	case LEFT:
		SDL_RenderCopyEx(pRenderer, pFish_2->pTexture, &Step_2[Ani_Count_2], &Move_2, 0, 0, SDL_FLIP_NONE);
		break;

	case RIGHT:
		SDL_RenderCopyEx(pRenderer, pFish_2->pTexture, &Step_2[Ani_Count_2], &Move_2, 0, 0, SDL_FLIP_HORIZONTAL);
		break;
	}
}

void Fish_2_Release (FISH_2* pFish_2)
{
	SDL_FreeSurface(pFish_2->pSurface);
	SDL_DestroyTexture(pFish_2->pTexture);

	delete pFish_2;
}