// SDL_MAIN.cpp : �� main �Լ��� �����ϰ� �ִ� �ҽ������Դϴ�.
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