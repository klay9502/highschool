// SDL_GAME.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	System_Init();

	Game_Init();

	Game_Loop();

	Game_Release();

	System_Release();

	return 0;
}

