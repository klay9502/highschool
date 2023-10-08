// p73 ����16

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i;

	for (i = 0; i <= 10; i++)
	{
		if (i == 5)
			break;
		else
			printf("%d\t",i);
	}
	printf("\n");
	_getch();
}
*/

// ppt, switch���� ���� break��.

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a = 1;

	switch (a) {
	case 1:
		printf("�ϳ�");
		//	break;
	case 2:
		printf("��");
		//	break;
	default:
		puts("1,2 �ƴ�"); }
	puts("�Դϴ�.");
	_getch();
}
*/

// ppt, while���� ���� break��.

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a = 0;

	while (1)
	{
		a++;
		printf("%d\n",a);
		if (a == 2)
			break;
	}
	puts("����");
	_getch();
}
*/

// ppt, break������ �ݺ��� �����ϱ�.

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i, j;
	i = j = 0;

	printf("break���� �׽�Ʈ�Դϴ�. \n");

	do {
		printf("do-while���� %d��° �ݺ��Դϴ�. \n",i);
		for(j = 0; j < 10; j++)
		{
			if (j == 5)
				break;
			printf("for���� %d��° �ݺ��Դϴ�.\n",j);
		}
		i++;
	} while (i < 5);
	printf("���α׷��� �����մϴ�.\n");
	_getch();
}
*/

// ppt, for���� ���� continue��.

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a;
	for ( a = 1; a <= 4; a++)
	{
		if ( a % 2 == 0)
		{
			puts("***");
			continue;
		}
		printf("%d\n", a);
	}
	puts("����");
	_getch();
}
*/

// ppt, while���� ���� continue��

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i = 0, hap = 0;

	while ( i <= 100)
	{
		i++;
		if ( i % 2 == 1)
			continue;
		hap += i;
		if ( hap > 1000)
			break;
	}
	printf("i�� ���� %d�� �� ���� 1000�� �Ѿ����ϴ� \n", i);
	_getch();
}
*/

// ppt, continue������ �ݺ��� �����ϱ�.

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i, j;
	i = j = 0;

	printf("continue���� �׽�Ʈ�Դϴ�. \n");

	do {
		printf("do-while���� %d��° �ݺ��Դϴ�. \n",i);
		for(j = 0; j < 10; j++)
		{
			if (j == 5)
				continue;
			printf("for���� %d��° �ݺ��Դϴ�.\n",j);
		}
		i++;
	} while (i < 5);
	printf("���α׷��� �����մϴ�.\n");
	_getch();
}
*/

// �������� ����ϵ� ¦����(2��, 4��, 6��, 8��)�� ����ϰԲ� ����.
// ���� 2���� 2*2����, 4���� 4*4����, 6���� 6*6����, 8���� 8*8���� �������.
// <����> continue�� break���� ����� ��.

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i, j;
	int sum;

	for (i = 1;i <= 8; i++)
	{
		if ( i % 2 == 1)		// Ȧ�����϶� ���
			continue;
		for (j = 1;; j++)
		{
			sum = i * j;
			printf("%d X %d = %d\n", i, j, sum);
			if ( j == i)		// �� ���ڿ� �� ���ڰ� ���� �� �ߴ�
				break;
		}
	}
	_getch();
}
*/

// ppt, goto������ �ݺ��� �����ϱ�.

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i, j;
	i = j = 0;

	printf("goto���� �׽�Ʈ�Դϴ�. \n");

	do {
		printf("do-while���� %d��° �ݺ��Դϴ�. \n",i);
		for(j = 0; j < 10; j++)
		{
			if (j == 5)
				goto stop1;
			printf("for���� %d��° �ݺ��Դϴ�.\n",j);
		}
		i++;
	} while (i < 5);
	stop1:
	printf("���α׷��� �����մϴ�.\n");
	_getch();
}
*/

// p74 goto�� ����17

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a = 1;

here:
	a++;
	if ( a == 2)
		goto here;
	printf("%d\n", a);
	_getch();
}
*/

#include <stdio.h>
#include <conio.h>

void main()
{
	int num, count;

	printf("10���� �Է� :"); scanf("%d",&num);
	count = 1;
	while (1)
	{
		if (count % 2 == 1)
			printf("1");
		else if (count % 2 == 0)
			printf("0");
		count = count / 2;
		if (count == 0)
			break;
	}
	_getch();
}