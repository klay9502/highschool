//================================================
// Desc : UtilDB.cpp�� ������۸��� �ָܼ�忡��
//        ����ϱ� ���� �Լ� ����.
// Date : 2014. 09. 18
// Author : Jong-Min Kim
// e-mail : clay9502@naver.com

#include "stdafx.h"
#include <stdlib.h>
#include <Windows.h>

static int g_nScreenIndex;	// ȭ���� ǥ���� ���� ��ȣ
static HANDLE g_hScreen[2];	// ȭ�� // ��ũ��

//================================================
// Desc : ScreenInit()�� �ΰ��� ȭ�� ���۸� ����
// Date : 2014. 09. 18

void ScreenInit()
{
	g_hScreen[0] = CreateConsoleScreenBuffer( GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER , NULL );
	g_hScreen[1] = CreateConsoleScreenBuffer( GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER , NULL );

	CONSOLE_CURSOR_INFO cci;	// Ŀ���� ����
	cci.dwSize = 1;
	cci.bVisible = false;		// true = Ŀ�� ����, false = Ŀ�� �Ⱥ���.

	SetConsoleCursorInfo( g_hScreen[0], &cci );
	SetConsoleCursorInfo( g_hScreen[1], &cci );
}

//================================================
// Desc : ScreenFlipping()�� �ΰ��� ���۸�
//        �����Ƽ� ȭ�鿡 ���
// Date : 2014. 09. 18

void ScreenFlipping()
{
	SetConsoleActiveScreenBuffer( g_hScreen[g_nScreenIndex] );		// ȭ�� ���
	g_nScreenIndex = !g_nScreenIndex;		// Flip 0 => 1, 1 => 0���� �ٲ�
}

//================================================
// Desc : ScreenClear()�� ȭ���� ������
// Date : 2014. 09. 18

void ScreenClear()
{
	COORD coord = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter( g_hScreen[g_nScreenIndex], ' ', 80 * 25, coord, &dw );
}

//================================================
// Desc : ScreenRelease()�� ȭ���� �޸𸮿��� ����
// Date : 2014. 09. 18

void ScreenRelease()
{
	CloseHandle( g_hScreen[0] );
	CloseHandle( g_hScreen[1] );
}

//================================================
// Desc : ScreenPrint()�� ȭ�鿡 ���� ���
// Date : 2014. 09. 18

void ScreenPrint(int x, int y, char* str)
{
	DWORD dw;
	COORD CursorPos = {x, y};
	SetConsoleCursorPosition( g_hScreen[g_nScreenIndex], CursorPos );
	WriteFile( g_hScreen[g_nScreenIndex], str, strlen(str), &dw, NULL );
}