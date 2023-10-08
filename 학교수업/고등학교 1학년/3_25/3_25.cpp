//작성날짜	: 2014.3.25
//작성내용	: 
//작성자		: 김종민

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int Number;
	int Age;

	int Person1, Person2;

	int Page = 10;
	int Page1 = 10, Page2 = 20;

	Person1 = Person2 = 100;

	printf("Person1 : %d, Person2 : %d,Page : %d, Page1 : %d,Page2 : %d\n",Person1,Person2,Page,Page1,Page2);

	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	float a = 1.123456789123456789;			// float 형
	double b = 1.123456789123456789;		// double 형
	printf("a의 출력 결과 : %1.20G\n",a);
	printf("b의 출력 결과 : %1.20G\n",b);	// 소수점 20자리 출력
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	float a = 10.0;
	double b = 10.0;

	int i = 0;
	while(i<10)
	{
		a = a/3.0;
		b = b/3.0;
		printf("float 형의 출력 결과 : %1.20G\n\n",a);
		printf("double 형의 출력 결과 : %1.20G\n\n",b);
		i ++;
	}
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char a = 'A';

	printf("문자형 a의 문자 표시 : %c\n",a);
	printf("문자형 a의 정수 표시 : %d\n",a);
	printf("문자형 a의 16진수 표시 : %x\n\n",a);

	a=a+1;
	printf("문자형 a의 문자 표시 : %c\n",a);
	printf("문자형 a의 정수 표시 : %d\n",a);
	printf("문자형 a의 16진수 표시 : %x\n\n",a);
	_getch();
}
*/

/*	========오버플로우 예제==========
#include <stdio.h>
#include <conio.h>

void main()
{
	short a = 32767;
	short b = -32768;
	printf("%d \n",sizeof(short));
	printf("a= %d \n",a);
	printf("a+1=%d\n",a=a+1);
	printf("b= %d \n",b);
	printf("b-1=%d\n",b=b-1);
	_getch();
}
*/	

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	short a = 32767;
	unsigned short b = 32767;

	printf("a+1 = %d\n",a=a+1);
	printf("b+1 = %d\n",b=b+1);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char a='A';
	int b=1,c;

	c=a+b;

	printf("c=%d\n",c);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	float a=6.7;
	int b=10,c;

	c=(int)a+b;

	printf("%d\n",c);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	float mileage,speed,time;
	int hour,min;

	mileage=600;
	speed=7;

	time = mileage/speed;	// 85.714287
	hour = (int)time;
	time = time - hour;		// 0.714287

	time = time * 60;
	min = (int)time;
	time = time - min;
	time = time * 60;


	printf("거리 :%d\n",(int)mileage);
	printf("속력 :%d\n",(int)speed);
	printf("걸리는 시간은 : %d시간, %d분, %0.2f초입니다.\n",hour,min,time);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	float hour = 0.456;
	int min;

	hour = hour * 60;
	min = (int)hour;
	hour = hour - min;

	printf("0.456시간은 %d분 %d초와 같습니다.",min,(int)(hour*60));
	_getch();
}
*/

#include <stdio.h>
#include <conio.h>

void main()
{
	int num1;
	float num2;
	char name;
	char array[20];
	printf("정수를 입력하세요.\n");
	scanf("%d",&num1);

	printf("실수를 입력하세요.\n");
	scanf("%f",&num2);
	fflush(stdin);

	printf("1개의 문자를 입력하세요.\n");
	scanf("%c",&name);
	fflush(stdin);

	printf("문자열을 입력하세요.\n");
	scanf("%s",array);
	fflush(stdin);

	printf("정수값=%d, 실수값=%f, 문자 =%c, 문자열=%s가 입력되었습니다.\n",num1,num2,name,array);
	_getch();
}