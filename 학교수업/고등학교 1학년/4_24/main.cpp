//========================
//Today...2014 / 04 / 24
//Subject...Switch
//Make by...'������'
//========================

// 53p 3-1

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char grade;

	puts("����� �Է��ϼ���.");
	scanf("%c",&grade);
	switch(grade)	{
	case 'a':
	case 'A':
		puts("90~100�� �����Դϴ�.\n");
		break;
	case 'b':
	case 'B':
		puts("80~90�� �����Դϴ�.\n");
		break;
	case 'c':
	case 'C':
		puts("70~80�� �����Դϴ�.\n");
		break;
	case 'd':
	case 'D':
		puts("60~70�� �����Դϴ�.\n");
		break;
	case 'e':
	case 'E':
		puts("60~70�� �����Դϴ�.\n");
		break;
	default:
		puts("50�� �����Դϴ�.\n");	}
	_getch();
}
*/

// 53p 3-2

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int month;

	printf("�� :");
	scanf("%d",&month);

	switch(month)	{
	case 1:
		printf("January\n");
		break;
	case 2:
		printf("February\n");
		break;
	case 3:
		printf("March\n");
		break;
	case 4:
		printf("April\n");
		break;
	case 5:
		printf("May\n");
		break;
	case 6:
		printf("June\n");
		break;
	case 7:
		printf("July\n");
		break;
	case 8:
		printf("August\n");
		break;
	case 9:
		printf("September\n");
		break;
	case 10:
		printf("October\n");
		break;
	case 11:
		printf("November\n");
		break;
	case 12:
		printf("December\n");
		break;
	default:
		printf("�߸��� Ű����\n");
	}
	_getch();
}
*/

// 53p 3-3

/*
#include<stdio.h>
#include<conio.h>

void main()
{
	int month, day;

	printf("��: ");
	scanf("%d", &month);
	printf("��: ");
	scanf("%d", &day);

	switch(month)
	{
	case 1:
		{
			if(day<20)
				puts("�����ڸ� �Դϴ�.");
			else
				puts("�����ڸ� �Դϴ�.");
		}
		break;
	case 2:
		{
			if(day<19)
				puts("�����ڸ� �Դϴ�.");
			else
				puts("������ڸ� �Դϴ�.");
		}
		break;
	case 3:
		{
			if(day<21)
				puts("������ڸ� �Դϴ�.");
			else
				puts("���ڸ� �Դϴ�.");
		}
	case 4:
		{
			if(day<20)
				puts("���ڸ� �Դϴ�.");
			else
				puts("Ȳ���ڸ� �Դϴ�.");
		}
		break;
	case 5:
		{
			if(day<21)
				puts("Ȳ���ڸ� �Դϴ�.");
			else
				puts("�ֵ����ڸ� �Դϴ�.");
		}
		break;
	case 6:
		{
			if(day<22)
				puts("�ֵ����ڸ� �Դϴ�.");
			else
				puts("���ڸ� �Դϴ�.");
		}
		break;
	case 7:
		{
			if(day<23)
				puts("���ڸ� �Դϴ�.");
			else
				puts("�����ڸ� �Դϴ�.");
		}
		break;
	case 8:
		{
			if(day<23)
				puts("�����ڸ� �Դϴ�.");
			else
				puts("ó���ڸ� �Դϴ�.");
		}
		break;
	case 9:
		{
			if(day<24)
				puts("ó���ڸ� �Դϴ�.");
			else
				puts("õĪ�ڸ� �Դϴ�.");
		}
		break;
	case 10:
		{
			if(day<23)
				puts("õĪ�ڸ� �Դϴ�.");
			else
				puts("�����ڸ� �Դϴ�.");
		}
		break;
	case 11:
		{
			if(day<23)
				puts("�����ڸ� �Դϴ�.");
			else
				puts("����ڸ� �Դϴ�.");
		}
		break;
	case 12:
		{
			if(day<25)
				puts("����ڸ� �Դϴ�.");
			else
				puts("�����ڸ� �Դϴ�.");
		}
		break;
	default:
		puts("����.");
	}
	_getch();
}
*/

// 53p 3-4

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int month;

	printf("���� �̿��Ͽ� ������ ���غ��ڽ��ϴ�.\n");
	printf("�� ��? :");
	scanf("%d",&month);

	switch(month)	{
	case 1:
		printf("�ܿ�\n");
		break;
	case 2:
		printf("�ܿ�\n");
		break;
	case 3:
		printf("��\n");
		break;
	case 4:
		printf("��\n");
		break;
	case 5:
		printf("��\n");
		break;
	case 6:
		printf("����\n");
		break;
	case 7:
		printf("����\n");
		break;
	case 8:
		printf("����\n");
		break;
	case 9:
		printf("����\n");
		break;
	case 10:
		printf("����\n");
		break;
	case 11:
		printf("����\n");
		break;
	case 12:
		printf("�ܿ�\n");
		break;
	default:
		printf("�߸��� Ű����\n");
	}
	_getch();
}
*/

// 53p 3-5

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num1,num2;
	char code;
	float result;

	scanf("%d%c%d",&num1,&code,&num2);
	
	switch (code)	{
	case '+' :
		result = num1 + num2;
		printf("%.1f",result);
		break;
	case '-' :
		result = num1 - num2;
		printf("%.1f",result);
		break;
	case '*' :
		result = num1 * num2;
		printf("%.1f",result);
		break;
	case '/' :
		result = num1 / num2;
		printf("%.1f",result);
		break;
	default :
		printf("�߸��� Ű����\n");
	}
	_getch();
}
*/

// 53p 3-6

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int code;

	printf("\n** ���� �޴� ���� **\n");
	printf("1. �����\n");
	printf("2. «��\n");
	printf("3. ������\n");
	printf("4. ��ä��\n\n");
	printf("�޴��� �����ϼ��� :");
	scanf("%d",&code);

	switch (code)	{
	case 1 :
		printf("�޴� 1�� �����߽��ϴ�.\n");
		printf("���ִ� ¥��� 3500��\n");
		break;
	case 2 :
		printf("�޴� 2�� �����߽��ϴ�.\n");
		printf("���ִ� «�� 4000��\n");
		break;
	case 3 :
		printf("�޴� 3�� �����߽��ϴ�.\n");
		printf("���ִ� ������ 3500��\n");
		break;
	case 4 :
		printf("�޴� 4�� �����߽��ϴ�.\n");
		printf("���ִ� ��ä�� 4000��\n");
		break;
	default :
		printf("�߸��� Ű����\n");
	}
	_getch();
}
*/

// PPT ����

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int kor,mat,eng;
	int code;
	char level;
	float ave;

	printf("===================================\n");
	printf("##########����������α׷�#########\n\n");
	
	printf("���� ������ �Է��ϼ��� :");
	scanf("%d",&kor);
	printf("���� ������ �Է��ϼ��� :");
	scanf("%d",&mat);
	printf("���� ������ �Է��ϼ��� :");
	scanf("%d",&eng);

	ave = (kor + mat + eng) / 3;

	printf("-----------------------------------\n");
	printf("����� ��, ��, �� ��������� ����Դϴ�.\n\n");

	code = ave/10;

	switch(code)	{
	case 10:
	case 9:
		level = 'A';
		break;
	case 8:
		level = 'B';
		break;
	case 7:
		level = 'C';
		break;
	case 6:
		level = 'D';
		break;
	case 5:
		level = 'E';
		break;
	default:
		level = 'F';	}

	printf("������� %.1f / ��� %c\n",ave,level);
	printf("-----------------------------------\n");
	_getch();
}
*/