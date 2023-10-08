// p89 실전문제 3-1

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
	printf("피겨 스케이팅 점수 계산 프로그램\n");
}

void Input1()
{
	printf("심판의 수를 입력하세요. : "); scanf("%d", &judge_num);
}

void Input2()
{
	for (int i = 1; i <= judge_num; i++)
	{
		printf("%d 번 심판의 점수< 0 - 10 > : ", i); scanf("%d", &judge_score);
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
	printf("총점 : %d 평점 : %.2f", total, average);
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

// p90 실전문제 3-2

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

	printf("이찹아정식의 해를 구하는 프로그램.\n\n");
	printf("이차방정식을 풀어볼까요.\n\n");
	printf("다음과 같은 형식으로 방정식을 입력하세요.\n");
	printf("ax2 + bx + c = 0의 형태입니다. a, b, c값을 입력하세요.\n\n");

	printf("입력 => "); scanf("%d%d%d",&a, &b, &c);

	ComputeAndOutput(a, b, c);
	_getch();
}
*/

// p90 실전문제 3-3

#include <stdio.h>
#include <conio.h>

void Change(int x, int y)
{
	int count;

	printf("교환 전 x = %d, y = %d\n", x, y);

	count = x;
	x = y;
	y = count;

	printf("교환 후 x = %d, y = %d", x, y);
}

void main()
{
	int x, y;

	printf("x값 입력 : "); scanf("%d", &x);
	printf("y값 입력 : "); scanf("%d", &y);

	Change(x, y);
	_getch();
}