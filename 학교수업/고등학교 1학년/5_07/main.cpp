//	Today 2014 / 05 / 07
//
//
//	'�ݺ���'
//
//
//	Created by 'Kim Jong Min'
//
//

// ���� 6
/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i = 0, j = 1;

	while (i < 10)
	{
		printf("%d��° ���� : i = %d \n",j,i);
		i++;
		j++;
	}
	_getch();
}
*/

// ���� 7
/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char alpha = 'a';

	while (alpha <= 'z')
	{
		printf("%c",alpha);
		alpha++;
	}
	printf("\n");
	_getch();
}
*/
// p56 ����4-1
/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int pf_num,pf_num2;
	int num, num2;
	int result = 0;

	printf("�� ���� ������ �Է����ּ���.\n");
	printf("���� 1 :");	scanf("%d",&num);
	printf("���� 2 :");	scanf("%d",&num2);

	pf_num = num;
	pf_num2 = num2;

	if (num > num2)			// ���� 1�� �� Ŭ ���
	{
		result = num;
		while (num > num2)
		{
			result += num2;
			num2++;
		}
		printf("%d �̻� %d ������ ��� ������ ���� %d �Դϴ�.\n",pf_num2,pf_num,result);
	}
	else					// ���� 2�� �� Ŭ ���� �� ���� ���� ���
	{
		result = num2;
		while (num2 > num)
		{
			result += num;
			num++;
		}
		printf("%d �̻� %d ������ ��� ������ ���� %d �Դϴ�.\n",pf_num,pf_num2,result);
	}
	_getch();
	return 0;
}
*/

// p56 ���� 4-2

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int i = 1, result;
	int num;

	printf("���� �Է�: ");	scanf("%d",&num);

	while (i < num+1)
	{
		result = 3*i;
		printf("3 x %d = %d\n",i,result);
		i++;
	}
	_getch();
	return 0;
}
*/

// p56 ���� 4-3

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int i = 1, result;
	int num;

	printf("������ ��� ���α׷�\n");
	printf("�� ��? ");	scanf("%d",&num);

	while (i < 10)
	{
		result = num*i;
		printf("%d x %d = %d\n",num,i,result);
		i++;
	}
	_getch();
	return 0;
}
*/

// p56 ���� 4-4

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int i = 1, result;
	int num;

	printf("������ ��� ���α׷�\n");
	printf("�� ��? ");	scanf("%d",&num);

	while (i < 10)
	{
		result = num*i;
		printf("%d x %d = %d\n",num,i,result);
		i++;
	}

	printf("\n���� ���\n");

	i = 9;

	while (i > 0)
	{
		result = num*i;
		printf("%d x %d = %d\n",num,i,result);
		i--;
	}
	_getch();
	return 0;
}
*/