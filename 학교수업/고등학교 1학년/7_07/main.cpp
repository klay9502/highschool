// p91 예제10

/*
// val이 지역변수로 쓰일 때

#include <stdio.h>
#include <conio.h>

void fuc();

void main()
{
	int i;
	for (i = 0; i < 5; i++)
		fuc();
	_getch();
}

void fuc()
{
	int val = 0;
	val++;
	printf("%d ", val);
}
*/

/*
// val이 정적변수로 쓰일 때

#include <stdio.h>
#include <conio.h>

void fuc();

void main()
{
	int i;
	for (i = 0; i < 5; i++)
		fuc();
	_getch();
}

void fuc()
{
	static int val = 0;
	val++;
	printf("%d ", val);
}
*/

// p91 예제11

/*
#include <stdio.h>
#include <conio.h>

static int val = 20;

void fuc();

void main()
{
	int i;
	for (i = 0; i < 5; i++)
		fuc();
	printf("%d ", val);
	_getch();
}

void fuc()
{
	static int val = 0;
	val++;
	printf("%d ", val);
}
*/

// ppt 예제

/*
#include <stdio.h>
#include <conio.h>

void IncreaseAge(int num);
static int Age;									// 정적변수 Age의 선언

void main()
{
	int i;
	Age = 33;									// 정적변수 Age의 초기화

	printf("여기는 main() 함수입니다.\n");
	printf("Age : %d\n\n", Age);

	for (i = 0; i < 5; i++)
		IncreaseAge(10);
	printf("\n여기는 main() 함수입니다.\n");
	printf("Age : %d\n", Age);
	_getch();
}

void IncreaseAge(int num)
{
	static int Age = 25;						// IncreaseAge() 함수 내에서 정적 변수 Age의 초기화

	Age = Age + num;
	printf("\n여기는 IncreaseAge() 함수 내부입니다.\n");
	printf("Age : %d\n", Age);
}
*/

// p92 예제13

/*
#include <stdio.h>
#include <conio.h>

extern void output();

int num;

void main()
{
	num = 10;
	output();
	_getch();
}
*/

// p93 연습 문제4

/*
#include <stdio.h>
#include <conio.h>

void save(int money);

void main()
{
	int money, choice;

	while(1)
	{
		printf("입금:1, 출금:2, 거래 종료:3 입력하세요.\n");
		scanf("%d", &choice);

		if (choice == 1)
		{
			printf("입금액 :");
			scanf("%d", &money);
		}
		else if (choice == 2)
		{
			printf("출금액 :");
			scanf("%d", &money);
			money =- money;
		}
		else if (choice == 3)
		{
			printf("거래 완료.\n");
			save(0);
			break;
		}
		else continue;
		save(money);
	}
	_getch();
}

void save(int money)
{
	static int total = 0;
	total += money;
	printf("현재까지의 총 저축액 %d\n",total);
}
*/

// p94 실전 4-1

/*
#include <stdio.h>
#include <conio.h>

extern void save(int money);

void main()
{
	int money, choice;

	while(1)
	{
		printf("입금:1, 출금:2, 거래 종료:3 입력하세요.\n");
		scanf("%d", &choice);

		if (choice == 1)
		{
			printf("입금액 :");
			scanf("%d", &money);
		}
		else if (choice == 2)
		{
			printf("출금액 :");
			scanf("%d", &money);
			money =- money;
		}
		else if (choice == 3)
		{
			printf("거래 완료.\n");
			save(0);
			break;
		}
		else continue;
		save(money);
	}
	_getch();
}
*/

// p94 실전 4-2

#include <stdio.h>
#include <conio.h>

extern void function(char ch);
extern void output();

void main()
{
	char ch;
	
	while ((ch = getchar()) != '\n')
		function(ch);
	output();
	printf("\n");
	_getch();
}