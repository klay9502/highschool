#include "stdafx.h"

typedef enum _ANIME {LEFT, RIGHT} ANIME;

ANIME g_pAnimeState_1 = RIGHT;

int Ani_Count_1 = 0;
SDL_Rect Step_1[10];
SDL_Rect Move_1;

FISH_1* Fish_1_Init(SDL_Renderer* pRenderer)
{
	FISH_1* pFish_1;
	pFish_1 = new FISH_1;

	pFish_1->pSurface = SDL_LoadBMP("Image/fish_1.bmp");
	pFish_1->colorKey = SDL_MapRGB(pFish_1->pSurface->format, 0, 0, 0);
	SDL_SetColorKey(pFish_1->pSurface, SDL_RLEACCEL, pFish_1->colorKey);
	
	pFish_1->pTexture = SDL_CreateTextureFromSurface(pRenderer, pFish_1->pSurface);

	for (int i = 0; i < 10; i++)
	{
		Step_1[i].x = i * 80;
		Step_1[i].y = 0;
		Step_1[i].w = 80;		// 스프라이트 표준 크기 80 * 80;
		Step_1[i].h = 80;
	}

	Move_1.x = 200;	// 스프라이트 위치 
	Move_1.y = 250;
	Move_1.w = 80;
	Move_1.h = 80;
	
	return pFish_1;
}

void Fish_1_Process (FISH_1* pFish_1, SDL_Renderer* pRenderer)
{
	if (++Ani_Count_1 >= 10)	// 애니메이션 카운터
	{
		Ani_Count_1 = 0;
	}

	switch (g_pAnimeState_1)
	{
	case LEFT:
		Move_1.x -= 3;
		break;

	case RIGHT:
		Move_1.x += 3;
		break;
	}

	if (Move_1.x < 10 && g_pAnimeState_1 == LEFT)
	{
		g_pAnimeState_1 = RIGHT;
	}

	if (Move_1.x > 560 && g_pAnimeState_1 == RIGHT)
	{
		g_pAnimeState_1 = LEFT;
	}

	SDL_Delay(15);
}

void Fish_1_Render (FISH_1* pFish_1, SDL_Renderer* pRenderer)
{
	switch (g_pAnimeState_1)
	{
	case LEFT:
		SDL_RenderCopyEx(pRenderer, pFish_1->pTexture, &Step_1[Ani_Count_1], &Move_1, 0, 0, SDL_FLIP_NONE);
		break;

	case RIGHT:
		SDL_RenderCopyEx(pRenderer, pFish_1->pTexture, &Step_1[Ani_Count_1], &Move_1, 0, 0, SDL_FLIP_HORIZONTAL);
		break;
	}
}

void Fish_1_Release (FISH_1* pFish_1)
{
	SDL_FreeSurface(pFish_1->pSurface);
	SDL_DestroyTexture(pFish_1->pTexture);

	delete pFish_1;
}