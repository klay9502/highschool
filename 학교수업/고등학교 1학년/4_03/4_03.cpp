// 날짜 : 2014 / 04 / 03
// 주제 : 배열
// 제작 : 김종민

// 104p 예제1 - 일차원 배열의 초기화1
/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i;
	int k[5];

	k[0] = 10; k[1] = 20; k[2] = 30; k[3] = 40; k[4] = 50;
							// k배열에 각각 초기값 대입
	for (i=0;i<5;i++)
		printf("k[%d] = %d\n",i,k[i]);
	_getch();
}
*/

// 105p 예제2 - 일차원 배열의 초기화2
/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i, sum=0;
	int k[6] = {10,20,30,40,50,60};
							// k배열 선언과 함께 초기값 대입
	for (i=0;i<6;i++)
	{
		sum += k[i];		// 초기값을 누계
		printf("sum = %d\n",sum);
	}
	_getch();
}
*/

// 105p 예제3 - 일차원 배열의 초기화3
/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i;
	int k[6] = {10,20,30};
							// k배열 선언과 함께 초기값 대입
	for (i=0;i<6;i++)
		printf("k[%d] ==> %d\n",i,k[i]);
	_getch();
}
*/

// 105p 예제4 - 일차원 배열의 초기화4
/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i, sum=0;
	int data[] = {1,2,3,4,5,6,7,8,9,10};
							// 첨자 요소 생략
	for (i=0;i<10;i++)
	{
		if(data[i] % 2 == 0)		// 초기화된 값 중 짝수만을 선택
			sum += data[i];
	}
	printf("2 + 4 + ... + 8 + 10 = %d\n", sum);
	_getch();
}
*/

// 106p 예제5 - 일차원 배열의 데이터 입력1

#include <stdio.h>
#include <conio.h>

void main()
{
	int k, i, a[10];

	printf("data input !\n");
	i = 0;

	while(scanf("%d", &a[i]) != EOF)		// 키보드에서 배열원소에 데이터 입력
		i++;								// 입력 종료는 ^z
	for (k=0;k<i;k++)
		printf("a[%d] = %d\n",k,a[k]);
	_getch();
}