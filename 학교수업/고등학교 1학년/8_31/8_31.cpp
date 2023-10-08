// 8_31.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


void PressAnyKey()
{
	puts("Press A Key!!!");
	getch();
}

// ��� ȣ���� �̿��� �Լ�
int rSum(int n)
{
	if (n == 0) return 0;
	return n + rSum(n - 1);
}

// ���ϰ� ���ڰ� �ִ� �Լ�
int Sum(int n)
{
	int sum = 0;

	for (int i = 0; i <= n; i++)
	{
		sum += i;
	}

	return sum;
}

// �����͸� ���� ���� ���� �޴� �Լ�
void Swap(int* a, int* b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// �����͸� ���� ���� ���� �޴� �� �ٸ� ���
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
		"����",
		"��  ��",
		"��  ��",
		"��  ��",
		"����",
	},
	{
		"���  ",
		"  ��  ",
		"  ��  ",
		"  ��  ",
		"����",
	},
	{
		"����",
		"    ��",
		"����",
		"��    ",
		"����",
	},
	{
		"����",
		"    ��",
		"����",
		"    ��",
		"����",
	},
	{
		"��  ��",
		"��  ��",
		"����",
		"    ��",
		"    ��",
	},
	{
		"����",
		"��    ",
		"����",
		"    ��",
		"����",
	},
	{
		"����",
		"��    ",
		"����",
		"��  ��",
		"����",
	},
	{
		"����",
		"    ��",
		"    ��",
		"    ��",
		"    ��",
	},
	{
		"����",
		"��  ��",
		"����",
		"��  ��",
		"����",
	},
	{
		"����",
		"��  ��",
		"����",
		"    ��",
		"    ��",
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
