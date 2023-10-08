// 10_13.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <SDL.h>						// SDL�� �⺻ ���
#include <SDL_main.h>					// SDL ���� ���
#pragma comment (lib, "sdl2.lib")		// SDL �⺻ ���̺귯��
#pragma comment (lib, "sdl2main.lib")	// SDL ���� ���̺귯��

#include "Exp.h"

int _tmain(int argc, _TCHAR* argv[])
{

	SDL_Init(SDL_INIT_EVERYTHING);		// SDL �ʱ�ȭ	// SDL_INIT_EVERYTHING ������ʱ�ȭ
	// SDL ������ ����
	SDL_Window* pWnd = SDL_CreateWindow("SDL_Raster", 100, 100, 407, 325, 0);
	// SDL �׸��� ǥ�� ������ ������	// ������ ��� ǥ��
	SDL_Surface* pScreenSurface = SDL_GetWindowSurface(pWnd);

	EXP* pEXP = InitExp();

	while(1)
	{
		Render( pEXP, pScreenSurface );
		SDL_UpdateWindowSurface(pWnd);
		SDL_Delay(1000/33);
	}

	Release( pEXP );

	SDL_FreeSurface(pScreenSurface);	// ȭ�� ǥ�� ����
	SDL_DestroyWindow(pWnd);	// ������ �ı�
	SDL_Quit();	// SDL ����
	return 0;
}

