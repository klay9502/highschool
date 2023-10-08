// 주제 : 연산자 응용문제
// 날짜 : 2014 / 4 / 14
// 제작 : 김종민

// 700MB크기의 파일하나를 다운받는데 걸리는 시간을 구하시오.

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int KBspeed;
	int hour,min,sec;

	printf("전송 속도(KB) : ");
	scanf("%d",&KBspeed);

	sec = (700*1024) / KBspeed;
	min = (sec / 60) % 60;
	hour = ((sec / 60) % min) % 24;			// 에러
	sec = sec % 60;

	printf("소요시간 : %d시간 %d분 %d초",hour,min,sec);
	_getch();
}
*/

// 3년 만기 정기예금의 이자가 5%일 경우, 1000만원을 3년동안 정기예금에 넣어두면, 만기 후 총액은?

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int money,plus;
	int sum;

	money = 10000000;

	plus = (money * 0.05) * 3;

	sum = money + plus;

	printf("예금액 : %10d\n",money);
	printf("이자액 : %10d\n",plus);
	printf("만기액 : %10d\n",sum);
	_getch();
}
*/

// 주제 : 제어문

// 예제1

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	float num;

	printf("수를 하나 입력하세요.\n");
	scanf("%f",&num);
	if ((num-(int)num)==0)
		printf("정수를 입력하셨습니다.\n");
	printf("당신이 입력한 수는 %.1f 입니다.\n",num);
	_getch();
}
*/

// 예제2

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	float num;

	printf("수를 하나 입력하세요.\n");
	scanf("%f",&num);
	if ((num-(int)num)==0)
		printf("정수를 입력하셨습니다.\n");
	else
		printf("실수를 입력하셨습니다.\n");

	printf("당신이 입력한 수는 %.4f 입니다.\n",num);

	_getch();
}
*/

// 연습문제 1

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num;

	printf("정수를 하나 입력하세요.\n");
	scanf("%d",&num);
	if (num >= 0)
		printf("양수를 입력하셨습니다.\n");
	else
		printf("음수를 입력하셨습니다.\n");
	_getch();
}
*/

// 실전문제 1-1

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num;

	printf("정수를 입력하세요.\n");
	printf("정수 :");
	scanf("%d",&num);

	if ((num%2)==0)
		printf("짝수입니다.\n");
	else
		printf("홀수입니다.\n");
	_getch();
}
*/