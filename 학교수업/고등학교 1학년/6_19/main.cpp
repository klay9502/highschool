// p89 �������� 3-1

/*
#include <stdio.h>
#include <conio.h>

int judge_num;
int judge_score;
int total;
int max = 0, min = 10;
float average;

void Intro()
{
	printf("�ǰ� �������� ���� ��� ���α׷�\n");
}

void Input1()
{
	printf("������ ���� �Է��ϼ���. : "); scanf("%d", &judge_num);
}

void Input2()
{
	for (int i = 1; i <= judge_num; i++)
	{
		printf("%d �� ������ ����< 0 - 10 > : ", i); scanf("%d", &judge_score);
		if (judge_score > max)
			max = judge_score;
		if (judge_score < min)
			min = judge_score;
		total += judge_score;
	}
}

void Cal()
{
	total = total - max - min;
	average = (float)total / (judge_num - 2);
}

void Output()
{
	printf("���� : %d ���� : %.2f", total, average);
}

void main()
{
	Intro();
	Input1();
	Input2();
	Cal();
	Output();
	_getch();
}
*/

// p90 �������� 3-2

/*
#include <stdio.h>
#include <conio.h>
#include <math.h>

void ComputeAndOutput(int a, int b, int c)
{
	int x1, x2;
	float count = (b * b) + (-4 * a * c);

	x1 = (-b + sqrt(count)) / (2 * a);
	x2 = (-b - sqrt(count)) / (2 * a);

	printf("x1 = \t%d\n", x1);
	printf("x2 = \t%d", x2);
}

void main()
{
	int a, b, c;

	printf("������������ �ظ� ���ϴ� ���α׷�.\n\n");
	printf("������������ Ǯ����.\n\n");
	printf("������ ���� �������� �������� �Է��ϼ���.\n");
	printf("ax2 + bx + c = 0�� �����Դϴ�. a, b, c���� �Է��ϼ���.\n\n");

	printf("�Է� => "); scanf("%d%d%d",&a, &b, &c);

	ComputeAndOutput(a, b, c);
	_getch();
}
*/

// p90 �������� 3-3

#include <stdio.h>
#include <conio.h>

void Change(int x, int y)
{
	int count;

	printf("��ȯ �� x = %d, y = %d\n", x, y);

	count = x;
	x = y;
	y = count;

	printf("��ȯ �� x = %d, y = %d", x, y);
}

void main()
{
	int x, y;

	printf("x�� �Է� : "); scanf("%d", &x);
	printf("y�� �Է� : "); scanf("%d", &y);

	Change(x, y);
	_getch();
}