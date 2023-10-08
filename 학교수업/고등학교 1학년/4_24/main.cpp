//========================
//Today...2014 / 04 / 24
//Subject...Switch
//Make by...'김종민'
//========================

// 53p 3-1

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char grade;

	puts("등급을 입력하세요.");
	scanf("%c",&grade);
	switch(grade)	{
	case 'a':
	case 'A':
		puts("90~100점 사이입니다.\n");
		break;
	case 'b':
	case 'B':
		puts("80~90점 사이입니다.\n");
		break;
	case 'c':
	case 'C':
		puts("70~80점 사이입니다.\n");
		break;
	case 'd':
	case 'D':
		puts("60~70점 사이입니다.\n");
		break;
	case 'e':
	case 'E':
		puts("60~70점 사이입니다.\n");
		break;
	default:
		puts("50점 이하입니다.\n");	}
	_getch();
}
*/

// 53p 3-2

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int month;

	printf("월 :");
	scanf("%d",&month);

	switch(month)	{
	case 1:
		printf("January\n");
		break;
	case 2:
		printf("February\n");
		break;
	case 3:
		printf("March\n");
		break;
	case 4:
		printf("April\n");
		break;
	case 5:
		printf("May\n");
		break;
	case 6:
		printf("June\n");
		break;
	case 7:
		printf("July\n");
		break;
	case 8:
		printf("August\n");
		break;
	case 9:
		printf("September\n");
		break;
	case 10:
		printf("October\n");
		break;
	case 11:
		printf("November\n");
		break;
	case 12:
		printf("December\n");
		break;
	default:
		printf("잘못된 키워드\n");
	}
	_getch();
}
*/

// 53p 3-3

/*
#include<stdio.h>
#include<conio.h>

void main()
{
	int month, day;

	printf("월: ");
	scanf("%d", &month);
	printf("일: ");
	scanf("%d", &day);

	switch(month)
	{
	case 1:
		{
			if(day<20)
				puts("염소자리 입니다.");
			else
				puts("물병자리 입니다.");
		}
		break;
	case 2:
		{
			if(day<19)
				puts("물병자리 입니다.");
			else
				puts("물고기자리 입니다.");
		}
		break;
	case 3:
		{
			if(day<21)
				puts("물고기자리 입니다.");
			else
				puts("양자리 입니다.");
		}
	case 4:
		{
			if(day<20)
				puts("양자리 입니다.");
			else
				puts("황소자리 입니다.");
		}
		break;
	case 5:
		{
			if(day<21)
				puts("황소자리 입니다.");
			else
				puts("쌍둥이자리 입니다.");
		}
		break;
	case 6:
		{
			if(day<22)
				puts("쌍둥이자리 입니다.");
			else
				puts("게자리 입니다.");
		}
		break;
	case 7:
		{
			if(day<23)
				puts("게자리 입니다.");
			else
				puts("사자자리 입니다.");
		}
		break;
	case 8:
		{
			if(day<23)
				puts("사자자리 입니다.");
			else
				puts("처녀자리 입니다.");
		}
		break;
	case 9:
		{
			if(day<24)
				puts("처녀자리 입니다.");
			else
				puts("천칭자리 입니다.");
		}
		break;
	case 10:
		{
			if(day<23)
				puts("천칭자리 입니다.");
			else
				puts("전갈자리 입니다.");
		}
		break;
	case 11:
		{
			if(day<23)
				puts("전갈자리 입니다.");
			else
				puts("사수자리 입니다.");
		}
		break;
	case 12:
		{
			if(day<25)
				puts("사수자리 입니다.");
			else
				puts("염소자리 입니다.");
		}
		break;
	default:
		puts("오류.");
	}
	_getch();
}
*/

// 53p 3-4

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int month;

	printf("월을 이용하여 계절을 구해보겠습니다.\n");
	printf("몇 월? :");
	scanf("%d",&month);

	switch(month)	{
	case 1:
		printf("겨울\n");
		break;
	case 2:
		printf("겨울\n");
		break;
	case 3:
		printf("봄\n");
		break;
	case 4:
		printf("봄\n");
		break;
	case 5:
		printf("봄\n");
		break;
	case 6:
		printf("여름\n");
		break;
	case 7:
		printf("여름\n");
		break;
	case 8:
		printf("여름\n");
		break;
	case 9:
		printf("가을\n");
		break;
	case 10:
		printf("가을\n");
		break;
	case 11:
		printf("가을\n");
		break;
	case 12:
		printf("겨울\n");
		break;
	default:
		printf("잘못된 키워드\n");
	}
	_getch();
}
*/

// 53p 3-5

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num1,num2;
	char code;
	float result;

	scanf("%d%c%d",&num1,&code,&num2);
	
	switch (code)	{
	case '+' :
		result = num1 + num2;
		printf("%.1f",result);
		break;
	case '-' :
		result = num1 - num2;
		printf("%.1f",result);
		break;
	case '*' :
		result = num1 * num2;
		printf("%.1f",result);
		break;
	case '/' :
		result = num1 / num2;
		printf("%.1f",result);
		break;
	default :
		printf("잘못된 키워드\n");
	}
	_getch();
}
*/

// 53p 3-6

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int code;

	printf("\n** 점심 메뉴 선택 **\n");
	printf("1. 자장면\n");
	printf("2. 짬뽕\n");
	printf("3. 볶음밥\n");
	printf("4. 잡채밥\n\n");
	printf("메뉴를 선택하세요 :");
	scanf("%d",&code);

	switch (code)	{
	case 1 :
		printf("메뉴 1을 선택했습니다.\n");
		printf("맛있는 짜장면 3500원\n");
		break;
	case 2 :
		printf("메뉴 2을 선택했습니다.\n");
		printf("맛있는 짬뽕 4000원\n");
		break;
	case 3 :
		printf("메뉴 3을 선택했습니다.\n");
		printf("맛있는 볶음밥 3500원\n");
		break;
	case 4 :
		printf("메뉴 4을 선택했습니다.\n");
		printf("맛있는 잡채밥 4000원\n");
		break;
	default :
		printf("잘못된 키워드\n");
	}
	_getch();
}
*/

// PPT 예제

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int kor,mat,eng;
	int code;
	char level;
	float ave;

	printf("===================================\n");
	printf("##########점수계산프로그램#########\n\n");
	
	printf("국어 성적을 입력하세요 :");
	scanf("%d",&kor);
	printf("수학 성적을 입력하세요 :");
	scanf("%d",&mat);
	printf("수학 성적을 입력하세요 :");
	scanf("%d",&eng);

	ave = (kor + mat + eng) / 3;

	printf("-----------------------------------\n");
	printf("당신의 국, 영, 수 평균점수와 등급입니다.\n\n");

	code = ave/10;

	switch(code)	{
	case 10:
	case 9:
		level = 'A';
		break;
	case 8:
		level = 'B';
		break;
	case 7:
		level = 'C';
		break;
	case 6:
		level = 'D';
		break;
	case 5:
		level = 'E';
		break;
	default:
		level = 'F';	}

	printf("평균점수 %.1f / 등급 %c\n",ave,level);
	printf("-----------------------------------\n");
	_getch();
}
*/