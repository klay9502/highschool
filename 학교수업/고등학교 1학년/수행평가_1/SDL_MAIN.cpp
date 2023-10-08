// SDL_MAIN.cpp : 주 main 함수를 포함하고 있는 소스파일입니다.
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