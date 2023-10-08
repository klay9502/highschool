// SDL_BG.cpp : 배경이미지를 생성 및 관리합니다.
//

#include "stdafx.h"

SDL_Rect BG_Rect;

BACKGROUND*	BG_Init(SDL_Renderer* pRenderer)
{
	BACKGROUND* pBG;
	pBG = new BACKGROUND;

	pBG->pSurface = SDL_LoadBMP("./BG.bmp");
	pBG->pTexture = SDL_CreateTextureFromSurface(pRenderer, pBG->pSurface);

	BG_Rect.x = 0;
	BG_Rect.y = 0;
	BG_Rect.w = 840;
	BG_Rect.h = 525;

	return pBG;
}

void BG_Render(BACKGROUND* pBG, SDL_Renderer* pRenderer)
{
	SDL_RenderCopy(pRenderer, pBG->pTexture, &BG_Rect, NULL);
}

void BG_Release(BACKGROUND* pBG)
{
	SDL_FreeSurface(pBG->pSurface);
	SDL_DestroyTexture(pBG->pTexture);

	delete pBG;
}