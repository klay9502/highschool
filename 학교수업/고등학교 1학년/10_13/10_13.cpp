// 10_13.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <SDL.h>						// SDL의 기본 헤더
#include <SDL_main.h>					// SDL 메인 헤더
#pragma comment (lib, "sdl2.lib")		// SDL 기본 라이브러리
#pragma comment (lib, "sdl2main.lib")	// SDL 메인 라이브러리

#include "Exp.h"

int _tmain(int argc, _TCHAR* argv[])
{

	SDL_Init(SDL_INIT_EVERYTHING);		// SDL 초기화	// SDL_INIT_EVERYTHING 모든기기초기화
	// SDL 윈도우 생성
	SDL_Window* pWnd = SDL_CreateWindow("SDL_Raster", 100, 100, 407, 325, 0);
	// SDL 그리기 표면 포인터 얻어오기	// 윈도우 출력 표면
	SDL_Surface* pScreenSurface = SDL_GetWindowSurface(pWnd);

	EXP* pEXP = InitExp();

	while(1)
	{
		Render( pEXP, pScreenSurface );
		SDL_UpdateWindowSurface(pWnd);
		SDL_Delay(1000/33);
	}

	Release( pEXP );

	SDL_FreeSurface(pScreenSurface);	// 화면 표면 해제
	SDL_DestroyWindow(pWnd);	// 윈도우 파괴
	SDL_Quit();	// SDL 종료
	return 0;
}

