/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a[10] = {10, 20, 30};
	int b;

	b = sizeof(a);

	printf("a[10]�� ������: %d\n", b);
	printf("a�� �ּ�: %d\n", a);
	for (int i = 0; i < 10; i++)
		printf("a[%d]�� �ּ�: %d\n", i ,&a[i]);
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

// p106 ����5

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int k, i, a[10];

	printf("data input!\n");
	i = 0;

	while (scanf("%d", &a[i]) != EOF)	// Ű���忡�� �迭���ҿ� ������ �Է�
		i++;	// �Է� ����� ^z
	for(k = 0; k < i; k++)
		printf("a[%d] = %d\n", k, a[k]);

	_getch();
}
*/

// p107 ����6

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int n[5];
	int i, max = 0;

	for (i = 0; i < 5; i++)
	{
		printf("���� %d....", i + 1); scanf("%d", &n[i]);
	}

	for (i = 0; i < 5; i++)
		if (n[i] > max)	// n[i]�� ���� amx���� ũ��
			max = n[i];	// n[i]�� max�� �Ѵ�.
	printf("\n�ִ밪 ==> %d\n", max);
	
	_getch();
}
*/

// p107 ����7

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

// p107 ����8

/*
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

void main()
{
	int a[3];
	int i;

	for (i = 0; i < 3; i++)
		scanf("%d", &a[i]);	// Ű���忡�� ���� �Է�
	system("cls");	// ȭ�������
	for (i = 2; i >= 0; i--)
		printf("\na[%d] = %d\n", i, a[i]);
	_getch();
}
*/

// �л� 5���� ü���� �о� ���� ���ſ� ü�߰� ���� ������ ü�� ǥ��

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	float weight[5];
	float max, min;

	printf("ü���� �Է����ּ���.\n");

	for (int i = 0; i < 5; i++)
	{
		printf(" %d�� : ", i + 1); scanf("%f", &weight[i]);
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

	printf("���� ���ſ� ����� ü�� : %.1f\n", max);
	printf("���� ������ ����� ü�� : %.1f\n", min);

	_getch();
}
*/

// p109 ���� 2-2

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

	printf("������ ������ 10, 27, 25, 18, 9, 35, 13, 47�� �����Ǿ� ������ ���⼭\n\n");
	printf("10 ~ 19������ ���� ������ %d�̴�.\n", count);
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