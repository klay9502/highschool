#include "stdafx.h"

int Monster_Ani_Count;

SDL_Rect rtDest_2 = {650, 428, 44, 44};

bool check_2 = false;

char strImageFile_2[][128] = {

	"Monster/monster_1.bmp",
	"Monster/monster_2.bmp"
};

MONSTER* Monster_Init (SDL_Renderer* pRenderer)
{
	MONSTER* pMonster;
	pMonster = new MONSTER;

	for (int i = 0; i < 2; i++)
	{
		pMonster->pSurface = SDL_LoadBMP(strImageFile_2[i]);
		pMonster->colorKey = SDL_MapRGB(pMonster->pSurface->format, 107, 140, 255);
		SDL_SetColorKey(pMonster->pSurface, SDL_RLEACCEL, pMonster->colorKey);
		pMonster->pTexture[i] = SDL_CreateTextureFromSurface(pRenderer, pMonster->pSurface);
	}

	return pMonster;
}

void Monster_Process(MONSTER* pbird, SDL_Renderer* pRenderer)
{
	if (++Monster_Ani_Count >= 2)
	{
		Monster_Ani_Count = 0;
	}

	if (rtDest_2.x > 670)
	{
		check_2 = true;
	}
	else if (rtDest_2.x < 400)
	{
		check_2 = false;
	}
}

void Monster_Render (MONSTER* pMonster, SDL_Renderer* pRenderer)
{
	SDL_RenderCopy(pRenderer, pMonster->pTexture[Monster_Ani_Count], NULL, &rtDest_2);

	if (check_2 == false)
	{
		rtDest_2.x += 3;
		SDL_Delay(100);
		rtDest_2.x += 3;
	}
	else
	{
		rtDest_2.x -= 3;
		SDL_Delay(100);
		rtDest_2.x -= 3;
	}
}

void Monster_Release (MONSTER* pMonster)
{
	SDL_FreeSurface(pMonster->pSurface);

	for (int i = 0; i < 2; i++)
		SDL_DestroyTexture(pMonster->pTexture[i]);

	delete pMonster;
}