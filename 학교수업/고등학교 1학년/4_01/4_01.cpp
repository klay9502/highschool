// ��¥ : 2014 / 04 / 01
// ���� : ���
// �̸� : ������

/* 28p ��� ����
#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
	float pi=3.14, area=0, R=4;
	area= pi*(pow(4.0,2.0));
	printf("%f\n",area);

	pi=3.14159;	// pi�� �����̹Ƿ� �缳�� ����
	area = pi*(pow(4.0,2.0));

	printf("%f\n",area);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>
#define MAX_PERSOM 3

void main()
{
	int Person[MAX_PERSOM]; int i;
	int TotalCountOfKorean = 0;
	float AverageOfKorean = 0;

	printf("�б��� ���� ������ ���� ������ ��� ���ϱ�\n");

	Person[0] = 95; Person[1] = 80; Person[2] = 92;

	for (i = 0; i < MAX_PERSOM; i++)
	{
		printf("%d��° �л��� ����� : %d\n\n",i+1,Person[i]);
		TotalCountOfKorean += Person[i];
	}
	AverageOfKorean = TotalCountOfKorean / MAX_PERSOM;

	printf("�� �б��� ���� ���� : %d\n",TotalCountOfKorean);
	printf("�� �б��� ���� ��� : %.2f\n",AverageOfKorean);
	_getch();
}
*/



// ���� : ������



/* 31p ����1
#include <stdio.h>
#include <conio.h>

void main()
{
	int a, b;
	scanf("%d%d",&a,&b);

	printf(" a + b : %d\n",a + b);
	printf(" a - b : %d\n",a - b);
	printf(" a x b : %d\n",a * b);
	printf(" a / b : %d\n",a / b);
	printf(" a %% b : %d\n",a % b);
	printf(" -a : %d\n",-a);
	_getch();
}
*/

/* 31p �������� 1
#include <stdio.h>
#include <conio.h>

void main()
{
	int Age, Day, Year;
	puts("���� �ڽ��� ���̸� �Է�: ");		// "puts" =/= "gets"  printf �� ������ ( ������ �ุ ��� )
	scanf("%d",&Age);
	puts("�� ����� ��� �ͽ��ϱ�? ");
	scanf("%d", &Year);

	Day = (Year-Age)*365;

	printf("%d����� �� %d �� ���ѽ��ϴ�.\n",Year,Day);
	_getch();
}
*/

/* 32p ���� 1-1
#include <stdio.h>
#include <conio.h>

void main()
{
	int age, year;
	int day, time, min, sec;
										// �Էº�
	puts("���� �ڽ��� ���̸� �Է�: ");
	scanf("%d",&age);
	puts("�� ����� ��� �ͽ��ϱ�? ");
	scanf("%d",&year);

	printf("%d������� ������ ���� ����ϸ�...\n",year);
										// �����
	day = (year - age)*365;			// �ϼ� ����
	time = day * 24;				// �ð� ����
	min = time * 60;				// ��   ����
	sec = min * 60;
										// ��º�
	printf("		�ϼ��δ�  : %d ��\n",day);
	printf("		�ð����δ�: %d ��\n",time);
	printf("		�����δ�  : %d ��\n",min);
	printf("		�ʷδ�    : %d ��	....�����ϴ�.",sec);
	_getch();
}
*/

/* 32p ���� 1-2
#include <stdio.h>
#include <conio.h>

void main()
{
	int sec, min, time;
	int Output_sec, Output_min;
											// �Էº�
	puts("�ʸ� �Է��ϼ���.");
	scanf("%d",&sec);
											// �����
	min = sec / 60;
	time = min / 60;

	Output_sec = sec % min;
	Output_min = min % time;
											// ��º�
	printf("%d�ʴ� %d�ð�, %d��, %d���Դϴ�.\n",sec,time,Output_min,Output_sec);
	_getch();
}
*/

/* 32p ���� 1-2 ������
#include <stdio.h>
#include <conio.h>

void main()
{
	int sec, sec1;
	int hour, min;
	puts("��ȯ�� �ʸ� �Է��ϼ���.");
	scanf("%d",&sec);
	sec1=sec;
	hour = sec1 / 3600;
	sec1 = sec1 % 3600;

	min = sec1 / 60;
	sec1 = sec1 % 60;

	printf("%d�ʴ� %d�ð�, %d��, %d���Դϴ�.\n",sec,hour,min,sec1);
	_getch();
}
*/

/* 32p ���� 1-3
#include <stdio.h>
#include <conio.h>

void main()
{
	int distance, speed, result, rest;
											// �Էº�
	puts("�Ÿ�(km): ");
	scanf("%d",&distance);
	puts("�ӵ�(km/h): ");
	scanf("%d",&speed);

	printf("%d(km)�� %d(km/h)�� �޸���...\n",distance,speed);
											// �����
	result = distance / speed;			// �ҿ�ð�
	rest = distance % speed;			// ������ �Ÿ�
											// ��º�
	printf("%d�ð��� �ҿ�ǰ�, %d(km)�� �����ϴ�.\n",result,rest);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a = 10;
	int b = 5;

	printf(" a > b�� %d�Դϴ�.\n",a>b);
	printf(" a < b�� %d�Դϴ�.\n",a<b);
	printf(" a == b�� %d�Դϴ�.\n",a==b);
	printf(" a != b�� %d�Դϴ�.\n",a!=b);
	_getch();
}
*/

/* 34p ����3
#include <stdio.h>
#include <conio.h>

void main()
{
	short a = 1;
	short b = 2;
	short c = 3;
	printf("(a > b) && (b < c) = %d \n",(a > b) && (b < c));
	printf("(a < b) && (b < c) = %d \n",(a < b) && (b < c)); 
	printf("(a > b) || (b > c) = %d \n",(a > b) || (b > c)); 
	printf("(a > b) || (b < c) = %d \n",(a > b) || (b < c)); 
	printf("!(a > b) = %d \n",!(a > b));
	_getch();
}
*/

/* 34p ����4
#include <stdio.h>
#include <conio.h>

void main()
{
	short a = 1, b = 2;
	a>=b ? puts("a�� B���� Ů�ϴ�") : puts("b�� a���� Ů�ϴ�.");
	_getch();
}
*/

/* 35p ����5
#include <Stdio.h>
#include <conio.h>

void main()
{
	short a = 1, b = 2;
	short Max = 0;

	Max = (a>=b) ? a: b;

	printf(" a=%d. b=%d �� ���� ū ���� %d�Դϴ�. \n",a,b,Max);
	_getch();
}
*/