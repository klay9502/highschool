// ���� : ������ ���빮��
// ��¥ : 2014 / 4 / 14
// ���� : ������

// 700MBũ���� �����ϳ��� �ٿ�޴µ� �ɸ��� �ð��� ���Ͻÿ�.

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int KBspeed;
	int hour,min,sec;

	printf("���� �ӵ�(KB) : ");
	scanf("%d",&KBspeed);

	sec = (700*1024) / KBspeed;
	min = (sec / 60) % 60;
	hour = ((sec / 60) % min) % 24;			// ����
	sec = sec % 60;

	printf("�ҿ�ð� : %d�ð� %d�� %d��",hour,min,sec);
	_getch();
}
*/

// 3�� ���� ���⿹���� ���ڰ� 5%�� ���, 1000������ 3�⵿�� ���⿹�ݿ� �־�θ�, ���� �� �Ѿ���?

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int money,plus;
	int sum;

	money = 10000000;

	plus = (money * 0.05) * 3;

	sum = money + plus;

	printf("���ݾ� : %10d\n",money);
	printf("���ھ� : %10d\n",plus);
	printf("����� : %10d\n",sum);
	_getch();
}
*/

// ���� : ���

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

// �������� 1

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num;

	printf("������ �ϳ� �Է��ϼ���.\n");
	scanf("%d",&num);
	if (num >= 0)
		printf("����� �Է��ϼ̽��ϴ�.\n");
	else
		printf("������ �Է��ϼ̽��ϴ�.\n");
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