//작성날짜 : 2014.3.19
//작성내용 : 출력형식 연습
//작성자 : 김종민
/*
#include <stdio.h>

void main()
{
	printf("%5c \n",'*');
	printf("%4c%2c \n",'*','*');
	printf("%4c%2c \n",'*','*');
	printf("%2c%c%2c%2c%c \n",'*','*','*','*','*');
	printf("%c%3c%2c%3c \n",'*','*','*','*');
	printf("%2c%c%2c%c%c%c \n",'*','*','*','#','*','*');
	printf("%4c%2c%c \n",'*','*','#');
	printf("%4c%2c%2c \n",'*','*','#');
	printf("%5c%3c \n",'*','#');
}


#include <stdio.h>

void main()
{
	printf("%s\n","◇");
}


#include <stdio.h>

void main()
{
	char a='A';
	char array[10]="BCDE";
	int b=5;
	float c=3.0;
	printf("(%c)\n",a);
	printf("(%s)\n",array);
	printf("(%d)\n",b);
	printf("(%.1f)\n",c);
}



#include <stdio.h>

void main()
{
	printf("정수 333을 8진수와 16진수로 출력\n8:%o, 16:%x\n",333,333);
}


#include <stdio.h>

void main()
{
	int Num=10;					//변수 Num의 정의 및 초기화
	short Age=0;				//변수 Age의 정의
	char TotalRank=0;			//변수 TotalRank의 정의

	printf("Number : %d\n",Num);
	printf("Age : %d\n",Age);
	printf("TotalRank : %d\n",TotalRank);
	printf("\n");
	Num=Num+1;					//변수 Num의 연산
	Age=18;						//변수 Age의 초기화
	TotalRank='A';				//변수 TotalRank의 초기화
	printf("Number : %d\n",Num);
	printf("Age :%d\n",Age);
	printf("TotalRank : %c\n",TotalRank);
}


#include <stdio.h>

void main()
{
	printf("Visual.Net에서 사용되는 자료형별 크기를 알아봅시다.\n");
	printf("정수형 자료형		-short : %d\n",sizeof(short));
	printf("			-int : %d\n",sizeof(int));
	printf("			-unsigned int: %d\n",sizeof(unsigned int));
	printf("			-long : %d\n",sizeof(long));
	printf("실수형 자료형		-float: %d\n",sizeof(float));
	printf("			-double : %d\n",sizeof(double));
	printf("문자형 자료형		-char : %d\n",sizeof(char));
	printf("			-unsigned char : %d\n",sizeof(unsigned char));
}



#include <stdio.h>

void main()
{
	int a=5;
	int b=7;
	printf("%d 와 %d 의 합은 %d 입니다.\n",a,b,a+b);
	printf("%d 와 %d 의 곱은 %d 입니다.\n",a,b,a*b);
}


#include <stdio.h>

void main()
{
	int X=10,Z=20;
	printf("삼각형 넓이 = %d\n사격형 넓이 = %d\n",X*Z/2,X*Z);
}


#include <stdio.h>

void main()
{
	printf("저의 이름 이니셜은 %c%c%c 입니다. 제 이름을 유추해 보세요.\n",'K','J','M');
	printf("맞춘 사람은..사탕 1개 지급..ㅋㅋ\n");
}
*/

#include <stdio.h>

void main()
{
	int a=7,b=3;
	printf("%d을 %d로 나눈 값은 %.2f 입니다.\n",a,b,(float)a/b);
	printf("%d을 %d로 나눈 값은 %.2f 입니다.\n",b,a,(float)b/a);
}