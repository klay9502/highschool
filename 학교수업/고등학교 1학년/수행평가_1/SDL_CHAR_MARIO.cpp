#include "stdafx.h"

int Mario_Ani_Count;

SDL_Rect rtDest = {60, 400, 42, 76};

bool check = false;

char strImageFile[][128] = {

	"Mario/mario_1.bmp",
	"Mario/mario_2.bmp",
	"Mario/mario_3.bmp",
	"Mario/mario_4.bmp"
};

MARIO* Mario_Init (SDL_Renderer* pRenderer)
{
	MARIO* pMario;
	pMario = new MARIO;

	for (int i = 0; i < 4; i++)
	{
		pMario->pSurface = SDL_LoadBMP(strImageFile[i]);
		pMario->colorKey = SDL_MapRGB(pMario->pSurface->format, 0, 128, 0);
		SDL_SetColorKey(pMario->pSurface, SDL_RLEACCEL, pMario->colorKey);
		pMario->pTexture[i] = SDL_CreateTextureFromSurface(pRenderer, pMario->pSurface);
	}

	return pMario;
}

void Mario_Process(MARIO* pbird, SDL_Renderer* pRenderer)
{
	if (++Mario_Ani_Count >= 4)
	{
		Mario_Ani_Count = 0;
	}


	if (rtDest.x > 350)
	{
		check = true;
	}
	else if (rtDest.x < 60)
	{
		check = false;
	}
}

void Mario_Render (MARIO* pMario, SDL_Renderer* pRenderer)
{
	if (check == false)
	{
		SDL_RenderCopyEx(pRenderer, pMario->pTexture[Mario_Ani_Count], NULL, &rtDest, 0, 0, SDL_FLIP_NONE);
		rtDest.x += 3;
		SDL_Delay(30);
		rtDest.x += 3;
	}
	else
	{
		SDL_RenderCopyEx(pRenderer, pMario->pTexture[Mario_Ani_Count], NULL, &rtDest, 0, 0, SDL_FLIP_HORIZONTAL);
		rtDest.x -= 3;
		SDL_Delay(30);
		rtDest.x -= 3;
	}
}

void Mario_Release (MARIO* pMario)
{
	SDL_FreeSurface(pMario->pSurface);

	for (int i = 0; i < 4; i++)
		SDL_DestroyTexture(pMario->pTexture[i]);

	delete pMario;
}