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

// p139 ����8

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int array[5] = {10, 20, 30, 40, 50};
	int i, *ipt;
	double d = 100, *fpt;

	for (i = 0; i < 5; i++)
		printf("array[%d]�� ������ %u�̴�.\n", i, &array[i]);

	printf("�迭��ǥ�� array = %u, &array[0] = %u\n", array, &array[0]);
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

	printf("pointer ���� ����\n");
	for (i = 0; i < 5; i++)
	{
		printf("pt = %u, *pt = %d\n", pt, *pt);
		pt++;
	}

	printf("\npointer ���� ����\n");

	for (i = 0; i < 5; i++)
	{
		pt--;
		printf("pt = %u, *pt = %d\n", pt, *pt);
	}

	printf("\npt = &arr[2] ���� ��\n");

	pt = &array[2];

	printf("pt + 1 = %u, pt[1] = %d\n", pt + 1, pt[1]);	// *(pt + 1)�� array[3]�� ��Ī
	printf("pt + 2 = %u, pt[2] = %d\n", pt + 2, pt[2]);	// *(pt + 2)�� array[4]�� ��Ī
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

// p143 ���� ����1 

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int array[] = {100, 200, 300, 400, 500};
	int sum = 0, cnt = 0;
	int *p = array;

	printf("*p + 1 ���\n");

	while (cnt++ < 5)
	{
		sum += *p + 1;	// p���� 1������ 101�� ���·� ����
		printf("sum = %d\n", sum);
	}

	cnt = 0;
	sum = 0;
	printf("*(p + 1) ���\n");

	while (cnt++ < 5)
	{
		sum += *(p + 1);	// p�� �ּҰ��� 1����(������ ũ�⸸ŭ)�� �� ����
		printf("sum = %d\n", sum);
	}

	sum = 0;
	printf("*p++ ���\n");

	while (p <= &array[4])
	{
		sum += *p++;	// sum = sum + (*p)�� �켱 ������ ���� ��� p�� �ּҰ��� 1����
		printf("sum = %d\n", sum);
	}

	sum = 0;
	cnt = 0;
	p = array;
	printf("(*p)++ ���\n");

	while (cnt++ < 5)
	{
		sum += (*p)++;	// sum = sum + (*p)�� �켱 ������ ���� ��� p���� 1����
		printf("sum = %d\n", sum);
	}

	sum = 0;
	p = array;
	printf("*p++ ���\n");

	while (p <= &array[4])
	{
		sum += *++p;	// p�� �ּҰ��� 1���� �� sum = sum + (*p)�� ����
		printf("sum = %d\n", sum);
	}

	sum = 0;
	p = array;
	cnt = 0;
	printf("++*p ���\n");

	while (cnt++ < 5)
	{
		sum += ++*p;	// p�� ���� 1 ���� �� sum = sum + (*p)�� ����
		printf("sum = %d\n", sum);
	}

	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void fct(int *arr2);	// ������ �����ͷ� ����ص� ����.

void main()
{
	int arr1[2] = {1, 2};

	fct(arr1);

	printf("%d\n", arr1[0]);
	_getch();
}

void fct(int arr2[])	// �迭 �������� ���� �� �ִ�. ������ ���ڰ��� �־ �ȉ´�.
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

	printf("������ �ٲٱ� �� �迭�� ����\n");
	for (i = 0; i < 5; i++)
		printf("%d ", p[i]);	// p[i] = *(p + i)

	for (i = 0; i < 3; i++)
	{
		temp = arr[i];
		arr[i] = arr[4 - i];
		arr[4 - i] = temp;
	}

	printf("\n������ �ٲ� �� �迭�� ����\n");
	for (i = 0; i < 5; i++)
		printf("%d ", p[i]);	// p[i] = *(p + i)

	_getch();
}