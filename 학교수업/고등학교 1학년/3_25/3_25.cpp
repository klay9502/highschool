//�ۼ���¥	: 2014.3.25
//�ۼ�����	: 
//�ۼ���		: ������

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int Number;
	int Age;

	int Person1, Person2;

	int Page = 10;
	int Page1 = 10, Page2 = 20;

	Person1 = Person2 = 100;

	printf("Person1 : %d, Person2 : %d,Page : %d, Page1 : %d,Page2 : %d\n",Person1,Person2,Page,Page1,Page2);

	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	float a = 1.123456789123456789;			// float ��
	double b = 1.123456789123456789;		// double ��
	printf("a�� ��� ��� : %1.20G\n",a);
	printf("b�� ��� ��� : %1.20G\n",b);	// �Ҽ��� 20�ڸ� ���
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	float a = 10.0;
	double b = 10.0;

	int i = 0;
	while(i<10)
	{
		a = a/3.0;
		b = b/3.0;
		printf("float ���� ��� ��� : %1.20G\n\n",a);
		printf("double ���� ��� ��� : %1.20G\n\n",b);
		i ++;
	}
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char a = 'A';

	printf("������ a�� ���� ǥ�� : %c\n",a);
	printf("������ a�� ���� ǥ�� : %d\n",a);
	printf("������ a�� 16���� ǥ�� : %x\n\n",a);

	a=a+1;
	printf("������ a�� ���� ǥ�� : %c\n",a);
	printf("������ a�� ���� ǥ�� : %d\n",a);
	printf("������ a�� 16���� ǥ�� : %x\n\n",a);
	_getch();
}
*/

/*	========�����÷ο� ����==========
#include <stdio.h>
#include <conio.h>

void main()
{
	short a = 32767;
	short b = -32768;
	printf("%d \n",sizeof(short));
	printf("a= %d \n",a);
	printf("a+1=%d\n",a=a+1);
	printf("b= %d \n",b);
	printf("b-1=%d\n",b=b-1);
	_getch();
}
*/	

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	short a = 32767;
	unsigned short b = 32767;

	printf("a+1 = %d\n",a=a+1);
	printf("b+1 = %d\n",b=b+1);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char a='A';
	int b=1,c;

	c=a+b;

	printf("c=%d\n",c);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	float a=6.7;
	int b=10,c;

	c=(int)a+b;

	printf("%d\n",c);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	float mileage,speed,time;
	int hour,min;

	mileage=600;
	speed=7;

	time = mileage/speed;	// 85.714287
	hour = (int)time;
	time = time - hour;		// 0.714287

	time = time * 60;
	min = (int)time;
	time = time - min;
	time = time * 60;


	printf("�Ÿ� :%d\n",(int)mileage);
	printf("�ӷ� :%d\n",(int)speed);
	printf("�ɸ��� �ð��� : %d�ð�, %d��, %0.2f���Դϴ�.\n",hour,min,time);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	float hour = 0.456;
	int min;

	hour = hour * 60;
	min = (int)hour;
	hour = hour - min;

	printf("0.456�ð��� %d�� %d�ʿ� �����ϴ�.",min,(int)(hour*60));
	_getch();
}
*/

#include <stdio.h>
#include <conio.h>

void main()
{
	int num1;
	float num2;
	char name;
	char array[20];
	printf("������ �Է��ϼ���.\n");
	scanf("%d",&num1);

	printf("�Ǽ��� �Է��ϼ���.\n");
	scanf("%f",&num2);
	fflush(stdin);

	printf("1���� ���ڸ� �Է��ϼ���.\n");
	scanf("%c",&name);
	fflush(stdin);

	printf("���ڿ��� �Է��ϼ���.\n");
	scanf("%s",array);
	fflush(stdin);

	printf("������=%d, �Ǽ���=%f, ���� =%c, ���ڿ�=%s�� �ԷµǾ����ϴ�.\n",num1,num2,name,array);
	_getch();
}