// 1410.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	System_Init();		// 시스템 초기화

	Game_Init();		// 인게임 초기화

	Game_Loop();		// 인게임 반복루프

	Game_Release();		// 인게임 릴리즈

	System_Release();	// 시스템 릴리즈

	return 0;
}

