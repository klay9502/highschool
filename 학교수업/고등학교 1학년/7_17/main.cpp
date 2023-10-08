// ppt 배열

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char buf[5] = {'a', 'b','c','d','e'};
	int num[10] = {1,2,3,4,5};
	int num1[100] = {0,};

	buf[0] = 'a';
	buf[1] = 'b';
	buf[2] = 'c';
	buf[3] = 'd';
	buf[4] = 'e';

	printf("%c, %c, %c, %c, %c\n", buf[0], buf[1], buf[2], buf[3],buf[4]);
	printf("%d, %d, %d, %d, %d, %d\n", num[0], num[1], num[2], num[3], num[4], num[5]);

	for (int i = 0; i < 100; i++)
		printf("%d", num1[i]);
	_getch();
}
*/

// p104 예제1

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i;
	int k[5];

	k[0] = 10;
	k[1] = 20;
	k[2] = 30;
	k[3] = 40;
	k[4] = 50;
				// k배열에 각각 초기값 대입
	for (i = 0; i < 5; i++)
		printf("k[%d] = %d\n", i, k[i]);
	_getch();
}
*/

// p105 예제2

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i, sum = 0;
	int k[6] = {10, 20, 30, 40, 50, 60};
				// k배열 선ㅇ너과 함께 초기값 대입
	for (i = 0; i < 6; i++)
	{
		sum += k[i];
		printf("sum = %d\n", sum);
	}
	_getch();
}
*/

// p105 예제3

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i;
	int k[6] = {10, 20, 30};
			// k배열 선언과 함께 초기값 대입
	for (i = 0; i < 6; i++)
		printf("k[%d] ==> %d\n", i, k[i]);
	_getch();
}
*/

// p105 예제4

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i, sum = 0;
	int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			// 첨자 요소 생략
	for (i = 0; i < 10; i++)
		if (data[i] % 2 == 0)
			sum += data[i];
	printf("2 + 4 + ... 8 + 10 =  %d\n", sum);
	_getch();
}
*/

// ppt 메모리의 기본적인 활용

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a[10] = {10, 20, 30};
	int b;

	b = sizeof(a);
	printf("a[10]의 사이즈 : %d\n", b);
	printf("a의 주소 : %d\n", a);

	for (int i = 0; i < 10; i++)
		printf("a[%d]의 주소 : %d\n", i , &a[i]);
	_getch();
}
*/

#include <stdio.h>
#include <conio.h>

void main()
{
	int num[10];
	int sum = 0;
	int min = 100, max = 0;
	float average;

	printf("게임과 1번부터 10번까지의 국어점수를 10개 입력하세요.\n");

	for (int i = 0; i < 10; i++)
	{
		printf("%d번 정수 : ", i + 1);
		scanf("%d", &num[i]);
	}

	printf("★배열에 입력된 내용 출력★\n");

	for (int i = 0; i < 10; i++)
	{
		printf("%d번 정수: %6d\n",i + 1 ,num[i]);
		sum += num[i];
		if (num[i] > max)
			max = num[i];
		if (num[i] < min)
			min = num[i];
	}

	average = (float)sum / 10;
	
	printf("\n합은 = %d입니다.\n", sum);
	printf("평균은 %.2f입니다.\n", average);
	printf("최대값은 = %d입니다.\n", max);
	printf("최소값은 = %d입니다.\n", min);
	_getch();
}