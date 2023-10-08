// p73 예제16

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i;

	for (i = 0; i <= 10; i++)
	{
		if (i == 5)
			break;
		else
			printf("%d\t",i);
	}
	printf("\n");
	_getch();
}
*/

// ppt, switch문에 사용된 break문.

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a = 1;

	switch (a) {
	case 1:
		printf("하나");
		//	break;
	case 2:
		printf("둘");
		//	break;
	default:
		puts("1,2 아님"); }
	puts("입니다.");
	_getch();
}
*/

// ppt, while문에 사용된 break문.

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a = 0;

	while (1)
	{
		a++;
		printf("%d\n",a);
		if (a == 2)
			break;
	}
	puts("종료");
	_getch();
}
*/

// ppt, break문으로 반복문 제어하기.

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i, j;
	i = j = 0;

	printf("break문의 테스트입니다. \n");

	do {
		printf("do-while문의 %d번째 반복입니다. \n",i);
		for(j = 0; j < 10; j++)
		{
			if (j == 5)
				break;
			printf("for문의 %d번째 반복입니다.\n",j);
		}
		i++;
	} while (i < 5);
	printf("프로그램을 종료합니다.\n");
	_getch();
}
*/

// ppt, for문에 사용된 continue문.

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a;
	for ( a = 1; a <= 4; a++)
	{
		if ( a % 2 == 0)
		{
			puts("***");
			continue;
		}
		printf("%d\n", a);
	}
	puts("종료");
	_getch();
}
*/

// ppt, while문에 사용된 continue문

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i = 0, hap = 0;

	while ( i <= 100)
	{
		i++;
		if ( i % 2 == 1)
			continue;
		hap += i;
		if ( hap > 1000)
			break;
	}
	printf("i의 값이 %d일 때 합이 1000을 넘었습니다 \n", i);
	_getch();
}
*/

// ppt, continue문으로 반복문 제어하기.

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i, j;
	i = j = 0;

	printf("continue문의 테스트입니다. \n");

	do {
		printf("do-while문의 %d번째 반복입니다. \n",i);
		for(j = 0; j < 10; j++)
		{
			if (j == 5)
				continue;
			printf("for문의 %d번째 반복입니다.\n",j);
		}
		i++;
	} while (i < 5);
	printf("프로그램을 종료합니다.\n");
	_getch();
}
*/

// 구구단을 출력하되 짝수단(2단, 4단, 6단, 8단)만 출력하게끔 하자.
// 또한 2단은 2*2까지, 4단은 4*4까지, 6단은 6*6까지, 8단은 8*8까지 출력하자.
// <조건> continue와 break문을 사용할 것.

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i, j;
	int sum;

	for (i = 1;i <= 8; i++)
	{
		if ( i % 2 == 1)		// 홀수단일때 통과
			continue;
		for (j = 1;; j++)
		{
			sum = i * j;
			printf("%d X %d = %d\n", i, j, sum);
			if ( j == i)		// 앞 숫자와 뒷 숫자가 같을 때 중단
				break;
		}
	}
	_getch();
}
*/

// ppt, goto문으로 반복문 제어하기.

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i, j;
	i = j = 0;

	printf("goto문의 테스트입니다. \n");

	do {
		printf("do-while문의 %d번째 반복입니다. \n",i);
		for(j = 0; j < 10; j++)
		{
			if (j == 5)
				goto stop1;
			printf("for문의 %d번째 반복입니다.\n",j);
		}
		i++;
	} while (i < 5);
	stop1:
	printf("프로그램을 종료합니다.\n");
	_getch();
}
*/

// p74 goto문 예제17

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a = 1;

here:
	a++;
	if ( a == 2)
		goto here;
	printf("%d\n", a);
	_getch();
}
*/

#include <stdio.h>
#include <conio.h>

void main()
{
	int num, count;

	printf("10진수 입력 :"); scanf("%d",&num);
	count = 1;
	while (1)
	{
		if (count % 2 == 1)
			printf("1");
		else if (count % 2 == 0)
			printf("0");
		count = count / 2;
		if (count == 0)
			break;
	}
	_getch();
}