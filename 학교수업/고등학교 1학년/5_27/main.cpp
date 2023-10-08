// p71 9-3

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int i, j, p_j = 1;
	int x, y;

	printf("몇 행입니까? "); scanf("%d",&x);
	printf("몇 열입니까? "); scanf("%d",&y);

	for (i = 1; i <= x; i++)
	{
		for (j = 1; j <= y; j++)
		{
			if (p_j >= 10)
				p_j = 0;
			printf("%d", p_j);
			p_j++;
		}
		printf("\n");
		p_j--;
	}

	_getch();
	return 0;
}
*/

// p71 9-4

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int i, j;
	int x, y;
	bool code = 0;

	printf("몇 행입니까? "); scanf("%d",&x);
	printf("몇 열입니까? "); scanf("%d",&y);

	for (i = 0; i < x; i++)
	{
		switch (code) {
		case 0:
			for (j = 0; j < y; j++)
			{
				if (j % 2 == 0)
					printf("O");
				else		// j % 2 == 1
					printf("X");
			}
			printf("\n");
			code = 1;
			break;
		case 1:
			for (j = 0; j < y; j++)
			{
				if (j % 2 == 0)
					printf("X");
				else		// j % 2 == 1
					printf("O");
			}
			printf("\n");
			code = 0;
		}
	}
	_getch();
	return 0;
}
*/

// p72 9-5

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int i, j = 'A';
	
	for (i = 1; j <= 'Z'; i++, j++)
	{
		printf("%c",j);
		if (i % 4 == 0)
			printf("\n");
	}
	_getch();
	return 0;
}
*/

// p72 9-6

/*

#include <stdio.h>
#include <conio.h>

int main(void)
{
	char in;
	
	printf("시작할 알파벳을 입력하시오 :");
	scanf("%c", &in);
	for (int i = 1; ;i++)		// 무한 루프
	{
		for (int j = 0; j < i; j++)
		{
			printf("%c",in);
			in++;
			if (in > 'z')
				break;
		}
		if (in > 'z')
				break;
		printf("\n");
	}
	_getch();
	return 0;
}
*/

// p72 9-7

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int cheak = 0;
	int result = 0;
	int next = 0;

	printf("1부터 1000까지의 수 중에서 소수를 구하는 프로그램\n\n");
	for (int i = 2; i <= 1000; i++)		// 1은 소수가 아님. 2부터 해도 상관없음
	{
		for (int j = 2; j <= i; j++)
		{
			if (i % j == 0)
				cheak++;
		}

		if (cheak == 1)
		{
			printf("%d\t",i);
			result++;
			next++;
		}
		cheak = 0;
		if (next == 8)
		{
			printf("\n");
			next = 0;
		}
	}
	printf("\n");
	printf("1부터 1000까지의 소수는 %d개 입니다.\n", result);
	_getch();
	return 0;
}
*/

// continue 예제 1

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i, j;
	i = j = 0;

	printf("continue문의 테스트입니다.\n");

	do {
		printf("do_while문의 %d번째 반복입니다.\n",i);
		for (j = 0; j < 10; j++)
		{
			if (j == 5)
				continue;
			printf("for문의 %d번째 반복입니다.\n",j);
		}
		i++;
	} while (i < 5);

	printf("프로그램을 종료합니다.\n");
	_getch();
}
*/

// continue 예제 2

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int i = 0, hap = 0;

	while (i <= 100)
	{
		i++;
		if (i % 2 == 1)
			continue;
		hap += i;
		if (hap > 1000)
			break;
	}
	printf("i의 값이 %d일 때 합이 1000을 넘었습니다.\n",i);
	_getch();
	return 0;
}
*/

// goto 예제 1

#include <stdio.h>
#include <conio.h>

int main(void)
{
	int a = 1;
here:
	a++;
	if (a == 2)
		goto here;
	printf("%d\n",a);
	_getch();
	return 0;
}