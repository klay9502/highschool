// 날짜 : 2014 / 04 / 01
// 주제 : 상수
// 이름 : 김종민

/* 28p 상수 예제
#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
	float pi=3.14, area=0, R=4;
	area= pi*(pow(4.0,2.0));
	printf("%f\n",area);

	pi=3.14159;	// pi는 변수이므로 재설정 가능
	area = pi*(pow(4.0,2.0));

	printf("%f\n",area);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>
#define MAX_PERSOM 3

void main()
{
	int Person[MAX_PERSOM]; int i;
	int TotalCountOfKorean = 0;
	float AverageOfKorean = 0;

	printf("학급의 국어 성적에 대한 총점과 평균 구하기\n");

	Person[0] = 95; Person[1] = 80; Person[2] = 92;

	for (i = 0; i < MAX_PERSOM; i++)
	{
		printf("%d번째 학생의 국어성적 : %d\n\n",i+1,Person[i]);
		TotalCountOfKorean += Person[i];
	}
	AverageOfKorean = TotalCountOfKorean / MAX_PERSOM;

	printf("이 학급의 국어 총점 : %d\n",TotalCountOfKorean);
	printf("이 학급의 국어 평균 : %.2f\n",AverageOfKorean);
	_getch();
}
*/



// 주제 : 연산자



/* 31p 예제1
#include <stdio.h>
#include <conio.h>

void main()
{
	int a, b;
	scanf("%d%d",&a,&b);

	printf(" a + b : %d\n",a + b);
	printf(" a - b : %d\n",a - b);
	printf(" a x b : %d\n",a * b);
	printf(" a / b : %d\n",a / b);
	printf(" a %% b : %d\n",a % b);
	printf(" -a : %d\n",-a);
	_getch();
}
*/

/* 31p 연습문제 1
#include <stdio.h>
#include <conio.h>

void main()
{
	int Age, Day, Year;
	puts("현재 자신의 나이를 입력: ");		// "puts" =/= "gets"  printf 의 구버전 ( 오로지 행만 출력 )
	scanf("%d",&Age);
	puts("몇 살까지 살고 싶습니까? ");
	scanf("%d", &Year);

	Day = (Year-Age)*365;

	printf("%d살까지 약 %d 일 남앗습니다.\n",Year,Day);
	_getch();
}
*/

/* 32p 실전 1-1
#include <stdio.h>
#include <conio.h>

void main()
{
	int age, year;
	int day, time, min, sec;
										// 입력부
	puts("현재 자신의 나이를 입력: ");
	scanf("%d",&age);
	puts("몇 살까지 살고 싶습니까? ");
	scanf("%d",&year);

	printf("%d살까지를 다음과 같이 계산하면...\n",year);
										// 연산부
	day = (year - age)*365;			// 일수 연산
	time = day * 24;				// 시간 연산
	min = time * 60;				// 분   연산
	sec = min * 60;
										// 출력부
	printf("		일수로는  : %d 일\n",day);
	printf("		시간으로는: %d 일\n",time);
	printf("		분으로는  : %d 일\n",min);
	printf("		초로는    : %d 일	....남습니다.",sec);
	_getch();
}
*/

/* 32p 실전 1-2
#include <stdio.h>
#include <conio.h>

void main()
{
	int sec, min, time;
	int Output_sec, Output_min;
											// 입력부
	puts("초를 입력하세요.");
	scanf("%d",&sec);
											// 연산부
	min = sec / 60;
	time = min / 60;

	Output_sec = sec % min;
	Output_min = min % time;
											// 출력부
	printf("%d초는 %d시간, %d분, %d초입니다.\n",sec,time,Output_min,Output_sec);
	_getch();
}
*/

/* 32p 실전 1-2 모범답안
#include <stdio.h>
#include <conio.h>

void main()
{
	int sec, sec1;
	int hour, min;
	puts("변환할 초를 입력하세요.");
	scanf("%d",&sec);
	sec1=sec;
	hour = sec1 / 3600;
	sec1 = sec1 % 3600;

	min = sec1 / 60;
	sec1 = sec1 % 60;

	printf("%d초는 %d시간, %d분, %d초입니다.\n",sec,hour,min,sec1);
	_getch();
}
*/

/* 32p 실전 1-3
#include <stdio.h>
#include <conio.h>

void main()
{
	int distance, speed, result, rest;
											// 입력부
	puts("거리(km): ");
	scanf("%d",&distance);
	puts("속도(km/h): ");
	scanf("%d",&speed);

	printf("%d(km)를 %d(km/h)로 달리면...\n",distance,speed);
											// 연산부
	result = distance / speed;			// 소요시간
	rest = distance % speed;			// 나머지 거리
											// 출력부
	printf("%d시간이 소요되고, %d(km)가 남습니다.\n",result,rest);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a = 10;
	int b = 5;

	printf(" a > b는 %d입니다.\n",a>b);
	printf(" a < b는 %d입니다.\n",a<b);
	printf(" a == b는 %d입니다.\n",a==b);
	printf(" a != b는 %d입니다.\n",a!=b);
	_getch();
}
*/

/* 34p 예제3
#include <stdio.h>
#include <conio.h>

void main()
{
	short a = 1;
	short b = 2;
	short c = 3;
	printf("(a > b) && (b < c) = %d \n",(a > b) && (b < c));
	printf("(a < b) && (b < c) = %d \n",(a < b) && (b < c)); 
	printf("(a > b) || (b > c) = %d \n",(a > b) || (b > c)); 
	printf("(a > b) || (b < c) = %d \n",(a > b) || (b < c)); 
	printf("!(a > b) = %d \n",!(a > b));
	_getch();
}
*/

/* 34p 예제4
#include <stdio.h>
#include <conio.h>

void main()
{
	short a = 1, b = 2;
	a>=b ? puts("a가 B보다 큽니다") : puts("b가 a보다 큽니다.");
	_getch();
}
*/

/* 35p 예제5
#include <Stdio.h>
#include <conio.h>

void main()
{
	short a = 1, b = 2;
	short Max = 0;

	Max = (a>=b) ? a: b;

	printf(" a=%d. b=%d 두 수중 큰 값은 %d입니다. \n",a,b,Max);
	_getch();
}
*/