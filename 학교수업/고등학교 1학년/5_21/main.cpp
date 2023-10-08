// p69 예제14

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int a, b;
	for (a = 1; a < 3; a++)
	{
		printf("a = %d;			\/\/바깥 제어변수\n", a);
		for (b = 1; b < 5; b++)
			printf("	b = %d		\/\/안쪽 제어변수\n", b);
	}
	_getch();
	return 0;
}
*/

// p69 예제15

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int a, b;
	for (a = 1; a < 5; a++)
	{
		for (b = 1; b < a; b++)
			printf("#");
		printf("울산애니원고등학교\n");
	}
	_getch();
	return 0;
}
*/

// p69 연습 문제9

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int i, j;
	int height, width;

	printf("행의 수: "); scanf("%d", &height);
	printf("열의 수: "); scanf("%d", &width);

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
			printf("*");
		printf("\n");
	}
	_getch();
	return 0;
}
*/

// p70 실전 9-1 1번

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int input;
	int i, j;

	printf("몇 단입니까 :"); scanf("%d", &input);
	for (i = 0; i < input; i++)
	{
		for (j = input; j > i; j--)
			printf("*");
		printf("\n");
	}
	_getch();
	return 0;
}
*/

// p70 실전 9-1 2번

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int input;
	int i, j;

	printf("몇 단입니까 :"); scanf("%d", &input);
	for (i = 0; i < input; i++)
	{
		for (j = input; j-1 > i; j--)
			printf(" ");
		for (j = 0; j <= i; j++)
			printf("*");
		printf("\n");
	}
	_getch();
	return 0;
}
*/

// p70 실전 9-1 3번

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int input;
	int i, j;

	printf("몇 단입니까 :"); scanf("%d", &input);
	for (i = 0; i < input; i++)
	{
		for (j = 0; j < i; j++)
			printf(" ");
		for (j = input; j > i; j--)
			printf("*");
		printf("\n");
	}
	_getch();
	return 0;
}
*/

// p71 실전 9-1 4번

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int input;
	int i, j;

	printf("피라미드를 만들어봅시다.\n");
	printf("몇 단입니까 :"); scanf("%d", &input);
	for (i = 1; i <= input; i++)
	{
		for (j = input; j > i; j--)
			printf(" ");
		for (j = 0; j < i*2-1; j++)
			printf("*");
		printf("\n");
	}
	_getch();
	return 0;
}
*/

// p71 실전 9-1 5번

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int input;
	int i, j;
	int p_i = 1;

	printf("피라미드를 만들어봅시다.\n");
	printf("몇 단입니까 :"); scanf("%d", &input);
	for (i = 1; i <= input; i++)
	{
		for (j = input; j > i; j--)
			printf(" ");
		for (j = 0; j < i*2-1; j++)
			printf("%d", p_i);
		printf("\n");
		p_i++;
		if (p_i == 10)
			p_i = 0;
	}
	_getch();
	return 0;
}
*/