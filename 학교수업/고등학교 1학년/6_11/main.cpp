// p82 ����4

/*
#include <stdio.h>

int plus(int x, int y);
int minus(int x, int y);

void main()
{
	int a, b;
	int sum, diff;

	printf("���� A :"); scanf("%d", &a);
	printf("���� B :"); scanf("%d", &b);
	
	sum = plus(a, b);
	diff = minus(a, b);

	printf("�� ������ �� : %d \n", sum);
	printf("�� ������ �� : %d \n", diff);
}

int plus(int x, int y)
{
	return (x + y);
}

int minus(int x, int y)
{
	if (x > y) return (x - y);
	else return (y - x);
}
*/

// p82~p83 ����5

/*
#include <stdio.h>

int plus(int x, int y);
int plus(int x, int y, int z);

void main()
{
	int a, b, c;
	int sum;
	int choice;

	printf("�� ���� ������ �� : 1, �� ���� ������ �� : 2, �� �Է�");
	scanf("%d", &choice);

	if (choice == 1)
	{
		printf("���� A :"); scanf("%d", &a);
		printf("���� B :"); scanf("%d", &b);
		sum = plus(a, b);
		printf("�� ������ �� : %d\n", sum);
	}

	else
	{
		printf("���� A :"); scanf("%d", &a);
		printf("���� B :"); scanf("%d", &b);
		printf("���� C :"); scanf("%d", &c);
		sum = plus(a, b, c);
		printf("�� ������ �� : %d\n", sum);
	}
}

int plus (int x, int y)
{
	return (x + y);
}

int plus (int x, int y, int z)
{
	return (x + y + z);
}
*/

// ppt, ������ ���ǿ� �����ϴ� ���α׷��� �ۼ��Ͻÿ�. (�ͼ���)

/*
#include <stdio.h>
#include <conio.h>

int CalMonth(int x)
{
	return (x / 100);
}

int CalDay(int y)
{
	return (y % 100);
}

void main()
{
	int month, day;
	int num;

	puts("����� ������ ���纼����.");
	puts("1. ����� �¾ ���� 5���ϰ� 12�� ���ϼ���.");
	puts("2. �� ����� 20���ϰ� �¾ ���� ���ϼ���.");
	puts("3. ���⼭ 365�� ���� �󸶰� �˴ϱ�? �� ���� �Է��غ�����.");
	printf(" => "); scanf("%d", &num);
	
	month = CalMonth(num + 125);
	day = CalDay(num + 125);

	printf("����! ����� ������ %d�� %d���̱���. \n", month, day);
	_getch();
}
*/

// p84 ��������2

/*
#include <stdio.h>
#include <conio.h>

int total(int, int, int);
double average(int);

void main()
{
	int kor, eng, mat, tot;
	double avg;

	printf("�� ������ ������ �Է��ϼ���.\n");
	printf("����: "); scanf("%d", &kor);
	printf("����: "); scanf("%d", &eng);
	printf("����: "); scanf("%d", &mat);

	tot = total(kor, eng, mat);
	avg = average(tot);

	printf("���� : %d, ��� : %.1lf\n", tot, avg);
	_getch();
}

int total(int kor, int eng, int mat)
{
	int tot;

	tot = kor + eng + mat;
	return tot;
}

double average(int tot)
{
	double avg;
	avg = tot / 3.0;
	return avg;
}
*/

// p80 �������� 1-1

/*
#include <stdio.h>
#include <conio.h>

void hello();

void main()
{
	hello();
	_getch();
}

void hello()
{
	puts("�ȳ��ϼ���.");
}
*/

// p80 �������� 1-2

/*
#include <stdio.h>
#include <conio.h>

void Star(int num);

void main()
{
	int num;

	printf("���� ����: "); scanf("%d", &num);
	Star(num);
	_getch();
}

void Star(int num)
{
	for (int i = 0; i < num; i++)
		printf("*");
	printf("\n");
}
*/

// p80 �������� 1-3

/*
#include <stdio.h>
#include <conio.h>

void Output (int x, int y)
{
	int sum = 1;

	for (int i = 0; i < y; i++)
		sum *= x;
	printf("%d�� %d���� %d�Դϴ�. \n", x, y, sum);
}

void main()
{
	int x, y;

	printf("�ؼ� �Է� : "); scanf("%d", &x);
	printf("���� �Է� : "); scanf("%d", &y);
	Output(x, y);
	_getch();
}
*/

// p80 �������� 1-4

/*
#include <stdio.h>
#include <conio.h>

void Output(int x, int y)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = y-1; j > i; j--)
			printf(" ");
		for (int j = 0; j < x; j++)
			printf("+");
		printf("\n");
	}
}

void main()
{
	int x, y;

	puts("����纯���� �׷����ô�.");
	printf("�ʺ� :"); scanf("%d", &x);
	printf("���� :"); scanf("%d", &y);

	Output(x, y);
	_getch();
}
*/

// p81 �������� 1-5

/*
#include <stdio.h>
#include <conio.h>

void chline(int code, int x, int y)
{
	for (int i = 1; i < x; i++)
		printf(" ");
	for (int j = 0; j <= y - x; j++)
		printf("%c", code);
}

void main()
{
	char code;
	int x, y;

	printf("����� ���ڸ� �Է��Ͻÿ�. <�������� q> : ");

	while (1)
	{
		scanf("%c", &code);
		if (code == 'q')
			break;
		if (code == '\n')
			continue;
		printf("���� ���� ���� ���� �ش��ϴ� �� ���� �Է��Ͻÿ�.");
		scanf("%d%d", &x, &y);
		chline(code, x, y);
		printf("\n���� ����� ���ڸ� �Է��Ͻÿ�. <�������� q> :");
	}
	printf("����!\n");
	_getch();
}
*/

// p81 �������� 1-6

/*
#include <stdio.h>
#include <conio.h>

int Output(int x, int y)
{
	return (x * y / 2);
}

void main()
{
	int x, y;
	int result;

	printf("������� ���̸� ���ϴ� ���α׷�.\n");
	printf("�غ� �Է� :"); scanf("%d", &x);
	printf("���� �Է� :"); scanf("%d", &y);

	result = Output(x, y);

	printf("���� : %d", result);
	_getch();
}
*/

// p81 �������� 1-7

/*
#include <stdio.h>
#include <conio.h>

int Output(int n)
{
	int count = 0;

	for (int i = 1; i <= n; i++)
		count += i * i;

	return count;
}

void main()
{
	int n;
	int result;

	printf("N :"); scanf("%d", &n);

	result = Output(n);

	printf("������� %d�Դϴ�.\n", result);

	_getch();
}
*/