#include "stdafx.h"

SDL_Window*		gWindow		= NULL;
SDL_Renderer*	gRenderer	= NULL;

BOOL SystemInit(void)
{
	SDL_Init( SDL_INIT_VIDEO );
	gWindow = SDL_CreateWindow( "SDL Tutorial" , SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, SDL_WINDOW_SHOWN );
	gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );

	return TRUE;
}

VOID SystemRelease(void)
{
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );

	SDL_Quit();
}