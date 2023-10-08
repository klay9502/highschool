//================================================
// Desc : UtilDB.cpp는 더블버퍼링을 콘솔모드에서
//        사용하기 위한 함수 모음.
// Date : 2014. 09. 18
// Author : Jong-Min Kim
// e-mail : clay9502@naver.com

#include "stdafx.h"
#include <stdlib.h>
#include <Windows.h>

static int g_nScreenIndex;	// 화면을 표시할 버퍼 번호
static HANDLE g_hScreen[2];	// 화면 // 스크린

//================================================
// Desc : ScreenInit()는 두개의 화면 버퍼를 설정
// Date : 2014. 09. 18

void ScreenInit()
{
	g_hScreen[0] = CreateConsoleScreenBuffer( GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER , NULL );
	g_hScreen[1] = CreateConsoleScreenBuffer( GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER , NULL );

	CONSOLE_CURSOR_INFO cci;	// 커서를 제어
	cci.dwSize = 1;
	cci.bVisible = false;		// true = 커서 보임, false = 커서 안보임.

	SetConsoleCursorInfo( g_hScreen[0], &cci );
	SetConsoleCursorInfo( g_hScreen[1], &cci );
}

//================================================
// Desc : ScreenFlipping()는 두개의 버퍼를
//        번갈아서 화면에 출력
// Date : 2014. 09. 18

void ScreenFlipping()
{
	SetConsoleActiveScreenBuffer( g_hScreen[g_nScreenIndex] );		// 화면 출력
	g_nScreenIndex = !g_nScreenIndex;		// Flip 0 => 1, 1 => 0으로 바뀜
}

//================================================
// Desc : ScreenClear()는 화면을 깨끗이
// Date : 2014. 09. 18

void ScreenClear()
{
	COORD coord = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter( g_hScreen[g_nScreenIndex], ' ', 80 * 25, coord, &dw );
}

//================================================
// Desc : ScreenRelease()는 화면을 메모리에서 제거
// Date : 2014. 09. 18

void ScreenRelease()
{
	CloseHandle( g_hScreen[0] );
	CloseHandle( g_hScreen[1] );
}

//================================================
// Desc : ScreenPrint()는 화면에 글자 출력
// Date : 2014. 09. 18

void ScreenPrint(int x, int y, char* str)
{
	DWORD dw;
	COORD CursorPos = {x, y};
	SetConsoleCursorPosition( g_hScreen[g_nScreenIndex], CursorPos );
	WriteFile( g_hScreen[g_nScreenIndex], str, strlen(str), &dw, NULL );
}