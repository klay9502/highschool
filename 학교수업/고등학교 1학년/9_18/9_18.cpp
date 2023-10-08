// 9_18.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

	dTime = dStartTime = GetTickCount();		// CPU시간	// ms단위로 움직임

	while ( !bIsQuit )
	{
		ScreenClear();

		oldTime = GetTickCount() - dTime;

		if ( oldTime >= 1000 )		// 1초마다
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

		ScreenPrint( 0, 0, "울산애니원고등학교" );
		sprintf( strbuff, "1초당 루프회전 수 : %d", nFPS);
		ScreenPrint( 0, 1, strbuff );
		sprintf( strbuff, "프로그램이 실행된지 %d초 지났음", nSec);
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

