// 9_18.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <conio.h>
#include <Windows.h>
#include "UtillDB.h"
#include <math.h>
#define ESC 27
#define pie 3.141592f

void PressAnyKey()
{
	puts("Press a Key!!!");
	getch();
}

void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X=x;
	Cur.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);
}

int _tmain(int argc, _TCHAR* argv[])
{
	ScreenInit();

	bool bIsQuit = false;
	int nKey;

	int i = 0;
	float x[360], y[360];
	float Radian;

	int nCount = 0, nFPS = 0, nSec = 0;
	double dStartTime, dTime, oldTime;

	char strbuff[128] = "";

	dTime = dStartTime = GetTickCount();		// CPU�ð�	// ms������ ������

	while ( !bIsQuit )
	{
		ScreenClear();

		oldTime = GetTickCount() - dTime;

		if ( oldTime >= 1000 )		// 1�ʸ���
		{
			dTime = GetTickCount();
			nFPS = nCount;
			nCount = 0;
			nSec++;
		}

		/*
		if ( !kbhit() )
		{
			nKey = getch();
		}

		switch ( nKey )
		{
		case ESC:
			bIsQuit = true;
			break;
		}
		*/

		Radian = i * pie / 180;
		x[i] = cos(Radian);
		y[i] = sin(Radian);
		gotoxy(x[i] * 18 + 30, y[i] * 10 + 15);
		putchar('*');

		ScreenPrint( 0, 0, "���ִϿ�����б�" );
		sprintf( strbuff, "1�ʴ� ����ȸ�� �� : %d", nFPS);
		ScreenPrint( 0, 1, strbuff );
		sprintf( strbuff, "���α׷��� ������� %d�� ������", nSec);
		ScreenPrint( 0, 2, strbuff );

		ScreenFlipping();

		Sleep(1000/33);
		nCount++;
		i++;

		if (i >= 360)
			i = 0;
		
	}

	ScreenRelease();

	PressAnyKey();
	
	return 0;
}

