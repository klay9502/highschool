// ppt �迭

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

// p104 ����1

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
				// k�迭�� ���� �ʱⰪ ����
	for (i = 0; i < 5; i++)
		printf("k[%d] = %d\n", i, k[i]);
	_getch();
}
*/

// p105 ����2

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i, sum = 0;
	int k[6] = {10, 20, 30, 40, 50, 60};
				// k�迭 �����ʰ� �Բ� �ʱⰪ ����
	for (i = 0; i < 6; i++)
	{
		sum += k[i];
		printf("sum = %d\n", sum);
	}
	_getch();
}
*/

// p105 ����3

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i;
	int k[6] = {10, 20, 30};
			// k�迭 ����� �Բ� �ʱⰪ ����
	for (i = 0; i < 6; i++)
		printf("k[%d] ==> %d\n", i, k[i]);
	_getch();
}
*/

// p105 ����4

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i, sum = 0;
	int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			// ÷�� ��� ����
	for (i = 0; i < 10; i++)
		if (data[i] % 2 == 0)
			sum += data[i];
	printf("2 + 4 + ... 8 + 10 =  %d\n", sum);
	_getch();
}
*/

// ppt �޸��� �⺻���� Ȱ��

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a[10] = {10, 20, 30};
	int b;

	b = sizeof(a);
	printf("a[10]�� ������ : %d\n", b);
	printf("a�� �ּ� : %d\n", a);

	for (int i = 0; i < 10; i++)
		printf("a[%d]�� �ּ� : %d\n", i , &a[i]);
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

	printf("���Ӱ� 1������ 10�������� ���������� 10�� �Է��ϼ���.\n");

	for (int i = 0; i < 10; i++)
	{
		printf("%d�� ���� : ", i + 1);
		scanf("%d", &num[i]);
	}

	printf("�ڹ迭�� �Էµ� ���� ��¡�\n");

	for (int i = 0; i < 10; i++)
	{
		printf("%d�� ����: %6d\n",i + 1 ,num[i]);
		sum += num[i];
		if (num[i] > max)
			max = num[i];
		if (num[i] < min)
			min = num[i];
	}

	average = (float)sum / 10;
	
	printf("\n���� = %d�Դϴ�.\n", sum);
	printf("����� %.2f�Դϴ�.\n", average);
	printf("�ִ밪�� = %d�Դϴ�.\n", max);
	printf("�ּҰ��� = %d�Դϴ�.\n", min);
	_getch();
}