// ��¥ : 2014 / 04 / 02
// ���� : ������
// ���� : ������

/* 35p �������� 2
#include <stdio.h>
#include <conio.h>

void main()
{
	int num;

	printf("������ �ϳ� �Է��ϼ��� \n");
	scanf("%d",&num);

	(num < 0) ?
		printf("%d�� ���밪�� %d�Դϴ�.\n",num,-num) :
		printf("%d�� ���밪�� %d�Դϴ�.\n",num,num);
	_getch();
}
*/

/* 36p ���� 2-1
#include <stdio.h>
#include <conio.h>

void main()
{
	int num, num2;
	int result, result2;

	printf("�ΰ��� ���� �Ʒ��� ���� ���·� �Է��ϼ���.\n��) 10 20\n");
	scanf("%d %d",&num,&num2);

	result = num - num2;
	result2 = num2 - num;

	(num < num2) ?
		printf("�Է��� �� ������ ���� ���̴� = %d",result2) :
		printf("�Է��� �� ������ ���� ���̴� = %d",result);
	_getch();
}
*/

/* 36p ���� 2-2
#include <stdio.h>
#include <conio.h>

void main()
{
	int num;

	printf("�ϳ��� ���� �Է��ϼ���.");
	scanf("%d",&num);

	(num%2 == 1) ?				// �������� 1�϶� Ȧ��, 0�϶� ¦�� ���
		printf("Ȧ���Դϴ�.\n") :
		printf("¦���Դϴ�.\n");
	_getch();
}
*/

/* 36p ���� 2-3
#include <stdio.h>
#include <conio.h>

void main()
{
	int num,num2;
	int result,result2;
	char code;

	printf("�� ���� ���� �Է��ϼ���. (�� :20 30)\n");
	scanf("%d %d",&num,&num2);
	fflush(stdin);					// ���� �����

	printf("���� ��ȣ�� �Է��ϼ���. (+ Ȥ�� - �Է�)\n");
	scanf("%c",&code);

	result = num-num2;
	result2 = num+num2;

	(code == '-') ?
		printf("%d - %d = %d\n",num,num2,result) :
		printf("%d + %d = %d\n",num,num2,result2);
	_getch();
}
*/

/* 36p ���� 2-4
#include <stdio.h>
#include <conio.h>

void main()
{
	char Alphabat, result, result2;

	printf("���ĺ� �ϳ��� �Է��ϼ���.\n(����, Ư�����ڴ� �Է��� �� �����ϴ�)\n");
	scanf("%c",&Alphabat);

	result = Alphabat + 32;
	result2 = Alphabat - 32;

	(Alphabat < 'a') ?
		printf("��� => %c",result) :
		printf("��� => %c",result2);
	_getch();
}
*/

/* 36p ���� 2-5 �������
#include <stdio.h>
#include <conio.h>

void main()
{
	char data;
	char result, result2;

	printf("���ĺ� �ϳ��� �Է��ϼ���.\n");
	printf("�Է� => ");
	scanf("%c",&data);

	data = ((data >= 'A') && (data <= 'Z')) ? data + ('a' - 'A') :
		   ((data >= 'a') && (data <= 'z')) ? data - ('a' - 'A') : data;

	printf("��� => %c\n",data);
	_getch();
}
*/


// ���� : ���� ������


/* ���� 1
#include <stdio.h>
#include <conio.h>

void main()
{
	int i = 1;

	printf("i�� �ʱⰪ�� %d\n",i);

	i++;

	printf("i++ ���� ���� %d\n",i);

	i--;

	printf("i-- ���� ���� %d\n",i);
	_getch();
}
*/

/* ���� 2
#include <stdio.h>
#include <conio.h>

void main()
{
	int a = 10, b = 10;

	printf("a++�� ���� : %d\n", a++);
	printf("a�� ���� : %d\n",a);
	printf("++a�� ���� : %d\n",++a);

	printf("\n");

	printf("b--�� ���� : %d\n",b--);
	printf("--b�� ���� : %d\n",--b);
	_getch();
}
*/

/* 38p ����8
#include <stdio.h>
#include <conio.h>

void main()
{
	int i=10, j=13;							// 10 = 1010, 13 = 1101
	
	printf("i & j �� ��: %d \n",i&j);		// 1000 = 8
	printf("i | j �� ��: %d \n",i|j);		// 1111 = 15
	printf("i ^ j �� ��: %d \n",i^j);		// 0111 = 7
	printf("~ i �� ��: %d \n",~i);			// 0101 = -11
	_getch();
}
*/