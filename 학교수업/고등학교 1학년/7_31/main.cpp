/*
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


void main()
{
	char *pBuf, *iBuf;
	int i;

	pBuf = (char*)malloc(10);

	iBuf = pBuf;

	for (i = 0; i < 10; i++)
		*pBuf++ = i + 'A';

	pBuf = iBuf;

	for (i = 0; i < 10; i++)
		printf("%c", *pBuf++);
	
	free(pBuf);
	_getch();	
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main()
{
	int *str;
	int num;
	int i = 0, sum = 0;

	printf("��� ���� �Է��Ͻðڽ��ϱ�?\n");
	scanf("%d", &num);

	str = (int *)malloc(sizeof(int) * num);

	printf("���� ���� �Է��ϼ���.\n");

	for (i = 0; i < num; i++)
	{
		scanf("%d", &str[i]);
		
		sum += str[i];
	}

	printf("sum = %d\n", sum);
	free(str);

	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

int str_equal(char *s1, char *s2)
{
	int i = 0;

	while (1)
	{
		if (s1[i] != s2[i])
			return 0;
		if (s1[i] == '\0' && s2[i] == '\0')
			return 1;
		i++;
	}
}

void main()
{
	char str1[100], str2[100];
	int code;

	printf("���ڿ��� �Է����ּ���. : ");
	gets(str1);
	fflush(stdin);
	printf("���ڿ��� �Է����ּ���. : ");
	gets(str2);

	code = str_equal(str1, str2);

	switch (code)
	{
	case 0:
		printf("�̵� ���ڿ��� �ٸ��ϴ�.\n");
		break;
	case 1:
		printf("�̵� ���ڿ��� �����ϴ�.\n");
	}
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void SelFunction(int s);
void Add(void);
void Min(void);

int main(void)
{
	int sel;

	while(1)
	{
		printf("���� : ����(1), ����(2), ����(3)");
		scanf("%d", &sel);
		
		if (sel == 3)
			break;
		SelFunction(sel);
	}

	printf("���α׷��� ���� �Ǿ����ϴ�. \n");

}

void SelFunction(int s)
{
	void (*fPtr)(void);
	if (s == 1)
		fPtr = Add;
	else
		fPtr = Min;
	fPtr();
}

void Add(void)
{
	int a, b;
	
	printf("������ ���� �� ���� ���� �Է� : ");
	scanf("%d %d", &a, &b);
	printf("���� ��� : %d \n\n", a + b);
}

void Min(void)
{
	int a, b;

	printf("������ ���� �� ���� ���� �Է� : ");
	scanf("%d %d", &a, &b);
	printf("���� ��� : %d \n\n", a - b);
}
*/

/*
#include <stdio.h>
#include <conio.h>

enum Days {MON, TUE, WED, THU, FRI, SAT, SUN};

void main()
{
	int day;

	printf("Input a day(0: Monday ~ 6: Sunday) : ");
	scanf("%d", &day);

	switch(day)
	{
	case MON:
		printf("������ �ϼ���. \n");
		break;
	case TUE:
		printf("������ �ϼ���. \n");
		break;
	case WED:
		printf("���� �� �ֹ�����. \n");
		break;
	case THU:
		printf("������ �ϼ���. \n");
		break;
	case FRI:
		printf("���� �� �ֹ�����. \n");
		break;
	case SAT:
		printf("����� �ϼ���. \n");
		break;
	case SUN:
		printf("���ϴ°� �ϼ���. \n");
		break;
	}
	_getch();
}
*/

#include <stdio.h>
#include <conio.h>

typedef struct Dog // ���� Ÿ�� 1
{
	int data1;
	int data2;
} DOG;

typedef struct // ���� Ÿ��2
{
	int data1;
	int data2;
} CAT;

void main()
{
	DOG d1; // typedef�� ���� ����
	struct Dog d2; // ���� ���� (OK)

	CAT c1; // typedef�� ���� ����
	struct Cat c2; // ���� ���� (ERROR)

	_getch();
}