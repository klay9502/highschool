// ��¥ : 2014 / 04 / 03
// ���� : �迭
// ���� : ������

// 104p ����1 - ������ �迭�� �ʱ�ȭ1
/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i;
	int k[5];

	k[0] = 10; k[1] = 20; k[2] = 30; k[3] = 40; k[4] = 50;
							// k�迭�� ���� �ʱⰪ ����
	for (i=0;i<5;i++)
		printf("k[%d] = %d\n",i,k[i]);
	_getch();
}
*/

// 105p ����2 - ������ �迭�� �ʱ�ȭ2
/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i, sum=0;
	int k[6] = {10,20,30,40,50,60};
							// k�迭 ����� �Բ� �ʱⰪ ����
	for (i=0;i<6;i++)
	{
		sum += k[i];		// �ʱⰪ�� ����
		printf("sum = %d\n",sum);
	}
	_getch();
}
*/

// 105p ����3 - ������ �迭�� �ʱ�ȭ3
/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i;
	int k[6] = {10,20,30};
							// k�迭 ����� �Բ� �ʱⰪ ����
	for (i=0;i<6;i++)
		printf("k[%d] ==> %d\n",i,k[i]);
	_getch();
}
*/

// 105p ����4 - ������ �迭�� �ʱ�ȭ4
/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i, sum=0;
	int data[] = {1,2,3,4,5,6,7,8,9,10};
							// ÷�� ��� ����
	for (i=0;i<10;i++)
	{
		if(data[i] % 2 == 0)		// �ʱ�ȭ�� �� �� ¦������ ����
			sum += data[i];
	}
	printf("2 + 4 + ... + 8 + 10 = %d\n", sum);
	_getch();
}
*/

// 106p ����5 - ������ �迭�� ������ �Է�1

#include <stdio.h>
#include <conio.h>

void main()
{
	int k, i, a[10];

	printf("data input !\n");
	i = 0;

	while(scanf("%d", &a[i]) != EOF)		// Ű���忡�� �迭���ҿ� ������ �Է�
		i++;								// �Է� ����� ^z
	for (k=0;k<i;k++)
		printf("a[%d] = %d\n",k,a[k]);
	_getch();
}