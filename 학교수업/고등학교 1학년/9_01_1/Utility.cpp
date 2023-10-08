#include "stdafx.h"

void gotoxy(int x, int y)
{
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

void PressAnyKey()
{
	puts("Press A Key!!!");
	getch();
}

// 글자색 바꾸기
void SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int intlen(int input) {
	char buffer[16];
	itoa(input, buffer, 10);
	return strlen(buffer);
}