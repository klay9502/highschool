// ���� : ������ ���빮��
// ��¥ : 2014 / 4 / 10
// ���� : ������

// �ƽ�Ű�ڵ带 �̿��ϵ�, �ҹ��ڸ� �̿����� �ʰ� �ҹ����� �������� ����Ͻÿ�.

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	printf("%-14s%s\n","�빮��","�ҹ���");
	printf("----------------------------\n");
	printf("A = %-10da = %d\n",'A','A'+32);
	printf("E = %-10de = %d\n",'E','E'+32);
	printf("I = %-10di = %d\n",'I','I'+32);
	printf("O = %-10do = %d\n",'O','O'+32);
	printf("U = %-10du = %d\n",'U','U'+32);
	printf("----------------------------\n");
	_getch();
}
*/

// ������ �����Ը� ���� �����Է� ȯ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	float earth_w;		// ���� ������
	float moon_w;			// �� ������
				// �޿����� ������ = ���������� �������� 12%
	printf("���� ������ :");
	scanf("%f",&earth_w);

	moon_w = earth_w * 0.17;

	printf("��   ������ : %.2f\n",moon_w);
	_getch();
}
*/

// ������ 5�� ���� ���� �� �� ������ ���� ���ϼ���.

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num;
	int quo,rem;

	printf("����   : ");
	scanf("%d",&num);

	quo = num / 5;
	rem = num % 5;

	printf("��     : %d\n",quo);
	printf("������ : %d",rem);
	_getch();
}
*/

// 1������ 30�Ϸ� ���������� �� ���� ������ ȯ���ϴ� ���α׷��� ����ÿ�.


#include <stdio.h>
#include <conio.h>

void main()
{
	int day;
	int month, rem_day;
				// 30�� = 1����
	printf("���� : ");
	scanf("%d",&day);

	month = day / 30;
	rem_day = day % 30;

	printf("��� : %d���� %d��\n",month,rem_day);
	_getch();
}