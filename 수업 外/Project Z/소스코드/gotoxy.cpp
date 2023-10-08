//	Start project since 2014 / 04 / 21 ~
//
//
//	'Project Z'
//
//	Source name 'gotoxy'
//
//
//	Created by 'Kim Jong Min'
//

#include <stdio.h>
#include <Windows.h>
#include "prototype.h"
#define HANDLE GetStdHandle(STD_OUTPUT_HANDLE)

extern void gotoxy(int x, int y)
{
	COORD Pos = {x-1, y-1};
	SetConsoleCursorPosition(HANDLE, Pos);
}