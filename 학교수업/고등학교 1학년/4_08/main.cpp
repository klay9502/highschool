//============================
//Today...2014 / 04 / 08
//Subject...'Operator'
//Make by...������
//============================

// 38p ����9

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i = 10;			// 10 = 00000000000010110
	
	printf("i << 2�� �� : %d\n",i<<2);		// 101000 = 40
	printf("i >> 2�� �� : %d\n",i>>2);		// 000010 = 2
	_getch();
}
*/

// ������ ����

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a = 0xF0;			// ������ : 11110000
	int b = 0x0F;			// ������ : 00001111

	int c = 0x0A;			// ������ : 00001010
	int d = 0x0B;			// ������ : 00001011

	int e = 0x02;			// ������ : 00000010
	int f = 0x08;			// ������ : 00001000

	printf("a & b�� ����� : %x\n", a&b);
	printf("a | b�� ����� : %x\n\n", a|b);

	printf("c ^ d�� ����� : %x\n",c^d);
	printf("~a�� ����� %x\n\n",~a);

	printf("e<<2�� ����� : %x\n",e<<2);
	printf("f>>2�� ����� : %x\n",f>>2);
	_getch();
}
*/

// 39p ��������3

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int left, right;

	printf("���� ������ ���´� ��մϱ�? ��ȣ: 1, �ҷ�: 0\n�Է�: ");
	scanf("%d",&left);
	printf("������ ������ ���´� ��մϱ�? ��ȣ: 1, �ҷ�: 0\n�Է�: ");
	scanf("%d",&right);

	(left & right)==1 ? puts("������ ���� ���Խ��ϴ�~"):
						puts("���� �ҷ����� ���� ���� �� �����ϴ�.");
	_getch();
}
*/