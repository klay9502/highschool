// 9_29.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL.h>
#include <SDL_main.h>
#pragma comment (lib, "sdl2.lib")
#pragma comment (lib, "sdl2main.lib")

#define WINDOWS_SIZE_X 1024
#define WINDOWS_SIZE_Y 300
#define PI 3.141592f

#define ESC 27

SDL_Window* pWnd; // SDL 윈도우 포인터 변수
SDL_Renderer* pRender; // 그림이 그려질 공간 포인터 변수
SDL_Rect rtRect = {0, 0, 10, 10};

float Sin[360], Cos[360];

void Init()
{
	SDL_Init( SDL_INIT_EVERYTHING );
	pWnd = SDL_CreateWindow("SDL Test", 10, 30, WINDOWS_SIZE_X, WINDOWS_SIZE_Y, SDL_WINDOW_SHOWN);
	pRender = SDL_CreateRenderer( pWnd, -1, 0 );

	for (int theta = 0; theta < 360; theta++)
	{
		float Q = PI / 180 * theta;
		Sin[theta] = sin(Q);
		Cos[theta] = cos(Q);
	}
}

void Release()
{
	SDL_DestroyRenderer( pRender );
	SDL_DestroyWindow( pWnd );
	SDL_Quit();
}

void PreRender()
{
	SDL_SetRenderDrawColor( pRender, 0, 0, 0, 255 );
	SDL_RenderClear( pRender ); // 화면을 깨끗이
}

void Render()
{
	SDL_SetRenderDrawColor( pRender, 255, 255, 255, 255 );

	for (int i = 0; i < 360; i++)
	{
		int x =  Cos[i] * 100 + Sin[i] * 100;
		int y = -Sin[i] * 100 + Cos[i] * 100;

		SDL_RenderDrawPoint( pRender, x + 200, y + 150 );
	}

	SDL_SetRenderDrawColor( pRender, 255, 0, 0, 255 );
	SDL_RenderDrawLine( pRender, 0, 150, 1024, 150 );
	SDL_RenderDrawLine( pRender, 400, 0, 400, 300 );

	static int nCount = 0;
	
	SDL_SetRenderDrawColor( pRender, 0, 0, 255, 255 );
	rtRect.x = ( Cos[nCount] * 100 + Sin[nCount] * 100) + 195;
	rtRect.y = (-Sin[nCount] * 100 + Cos[nCount] * 100) + 145;
	SDL_RenderDrawLine( pRender, 200, 150 , rtRect.x , rtRect.y);
	SDL_RenderFillRect( pRender, &rtRect ); 

	if ( ++nCount >= 360 )
		nCount = 0;
}

void PostRender()
{
	SDL_RenderPresent( pRender ); // 현재 화면 갱신
}

int main(int argc, char* argv[])
{
	bool bIsQuit = false;
	int nKey = -1;

	Init();

	while( !bIsQuit )
	{
		if ( kbhit() )
		{
			nKey = getch();

			if ( nKey == ESC )
				bIsQuit = !bIsQuit;
		}

		PreRender();
		Render();
		PostRender();
		SDL_Delay(1000/33);
	}

	Release();

	return 0;
}

