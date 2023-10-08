// 날짜 : 2014 / 04 / 02
// 주제 : 연산자
// 제작 : 김종민

/* 35p 연습문제 2
#include <stdio.h>
#include <conio.h>

void main()
{
	int num;

	printf("정수를 하나 입력하세요 \n");
	scanf("%d",&num);

	(num < 0) ?
		printf("%d의 절대값은 %d입니다.\n",num,-num) :
		printf("%d의 절대값은 %d입니다.\n",num,num);
	_getch();
}
*/

/* 36p 실전 2-1
#include <stdio.h>
#include <conio.h>

void main()
{
	int num, num2;
	int result, result2;

	printf("두개의 수를 아래와 같은 형태로 입력하세요.\n예) 10 20\n");
	scanf("%d %d",&num,&num2);

	result = num - num2;
	result2 = num2 - num;

	(num < num2) ?
		printf("입력한 두 정수의 값의 차이는 = %d",result2) :
		printf("입력한 두 정수의 값의 차이는 = %d",result);
	_getch();
}
*/

/* 36p 실전 2-2
#include <stdio.h>
#include <conio.h>

void main()
{
	int num;

	printf("하나의 수를 입력하세요.");
	scanf("%d",&num);

	(num%2 == 1) ?				// 나머지가 1일때 홀수, 0일때 짝수 출력
		printf("홀수입니다.\n") :
		printf("짝수입니다.\n");
	_getch();
}
*/

/* 36p 실전 2-3
#include <stdio.h>
#include <conio.h>

void main()
{
	int num,num2;
	int result,result2;
	char code;

	printf("두 개의 수를 입력하세요. (예 :20 30)\n");
	scanf("%d %d",&num,&num2);
	fflush(stdin);					// 버퍼 지우기

	printf("연산 기호를 입력하세요. (+ 혹은 - 입력)\n");
	scanf("%c",&code);

	result = num-num2;
	result2 = num+num2;

	(code == '-') ?
		printf("%d - %d = %d\n",num,num2,result) :
		printf("%d + %d = %d\n",num,num2,result2);
	_getch();
}
*/

/* 36p 실전 2-4
#include <stdio.h>
#include <conio.h>

void main()
{
	char Alphabat, result, result2;

	printf("알파벳 하나를 입력하세요.\n(숫자, 특수문자는 입력할 수 없습니다)\n");
	scanf("%c",&Alphabat);

	result = Alphabat + 32;
	result2 = Alphabat - 32;

	(Alphabat < 'a') ?
		printf("출력 => %c",result) :
		printf("출력 => %c",result2);
	_getch();
}
*/

/* 36p 실전 2-5 모범예제
#include <stdio.h>
#include <conio.h>

void main()
{
	char data;
	char result, result2;

	printf("알파벳 하나를 입력하세요.\n");
	printf("입력 => ");
	scanf("%c",&data);

	data = ((data >= 'A') && (data <= 'Z')) ? data + ('a' - 'A') :
		   ((data >= 'a') && (data <= 'z')) ? data - ('a' - 'A') : data;

	printf("출력 => %c\n",data);
	_getch();
}
*/


// 주제 : 증감 연산자


/* 예제 1
#include <stdio.h>
#include <conio.h>

void main()
{
	int i = 1;

	printf("i의 초기값은 %d\n",i);

	i++;

	printf("i++ 후의 값은 %d\n",i);

	i--;

	printf("i-- 후의 값은 %d\n",i);
	_getch();
}
*/

/* 예제 2
#include <stdio.h>
#include <conio.h>

void main()
{
	int a = 10, b = 10;

	printf("a++의 값은 : %d\n", a++);
	printf("a의 값은 : %d\n",a);
	printf("++a의 값은 : %d\n",++a);

	printf("\n");

	printf("b--의 값은 : %d\n",b--);
	printf("--b의 값은 : %d\n",--b);
	_getch();
}
*/

/* 38p 예제8
#include <stdio.h>
#include <conio.h>

void main()
{
	int i=10, j=13;							// 10 = 1010, 13 = 1101
	
	printf("i & j 의 값: %d \n",i&j);		// 1000 = 8
	printf("i | j 의 값: %d \n",i|j);		// 1111 = 15
	printf("i ^ j 의 값: %d \n",i^j);		// 0111 = 7
	printf("~ i 의 값: %d \n",~i);			// 0101 = -11
	_getch();
}
*/