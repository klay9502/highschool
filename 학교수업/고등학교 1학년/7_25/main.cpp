/*
#include <stdio.h>
#include <conio.h>

void main()
{
	short M[3] = {10, 20, 30};
	
	printf("%d %d\n", M[0], M[1]);
	printf("%d %d\n", *&M[0], *&M[1]);
	printf("%d %d\n", *M, *(M + 1));
	printf("%d\n", *M + 2);

	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int arr[3] = {0, 1, 2};
	int *ptr;

	ptr = arr;

	printf("%d, %d, %d\n", ptr[0], ptr[1], ptr[2]);
	_getch();
}
*/

// p139 예제8

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int array[5] = {10, 20, 30, 40, 50};
	int i, *ipt;
	double d = 100, *fpt;

	for (i = 0; i < 5; i++)
		printf("array[%d]의 번지는 %u이다.\n", i, &array[i]);

	printf("배열대표명 array = %u, &array[0] = %u\n", array, &array[0]);
	printf("*array = %d\n", *array);

	ipt = &i;
	fpt = &d;

	printf("&i = %u, (&i + 1) = %u\n", &i, &i + 1);
	printf("ipt = %u, ipt + 1 = %u\n", ipt, ipt + 1);
	printf("fpt = %u, fpt + 1 = %u\n", fpt, fpt + 1);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int array[5] = {10, 20, 30, 40, 50};
	int i, *pt;

	pt = array;

	printf("pointer 변수 증가\n");
	for (i = 0; i < 5; i++)
	{
		printf("pt = %u, *pt = %d\n", pt, *pt);
		pt++;
	}

	printf("\npointer 변수 증가\n");

	for (i = 0; i < 5; i++)
	{
		pt--;
		printf("pt = %u, *pt = %d\n", pt, *pt);
	}

	printf("\npt = &arr[2] 실행 후\n");

	pt = &array[2];

	printf("pt + 1 = %u, pt[1] = %d\n", pt + 1, pt[1]);	// *(pt + 1)은 array[3]을 지칭
	printf("pt + 2 = %u, pt[2] = %d\n", pt + 2, pt[2]);	// *(pt + 2)은 array[4]을 지칭
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int arr[2] = {1, 2};
	int *pArr = arr;

	printf("%d, %d\n", arr[0], *(arr + 1));
	printf("%d, %d\n", pArr[0], *(pArr + 1));
	_getch();
}
*/

// p143 연습 문제1 

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int array[] = {100, 200, 300, 400, 500};
	int sum = 0, cnt = 0;
	int *p = array;

	printf("*p + 1 출력\n");

	while (cnt++ < 5)
	{
		sum += *p + 1;	// p값이 1증가한 101의 상태로 가산
		printf("sum = %d\n", sum);
	}

	cnt = 0;
	sum = 0;
	printf("*(p + 1) 출력\n");

	while (cnt++ < 5)
	{
		sum += *(p + 1);	// p의 주소값이 1증가(데이터 크기만큼)한 후 가산
		printf("sum = %d\n", sum);
	}

	sum = 0;
	printf("*p++ 출력\n");

	while (p <= &array[4])
	{
		sum += *p++;	// sum = sum + (*p)를 우선 실행한 다음 계속 p의 주소값을 1증가
		printf("sum = %d\n", sum);
	}

	sum = 0;
	cnt = 0;
	p = array;
	printf("(*p)++ 출력\n");

	while (cnt++ < 5)
	{
		sum += (*p)++;	// sum = sum + (*p)를 우선 실행한 다음 계속 p값을 1증가
		printf("sum = %d\n", sum);
	}

	sum = 0;
	p = array;
	printf("*p++ 출력\n");

	while (p <= &array[4])
	{
		sum += *++p;	// p의 주소값을 1증가 후 sum = sum + (*p)를 실행
		printf("sum = %d\n", sum);
	}

	sum = 0;
	p = array;
	cnt = 0;
	printf("++*p 출력\n");

	while (cnt++ < 5)
	{
		sum += ++*p;	// p의 값을 1 증가 후 sum = sum + (*p)를 실행
		printf("sum = %d\n", sum);
	}

	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void fct(int *arr2);	// 어려우면 포인터로 사용해도 좋다.

void main()
{
	int arr1[2] = {1, 2};

	fct(arr1);

	printf("%d\n", arr1[0]);
	_getch();
}

void fct(int arr2[])	// 배열 형식으로 만들 수 있다. 하지만 인자값을 넣어선 안됀다.
{
	printf("%d \n", arr2[0]);
	arr2[0] = 3;
}
*/

#include <stdio.h>
#include <conio.h>

void main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	int *p = arr;
	int i, temp;

	printf("순서를 바꾸기 전 배열의 내용\n");
	for (i = 0; i < 5; i++)
		printf("%d ", p[i]);	// p[i] = *(p + i)

	for (i = 0; i < 3; i++)
	{
		temp = arr[i];
		arr[i] = arr[4 - i];
		arr[4 - i] = temp;
	}

	printf("\n순서를 바꾼 후 배열의 내용\n");
	for (i = 0; i < 5; i++)
		printf("%d ", p[i]);	// p[i] = *(p + i)

	_getch();
}