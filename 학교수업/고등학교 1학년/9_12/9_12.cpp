// 9_12.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <math.h>
#include <conio.h>
#define PI 3.141592

void PressAnyKey()
{
	puts("Press A Ke!!!");
	getch();
}

int _tmain(int argc, _TCHAR* argv[])
{
	float radian;
	float s[360], c[360];

	for (int i = 0; i < 360 ; i++)
	{
		radian = i * PI / 180.0f;

		s[i] = sin(radian);
		c[i] = cos(radian);
	}

	for (int i = 0; i< 360; i++)
	{
		gotoxy(x + 1,

	}
	PressAnyKey();
	_getch();
}