#include "stdafx.h"

SDL_Rect gdDest = { 60, 400, 520, 150 };

GOOD* GOOD_Init(SDL_Renderer* pRenderer)
{
	GOOD* pGood;
	pGood = new GOOD;

	pGood->pSurface = IMG_Load("./Resource/IMG_GOOD.png");
	pGood->pTexture = SDL_CreateTextureFromSurface(pRenderer, pGood->pSurface);

	return pGood;
}

void GOOD_Render(GOOD* pGood, SDL_Renderer* pRenderer)
{
	SDL_RenderCopy(pRenderer, pGood->pTexture, NULL, &gdDest);
}

void GOOD_Release(GOOD* pGood)
{
	SDL_FreeSurface(pGood->pSurface);
	SDL_DestroyTexture(pGood->pTexture);

	delete pGood;
}