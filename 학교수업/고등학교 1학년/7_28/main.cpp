/*
#include <stdio.h>
#include <conio.h>

int MaxVal(int *ptr, int n);

void main()
{
	int arr[10];
	int i, max;
	
	printf("�迭�� ���� �Է��ϼ���.\n");

	for (i = 0; i < 10; i++) {
		printf("%d��° ����� �� : ", i);
		scanf("%d", &arr[i]);
	}

	max = MaxVal(arr, sizeof(arr) / sizeof(int));

	printf("�ִ밪 : %d\n", max);
	_getch();
}

int MaxVal(int *ptr, int n)
{
	int max = *ptr;

	for (int i = 0; i < n; i++) {
		if (max < ptr[i]) {
			max = ptr[i];
		}
	}

	return max;
}
*/

// p128 ����23 Bubble Sort 2

/*
#include <stdio.h>
#include <conio.h>

#define MAX 10

void main()
{
	char array[MAX] = {10, 8, 6, 4, 2, 9, 7, 5, 3, 1};
	int i ,j ,temp;

	printf("Sort���� �迭���� : \t");

	for (i = 0; i < MAX; i++)
		printf("%3d", array[i]);
	printf("\n\n");

	for (i = 0; i < MAX - 1; i++)
	{
		for (j = 0; j < MAX - 1 - i; j++)
		{
			if ( array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}

		printf("\n%d �ܰ� ���� �迭 ���� : ", i + 1);

		for (j = 0; j < MAX; j++)
			printf("%3d", array[j]);
	}
	
	printf("\n\n");
	printf("Sort���� �迭���� : \t");

	for (i = 0; i < MAX; i++)
		printf("%3d", array[i]);
	printf("\n");
	_getch();
}
*/

// p130 ����24 Selection Sort 1 (��ȯ�Ǵ� ȸ���� �� �ܰ迡 ���� ��)

/*
#include <stdio.h>
#include <conio.h>

#define MAX 10

void main()
{
	char array[MAX] = {10, 8, 6, 4, 2, 9, 7, 5, 3, 1};
	int i, j, temp;

	printf("------Selection Sort------\n");
	printf("Sort���� �迭���� : \t");

	for (i = 0; i < MAX; i++)
		printf("%3d", array[i]);

	printf("\n\n");

	for (i = 0; i < MAX - 1; i++)
	{
		for (j = i + 1; j < MAX; j++)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}

	printf("\nSort���� �迭 ����: \t");

	for (i = 0; i < MAX; i++)
		printf("%3d", array[i]);

	printf("\n");
	_getch();
}
*/

// p131 ����25 Selection Sort 2 (��ȯ�Ǵ� ȸ���� �� �ܰ迡 �� ��)

/*
#include <stdio.h>
#include <conio.h>

#define MAX 10

void main()
{
	char array[MAX] = {10, 8, 6, 4, 2, 9, 7, 5, 3, 1};
	int i, j, temp, p;

	printf("------Selection Sort------\n");
	printf("Sort���� �迭���� : \t");

	for (i = 0; i < MAX; i++)
		printf("%3d", array[i]);

	printf("\n\n");

	for (i = 0; i < MAX - 1; i++)
	{
		p = i;
		for (j = i + 1; j < MAX; j++)
		{
			if (array[p] > array[j])
			{
				p = j;
			}
		}

		temp = array[i];
		array[i] = array[p];
		array[p] = temp;

		printf("\n%d �ܰ� ���� �迭 ���� : ", i + 1);
		
		for (j = 0; j < MAX; j++)
			printf("%3d", array[j]);
	}

	printf("\n\n");
	printf("Sort���� �迭 ����: \t");

	for (i = 0; i < MAX; i++)
		printf("%3d", array[i]);

	printf("\n");
	_getch();
}
*/

// Bubble Sort + �Լ�

/*
#include <stdio.h>
#include <conio.h>

#define MAX 10

void bubble(int *arr);

void main()
{
	int array[MAX] = {10, 8, 6, 4, 2, 9, 7, 5, 3, 1};
	int i, j;

	printf("------Bubble Sort------\n");
	printf("Sort���� �迭���� : \t");

	for (i = 0; i < MAX; i++)
		printf("%3d", array[i]);
	
	printf("\n");

	bubble(array);

	printf("\nSort���� �迭���� : \t");

	for (i = 0; i < MAX; i++)
		printf("%3d", array[i]);

	printf("\n");
	_getch();
}

void bubble(int *arr)
{
	int i, j, temp;

	for (i = 0; i < MAX - 1; i++)
	{
		for (j = 0; j < MAX - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}

		printf("\n%d�ܰ� ���� �迭 ���� : ", i + 1);

		for (j = 0; j < MAX; j++)
			printf("%3d", arr[i]);
	}
}
*/

// Selection Sort + �Լ�

/*
#include <stdio.h>
#include <conio.h>

#define MAX 10

void selection(int *arr);

void main()
{
	int array[MAX] = {10, 8, 6, 4, 2, 9, 7, 5, 3, 1};
	int i, j;

	printf("------Selection Sort------\n");
	printf("Sort���� �迭���� : \t");

	for (i = 0; i < MAX; i++)
		printf("%3d", array[i]);
	
	printf("\n");

	selection(array);

	printf("\n\n");
	printf("Sort���� �迭���� : \t");

	for (i = 0; i < MAX; i++)
		printf("%3d", array[i]);

	printf("\n");
	_getch();
}

void selection(int *arr)
{
	int i, j, p, temp;

	for (i = 0; i < MAX - 1; i++)
	{
		p = i;
		for (j = i + 1; j < MAX; j++)
		{
			if (arr[p] > arr[j])
			{
				p = j;
			}
		}

		temp = arr[i];
		arr[i] = arr[p];
		arr[p] = temp;

		printf("\n%d �ܰ� ���� �迭 ���� : ", i + 1);
		
		for (j = 0; j < MAX; j++)
			printf("%3d", arr[j]);
	}
}
*/

/*
#include <stdio.h>
#include <conio.h>

#define SIZE 5

void merge(int *A, int *B, int *C);
void rect(int *a);

void main()
{
	int A[SIZE] = {5, 2, 8, 7, 9};
	int B[SIZE] = {4, 3, 6, 1, 10};
	int C[100] = {0};
	int i = 0;

	rect(A);
	rect(B);
	merge(A, B, C);

	printf("�迭 {");

	while (C[i] != '\0')
	{
		printf("%d, ", C[i]);
		i++;
	}

	puts("}");
	_getch();
}

void merge(int *A, int *B, int *C)
{
	int a = 0, b = 0, c = 0;


	while(1)
	{
		if (A[a] > B[b]) {
			C[c] = B[b];
			b++;
		} else {
			C[c] = A[a];
			a++;
		}
		c++;

		if (a == SIZE)
		{
			for (; b < SIZE; c++, b++)
				C[c] = B[b];
			break;
		}

		if (b == SIZE)
		{
			for (; a < SIZE; c++, a++)
				C[c] = A[a];
			break;
		}
	}
}

void rect(int *a)
{
	int temp;

	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = i + 1; j < SIZE; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
*/