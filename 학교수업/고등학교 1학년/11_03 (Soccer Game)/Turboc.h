//	Date of Manufacture 2014 / 05 / 21
//	UpDate of Color		2014 / 10 / 21
//
//
//	Header name 'Turboc.h'
//
//
//	Created by 'Kim Jong Min'
//

#ifndef TURBOC_HEADER
#define TURBOC_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void clrscr();
void gotoxy(int x, int y);
int wherex();
int wherey();
void setcursortype(CURSOR_TYPE c);

#define delay(n) Sleep(n)
#define randomize() srand((unsigned)time(NULL))
#define random(n) (rand() % (n))
#define HANDLE GetStdHandle(STD_OUTPUT_HANDLE)
#define WHITE SetConsoleTextAttribute(HANDLE, 0x007)
#define GRAY SetConsoleTextAttribute(HANDLE, 0x008)
#define GREEN SetConsoleTextAttribute(HANDLE, 0x00a)
#define SKY SetConsoleTextAttribute(HANDLE, 0x00b)
#define RED SetConsoleTextAttribute(HANDLE, 0x000c)
#ifndef TURBOC_PROTOTYPE_ONLY

void clrscr() {									// ȭ���� ��� �����.
	system("cls");
}

void gotoxy(int x, int y) {						// Ŀ���� x, y��ǥ�� �̵���Ų��.
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int wherex() {									// Ŀ���� x ��ǥ�� �����Ѵ�.
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.X;
}

int wherey() {									// Ŀ���� y ��ǥ�� �����Ѵ�.
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.Y;
}

void setcursortype(CURSOR_TYPE c) {				// Ŀ���� ����ų� �ٽ� ǥ���Ѵ�.
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}
#endif
#endif