//	Today 2014 / 05 / 13
//
//
//
//
//
//	Created by 'Kim Jong Min'
//
//

// p57 ����8 

//#include <stdio.h>
//#include <conio.h>
//
//int main(void)
//{
//	int i = 0;
//	int j = 1;
//
//	while (j)
//	{
//		printf("Hello! \n");
//		printf("My name is KJM!\n");
//		i++;
//
//		if (i == 10)
//			j = 0;
//	}
//	_getch();
//	return 0;
//}

// p57 ����9 

//#include <stdio.h>
//#include <conio.h>
//
//int main(void)
//{
//	int i;
//	int sum = 0;
//
//	printf("Ű����� �Էµ� ���� ���� ���ϱ�\n");
//	printf("�Է��� �������� ^Z�� ��������.\n");
//
//	while (scanf("%d",&i) != EOF)
//	{
//		sum = sum + i;
//	}
//	printf("�� �� = %d\n",sum);
//
//	_getch();
//	return 0;
//}

// p58 ���� ����5 

//#include <stdio.h>
//#include <conio.h>
//
//int main(void)
//{
//	int num, count = 1, i = 1;
//
//	while (i)
//	{
//		printf("������ �Է����ּ���. :");
//		scanf("%d",&num);
//		if (num > 0)
//			i = 0;
//		else
//			puts("������ �Է� ����. ���Է��ϼ���.");
//	}
//	while (num > 0)
//	{
//		printf("%d ",num);
//		num--;
//		count++;
//		if (count%10 == 1)
//		{
//			putchar('\n');
//			count = 1;
//		}
//	}
//	_getch();
//	return 0;
//}

// p59 �������� 5-1

//#include <stdio.h>
//#include <stdlib.h>
//#include <conio.h>
//#include <time.h>
//
//int main(void)
//{
//	int p_num,c_num;
//	int i = 1;
//
//	printf("����, ����, �� ����\n");
//	srand(time(NULL));
//
//	while (i)
//	{
//		printf("���� = 0, ���� = 1, �� =  2 �� �Է��ϼ��� : ");
//		scanf("%d",&p_num);
//
//		c_num = rand()%3;
//
//		switch (c_num) {
//		case 0:
//			printf("com = ����, ");
//			break;
//		case 1:
//			printf("com = ����, ");
//			break;
//		case 2:
//			printf("com = ��, "); }
//
//		switch (p_num) {
//		case 0:
//			printf("user = ����");
//			break;
//		case 1:
//			printf("user = ����");
//			break;
//		case 2:
//			printf("user = ��"); }
//
//		if (c_num == 0)		// ��ǻ�Ͱ� ������ ��
//		{
//			switch (p_num) {
//			case 0:
//				printf("tie\n");
//				printf("replay\n");
//				break;
//			case 1:
//				printf("user win\n");
//				i = 0;
//				break;
//			case 2:
//				printf("computer win\n");
//				printf("replay\n"); }
//		}
//
//		if (c_num == 1)		// ��ǻ�Ͱ� ������ ��
//		{
//			switch (p_num) {
//			case 0:
//				printf("computer win\n");
//				printf("replay\n");
//				break;
//			case 1:
//				printf("tie\n");
//				printf("replay\n");
//				break;
//			case 2:
//				printf("user win\n");
//				i = 0; }
//		}
//
//		if (c_num == 2)		// ��ǻ�Ͱ� ���� ��
//		{
//			switch (p_num) {
//			case 0:
//				printf("user win\n");
//				i = 0;
//				break;
//			case 1:
//				printf("computer win\n");
//				printf("replay\n");
//				break;
//			case 2:
//				printf("tie\n");
//				printf("replay\n");
//				break; }
//		}
//	}
//	_getch();
//	return 0;
//}

 /*p59 �������� 5-2*/

//#include <stdio.h>
//#include <conio.h>
//#include <stdlib.h>
//#include <time.h>
//
//int main(void)
//{
//	int dice1,dice2,sum;
//	int i = 1;
//	char j;
//
//	srand(time(NULL));
//
//	while (i)
//	{
//		dice1 = rand()%6+1;
//		dice2 = rand()%6+1;
//
//		printf("�ֻ���1 = %d, �ֻ���2 = %d",dice1,dice2);
//
//		sum = dice1 + dice2;
//
//		printf("�� �� = %d\n",sum);
//		
//		printf("��� �Ͻðڽ��ϱ�? y or n :"); scanf("%c",&sum);	fflush(stdin);
//		if (sum == 'n')
//			i = 0;
//	}
//	_getch();
//	return 0;
//}

// p59 �������� 5-3

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int num, j=2;
	int i = 1;

	printf("number :");	scanf("%d",&num);

	while (num != 0)
	{
		if (num % j == 0)//6
		{
			printf("%d*",j);
			num = num / j;
		}
		else if (num % j != 0)
		{
			j++;
		}
	}
	printf("%d",j);
	_getch();
	return 0;
}
*/