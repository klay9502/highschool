#include "stdafx.h"

char g_strNumber[10][5][10] =
{
	{
		"бсбсбс",
		"бс  бс",
		"бс  бс",
		"бс  бс",
		"бсбсбс",
	},
	{
		"бсбс  ",
		"  бс  ",
		"  бс  ",
		"  бс  ",
		"бсбсбс",
	},
	{
		"бсбсбс",
		"    бс",
		"бсбсбс",
		"бс    ",
		"бсбсбс",
	},
	{
		"бсбсбс",
		"    бс",
		"бсбсбс",
		"    бс",
		"бсбсбс",
	},
	{
		"бс  бс",
		"бс  бс",
		"бсбсбс",
		"    бс",
		"    бс",
	},
	{
		"бсбсбс",
		"бс    ",
		"бсбсбс",
		"    бс",
		"бсбсбс",
	},
	{
		"бсбсбс",
		"бс    ",
		"бсбсбс",
		"бс  бс",
		"бсбсбс",
	},
	{
		"бсбсбс",
		"    бс",
		"    бс",
		"    бс",
		"    бс",
	},
	{
		"бсбсбс",
		"бс  бс",
		"бсбсбс",
		"бс  бс",
		"бсбсбс",
	},
	{
		"бсбсбс",
		"бс  бс",
		"бсбсбс",
		"    бс",
		"    бс",
	}
};

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

void BOOM()
{

}