// p71 실전문제 9-2

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i, j, p = 1;
	bool code = 0;

	printf("지그재그로 숫자를 출력하는 프로그램\n");

	while (p < 25)
	{
		switch (code) {
		case 0:
			for (i = 0; i < 5; i++)
			{
				printf("%d\t",p);
				p++;
			}
			printf("\n");
			code = 1;
			break;
		case 1:
			p += 4;
			for (j = 5; j > 0; j--)
			{
				printf("%d\t",p);
				p--;
			}
			printf("\n");
			p += 6;
			code = 0;
			break;
		}
	}
	_getch();
}
*/

// p71 실전문제 9-3

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int x, y;
	int i, j;
	int num , up = 1;

	printf("몇 행입니까? "); scanf("%d",&y);
	printf("몇 열입니까? "); scanf("%d",&x);

	for (i = 0; i < y; i++)
	{
		num = up;
		for (j = 0; j < x; j++)
		{
			printf("%d",num++);
			if (num == 10)
				num = 0;
		}
		up++;
		if (up == 10)
				up = 0;
		printf("\n");
	}
	_getch();
}
*/

// p71 실전문제 9-4

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int x, y;
	int i, j;
	bool code = 0;

	printf("몇 행입니까? "); scanf("%d",&y);
	printf("몇 열입니까? "); scanf("%d",&x);

	for (i = 0; i < y; i++)
	{
		switch (code) {
		case 0:
			for (j = 0; j < x; j++)
			{
				if (j % 2 == 0)
					printf("O");
				else if (j % 2 == 1)
					printf("X");
			}
			printf("\n");
			code = 1;
			break;
		case 1:
			for (j = 0; j < x; j++)
			{
				if (j % 2 == 0)
					printf("X");
				else if (j % 2 == 1)
					printf("O");
			}
			printf("\n");
			code = 0;
			break;
		}
	}
	_getch();
}
*/

// p72 실전문제 9-5

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char Alphabat = 'A';
	int i, j;

	for (i = 'A'; Alphabat < 'Z'; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%c",Alphabat);
			Alphabat++;
			if (Alphabat > 'Z')
				break;
		}
		printf("\n");
	}
	_getch();
}
*/

// p72 실전문제 9-6

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char Alphabat;
	int i,j;

	printf("시작할 알파벳을 입력(소문자) : "); scanf("%c",&Alphabat);

	for (i = 1; Alphabat < 'z'; i++)
	{
		for (j = 0; j < i; j++)
		{
			printf("%c",Alphabat);
			Alphabat++;
			if (Alphabat > 'z')
				break;
		}
		printf("\n");
	}
	_getch();
}
*/

// p72 실전문제 9-7

#include <stdio.h>
#include <conio.h>

void main()
{
	int i, j;

	for (j = 0; j < 8; j++)
	{
		for (i = 0; i < 1000; i++)
		{
			
		}
		printf("\n");
	}
	_getch();
}