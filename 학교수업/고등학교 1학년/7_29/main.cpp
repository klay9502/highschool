/*
#include <stdio.h>
#include <conio.h>

void show_data(int (*ptr)[4], int a);

void main()
{
	int arr1[2][4] = {1, 2, 3, 4, 5, 6, 7, 8};
	int arr2[3][4] = {{1}, {2}, {3}};

	show_data(arr1, 2);
	show_data(arr2, 3);

	_getch();
}

void show_data(int (*ptr)[4], int a)
{
	int i, j;
	
	printf("----Start Print----\n");

	for (i = 0; i < a; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%d", ptr[i][j]);
		printf("\n");
	}
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a[3][2] = {1, 2, 3, 4, 5, 6};

	printf("a	: %u\n", a);
	printf("a + 1 size : %d\n", sizeof(a + 1));
	printf("a + 1 : %d\n", a + 1);

	printf("a[1] size : %d\n", sizeof(a[1]));			// a[1] = *(a + 1)
	printf("a[1] : %d\n", a[1]);

	printf("*(a + 1) size : %d\n", sizeof(*(a + 1)));
	printf("*(a + 1) : %d\n", *(a + 1));

	_getch();
}
*/

// p148 ���� 13

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int array[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int i, *pt;

	pt = (int *)array;	// 12�� �����ϴ� ������ 4�� �����ϴ� ������ ��ȯ
	printf("array = %u, array + 1 = %u, pt + 1 = %u\n", array, array + 1, pt + 1);
	// array + 1�� 12����, pt + 1�� 4����

	for(i = 0; i < 12; i++)
	{
		printf("pt + %2d = %u, *(pt + %2d) = %2d", i, (pt + 1), i, *(pt + i));
		printf("pt[%2d] = %d\n", i, pt[i]);
	}
	_getch();
}
*/

// p149 ����14

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int array[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int (*pt1)[2], (*pt2)[4];	// int 2�� ������ pt1�� 4�� ������ pt2�� ����
	int i;

	pt1 = (int (*)[2])array;	// int 2�� ������ �����ϴ� ������ ����
	pt2 = (int (*)[4])array;	// int 4�� ������ �����ϴ� ������ ����

	printf("array = %u, array + 1 = %u\n", array, array + 1);
	printf("pt1 + 1 = %u, pt2 + 1 = %u\n", pt1 + 1, pt2 + 1);

	for (i = 0; i < 3; i++)
	{
		printf("pt1[%d][0] = %2d, pt1[%d][1] = %2d \t", i, pt1[i][0], i, pt1[i][1]);
		printf("pt2[%d][0] = %2d, pt2[%d][1] = %2d \n", i, pt2[i][0], i, pt2[i][1]);
	}
	_getch();
}
*/

// p150 ����15

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int array[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int array1[5] = {11, 12, 13, 14, 15};
	int array2[5] = {21, 22, 23, 24, 25};
	int *pt[4];	// int(*pt)[4]�� ȥ������ �� ��
	int i, j;

	pt[0] = array1;	// ������ �迭�� ���۹��� ����
	pt[1] = array2;
	pt[2] = array[0];	// 2���� �迭�� 0���� ����
	pt[3] = array[2];

	printf("pointer �迭�� ������ ���� ����\n");

	for (i = 0; i < 4; i++)
	{
		for(j = 0; j < 5; j++)
		{
			printf("pt[%d][%d] = %2d\n", i, j, pt[i][j]);
		}
	}

	printf("array1 = %u \t array2 = %u\n", array1, array2);
	printf("array = %u \t array + 1 = %u\n", array, array + 1);
	printf("array + 2 = %u \t array + 3 = %u\n", array + 2, array + 3);
	_getch();
}
*/

// p151 ����16

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int array1[5] = {11, 12, 13, 14, 15};
	int array2[2] = {21, 22};
	int array3[3] = {31, 32, 33};
	int *pt[3];
	int **pp;
	int i, j;
	pp = pt;

	printf("array1 = %u array2 = %u array3 = %u\n", array1, array2, array3);

	for(i = 0; i < 3; i++)
	{
		printf("pt + %d = %u\t", i, pt + i);
		printf("pp + %d = %d\n", i, pp + i);
	}

	pt[0] = array1;
	pt[1] = array2;
	pt[2] = array3;

	printf("pointer �迭�� ������ ���� ����\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("pp[%d][%d] = %2d\n", i, j, pp[i][j]);
		}
	}

	printf("pointer�� pointer �����ϸ� ���\n");
	printf("pp = %u, *pp = %u, **pp = %d\n", pp, *pp, **pp);
	printf("pp[0][1] = %2d\n", pp[0][1]);
	printf("(*pp)[1] = %2d\n", (*pp)[1]);
	printf("*pp[1] = %2d\n", *pp[1]);

	pp++;	// pp 1 ����

	printf("pp[0][1] = %2d\n", pp[0][1]);
	printf("(*pp)[1] = %2d\n", (*pp)[1]);
	printf("*pp[1] = %2d\n", *pp[1]);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i, j;
	int data[][2] = {{10, 20}, {30, 40}, {50, 60}, {70, 80}, {90, 100}};
	int (*ptr)[2];
	int *tptr[5];

	ptr = data;
	tptr[0] = &data[0][0];
	tptr[1] = &data[1][0];
	tptr[2] = &data[2][0];
	tptr[3] = &data[3][0];
	tptr[4] = &data[4][0];

	for (i = 0; i < 5; i++)
	{
		printf("ptr : %u, **ptr : %d, *(*ptr + 1) : %d\n", ptr, **ptr, *(*ptr + 1));
		ptr++;
	}

	ptr = data;

	for (i = 0; i < 5; i++)
	{
		printf("ptr : %u, ptr[%d][0] : %d, ptr[%d][1] : %d\n", ptr, i, ptr[i][0], i, ptr[i][1]);
	}

	for (i = 0; i < 5; i++)
	{
		printf("tptr[%d] : %u, *tptr[%d] : %d, *(tptr[%d] + 1) : %d\n", i, tptr[i], i, *tptr[i], i, *(tptr[i] + 1));
	}

	for(i = 0; i < 5; i++)
	{
		printf("tptr[%d] : %u, tptr[%d][0] : %d, tptr[%d][1] : %d\n", i, tptr[i], i, tptr[i][0], i, tptr[i][1]);
	}
	_getch();
}
*/

#include <stdio.h>
#include <conio.h>

#define NUM_Student	5

void main()
{
	int i, j;

	int data[][3] = {{100, 90, 80}, {90, 90, 80}, {70, 90, 80}, {100, 30, 70}, {100, 90, 100}};
	int (*ptr)[3]; // 2���� �迭�� ���� �����͸� ����Ű�� ������
	int *tptr[5]; // ������ �迭 ����
	int Student[5][2]; //�л������� ������ ����� ������ �迭����
	int Class[3] = {0}; // �� Ŭ������ ����� ������ �迭

	ptr = data;
	tptr[0] = &data[0][0];
	tptr[1] = &data[1][0];
	tptr[2] = &data[2][0];
	tptr[3] = &data[3][0];
	tptr[4] = &data[4][0];

	// �л��� ���� �� ���
	for (i = 0; i < NUM_Student; i++)
	{
		for (j = 0; j < 2; j++)
		{
			Student[i][j] = tptr[i][0] + tptr[i][1] + tptr[i][2];
							// *tptr[i] + *(tptr[i] + 1) + *(tptr[i] + 2);
		}
		Student[i][1] = Student[i][1] / 3;
		printf("[%d]�л��� ���� : %d, ��� : %d\n", i + 1, Student[i][0], Student[i][1]);
	}
	printf("\n");
	// ���� ���
	for (i = 0; i < NUM_Student; i++)
	{
		Class[0] += ptr[i][0];
		Class[1] += ptr[i][1];
		Class[2] += ptr[i][2];
	}

	printf("���� ������ ��� : %d\n", Class[0] / NUM_Student);
	printf("���� ������ ��� : %d\n", Class[1] / NUM_Student);
	printf("���� ������ ��� : %d\n", Class[2] / NUM_Student);
	_getch();
}