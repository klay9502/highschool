// p81 실전 1-5

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
		Output(code, x, y);
		printf("\n다음 출력할 문자를 입력하시오. <끝내려면 q> :");
	}
	printf("종료!\n");
	_getch();
}
*/

// p81 실전 1-6

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

	printf("삼각형의 넓이를 구해봅시다.\n");
	printf("밑변 : "); scanf("%d", &x);
	printf("높이 : "); scanf("%d" ,&y);

	result = Output(x, y);

	printf("넓이 : %d\n", result);
	_getch();
}
*/

// p81 실전 1-7

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

	printf("결과값은 %d입니다.\n", result);
	_getch();
}
*/

// p82 예제4

/*
#include <stdio.h>

int plus (int x, int y);
int minus(int x, int y);

void main()
{
	int a, b;
	int sum, diff;
	
	printf("정수 A : "); scanf("%d", &a);
	printf("정수 B : "); scanf("%d", &b);

	sum = plus(a, b);
	diff = minus(a, b);

	printf("두 정수의 합 : %d\n", sum);
	printf("두 정수의 차 : %d\n", diff);
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

// p82~83 예제5

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

// p84 연습문제2

/*
#include <stdio.h>

int total (int, int, int);
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

// p85 실전 2-1

/*
#include <stdio.h>
#include <conio.h>

int Compute(int km, int min)
{
	int count_km = km * 1000;
	int count_pay = 0;
	int code;

	printf("주간입니까? 할증입니까?\n주간 : 0, 할증 : 1 "); scanf("%d", &code);

	if (count_km <= 2000)
		count_km = 0;								
	else
		count_km = count_km - 2000;					// 기본구간 2000m (2km)를 뺀다.

	switch (code) {
	case 0:
		for (int i = count_km; i >= 180;)
		{
			count_pay += 100;
			i -= 180;
		}
		count_pay += min * 100;						// 주행시 60초마다 100원씩 요금부과
		count_pay += 1800;							// 기본요금
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

	printf("택시요금을 계산하는 프로그램입니다.\n");
	printf("이동한 거리<단위 : km>를 입력하세요 : "); scanf("%d", &km);
	printf("이동한 거리<단위 : 분>을 입력하세요 : "); scanf("%d", &min);

	pay = Compute(km, min);

	printf("계산된 요금은 %d원입니다.\n", pay);
	_getch();
}
*/

// p85 실전 2-2

/*
#include <stdio.h>
#include <conio.h>

int Binary(int num)				// 2진수를 변환하는 함수
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
int Octal(int num)				// 8진수를 변환하는 함수
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

	printf("진수 변환 프로그램.\n\n");
	printf("10진수를 입력하세요.\n\n");
	printf("[10진수] ==> "); scanf("%d", &num);
	printf("\n[2진수] ==> %d\n\n", Binary(num));
	printf("[8진수] ==> %d\n\n", Octal(num));
	_getch();
}
*/

// p86 예제6

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a = 10;
	printf("지역변수에 대한 테스트\n");
	printf("a의 값은 : %d\n", a);
	
	if (a == 10)
	{
		int a = 7;
		printf("if문의 코드 블록 안입니다.\n");
		printf("a의 값은 : %d\n", a);
	}
	printf("지역변수에 대한 테스트\n");
	printf("a의 값은 : %d\n", a);
	_getch();
}
*/