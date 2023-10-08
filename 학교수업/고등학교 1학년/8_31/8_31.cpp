// 8_31.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


void PressAnyKey()
{
	puts("Press A Key!!!");
	getch();
}

// 재귀 호출을 이용한 함수
int rSum(int n)
{
	if (n == 0) return 0;
	return n + rSum(n - 1);
}

// 리턴과 인자가 있는 함수
int Sum(int n)
{
	int sum = 0;

	for (int i = 0; i <= n; i++)
	{
		sum += i;
	}

	return sum;
}

// 포인터를 통해 값을 전달 받는 함수
void Swap(int* a, int* b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// 포인터를 통해 값을 전달 받는 또 다른 방법
void aSwap(int& a, int &b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}

void gotoxy(int x, int y)
{
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

char g_strNumber[10][5][10] =
{
	{
		"■■■",
		"■  ■",
		"■  ■",
		"■  ■",
		"■■■",
	},
	{
		"■■  ",
		"  ■  ",
		"  ■  ",
		"  ■  ",
		"■■■",
	},
	{
		"■■■",
		"    ■",
		"■■■",
		"■    ",
		"■■■",
	},
	{
		"■■■",
		"    ■",
		"■■■",
		"    ■",
		"■■■",
	},
	{
		"■  ■",
		"■  ■",
		"■■■",
		"    ■",
		"    ■",
	},
	{
		"■■■",
		"■    ",
		"■■■",
		"    ■",
		"■■■",
	},
	{
		"■■■",
		"■    ",
		"■■■",
		"■  ■",
		"■■■",
	},
	{
		"■■■",
		"    ■",
		"    ■",
		"    ■",
		"    ■",
	},
	{
		"■■■",
		"■  ■",
		"■■■",
		"■  ■",
		"■■■",
	},
	{
		"■■■",
		"■  ■",
		"■■■",
		"    ■",
		"    ■",
	}
};

int intlen(int input) {
	char buffer[16];
	itoa(input, buffer, 10);
	return strlen(buffer);
}

void OutputNumber(int num)
{
	int place;
	int cheak_place = 1;
	int anum;
	int x = 0;

	place = intlen(num);

	while (place > 1)
	{
		cheak_place *= 10;
		place--;
	}

	system("cls");

	while (1)
	{
		anum = num / cheak_place;

		for (int i = 0; i < 5; i++)
		{
			gotoxy(x, 0 + i);
			printf("%s", g_strNumber[anum][i]);
		}

		anum *= cheak_place;
		num -= anum;
		cheak_place /= 10;
		anum = 0;
		x += 8;

		if (cheak_place == 0)
		{
			break;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int num;

	scanf("%d", &num);
	OutputNumber(num);

	PressAnyKey();
	return 0;
}
