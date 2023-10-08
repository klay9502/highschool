// 날짜 : 2014/03/26
// 주제 : scanf 활용
// 이름 : 김종민

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a,b;		// a=밑변,b=높이

	printf("밑변입력: ");
	scanf("%d",&a);
	printf("높이입력: ");
	scanf("%d",&b);
	printf("삼각형의 넓이는 %d입니다.\n",a*b/2);
	_getch();
}
*/

/* 26p 3-1
#include <stdio.h>
#include <conio.h>

void main()
{
	int num;

	printf("정수입력: ");
	scanf("%d",&num);
	printf("이 값에서 10을 빼면 %d입니다.",num-10);
	_getch();
}
*/

/* 26p 3-2
#include <stdio.h>
#include <conio.h>

void main()
{
	float num;

	printf("원의 반지름을 입력하세요: ");
	scanf("%f",&num);
	printf("원의 넓이: %0.2f 원주: %0.2f",(float)num*num*3.14,(float)num*2*3.14);
	_getch();
}
*/

/* 26p 3-3
#include <stdio.h>
#include <conio.h>

void main()
{
	float A,B;

	printf("두 개의 정수를 입력해주세요.\n");
	printf("정수 A:");
	scanf("%f",&A);
	printf("정수 B:");
	scanf("%f",&B);
	printf("A의 값은 B의 %0.0f %%입니다.",A/B*100);
	_getch();
}
*/

/* 27p 3-4
#include <stdio.h>
#include <conio.h>

void main()
{
	int M,K,E;		// M = 수학, K = 국어, E = 영어

	printf("수학점수 :");
	scanf("%d",&M);
	printf("국어점수 :");
	scanf("%d",&K);
	printf("영어점수 :");
	scanf("%d",&E);
	printf("총점 : %d 평균 : %.2f\n",(M+K+E),(float)(M+K+E)/3);
	_getch();
}
*/

/* 27p 3-5
#include <stdio.h>
#include <conio.h>

void main()
{
	char code;

	printf("문자를 입력하세요: ");
	scanf("%c",&code);
	printf("문자 %c의 아스키코드값은 %d입니다.",code,code);
	_getch();
}
*/

/* 27p 3-6
#include <stdio.h>
#include <conio.h>

void main()
{
	float height,result;

	printf("키를 입력하세요: ");
	scanf("%f",&height);

	result = (height-100)*0.9;

	printf("표준 체중은 %0.1f입니다.",result);
	_getch();
}
*/

/* 27p 3-7
#include <stdio.h>
#include <conio.h>

void main()
{
	float weight,height,result;

	printf("몸무게: ");
	scanf("%f",&weight);
	printf("키: ");
	scanf("%f",&height);

	result = weight/(height*height);

	printf("BMI 지수 : %f",result);
	_getch();
}
*/

/* 27p 3-8
#include <stdio.h>
#include <conio.h>

// 기본료 : 13000원
// 10초당 10원의 요금 부가
// 총 금액의 5%를 세금으로 추가 징수

void main()
{
	int sec,plusmoney,money,tax;

	printf("몇 초동안 휴대폰을 사용하셨습니까?\n");
	scanf("%d",&sec);

	plusmoney=sec*0.1;
	plusmoney=plusmoney*10;		// 추가요금 계산

	money=13000+plusmoney;		// 추가요금 + 기본요금
	tax=money*0.05;				// 5% 세금

	money = money + tax;		// 합산

	printf("이번에 사용하신 휴대폰 요금은 %d원입니다.",money);
	_getch();
}
*/

/* 27p 3-9
#include <stdio.h>
#include <conio.h>

void main()
{
	int money,coke,soda,power,change,allmoney;
	int cokenum,sodanum,powernum;
	int Fcoin,Hcoin,FHcoin;			// Fcoin = 50원, Hcoin = 100원, FHcoin = 500원

	printf("================================================================\n");
	printf("자판기프로그램입니다. 콜라700원,사이다550원,파워에이드1000원입니다.\n");
	printf("================================================================\n\n");

	printf("금액을 투입하세요. :");
	scanf("%d",&money);
	printf("콜라 몇 개?\n");
	scanf("%d",&coke);
	printf("사이다 몇 개?\n");
	scanf("%d",&soda);
	printf("파워에이드 몇 개?\n");
	scanf("%d",&power);

	cokenum = 700 * coke;									// 콜라의 총 가격
	sodanum = 550 * soda;									// 사이다의 총 가격
	powernum = 1000 * power;								// 파워에이드의 총 가격


	allmoney = cokenum + sodanum + powernum;				// 음료의 총 가격
	change = money - allmoney;								// 잔돈

	FHcoin = change/500;									// 500원 잔돈
	Hcoin = (change-FHcoin*500)/100;							// 100원 잔돈
	Fcoin = (change-FHcoin*500-Hcoin*100)/50;				// 50원 잔돈

	printf("\n총구입금액은%d원입니다. 거스름돈 %d원을\n",allmoney,change);
	printf("500원짜리%d개,100원짜리%d개,50원짜리%d개로 드립니다.",FHcoin,Hcoin,Fcoin);
	_getch();
}
*/

/* 28p 3-10
#include <stdio.h>
#include <conio.h>

void main()
{
	unsigned int nowage,wantage;				// 나이 변수
	unsigned int days,time,min,sec;				// 시간 변수
													// 오버플로우를 방지하여 'unsigned int'를 사용.
	printf("현재 당신 나이는 몇살입니까?");
	scanf("%d",&nowage);
	printf("몇 살까지 살고 싶습니까?");
	scanf("%d",&wantage);

	days = (wantage - nowage) * 365;				// 날짜
	time = days * 24;							// 시간
	min = time * 60;							// 분
	sec = min * 60;								// 초

	printf("날짜로는 %d일, 시간으로는 %d시간,\n분으로는 %d분, 초로는 %d초 남았습니다.\n",days,time,min,sec);
	_getch();
}
*/