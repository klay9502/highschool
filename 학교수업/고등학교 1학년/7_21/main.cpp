/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a[10] = {10, 20, 30};
	int b;

	b = sizeof(a);

	printf("a[10]의 사이즈: %d\n", b);
	printf("a의 주소: %d\n", a);
	for (int i = 0; i < 10; i++)
		printf("a[%d]의 주소: %d\n", i ,&a[i]);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int month;

	printf("Input month : "); scanf("%d", &month);
	printf("days = %d\n", days[month]);

	_getch();
}
*/

// p106 예제5

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int k, i, a[10];

	printf("data input!\n");
	i = 0;

	while (scanf("%d", &a[i]) != EOF)	// 키보드에서 배열원소에 데이터 입력
		i++;	// 입력 종료는 ^z
	for(k = 0; k < i; k++)
		printf("a[%d] = %d\n", k, a[k]);

	_getch();
}
*/

// p107 예제6

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int n[5];
	int i, max = 0;

	for (i = 0; i < 5; i++)
	{
		printf("숫자 %d....", i + 1); scanf("%d", &n[i]);
	}

	for (i = 0; i < 5; i++)
		if (n[i] > max)	// n[i]의 값이 amx보다 크면
			max = n[i];	// n[i]를 max로 한다.
	printf("\n최대값 ==> %d\n", max);
	
	_getch();
}
*/

// p107 예제7

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char str[8];

	scanf("%8s", str);

	printf("%s\n", str);

	_getch();
}
*/

// p107 예제8

/*
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

void main()
{
	int a[3];
	int i;

	for (i = 0; i < 3; i++)
		scanf("%d", &a[i]);	// 키보드에서 점수 입력
	system("cls");	// 화면지우기
	for (i = 2; i >= 0; i--)
		printf("\na[%d] = %d\n", i, a[i]);
	_getch();
}
*/

// 학생 5명의 체중을 읽어 가장 무거운 체중과 가장 가벼운 체중 표시

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	float weight[5];
	float max, min;

	printf("체중을 입력해주세요.\n");

	for (int i = 0; i < 5; i++)
	{
		printf(" %d번 : ", i + 1); scanf("%f", &weight[i]);
	}

	max = weight[0];
	min = weight[0];

	for (int i = 1; i < 5; i++)
	{
		if (weight[i] > max)
			max = weight[i];
		if (weight[i] < min)
			min = weight[i];
	}

	printf("가장 무거운 사람의 체중 : %.1f\n", max);
	printf("가장 가벼운 사람의 체중 : %.1f\n", min);

	_getch();
}
*/

// p109 실전 2-2

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num[8] = {10, 27, 25, 18, 9, 35, 13, 47};
	int count = 0;

	for (int i = 0; i < 8; i++)
		if (10 <= num[i] && 19 >= num[i])
			count++;

	printf("원소의 구성은 10, 27, 25, 18, 9, 35, 13, 47로 구성되어 있으며 여기서\n\n");
	printf("10 ~ 19사이의 값의 개수는 %d이다.\n", count);
	_getch();
}
*/

//


#include <stdio.h>
#include <conio.h>

void main()
{
	int num[10] = {1, 2};

	for (int i = 2; i < 10; i++)
		num[i] = num[i-2] + num[i-1];

	for (int i = 0; i < 10; i++)
		printf(" a%d = %d\n", i + 1, num[i]);

	_getch();
}