// ���� : ���
// ��¥ : 2014 / 4 / 21
// ���� : ������

// ����1

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	float num;

	printf("���� �ϳ� �Է��ϼ���.\n");
	scanf("%f",&num);
	if ((num-(int)num)==0)
		printf("������ �Է��ϼ̽��ϴ�.\n");
	printf("����� �Է��� ���� %.1f �Դϴ�.\n",num);
	_getch();
}
*/

// ����2

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	float num;

	printf("���� �ϳ� �Է��ϼ���.\n");
	scanf("%f",&num);
	if ((num-(int)num)==0)
		printf("������ �Է��ϼ̽��ϴ�.\n");
	else
		printf("�Ǽ��� �Է��ϼ̽��ϴ�.\n");

	printf("����� �Է��� ���� %.4f �Դϴ�.\n",num);

	_getch();
}
*/

// �������� 1-1

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num;

	printf("������ �Է��ϼ���.\n");
	printf("���� :");
	scanf("%d",&num);

	if ((num%2)==0)
		printf("¦���Դϴ�.\n");
	else
		printf("Ȧ���Դϴ�.\n");
	_getch();
}
*/

// �������� 1-2

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num1,num2;

	printf("�� ���� ������ �Է����ּ���.\n");

	printf("����1 :");
	scanf("%d",&num1);
	printf("����2 :");
	scanf("%d",&num2);

	if (num1 > num2)
	{
		if (num1 % num2 == 0)
			printf("%d�� %d�� ����Դϴ�.\n",num2,num1);
	}
	else
	{
		if (num2 % num1 == 0)
			printf("%d�� %d�� ����Դϴ�.\n",num1,num2);
	}
	_getch();
}
*/

// �������� 1-3

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char gender;

	printf("������ �Է��ϼ��� ('F' or 'M')\n");
	scanf("%c",&gender);

	if (gender == 'F')
		printf("����� '����'�Դϴ�.\n");
	else if (gender == 'M')
		printf("����� '����'�Դϴ�.\n");
	else
		printf("�� �� ���� Ű�����Դϴ�.\n");
	_getch();
}
*/

// ���� 3

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num;

	printf("������ �ϳ� �Է��ϼ���.\n");
	scanf("%d",&num);
	if(num>0)
		printf("����� �Է��ϼ̽��ϴ�.\n");
	else if(num<0)
		printf("������ �Է��ϼ̽��ϴ�.\n");
	else
		printf("0�� �Է��ϼ̽��ϴ�.\n");
	_getch();
}
*/

// �������� 2

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num1,num2;

	printf("�ΰ��� ������ �Է����ּ���.\n");
	printf("���� A:");		scanf("%d",&num1);
	printf("���� B:");		scanf("%d",&num2);

	if (num1-num2 > 0)
		printf("A�� B���� Ů�ϴ�.");
	else if (num1-num2 <0)
		printf("A�� B���� �۽��ϴ�.");
	else
		printf("A�� B�� ���� ���Դϴ�.");
	_getch();
}
*/

// �������� 2-1

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num1,num2,num3;

	printf("�� ���� ������ �Է����ּ���.\n");
	printf("���� A: ");		scanf("%d",&num1);
	printf("���� B: ");		scanf("%d",&num2);
	printf("���� C: ");		scanf("%d",&num3);

	if (num1 == num2 && num2 == num3)
		printf("A,B,C �� ���� ��� �����ϴ�.\n");
	else if (num1 == num2 || num2 == num3 || num1 == num3)
		printf("A,B,C �� �� ���� ���� �����ϴ�.\n");
	else
		printf("A,B,C�� ���� ��� �ٸ��ϴ�.");
	_getch();
}
*/

// �������� 2-2

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num1,num2,num3;

	printf("�� ���� ������ �Է����ּ���.\n");
	printf("���� A: ");		scanf("%d",&num1);
	printf("���� B: ");		scanf("%d",&num2);
	printf("���� C: ");		scanf("%d",&num3);

	if (num1 == num2 && num2 == num3)
		printf("A,B,C �� ���� ��� �����ϴ�.\n");
	else if (num1 == num2 || num2 == num3 || num1 == num3)
	{
		if (num1 == num2)
			printf("A,B,C�� A,B�� ���� �����ϴ�.\n");
		else if (num2 == num3)
			printf("A,B,C�� B,C�� ���� �����ϴ�.\n");
		else if (num1 == num3)
			printf("A,B,C�� A,C�� ���� �����ϴ�.\n");
	}
	else
		printf("A,B,C�� ���� ��� �ٸ��ϴ�.");
	_getch();
}
*/

// �������� 2-3

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a,c;
	char b;
	float result;

	scanf("%d%c%d",&a,&b,&c);

	if (b =='+')
		result = a + c;
	else if (b == '-')
		result = a - c;
	else if (b == '*')
		result = a * c;
	else
		result = a / c;

	printf("%.1f",result);
	_getch();
}
*/

// �������� 2-4

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int month;

	printf("���� �̿��Ͽ� ������ ���غ��ڽ��ϴ�.\n");
	printf("�� ��?: ");		scanf("%d",&month);

	if (3 <= month && 5 >= month)
		printf("���Դϴ�.\n");
	else if (6 <= month && 8 >= month)
		printf("�����Դϴ�.\n");
	else if (9 <= month && 11 >= month)
		printf("�����Դϴ�.\n");
	else if (12 == month || 2 >= month)
		printf("�ܿ��Դϴ�.\n");
	else
		printf("�߸��� Ű�����Դϴ�.\n\a");
	_getch();
}
*/

// �������� 2-5

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char gender;
	int age;

	printf("������ �Է��ϼ���.(��:m or ��:f) :");		scanf("%c",&gender);
	printf("���̸� �Է��ϼ���. :");		scanf("%d",&age);

	if (gender == 'F' || gender == 'f')
	{
		if (age > 19)
			printf("���� ������\n");
		else if (age <= 19)
			printf("���� �̼�����\n");
	}
	else if (gender == 'M' || gender == 'm')
	{
		if (age > 19)
			printf("���� ������\n");
		else if (age <= 19)
			printf("���� �̼�����\n");
	}
	else
		printf("�߸��� Ű�����Դϴ�.\n\a");
	_getch();
}
*/

// ����4

/*
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

void main()
{
	int num;

	printf("0~2 ������ ���� �߻� ����~!\n");
	srand(time(NULL));
	num=rand()%3;

	switch(num)	{
	case 0:
		puts("0");
		break;
	case 1:
		puts("1");
		break;
	case 2:
		puts("2");
		break;
	default:
		puts("�߸��� ���� �߻�:");	}
	_getch();
}
*/

// ����5

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char ch;

	printf("����� ���� ����Ͻʴϱ�? (y or n)\n");
	scanf("%c",&ch);

	switch(ch)	{
	case 'y':
		puts("���� ����� ����մϴ�.\n");
		break;
	case 'n':
		puts("�׷��� ���� ����� �����ϴ�.\n");
		break;
	default:
		puts("�߸��� �Է�");	}
	_getch();
}
*/

// 52p ��������3

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char grade;

	puts("����� �Է��ϼ���.");
	scanf("%c",&grade);
	switch(grade)	{
	case 'A':
		puts("90~100�� �����Դϴ�.\n");
		break;
	case 'B':
		puts("80~90�� �����Դϴ�.\n");
		break;
	case 'C':
		puts("70~80�� �����Դϴ�.\n");
		break;
	case 'D':
		puts("60~70�� �����Դϴ�.\n");
		break;
	case 'E':
		puts("60~70�� �����Դϴ�.\n");
		break;
	default:
		puts("50�� �����Դϴ�.\n");	}
	_getch();
}
*/

// ���ܹ���

#include <stdio.h>
#include <conio.h>

void main()
{
	int score,result;

	puts("������ �Է��ϼ���.");
	scanf("%d",&score);
	result = score/10;

	switch(result)	{
	case 10:
	case 9:
		puts("A��� �Դϴ�.\n");
		break;
	case 8:
		puts("B��� �Դϴ�.\n");
		break;
	case 7:
		puts("C��� �Դϴ�.\n");
		break;
	case 6:
		puts("D��� �Դϴ�.\n");
		break;
	case 5:
		puts("E��� �Դϴ�.\n");
		break;
	default:
		puts("F��� �Դϴ�.\n");	}
	_getch();
}