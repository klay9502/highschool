// p69 ����14

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int a, b;
	for (a = 1; a < 3; a++)
	{
		printf("a = %d;			\/\/�ٱ� �����\n", a);
		for (b = 1; b < 5; b++)
			printf("	b = %d		\/\/���� �����\n", b);
	}
	_getch();
	return 0;
}
*/

// p69 ����15

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
		printf("���ִϿ�����б�\n");
	}
	_getch();
	return 0;
}
*/

// p69 ���� ����9

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int i, j;
	int height, width;

	printf("���� ��: "); scanf("%d", &height);
	printf("���� ��: "); scanf("%d", &width);

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

// p70 ���� 9-1 1��

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int input;
	int i, j;

	printf("�� ���Դϱ� :"); scanf("%d", &input);
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

// p70 ���� 9-1 2��

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int input;
	int i, j;

	printf("�� ���Դϱ� :"); scanf("%d", &input);
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

// p70 ���� 9-1 3��

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int input;
	int i, j;

	printf("�� ���Դϱ� :"); scanf("%d", &input);
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

// p71 ���� 9-1 4��

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int input;
	int i, j;

	printf("�Ƕ�̵带 �����ô�.\n");
	printf("�� ���Դϱ� :"); scanf("%d", &input);
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

// p71 ���� 9-1 5��

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int input;
	int i, j;
	int p_i = 1;

	printf("�Ƕ�̵带 �����ô�.\n");
	printf("�� ���Դϱ� :"); scanf("%d", &input);
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