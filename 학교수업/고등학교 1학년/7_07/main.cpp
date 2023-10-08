// p91 ����10

/*
// val�� ���������� ���� ��

#include <stdio.h>
#include <conio.h>

void fuc();

void main()
{
	int i;
	for (i = 0; i < 5; i++)
		fuc();
	_getch();
}

void fuc()
{
	int val = 0;
	val++;
	printf("%d ", val);
}
*/

/*
// val�� ���������� ���� ��

#include <stdio.h>
#include <conio.h>

void fuc();

void main()
{
	int i;
	for (i = 0; i < 5; i++)
		fuc();
	_getch();
}

void fuc()
{
	static int val = 0;
	val++;
	printf("%d ", val);
}
*/

// p91 ����11

/*
#include <stdio.h>
#include <conio.h>

static int val = 20;

void fuc();

void main()
{
	int i;
	for (i = 0; i < 5; i++)
		fuc();
	printf("%d ", val);
	_getch();
}

void fuc()
{
	static int val = 0;
	val++;
	printf("%d ", val);
}
*/

// ppt ����

/*
#include <stdio.h>
#include <conio.h>

void IncreaseAge(int num);
static int Age;									// �������� Age�� ����

void main()
{
	int i;
	Age = 33;									// �������� Age�� �ʱ�ȭ

	printf("����� main() �Լ��Դϴ�.\n");
	printf("Age : %d\n\n", Age);

	for (i = 0; i < 5; i++)
		IncreaseAge(10);
	printf("\n����� main() �Լ��Դϴ�.\n");
	printf("Age : %d\n", Age);
	_getch();
}

void IncreaseAge(int num)
{
	static int Age = 25;						// IncreaseAge() �Լ� ������ ���� ���� Age�� �ʱ�ȭ

	Age = Age + num;
	printf("\n����� IncreaseAge() �Լ� �����Դϴ�.\n");
	printf("Age : %d\n", Age);
}
*/

// p92 ����13

/*
#include <stdio.h>
#include <conio.h>

extern void output();

int num;

void main()
{
	num = 10;
	output();
	_getch();
}
*/

// p93 ���� ����4

/*
#include <stdio.h>
#include <conio.h>

void save(int money);

void main()
{
	int money, choice;

	while(1)
	{
		printf("�Ա�:1, ���:2, �ŷ� ����:3 �Է��ϼ���.\n");
		scanf("%d", &choice);

		if (choice == 1)
		{
			printf("�Աݾ� :");
			scanf("%d", &money);
		}
		else if (choice == 2)
		{
			printf("��ݾ� :");
			scanf("%d", &money);
			money =- money;
		}
		else if (choice == 3)
		{
			printf("�ŷ� �Ϸ�.\n");
			save(0);
			break;
		}
		else continue;
		save(money);
	}
	_getch();
}

void save(int money)
{
	static int total = 0;
	total += money;
	printf("��������� �� ����� %d\n",total);
}
*/

// p94 ���� 4-1

/*
#include <stdio.h>
#include <conio.h>

extern void save(int money);

void main()
{
	int money, choice;

	while(1)
	{
		printf("�Ա�:1, ���:2, �ŷ� ����:3 �Է��ϼ���.\n");
		scanf("%d", &choice);

		if (choice == 1)
		{
			printf("�Աݾ� :");
			scanf("%d", &money);
		}
		else if (choice == 2)
		{
			printf("��ݾ� :");
			scanf("%d", &money);
			money =- money;
		}
		else if (choice == 3)
		{
			printf("�ŷ� �Ϸ�.\n");
			save(0);
			break;
		}
		else continue;
		save(money);
	}
	_getch();
}
*/

// p94 ���� 4-2

#include <stdio.h>
#include <conio.h>

extern void function(char ch);
extern void output();

void main()
{
	char ch;
	
	while ((ch = getchar()) != '\n')
		function(ch);
	output();
	printf("\n");
	_getch();
}