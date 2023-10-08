// p81 ���� 1-5

/*
#include <stdio.h>
#include <conio.h>

void Output(int code, int x, int y)
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
		Output(code, x, y);
		printf("\n���� ����� ���ڸ� �Է��Ͻÿ�. <�������� q> :");
	}
	printf("����!\n");
	_getch();
}
*/

// p81 ���� 1-6

/*
#include <stdio.h>
#include <conio.h>

int Output(int x, int y)
{
	return (x * y / 2);
}

void main()
{
	int x, y, result;

	printf("�ﰢ���� ���̸� ���غ��ô�.\n");
	printf("�غ� : "); scanf("%d", &x);
	printf("���� : "); scanf("%d" ,&y);

	result = Output(x, y);

	printf("���� : %d\n", result);
	_getch();
}
*/

// p81 ���� 1-7

/*
#include <stdio.h>
#include <conio.h>

int Compute(int n)
{
	int count = 0;

	for (int i = 1; i <= n; i++)
		count += i * i;

	return count;
}

void main()
{
	int n, result;

	printf("N : "); scanf("%d", &n);

	result = Compute(n);

	printf("������� %d�Դϴ�.\n", result);
	_getch();
}
*/

// p82 ����4

/*
#include <stdio.h>

int plus (int x, int y);
int minus(int x, int y);

void main()
{
	int a, b;
	int sum, diff;
	
	printf("���� A : "); scanf("%d", &a);
	printf("���� B : "); scanf("%d", &b);

	sum = plus(a, b);
	diff = minus(a, b);

	printf("�� ������ �� : %d\n", sum);
	printf("�� ������ �� : %d\n", diff);
}

int plus(int x, int y)
{
	return (x + y);
}

int minus(int x, int y)
{
	if (x > y)
		return (x - y);
	else
		return (y - x);
}
*/

// p82~83 ����5

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

// p84 ��������2

/*
#include <stdio.h>

int total (int, int, int);
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

// p85 ���� 2-1

/*
#include <stdio.h>
#include <conio.h>

int Compute(int km, int min)
{
	int count_km = km * 1000;
	int count_pay = 0;
	int code;

	printf("�ְ��Դϱ�? �����Դϱ�?\n�ְ� : 0, ���� : 1 "); scanf("%d", &code);

	if (count_km <= 2000)
		count_km = 0;								
	else
		count_km = count_km - 2000;					// �⺻���� 2000m (2km)�� ����.

	switch (code) {
	case 0:
		for (int i = count_km; i >= 180;)
		{
			count_pay += 100;
			i -= 180;
		}
		count_pay += min * 100;						// ����� 60�ʸ��� 100���� ��ݺΰ�
		count_pay += 1800;							// �⺻���
		break;
	case 1:
		for (int i = count_km; i >= 200;)
		{
			count_pay += 200;
			i -= 180;
		}
		count_pay += min * 100;
		count_pay += 2180;
	}
	return count_pay;
}

void main()
{
	int km, min;
	int pay;

	printf("�ýÿ���� ����ϴ� ���α׷��Դϴ�.\n");
	printf("�̵��� �Ÿ�<���� : km>�� �Է��ϼ��� : "); scanf("%d", &km);
	printf("�̵��� �Ÿ�<���� : ��>�� �Է��ϼ��� : "); scanf("%d", &min);

	pay = Compute(km, min);

	printf("���� ����� %d���Դϴ�.\n", pay);
	_getch();
}
*/

// p85 ���� 2-2

/*
#include <stdio.h>
#include <conio.h>

int Binary(int num)				// 2������ ��ȯ�ϴ� �Լ�
{
	int count_num;
	int count_result = 0;
	int i = 1;

	while (1)
	{
		if (num == 0)
			break;
		count_num = num % 2;
		count_result += count_num * i;
		num = num / 2;
		i *= 10;
	}

	return count_result;
}
int Octal(int num)				// 8������ ��ȯ�ϴ� �Լ�
{
	int count_num;
	int count_result = 0;
	int i = 1;

	while (1)
	{
		if (num == 0)
			break;
		count_num = num % 8;
		count_result += count_num * i;
		num = num / 8;
		i *= 10;
	}

	return count_result;
}
void main()
{
	int num;

	printf("���� ��ȯ ���α׷�.\n\n");
	printf("10������ �Է��ϼ���.\n\n");
	printf("[10����] ==> "); scanf("%d", &num);
	printf("\n[2����] ==> %d\n\n", Binary(num));
	printf("[8����] ==> %d\n\n", Octal(num));
	_getch();
}
*/

// p86 ����6

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a = 10;
	printf("���������� ���� �׽�Ʈ\n");
	printf("a�� ���� : %d\n", a);
	
	if (a == 10)
	{
		int a = 7;
		printf("if���� �ڵ� ��� ���Դϴ�.\n");
		printf("a�� ���� : %d\n", a);
	}
	printf("���������� ���� �׽�Ʈ\n");
	printf("a�� ���� : %d\n", a);
	_getch();
}
*/