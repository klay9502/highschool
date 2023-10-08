// p82 예제4

/*
#include <stdio.h>

int plus(int x, int y);
int minus(int x, int y);

void main()
{
	int a, b;
	int sum, diff;

	printf("정수 A :"); scanf("%d", &a);
	printf("정수 B :"); scanf("%d", &b);
	
	sum = plus(a, b);
	diff = minus(a, b);

	printf("두 정수의 합 : %d \n", sum);
	printf("두 정수의 차 : %d \n", diff);
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

// p82~p83 예제5

/*
#include <stdio.h>

int plus(int x, int y);
int plus(int x, int y, int z);

void main()
{
	int a, b, c;
	int sum;
	int choice;

	printf("두 개의 정수의 합 : 1, 세 개의 정수의 합 : 2, 를 입력");
	scanf("%d", &choice);

	if (choice == 1)
	{
		printf("정수 A :"); scanf("%d", &a);
		printf("정수 B :"); scanf("%d", &b);
		sum = plus(a, b);
		printf("두 정수의 합 : %d\n", sum);
	}

	else
	{
		printf("정수 A :"); scanf("%d", &a);
		printf("정수 B :"); scanf("%d", &b);
		printf("정수 C :"); scanf("%d", &c);
		sum = plus(a, b, c);
		printf("세 정수의 합 : %d\n", sum);
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

// ppt, 다음의 조건에 만족하는 프로그램을 작성하시오. (넌센스)

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

	puts("당신의 생일을 맞춰볼께요.");
	puts("1. 당신이 태어난 달을 5배하고 12를 더하세요.");
	puts("2. 그 결과를 20배하고 태어난 날을 더하세요.");
	puts("3. 여기서 365를 빼면 얼마가 됩니까? 그 값을 입력해보세요.");
	printf(" => "); scanf("%d", &num);
	
	month = CalMonth(num + 125);
	day = CalDay(num + 125);

	printf("아하! 당신의 생일은 %d월 %d일이군요. \n", month, day);
	_getch();
}
*/

// p84 연습문제2

/*
#include <stdio.h>
#include <conio.h>

int total(int, int, int);
double average(int);

void main()
{
	int kor, eng, mat, tot;
	double avg;

	printf("세 과목의 점수를 입력하세요.\n");
	printf("국어: "); scanf("%d", &kor);
	printf("영어: "); scanf("%d", &eng);
	printf("수학: "); scanf("%d", &mat);

	tot = total(kor, eng, mat);
	avg = average(tot);

	printf("총점 : %d, 평균 : %.1lf\n", tot, avg);
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

// p80 실전문제 1-1

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
	puts("안녕하세요.");
}
*/

// p80 실전문제 1-2

/*
#include <stdio.h>
#include <conio.h>

void Star(int num);

void main()
{
	int num;

	printf("별의 개수: "); scanf("%d", &num);
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

// p80 실전문제 1-3

/*
#include <stdio.h>
#include <conio.h>

void Output (int x, int y)
{
	int sum = 1;

	for (int i = 0; i < y; i++)
		sum *= x;
	printf("%d의 %d승은 %d입니다. \n", x, y, sum);
}

void main()
{
	int x, y;

	printf("밑수 입력 : "); scanf("%d", &x);
	printf("지수 입력 : "); scanf("%d", &y);
	Output(x, y);
	_getch();
}
*/

// p80 실전문제 1-4

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

	puts("평행사변형을 그려봅시다.");
	printf("너비 :"); scanf("%d", &x);
	printf("높이 :"); scanf("%d", &y);

	Output(x, y);
	_getch();
}
*/

// p81 실전문제 1-5

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

	printf("출력할 문자를 입력하시오. <끝내려면 q> : ");

	while (1)
	{
		scanf("%c", &code);
		if (code == 'q')
			break;
		if (code == '\n')
			continue;
		printf("시작 열과 마감 열에 해당하는 두 수를 입력하시오.");
		scanf("%d%d", &x, &y);
		chline(code, x, y);
		printf("\n다음 출력할 문자를 입력하시오. <끝내려면 q> :");
	}
	printf("종료!\n");
	_getch();
}
*/

// p81 실전문제 1-6

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

	printf("삼격형의 넓이를 구하는 프로그램.\n");
	printf("밑변 입력 :"); scanf("%d", &x);
	printf("높이 입력 :"); scanf("%d", &y);

	result = Output(x, y);

	printf("넓이 : %d", result);
	_getch();
}
*/

// p81 실전문제 1-7

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

	printf("결과값은 %d입니다.\n", result);

	_getch();
}
*/