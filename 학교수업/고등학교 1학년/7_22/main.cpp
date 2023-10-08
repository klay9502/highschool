// p111 예제10

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int array[2][3] = {10, 20, 30, 40, 50, 60};
	// int array[2][3] = {{10, 20, 30}, {40, 50, 60}};	// 가능(권장)
	// int array[][3] = {10, 20, 30, 40, 50, 60};	// 가능
	// int array[][3] = {{10, 20, 30}, {40, 50, 60}};	// 가능(권장)
	// int array[][3] = {{10, 20, 30}, 40, 50, 60};	// 가능
	// int array[][3] = {10, 20, 30, {40, 50, 60}};	// 가능
	// int array[2][] = {10, 20, 30, 40, 50, 60};	// 불가능
	// int array[2][3] = {10, 20, 30, 40, 50, 60, 70};	// 불가능
	// int array[2][3] = {{10, 20, 30}, 40, 50, 60, 70};	// 불가능

	int a, b;
	
	a = 1, b = 0;

	printf("%4d %4d %4d\n", array[0][0], array[b][a], array[0][2]);
	printf("%4d %4d %4d\n", array[a][b], array[1][1], array[1][2]);

	_getch();
}
*/

// ppt 이차원 배열 예제1

/*
#include <stdio.h>
#include <conio.h>


void main()
{
	int area[2][3];
	int m, n;

	puts("이차원 배열 예제1");

	for (m = 0; m < 2; m++)
		for (n = 0; n < 3; n++)
			area[m][n] = 10 * m + n;

	for (m = 0; m < 2; m++)
		for (n = 0; n < 3; n++)
			printf("area[%d][%d] = %d\n", m, n, area[m][n]);

	_getch();
}
*/

// p113 연습 문제3

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int total[5][4] = {
		{95, 60, 88},
		{85, 75, 90},
		{80, 92, 78},
		{96, 86, 98},
		{75, 53, 93}
	};

	for (int i = 0; i < 5; i++)
		total[i][3] = total[i][0] + total[i][1] + total[i][2];

	printf("==================================================\n");
	printf("\tkor\teng\tmat\t\ttotal\n");
	printf("--------------------------------------------------\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("\t%d", total[i][j]);
		printf("\t\t%d\n", total[i][3]);
		printf("--------------------------------------------------\n");
	}

	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
	int B[2][3] = {{6, 3, 4}, {5, 1, 2}};

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%4d", A[i][j] + B[i][j]);
		printf("\n");
	}

	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int arr[8][9];

	for (int i = 2; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
			arr[i - 2][j - 1] = i * j;
	}

	for (int i = 0; i < 8; i++)
	{
		printf("%d단 : \t",i + 2);
		for (int j = 0; j < 9; j++)
			printf("%4d", arr[i][j]);
		printf("\n");
	}

	_getch();
}
*/

// p116 예제15

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int array[2][2][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	// int array[2][2][3] = {{{1, 2, 3}, {4, 5, 6}},{{7, 8, 9}, {10, 11, 12}}};
	// int array[][2][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	// int array[][2][3] = {{1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}};
	// int array[][2][3] = {{{1, 2, 3}, {4, 5, 6}}, {{7, 8, 9}, {10, 11, 12}}};

	int a, b, c;

	int M = sizeof(array) / sizeof(array[0]);
	int H = sizeof(array[0]) / sizeof(array[0][0]);
	int Y = sizeof(array[0][0]) / sizeof(array[0][0][0]);

	for (a = 0; a < M; a++)
	{
		for (b = 0; b < H; b++)
		{
			for (c = 0; c < Y; c++)
				printf("%3d", array[a][b][c]);
			printf("\n");
		}
		printf("\n");
	}
	puts("종료");
	_getch();
}
*/

// p125 연습문제6

/*
#include <stdio.h>
#include <conio.h>

#define MAX 5

void main()
{
	int array[MAX][MAX] = {0};
	int i, j, cnt = 0;

	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j <= i; j++)
		{
			cnt++;
			array[i][j] = cnt;
		}
	}
	
	printf("배열에 입력된 내용 출력\n");

	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (array[i][j] == 0)
				printf("\t");
			else
				printf("%5d", array[i][j]);
		}
		printf("\n");
	}
	_getch();
}

*/

// p126 실전 6-1

/*
#include <stdio.h>
#include <conio.h>

#define MAX 5

void main()
{
	int array[MAX][MAX] = {0};
	int i, j, cnt = 0;

	for (i = 0; i < MAX; i++)
	{
		for (j = MAX - 1; j >= MAX - 1 - i; j--)
		{
			cnt++;
			array[i][j] = cnt;
		}
	}
	
	printf("배열에 입력된 내용 출력\n");

	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			if (array[i][j] == 0)
				printf("     ");
			else
				printf("%5d", array[i][j]);
		}
		printf("\n");
	}
	_getch();
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void main()
{
	int com_num[3] = {0};
	int num[3] = {0};
	int Inning;
	int strike = 0, ball = 0;
	int count = 1;

	srand((int)time(NULL));
	
	while(1)
	{
		for (int i = 0; i < 3; i++)
			com_num[i] = rand()%9 + 1;
		if (com_num[0] == com_num[1] || com_num[1] == com_num[2] || com_num[0] == com_num[2])
			continue;
		else
			break;
	}

	printf("computer : %d %d %d\n\n", com_num[0], com_num[1], com_num[2]);

	while(1)
	{
		printf("%dth Inning : Insert Number (ex.5 2 8) : ", count);
		scanf("%d %d %d", &num[0], &num[1], &num[2]);

		if (num[0] == com_num[0])
			strike++;
		if (num[0] == com_num[1] || num[0] == com_num[2])
			ball++;
		if (num[1] == com_num[1])
			strike++;
		if (num[1] == com_num[0] || num[1] == com_num[2])
			ball++;
		if (num[2] == com_num[2])
			strike++;
		if (num[2] == com_num[0] || num[2] == com_num[1])
			ball++;

		printf("%d strike, %d ball\n", strike, ball);

		if (strike == 3)
		{
			puts("You Win!");
			break;
		}
		
		if (count > 8)
		{
			puts("Computer Win! You Lose!");
			break;
		}

		strike = 0;
		ball = 0;
		count++;
	}
	_getch();
}