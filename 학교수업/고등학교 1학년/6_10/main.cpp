// p75 �������� 10-1

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num, sum = 0, count = 1;
	bool share = 0;

	printf("10������ �Է��ϼ���.\n");
	printf("[10����] ==> "); scanf("%d",&num);
	printf("[2����] ==> ");
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

// p75 �������� 10-2

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
	printf("goto���� ����� 1���� 10������ ����\n");
	printf("sum = %d\n", sum);
	_getch();
}
*/

// �Լ� ppt.

/*
#include <stdio.h>
#include <conio.h>

int Max (int a, int b);

void main()
{
	int a, b, m;

	printf("�� ���� �Է��ϼ���. :");
	scanf("%d%d", &a, &b);
	m = Max (a, b);
	printf("�� ���� ū ���� %d�Դϴ�.\n", m);
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

// p78 ����1 < ���� �Լ����� ���� >

/*
#include <stdio.h>

void main()
{
	printf("�� �� �� ���� ���� ���ϱ�");

	int a, b, min;

	scanf("%d%d", &a, &b);
	if (a > b)
		min = b;
	else
		min = a;
	printf("�� �� �� ���� ���� %d", min);
}
*/

// p78 ����2 < ����� �Լ��� ���� >

/*
#include <stdio.h>

void min();

void main()
{
	printf("�� �� �� ���� ���� ���ϱ�");
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
	printf("�� �� �� ���� ���� %d", min);
}
*/

// p78 ����2

/*
#include <stdio.h>

void min(int x, int y);

void main()
{
	printf("�� �� �� ���� ���� ���ϱ�");

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
	printf("�� �� �� ���� ���� %d", m);
}
*/

// p79 ����3

/*
#include <stdio.h>

int min(int x, int y);

void main()
{
	printf("�� �� �� ���� ���� ���ϱ�");

	int a, b, m;
	scanf("%d%d", &a, &b);
	m = min(a, b);
	printf("�� �� �� ���� ���� %d", m);
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