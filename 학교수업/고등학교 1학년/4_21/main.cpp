// 주제 : 제어문
// 날짜 : 2014 / 4 / 21
// 제작 : 김종민

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

// 실전문제 1-2

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num1,num2;

	printf("두 개의 정수를 입력해주세요.\n");

	printf("정수1 :");
	scanf("%d",&num1);
	printf("정수2 :");
	scanf("%d",&num2);

	if (num1 > num2)
	{
		if (num1 % num2 == 0)
			printf("%d는 %d의 약수입니다.\n",num2,num1);
	}
	else
	{
		if (num2 % num1 == 0)
			printf("%d는 %d의 약수입니다.\n",num1,num2);
	}
	_getch();
}
*/

// 실전문제 1-3

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char gender;

	printf("성별을 입력하세요 ('F' or 'M')\n");
	scanf("%c",&gender);

	if (gender == 'F')
		printf("당신은 '여성'입니다.\n");
	else if (gender == 'M')
		printf("당신은 '남성'입니다.\n");
	else
		printf("알 수 없는 키워드입니다.\n");
	_getch();
}
*/

// 예제 3

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num;

	printf("정수를 하나 입력하세요.\n");
	scanf("%d",&num);
	if(num>0)
		printf("양수를 입력하셨습니다.\n");
	else if(num<0)
		printf("음수를 입력하셨습니다.\n");
	else
		printf("0을 입력하셨습니다.\n");
	_getch();
}
*/

// 연습문제 2

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num1,num2;

	printf("두개의 정수를 입력해주세요.\n");
	printf("정수 A:");		scanf("%d",&num1);
	printf("정수 B:");		scanf("%d",&num2);

	if (num1-num2 > 0)
		printf("A는 B보다 큽니다.");
	else if (num1-num2 <0)
		printf("A는 B보다 작습니다.");
	else
		printf("A와 B는 같은 수입니다.");
	_getch();
}
*/

// 실전문제 2-1

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num1,num2,num3;

	printf("세 개의 정수를 입력해주세요.\n");
	printf("정수 A: ");		scanf("%d",&num1);
	printf("정수 B: ");		scanf("%d",&num2);
	printf("정수 C: ");		scanf("%d",&num3);

	if (num1 == num2 && num2 == num3)
		printf("A,B,C 의 값이 모두 같습니다.\n");
	else if (num1 == num2 || num2 == num3 || num1 == num3)
		printf("A,B,C 중 두 개의 값이 같습니다.\n");
	else
		printf("A,B,C의 값이 모두 다릅니다.");
	_getch();
}
*/

// 실전문제 2-2

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num1,num2,num3;

	printf("세 개의 정수를 입력해주세요.\n");
	printf("정수 A: ");		scanf("%d",&num1);
	printf("정수 B: ");		scanf("%d",&num2);
	printf("정수 C: ");		scanf("%d",&num3);

	if (num1 == num2 && num2 == num3)
		printf("A,B,C 의 값이 모두 같습니다.\n");
	else if (num1 == num2 || num2 == num3 || num1 == num3)
	{
		if (num1 == num2)
			printf("A,B,C중 A,B의 값이 같습니다.\n");
		else if (num2 == num3)
			printf("A,B,C중 B,C의 값이 같습니다.\n");
		else if (num1 == num3)
			printf("A,B,C중 A,C의 값이 같습니다.\n");
	}
	else
		printf("A,B,C의 값이 모두 다릅니다.");
	_getch();
}
*/

// 실전문제 2-3

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a,c;
	char b;
	float result;

	scanf("%d%c%d",&a,&b,&c);

	if (b =='+')
		result = a + c;
	else if (b == '-')
		result = a - c;
	else if (b == '*')
		result = a * c;
	else
		result = a / c;

	printf("%.1f",result);
	_getch();
}
*/

// 실전문제 2-4

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int month;

	printf("월을 이용하여 계절을 구해보겠습니다.\n");
	printf("몇 월?: ");		scanf("%d",&month);

	if (3 <= month && 5 >= month)
		printf("봄입니다.\n");
	else if (6 <= month && 8 >= month)
		printf("여름입니다.\n");
	else if (9 <= month && 11 >= month)
		printf("가을입니다.\n");
	else if (12 == month || 2 >= month)
		printf("겨울입니다.\n");
	else
		printf("잘못된 키워드입니다.\n\a");
	_getch();
}
*/

// 실전문제 2-5

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char gender;
	int age;

	printf("성별을 입력하세요.(남:m or 여:f) :");		scanf("%c",&gender);
	printf("나이를 입력하세요. :");		scanf("%d",&age);

	if (gender == 'F' || gender == 'f')
	{
		if (age > 19)
			printf("여자 성년자\n");
		else if (age <= 19)
			printf("여자 미성년자\n");
	}
	else if (gender == 'M' || gender == 'm')
	{
		if (age > 19)
			printf("남자 성년자\n");
		else if (age <= 19)
			printf("남자 미성년자\n");
	}
	else
		printf("잘못된 키워드입니다.\n\a");
	_getch();
}
*/

// 예제4

/*
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

void main()
{
	int num;

	printf("0~2 사이의 난수 발생 시작~!\n");
	srand(time(NULL));
	num=rand()%3;

	switch(num)	{
	case 0:
		puts("0");
		break;
	case 1:
		puts("1");
		break;
	case 2:
		puts("2");
		break;
	default:
		puts("잘못된 난수 발생:");	}
	_getch();
}
*/

// 예제5

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char ch;

	printf("당신은 나를 사랑하십니까? (y or n)\n");
	scanf("%c",&ch);

	switch(ch)	{
	case 'y':
		puts("나도 당신을 사랑합니다.\n");
		break;
	case 'n':
		puts("그래도 나는 당신이 좋습니다.\n");
		break;
	default:
		puts("잘못된 입력");	}
	_getch();
}
*/

// 52p 연습문제3

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char grade;

	puts("등급을 입력하세요.");
	scanf("%c",&grade);
	switch(grade)	{
	case 'A':
		puts("90~100점 사이입니다.\n");
		break;
	case 'B':
		puts("80~90점 사이입니다.\n");
		break;
	case 'C':
		puts("70~80점 사이입니다.\n");
		break;
	case 'D':
		puts("60~70점 사이입니다.\n");
		break;
	case 'E':
		puts("60~70점 사이입니다.\n");
		break;
	default:
		puts("50점 이하입니다.\n");	}
	_getch();
}
*/

// 번외문제

#include <stdio.h>
#include <conio.h>

void main()
{
	int score,result;

	puts("점수를 입력하세요.");
	scanf("%d",&score);
	result = score/10;

	switch(result)	{
	case 10:
	case 9:
		puts("A등급 입니다.\n");
		break;
	case 8:
		puts("B등급 입니다.\n");
		break;
	case 7:
		puts("C등급 입니다.\n");
		break;
	case 6:
		puts("D등급 입니다.\n");
		break;
	case 5:
		puts("E등급 입니다.\n");
		break;
	default:
		puts("F등급 입니다.\n");	}
	_getch();
}