#include "stdafx.h"

SDL_Rect lgDest = { 60, 400, 520, 150 };

LOGO* LOGO_Init(SDL_Renderer* pRenderer)
{
	LOGO* pLogo;
	pLogo = new LOGO;

	pLogo->pSurface = IMG_Load("./Resource/IMG_LOGO.png");
	pLogo->pTexture = SDL_CreateTextureFromSurface(pRenderer, pLogo->pSurface);

	return pLogo;
}

void LOGO_Render(LOGO* pLogo, SDL_Renderer* pRenderer)
{
	SDL_RenderCopy(pRenderer, pLogo->pTexture, NULL, &lgDest);
}

void LOGO_Release(LOGO* pLogo)
{
	SDL_FreeSurface(pLogo->pSurface);
	SDL_DestroyTexture(pLogo->pTexture);

	delete pLogo;
}