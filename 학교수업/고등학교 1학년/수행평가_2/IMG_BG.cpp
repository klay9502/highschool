#include "stdafx.h"

BACKGROUND* BG_Init(SDL_Renderer* pRenderer)
{
	BACKGROUND* pBG;
	pBG = new BACKGROUND;

	pBG->pSurface = IMG_Load("./Resource/IMG_BG.png");
	pBG->pTexture = SDL_CreateTextureFromSurface(pRenderer, pBG->pSurface);

	return pBG;
}

void BG_Render(BACKGROUND* pBG, SDL_Renderer* pRenderer)
{
	SDL_RenderCopy(pRenderer, pBG->pTexture, NULL, NULL);
}

void BG_Release(BACKGROUND* pBG)
{
	SDL_FreeSurface(pBG->pSurface);
	SDL_DestroyTexture(pBG->pTexture);

	delete pBG;
}