// p75 실전문제 10-1

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num, sum = 0, count = 1;
	bool share = 0;

	printf("10진수를 입력하세요.\n");
	printf("[10진수] ==> "); scanf("%d",&num);
	printf("[2진수] ==> ");
	while (1)
	{
		share = num % 2;
		num = num / 2;
		sum += count * share;
		count = count * 10;
		if (num == 0)
			break;
	}
	printf("%d", sum);
	_getch();
}
*/

// p75 실전문제 10-2

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a = 0;
	int sum = 0;
goback:
	sum += a;
	a++;
	if (a <= 10)
		goto goback;
	printf("goto문을 사용한 1부터 10까지의 합은\n");
	printf("sum = %d\n", sum);
	_getch();
}
*/

// 함수 ppt.

/*
#include <stdio.h>
#include <conio.h>

int Max (int a, int b);

void main()
{
	int a, b, m;

	printf("두 수를 입력하세요. :");
	scanf("%d%d", &a, &b);
	m = Max (a, b);
	printf("두 수중 큰 값은 %d입니다.\n", m);
	_getch();
}

int Max (int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
*/

// p78 예제1 < 메인 함수에서 구현 >

/*
#include <stdio.h>

void main()
{
	printf("두 수 중 작은 수를 구하기");

	int a, b, min;

	scanf("%d%d", &a, &b);
	if (a > b)
		min = b;
	else
		min = a;
	printf("두 수 중 작은 수는 %d", min);
}
*/

// p78 예제2 < 사용자 함수로 구현 >

/*
#include <stdio.h>

void min();

void main()
{
	printf("두 수 중 작은 수를 구하기");
	min();
}

void min()
{
	int a, b, min;

	scanf("%d%d", &a, &b);
	if (a > b)
		min = b;
	else
		min = a;
	printf("두 수 중 작은 수는 %d", min);
}
*/

// p78 예제2

/*
#include <stdio.h>

void min(int x, int y);

void main()
{
	printf("두 수 중 작은 수를 구하기");

	int a, b;
	scanf("%d%d", &a, &b);
	min(a,b);
}

void min(int x, int y)
{
	int m;

	if (x > y)
		m = y;
	else
		m = x;
	printf("두 수 중 작은 수는 %d", m);
}
*/

// p79 예제3

/*
#include <stdio.h>

int min(int x, int y);

void main()
{
	printf("두 수 중 작은 수를 구하기");

	int a, b, m;
	scanf("%d%d", &a, &b);
	m = min(a, b);
	printf("두 수 중 작은 수는 %d", m);
}

int min(int x, int y)
{
	int m;

	if (x > y)
		m = y;
	else
		m = x;
	return m;
}
*/