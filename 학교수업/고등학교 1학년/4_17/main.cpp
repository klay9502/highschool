// ���� : ���
// ��¥ : 2014 / 4 / 17
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
		if (age > 18)
			printf("���� ������\n");
		else if (age <= 18)
			printf("���� �̼�����\n");
	}
	else if (gender == 'M' || gender == 'm')
	{
		if (age > 18)
			printf("���� ������\n");
		else if (age <= 18)
			printf("���� �̼�����\n");
	}
	else
		printf("�߸��� Ű�����Դϴ�.\n\a");
	_getch();
}
*/