//	Today 2014 / 05 / 13
//
//
//
//
//
//	Created by 'Kim Jong Min'
//
//

// p57 예제8 

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

// p57 예제9 

//#include <stdio.h>
//#include <conio.h>
//
//int main(void)
//{
//	int i;
//	int sum = 0;
//
//	printf("키보드로 입력된 값의 총합 구하기\n");
//	printf("입력을 끝내려면 ^Z를 누르세요.\n");
//
//	while (scanf("%d",&i) != EOF)
//	{
//		sum = sum + i;
//	}
//	printf("총 합 = %d\n",sum);
//
//	_getch();
//	return 0;
//}

// p58 연습 문제5 

//#include <stdio.h>
//#include <conio.h>
//
//int main(void)
//{
//	int num, count = 1, i = 1;
//
//	while (i)
//	{
//		printf("정수를 입력해주세요. :");
//		scanf("%d",&num);
//		if (num > 0)
//			i = 0;
//		else
//			puts("음수를 입력 오류. 재입력하세요.");
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

// p59 실전문제 5-1

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
//	printf("가위, 바위, 보 게임\n");
//	srand(time(NULL));
//
//	while (i)
//	{
//		printf("가위 = 0, 바위 = 1, 보 =  2 를 입력하세요 : ");
//		scanf("%d",&p_num);
//
//		c_num = rand()%3;
//
//		switch (c_num) {
//		case 0:
//			printf("com = 가위, ");
//			break;
//		case 1:
//			printf("com = 바위, ");
//			break;
//		case 2:
//			printf("com = 보, "); }
//
//		switch (p_num) {
//		case 0:
//			printf("user = 가위");
//			break;
//		case 1:
//			printf("user = 바위");
//			break;
//		case 2:
//			printf("user = 보"); }
//
//		if (c_num == 0)		// 컴퓨터가 가위일 때
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
//		if (c_num == 1)		// 컴퓨터가 바위일 때
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
//		if (c_num == 2)		// 컴퓨터가 보일 때
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

 /*p59 실전문제 5-2*/

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
//		printf("주사위1 = %d, 주사위2 = %d",dice1,dice2);
//
//		sum = dice1 + dice2;
//
//		printf("총 합 = %d\n",sum);
//		
//		printf("계속 하시겠습니까? y or n :"); scanf("%c",&sum);	fflush(stdin);
//		if (sum == 'n')
//			i = 0;
//	}
//	_getch();
//	return 0;
//}

// p59 실전문제 5-3

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