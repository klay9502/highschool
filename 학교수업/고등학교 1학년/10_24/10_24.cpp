// 10_24.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <SDL.h>
#include <SDL_main.h>
#pragma comment(lib, "sdl2.lib")
#pragma comment(lib, "sdl2Main.lib")
#define IMAGE_NUM 16

void Initialize();
void Processing();
void Rendering();
void Release();

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

static int nCount = 0;

typedef struct tagAnimation {
	SDL_Surface* Surface;
	SDL_Texture* Texture;
	int DelayTime;
} ANIMATION;

ANIMATION Animation[IMAGE_NUM];

char strImageFile[][128] = {
	"./Image/TL_A0000.bmp",
	"./Image/TL_A0002.bmp",
	"./Image/TL_A0004.bmp",
	"./Image/TL_A0006.bmp",
	"./Image/TL_A0008.bmp",
	"./Image/TL_A0010.bmp",
	"./Image/TL_A0012.bmp",
	"./Image/TL_A0014.bmp",
	"./Image/TL_A0016.bmp",
	"./Image/TL_A0018.bmp",
	"./Image/TL_A0020.bmp",
	"./Image/TL_A0022.bmp",
	"./Image/TL_A0024.bmp",
	"./Image/TL_A0026.bmp",
	"./Image/TL_A0028.bmp",
	"./Image/TL_A0030.bmp"
};

void Initialize()
{
	SDL_Init( SDL_INIT_VIDEO );
	gWindow = SDL_CreateWindow("SDL Titorial",
					SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED,
					255, 255,
					SDL_WINDOW_SHOWN);
	gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
	SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
}

void Processing()
{
	for (int i = 0; i < IMAGE_NUM; i++)
	{
		Animation[i].Surface = SDL_LoadBMP( strImageFile[i] );
		Animation[i].Texture = SDL_CreateTextureFromSurface(gRenderer, Animation[i].Surface);
		Animation[i].DelayTime = 50;
	}
}

void Rendering()
{
	SDL_RenderClear( gRenderer );
	SDL_RenderCopy( gRenderer, Animation[nCount].Texture, NULL, NULL );
	SDL_RenderPresent( gRenderer );

	if (nCount++ >= IMAGE_NUM - 1)
		nCount = 0;

	SDL_Delay( Animation[nCount].DelayTime );
}

void Release()
{
	for (int i = 0; i < IMAGE_NUM; i++)
	{
		SDL_FreeSurface( Animation[i].Surface );
		SDL_DestroyTexture( Animation[i].Texture );
	}

	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
}

int _tmain(int argc, _TCHAR* argv[])
{
	Initialize();

	while (1)
	{
		Processing();
		Rendering();
	}

	Release();
	return 0;
}

