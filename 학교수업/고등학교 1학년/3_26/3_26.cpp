// ��¥ : 2014/03/26
// ���� : scanf Ȱ��
// �̸� : ������

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a,b;		// a=�غ�,b=����

	printf("�غ��Է�: ");
	scanf("%d",&a);
	printf("�����Է�: ");
	scanf("%d",&b);
	printf("�ﰢ���� ���̴� %d�Դϴ�.\n",a*b/2);
	_getch();
}
*/

/* 26p 3-1
#include <stdio.h>
#include <conio.h>

void main()
{
	int num;

	printf("�����Է�: ");
	scanf("%d",&num);
	printf("�� ������ 10�� ���� %d�Դϴ�.",num-10);
	_getch();
}
*/

/* 26p 3-2
#include <stdio.h>
#include <conio.h>

void main()
{
	float num;

	printf("���� �������� �Է��ϼ���: ");
	scanf("%f",&num);
	printf("���� ����: %0.2f ����: %0.2f",(float)num*num*3.14,(float)num*2*3.14);
	_getch();
}
*/

/* 26p 3-3
#include <stdio.h>
#include <conio.h>

void main()
{
	float A,B;

	printf("�� ���� ������ �Է����ּ���.\n");
	printf("���� A:");
	scanf("%f",&A);
	printf("���� B:");
	scanf("%f",&B);
	printf("A�� ���� B�� %0.0f %%�Դϴ�.",A/B*100);
	_getch();
}
*/

/* 27p 3-4
#include <stdio.h>
#include <conio.h>

void main()
{
	int M,K,E;		// M = ����, K = ����, E = ����

	printf("�������� :");
	scanf("%d",&M);
	printf("�������� :");
	scanf("%d",&K);
	printf("�������� :");
	scanf("%d",&E);
	printf("���� : %d ��� : %.2f\n",(M+K+E),(float)(M+K+E)/3);
	_getch();
}
*/

/* 27p 3-5
#include <stdio.h>
#include <conio.h>

void main()
{
	char code;

	printf("���ڸ� �Է��ϼ���: ");
	scanf("%c",&code);
	printf("���� %c�� �ƽ�Ű�ڵ尪�� %d�Դϴ�.",code,code);
	_getch();
}
*/

/* 27p 3-6
#include <stdio.h>
#include <conio.h>

void main()
{
	float height,result;

	printf("Ű�� �Է��ϼ���: ");
	scanf("%f",&height);

	result = (height-100)*0.9;

	printf("ǥ�� ü���� %0.1f�Դϴ�.",result);
	_getch();
}
*/

/* 27p 3-7
#include <stdio.h>
#include <conio.h>

void main()
{
	float weight,height,result;

	printf("������: ");
	scanf("%f",&weight);
	printf("Ű: ");
	scanf("%f",&height);

	result = weight/(height*height);

	printf("BMI ���� : %f",result);
	_getch();
}
*/

/* 27p 3-8
#include <stdio.h>
#include <conio.h>

// �⺻�� : 13000��
// 10�ʴ� 10���� ��� �ΰ�
// �� �ݾ��� 5%�� �������� �߰� ¡��

void main()
{
	int sec,plusmoney,money,tax;

	printf("�� �ʵ��� �޴����� ����ϼ̽��ϱ�?\n");
	scanf("%d",&sec);

	plusmoney=sec*0.1;
	plusmoney=plusmoney*10;		// �߰���� ���

	money=13000+plusmoney;		// �߰���� + �⺻���
	tax=money*0.05;				// 5% ����

	money = money + tax;		// �ջ�

	printf("�̹��� ����Ͻ� �޴��� ����� %d���Դϴ�.",money);
	_getch();
}
*/

/* 27p 3-9
#include <stdio.h>
#include <conio.h>

void main()
{
	int money,coke,soda,power,change,allmoney;
	int cokenum,sodanum,powernum;
	int Fcoin,Hcoin,FHcoin;			// Fcoin = 50��, Hcoin = 100��, FHcoin = 500��

	printf("================================================================\n");
	printf("���Ǳ����α׷��Դϴ�. �ݶ�700��,���̴�550��,�Ŀ����̵�1000���Դϴ�.\n");
	printf("================================================================\n\n");

	printf("�ݾ��� �����ϼ���. :");
	scanf("%d",&money);
	printf("�ݶ� �� ��?\n");
	scanf("%d",&coke);
	printf("���̴� �� ��?\n");
	scanf("%d",&soda);
	printf("�Ŀ����̵� �� ��?\n");
	scanf("%d",&power);

	cokenum = 700 * coke;									// �ݶ��� �� ����
	sodanum = 550 * soda;									// ���̴��� �� ����
	powernum = 1000 * power;								// �Ŀ����̵��� �� ����


	allmoney = cokenum + sodanum + powernum;				// ������ �� ����
	change = money - allmoney;								// �ܵ�

	FHcoin = change/500;									// 500�� �ܵ�
	Hcoin = (change-FHcoin*500)/100;							// 100�� �ܵ�
	Fcoin = (change-FHcoin*500-Hcoin*100)/50;				// 50�� �ܵ�

	printf("\n�ѱ��Աݾ���%d���Դϴ�. �Ž����� %d����\n",allmoney,change);
	printf("500��¥��%d��,100��¥��%d��,50��¥��%d���� �帳�ϴ�.",FHcoin,Hcoin,Fcoin);
	_getch();
}
*/

/* 28p 3-10
#include <stdio.h>
#include <conio.h>

void main()
{
	unsigned int nowage,wantage;				// ���� ����
	unsigned int days,time,min,sec;				// �ð� ����
													// �����÷ο츦 �����Ͽ� 'unsigned int'�� ���.
	printf("���� ��� ���̴� ����Դϱ�?");
	scanf("%d",&nowage);
	printf("�� ����� ��� �ͽ��ϱ�?");
	scanf("%d",&wantage);

	days = (wantage - nowage) * 365;				// ��¥
	time = days * 24;							// �ð�
	min = time * 60;							// ��
	sec = min * 60;								// ��

	printf("��¥�δ� %d��, �ð����δ� %d�ð�,\n�����δ� %d��, �ʷδ� %d�� ���ҽ��ϴ�.\n",days,time,min,sec);
	_getch();
}
*/