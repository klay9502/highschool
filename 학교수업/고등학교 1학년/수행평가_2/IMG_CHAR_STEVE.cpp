#include "stdafx.h"

typedef enum _MOVING_STATE {DEFAULT, LEFT, RIGHT, L_STAND, R_STAND} MOVING_STATE;
typedef enum _GAME_STATE {MENU, PLAY} GAME_STATE;
extern MOVING_STATE g_enMovingState;
extern GAME_STATE g_enGameState;

SDL_Rect rtDest = {100, 700, 120, 260};

STEVE* STEVE_Init (SDL_Renderer* pRenderer)
{
	STEVE* pSteve;
	pSteve = new STEVE;

	pSteve->pSurface = IMG_Load("./Resource/IMG_STEVE.png");
	pSteve->pTexture = SDL_CreateTextureFromSurface(pRenderer, pSteve->pSurface);

	g_enMovingState = R_STAND;	// 임시 초기화

	return pSteve;
}

void STEVE_Process (STEVE* pSteve, SDL_Renderer* pRenderer)
{
	if (rtDest.x < -50)
	{
		rtDest.x = -50;
	}

	else if (rtDest.x > 590)
	{
		rtDest.x = 590;
	}

	pSteve->xpos = rtDest.x;
	pSteve->ypos = rtDest.y;
}

void STEVE_Render (STEVE* pSteve, SDL_Renderer* pRenderer)
{
	if (g_enMovingState == L_STAND)
	{
		SDL_RenderCopyEx(pRenderer, pSteve->pTexture, NULL, &rtDest, 0, 0, SDL_FLIP_HORIZONTAL);
	}

	else if (g_enMovingState == R_STAND)
	{
		SDL_RenderCopyEx(pRenderer, pSteve->pTexture, NULL, &rtDest, 0, 0, SDL_FLIP_NONE);
	}

	else if (g_enMovingState == LEFT)
	{
		SDL_RenderCopyEx(pRenderer, pSteve->pTexture, NULL, &rtDest, 0, 0, SDL_FLIP_HORIZONTAL);
		rtDest.x -= 3;
		g_enMovingState = L_STAND;
	}

	else if (g_enMovingState == RIGHT)
	{
		SDL_RenderCopyEx(pRenderer, pSteve->pTexture, NULL, &rtDest, 0, 0, SDL_FLIP_NONE);
		rtDest.x += 3;
		g_enMovingState = R_STAND;
	}
}

void STEVE_Release (STEVE* pSteve)
{
	SDL_FreeSurface(pSteve->pSurface);

	SDL_DestroyTexture(pSteve->pTexture);

	delete pSteve;
}