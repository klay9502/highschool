#include "stdafx.h"

typedef enum _MOVING {L_DEFAULT, R_DEFAULT, LEFT, RIGHT} MOVING;

extern MOVING g_pMovingState;

int Ani_Count = 0;
SDL_Rect Step[10];
SDL_Rect Move;

MERYL* Meryl_Init(SDL_Renderer* pRenderer)
{
	MERYL* pMeryl;
	pMeryl = new MERYL;

	pMeryl->pSurface = SDL_LoadBMP("Image/meryl.bmp");
	pMeryl->colorKey = SDL_MapRGB(pMeryl->pSurface->format, 0, 0, 0);
	SDL_SetColorKey(pMeryl->pSurface, SDL_RLEACCEL, pMeryl->colorKey);
	
	pMeryl->pTexture = SDL_CreateTextureFromSurface(pRenderer, pMeryl->pSurface);

	for (int i = 0; i < 10; i++)
	{
		Step[i].x = i * 80;
		Step[i].y = 0;
		Step[i].w = 80;		// 스프라이트 표준 크기 80 * 80;
		Step[i].h = 80;
	}

	Move.x = 100;	// 스프라이트 위치 
	Move.y = 200;
	Move.w = 80;
	Move.h = 80;
	
	return pMeryl;
}

void Meryl_Process (MERYL* pMeryl, SDL_Renderer* pRenderer)
{
	if (++Ani_Count >= 10)	// 애니메이션 카운터
	{
		Ani_Count = 0;
	}
	SDL_Delay(15);
}

void Meryl_Render (MERYL* pMeryl, SDL_Renderer* pRenderer)
{
	switch (g_pMovingState)
	{
	case L_DEFAULT:
		SDL_RenderCopyEx(pRenderer, pMeryl->pTexture, &Step[Ani_Count], &Move, 0, 0, SDL_FLIP_NONE);
		break;
	case LEFT:
		SDL_RenderCopyEx(pRenderer, pMeryl->pTexture, &Step[Ani_Count], &Move, 0, 0, SDL_FLIP_NONE);
		Move.x -= 2;
		g_pMovingState = L_DEFAULT;
		break;
	case R_DEFAULT:
		SDL_RenderCopyEx(pRenderer, pMeryl->pTexture, &Step[Ani_Count], &Move, 0, 0, SDL_FLIP_HORIZONTAL);
		break;
	case RIGHT:
		SDL_RenderCopyEx(pRenderer, pMeryl->pTexture, &Step[Ani_Count], &Move, 0, 0, SDL_FLIP_HORIZONTAL);
		Move.x += 2;
		g_pMovingState = R_DEFAULT;
		break;
	}
}

void Meryl_Release (MERYL* pMeryl)
{
	SDL_FreeSurface(pMeryl->pSurface);
	SDL_DestroyTexture(pMeryl->pTexture);

	delete pMeryl;
}