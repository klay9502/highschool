// SDL_MAIN.cpp : �ý��� ���� �ڵ带 �����ϰ� �ִ� �ҽ������Դϴ�.
//

#include "stdafx.h"

SDL_Window*		gWnd = NULL;
SDL_Renderer*	gRenderer = NULL;

BOOL System_Init(void)
{
	SDL_Init(SDL_INIT_VIDEO);
	gWnd = SDL_CreateWindow("Super_Mario", 100, 100, 840, 525, 0);
	gRenderer = SDL_CreateRenderer(gWnd, -1, SDL_RENDERER_ACCELERATED);

	return TRUE;
}

void System_Release(void)
{
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWnd);

	SDL_Quit();
}