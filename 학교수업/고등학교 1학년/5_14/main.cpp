// p60 예제10

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int i = 1;
	int dan;
	int count = 0;
	printf("구구단 출력 프로그램\n");
	printf("몇 단?");
	scanf("%d",&dan);
	while (dan < 10)
	{
		while (i < 10)
		{
			count++;
			printf("%d * %d = %d\t",dan,i,dan*i);
			if (count == 3)
			{
				printf("\n");
				count = 0;
			}
			i++;
		}
		printf("\n");
		i = 1;
		dan++;
	}
	_getch();
	return 0;
}
*/

// p61 연습문제6

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int a = 0, b = 0;
	int height;
	printf("몇 줄 :");
	scanf("%d",&height);

	while (a < height)
	{
		while (b <= a)
		{
			printf("#");
			b++;
		}
		b = 0;
		printf("\n");
		a++;
	}
	_getch();
	return 0;
}
*/

// p61 6-1-1

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int a = 0, b = 0;
	int height;
	printf("몇 줄 :");
	scanf("%d",&height);

	while (a < height)
	{
		while (b < a)
		{
			printf("#");
			b++;
		}
		b = 0;
		printf("&\n");
		a++;
	}
	_getch();
	return 0;
}
*/

// p61 6-1-2

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int a = 0, b = 0;
	int height;
	printf("몇 줄 :");
	scanf("%d",&height);

	while (a < height)
	{
		while (b <= a)
		{
			printf("%d",b+1);
			b++;
		}
		b = 0;
		printf("\n");
		a++;
	}
	_getch();
	return 0;
}
*/

// p62 예제 11

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int i = 1;
	char ch;

	printf("do-while을 시작합니다. q 입력 시 종료\n");

	do{
		printf("%d번째 실행 :",i);
		scanf("%c",&ch);
		fflush(stdin);
		i++;
	} while (ch != 'q');

	printf("프로그램을 종료합니다.\n");
	_getch();
	return 0;
}
*/

// p63 연습문제 7

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int num, re_num;

	do {
		printf("양수 1개를 입력해주세요. :");
		scanf("%d",&num);
		if (num < 0)
			puts("\a 음수는 입력할 수 없습니다. 다시 입력하세요.\n");
	} while (num < 0);

	printf("%d을 역순으로 읽으면 ",num);		// 중요!

	do {
		re_num = num % 10;
		printf("%d", re_num);
		num = num / 10;
	} while (num > 0);
	puts("입니다.\n");
	_getch();
	return 0;
}
*/

// p63 실전 7-1

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int i = 1, num, sum = 0;

	printf("수를 입력하세요."); scanf("%d",&num);

	do {
		if (i % 2 == 1)
			sum += i;
		i++;
	} while (i <= num);

	printf("%d",sum);

	_getch();
	return 0;
}
*/

// p64 실전 7-2

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int num,sum = 0,j = 1;
	int i = 0;

	do {
		printf("양수 1개를 입력하세요 :"); scanf("%d",&num);
		if (num < 0)
			puts("\a EEROR\n");
	} while (num < 0);

	do {
		if (num / j != 0)
		{
			j *= 10;
			sum++;
		}
		else
			i = 1;
	} while (i == 0);
	printf("%d은(는) %d자리입니다.",num,sum);

	_getch();
	return 0;
}
*/

// p64 실전 7-3

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int num,sum = 0,j = 1;
	int i = 0;

	printf("양수 1개를 입력하세요 :"); scanf("%d",&num);

	do {
		if (num / j != 0)
		{
			j *= 10;
			sum++;
		}
		else
			i = 1;
	} while (i == 0);
	printf("%d은(는) %d자리입니다.",num,sum);

	_getch();
	return 0;
}
*/

// p64 실전 7-4

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int i, j ,k;
	int num = 100;
	int sum;

	printf("암스트롱수 구하기\n");

	do {
		i = num / 100;
		j = (num - (100 * i)) / 10;
		k = (num - (100 * i) - (10 * j)) / 1;

		i = i * i * i;
		j = j * j * j;
		k = k * k * k;

		sum = i + j + k;

		if (num == sum)
			printf("%d ",num);
		num++;
	} while (num < 1000);

	_getch();
	return 0;
}
*/

// p64 실전 7-5

/*
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main(void)
{
	int code, input;
	int i, j;
	int a = 0;
	int answer = 0;

	printf("덧셈 계산프로그램\n");
	printf("일의 자리 : 1\t십의 자리 : 2\n"); scanf("%d",&code);

	srand(time(NULL));

	switch (code) {
	case 1:
		do {
			i = rand()%10;
			j = rand()%10;
			printf("%02d.\t%d + %d = ",a+1,i,j); scanf("%d",&input);
			if (input == i + j)
				answer++;
			a++;
		} while (a < 10);
		break;
	case 2:
		do {
			i = rand()%100+10;
			j = rand()%100+10;
			printf("%02d.\t%d + %d = ",a+1,i,j); scanf("%d",&input);
			if (input == i + j)
				answer++;
			a++;
		} while (a < 10);
	}
	printf("10문제 중 %d개 정답\n",answer);
	printf("점수는 %d 점 입니다.\n",answer*10);
	_getch();
	return 0;
}
*/