//	Today 2014 / 05 / 07
//
//
//	'반복문'
//
//
//	Created by 'Kim Jong Min'
//
//

// 예제 6
/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i = 0, j = 1;

	while (i < 10)
	{
		printf("%d번째 실행 : i = %d \n",j,i);
		i++;
		j++;
	}
	_getch();
}
*/

// 예제 7
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
// p56 예제4-1
/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int pf_num,pf_num2;
	int num, num2;
	int result = 0;

	printf("두 개의 정수를 입력해주세요.\n");
	printf("정수 1 :");	scanf("%d",&num);
	printf("정수 2 :");	scanf("%d",&num2);

	pf_num = num;
	pf_num2 = num2;

	if (num > num2)			// 정수 1이 더 클 경우
	{
		result = num;
		while (num > num2)
		{
			result += num2;
			num2++;
		}
		printf("%d 이상 %d 이하의 모든 정수의 합은 %d 입니다.\n",pf_num2,pf_num,result);
	}
	else					// 정수 2이 더 클 경우와 두 수가 같을 경우
	{
		result = num2;
		while (num2 > num)
		{
			result += num;
			num++;
		}
		printf("%d 이상 %d 이하의 모든 정수의 합은 %d 입니다.\n",pf_num,pf_num2,result);
	}
	_getch();
	return 0;
}
*/

// p56 예제 4-2

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int i = 1, result;
	int num;

	printf("정수 입력: ");	scanf("%d",&num);

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

// p56 예제 4-3

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int i = 1, result;
	int num;

	printf("구구단 출력 프로그램\n");
	printf("몇 단? ");	scanf("%d",&num);

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

// p56 예제 4-4

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int i = 1, result;
	int num;

	printf("구구단 출력 프로그램\n");
	printf("몇 단? ");	scanf("%d",&num);

	while (i < 10)
	{
		result = num*i;
		printf("%d x %d = %d\n",num,i,result);
		i++;
	}

	printf("\n역순 찍기\n");

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