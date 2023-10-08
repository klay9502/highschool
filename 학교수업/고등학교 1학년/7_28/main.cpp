/*
#include <stdio.h>
#include <conio.h>

int MaxVal(int *ptr, int n);

void main()
{
	int arr[10];
	int i, max;
	
	printf("배열에 값을 입력하세요.\n");

	for (i = 0; i < 10; i++) {
		printf("%d번째 요소의 값 : ", i);
		scanf("%d", &arr[i]);
	}

	max = MaxVal(arr, sizeof(arr) / sizeof(int));

	printf("최대값 : %d\n", max);
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

// p128 예제23 Bubble Sort 2

/*
#include <stdio.h>
#include <conio.h>

#define MAX 10

void main()
{
	char array[MAX] = {10, 8, 6, 4, 2, 9, 7, 5, 3, 1};
	int i ,j ,temp;

	printf("Sort전의 배열내용 : \t");

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

		printf("\n%d 단계 후의 배열 내용 : ", i + 1);

		for (j = 0; j < MAX; j++)
			printf("%3d", array[j]);
	}
	
	printf("\n\n");
	printf("Sort후의 배열내용 : \t");

	for (i = 0; i < MAX; i++)
		printf("%3d", array[i]);
	printf("\n");
	_getch();
}
*/

// p130 예제24 Selection Sort 1 (교환되는 회수를 한 단계에 여러 번)

/*
#include <stdio.h>
#include <conio.h>

#define MAX 10

void main()
{
	char array[MAX] = {10, 8, 6, 4, 2, 9, 7, 5, 3, 1};
	int i, j, temp;

	printf("------Selection Sort------\n");
	printf("Sort전의 배열내용 : \t");

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

	printf("\nSort후의 배열 내용: \t");

	for (i = 0; i < MAX; i++)
		printf("%3d", array[i]);

	printf("\n");
	_getch();
}
*/

// p131 예제25 Selection Sort 2 (교환되는 회수를 한 단계에 한 번)

/*
#include <stdio.h>
#include <conio.h>

#define MAX 10

void main()
{
	char array[MAX] = {10, 8, 6, 4, 2, 9, 7, 5, 3, 1};
	int i, j, temp, p;

	printf("------Selection Sort------\n");
	printf("Sort전의 배열내용 : \t");

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

		printf("\n%d 단계 후의 배열 내용 : ", i + 1);
		
		for (j = 0; j < MAX; j++)
			printf("%3d", array[j]);
	}

	printf("\n\n");
	printf("Sort후의 배열 내용: \t");

	for (i = 0; i < MAX; i++)
		printf("%3d", array[i]);

	printf("\n");
	_getch();
}
*/

// Bubble Sort + 함수

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
	printf("Sort전의 배열내용 : \t");

	for (i = 0; i < MAX; i++)
		printf("%3d", array[i]);
	
	printf("\n");

	bubble(array);

	printf("\nSort후의 배열내용 : \t");

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

		printf("\n%d단계 후의 배열 내용 : ", i + 1);

		for (j = 0; j < MAX; j++)
			printf("%3d", arr[i]);
	}
}
*/

// Selection Sort + 함수

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
	printf("Sort전의 배열내용 : \t");

	for (i = 0; i < MAX; i++)
		printf("%3d", array[i]);
	
	printf("\n");

	selection(array);

	printf("\n\n");
	printf("Sort후의 배열내용 : \t");

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

		printf("\n%d 단계 후의 배열 내용 : ", i + 1);
		
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

	printf("배열 {");

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