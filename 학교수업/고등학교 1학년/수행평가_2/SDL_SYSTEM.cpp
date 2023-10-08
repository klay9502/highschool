#include "stdafx.h"

SDL_Window*		gWnd = NULL;
SDL_Renderer*	gRenderer = NULL;

BOOL System_Init(void)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
	gWnd = SDL_CreateWindow("Game", 100, 100, 640, 1138, 0);

	gRenderer = SDL_CreateRenderer(gWnd, -1, SDL_RENDERER_SOFTWARE);

	return TRUE;
}

void System_Release(void)
{
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWnd);

	IMG_Quit();
	SDL_Quit();
}