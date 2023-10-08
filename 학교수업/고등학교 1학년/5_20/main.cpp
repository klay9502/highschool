// p67 8-2

//#include <stdio.h>
//#include <conio.h>
//
//void main()
//{
//	int i;
//	int num;
//	int three = 0,seven = 0;
//	int t_result = 0,s_result = 0;
//
//	puts("3의 배수, 7의 배수의 총합. 1부터 어디까지 수 중에?");
//
//	scanf("%d", &num);
//
//	for (i = 1; i <= num; i++)
//	{
//		three++;
//		seven++;
//		if (i % 3 == 0)
//			t_result += three;
//		if (i % 7 == 0)
//			s_result += seven;
//	}
//	printf("1부터 %d까지 3의 배수는 총합 %d, 7의 배수 총합 %d 입니다.\n",num,t_result,s_result);
//	_getch();
//}

// p67 8-3

//#include <stdio.h>		// made by 상추
//#include <conio.h>
//
//int main(void)
//{
//	int num,num2; //입력받을 num과  num2를 변수로 선언
//	int i;//for문에서 돌릴 i를 선언
//
//	printf("1부터 100까지의 수 중에서 공배수 구하기\n");
//	printf("배수1:");
//	scanf("%d", &num);
//	printf("배수2:");
//	scanf("%d", &num2);//입력받기
//
//	for(i=1; i<=100; i++)//1부터 100까지이므로 i를 1로 초기화하고 100까지 +1씩해서 돌리기
//	{
//		if(i%num==0 && i%num2==0)//만약에 i가 num과 num2로 나눠지면 공배수라는 것이므로
//		{
//			printf("%d와 %d의 공배수 : %d\n",num,num2,i);//요로코롬 출력하기
//		}
//	}
//	_getch();
//}

// p67 8-4

//#include <stdio.h>		// made by 상추
//#include <conio.h>
//
//int main(void)
//{
//	int num,num2; //입력받은 num,num2를 변수로 두고
//	int i,inum; //for문에서 돌릴 i와 num,num2를 비교해서 작은 수를 넣을 inum(for문에서 조건으로 둘것)
//
//	printf("약수를 구할 두 정수를 입력하세요\n");
//	printf("입력1:");
//	scanf("%d",&num);
//	printf("입력2:");
//	scanf("%d", &num2);//입력받기
//
//	printf("공약수:");//미리 출력하기
//
//	if(num<num2)
//	{
//		inum=num;
//	}
//	else;
//	{
//		inum=num2;
//	}
//	//공배수라는 것이 결국 공통이어야되므로 for문을 돌릴 횟수를 최대한 줄이기 위해
//	//num과 num2를 비교해서 작은 수를 조건으로 두고 돌리기 위해 비교하고 작은 값을 inum에 대입
//
//	for(i=1; i<=inum; i++)//i를 1로 두고 작은num(inum)까지 돌리기
//	{
//		if(num%i==0 && num2%i==0)//만약 i가 num과 num2로 다 나눠진다면
//		{
//			printf("%4d", i);//i가 공배수라는 것이므로 i출력
//		}
//	}
//	printf("\n");
//}

// ppt 예제

//#include <stdio.h>
//#include <conio.h>
//
//void main()
//{
//	int TotalNumber, InputNumber;
//	int i,j;
//
//	printf("1부터 덧셈하는 프로그램입니다.\n");
//	printf("마지막 값을 입력하세요. \n");
//	printf("1 부터 -> ");
//	scanf("%d",&InputNumber);
//
//	printf("1부터 %d까지 덧셈합니다.\n", InputNumber);
//
//	TotalNumber = 0;
//	i = 1;
//	for (; i <= InputNumber; i++)
//	{
//		TotalNumber += i;
//		printf("TotalNumber의 값 : %d\n",TotalNumber);
//	}
//	printf("\n1부터 %d까지의 총합은 %d입니다.\n", InputNumber,TotalNumber);
//	_getch();
//}

//#include <stdio.h>
//#include <conio.h>
//
//void main()
//{
//	int TotalNumber, InputNumber;
//	int i,j;
//
//	printf("1부터 덧셈하는 프로그램입니다.\n");
//	printf("마지막 값을 입력하세요. \n");
//	printf("1 부터 -> ");
//	scanf("%d",&InputNumber);
//
//	printf("1부터 %d까지 덧셈합니다.\n", InputNumber);
//
//	TotalNumber = 0;
//	for (i = 1; i <= InputNumber ; TotalNumber += i++);	// 마지막에 세미콜론 주의
//
//	printf("\n1부터 %d까지의 총합은 %d입니다.\n", InputNumber,TotalNumber);
//	_getch();
//}

//#include <stdio.h>
//#include <conio.h>
//
//void main()
//{
//	int a = 1;
//
//	for (; a <= 2; a++)
//		printf("%2d",a);
//
//	puts("\n야호!");
//
//	for (; a >= 1; a--)
//		printf("%2d",a);
//
//	putchar('\n');
//	_getch();
//}

// p67 8-5

//#include <stdio.h>
//#include <conio.h>
//
//void main()
//{
//	int num1,num2;;
//	int GCM, LCM;	// 최대공약수 및 최소 공배수
//
//	printf("두 정수를 입력하세요.##\n");
//	printf("입력1 :"); scanf("%d",&num1);
//	printf("입력2 :"); scanf("%d",&num2);
//
//	for (int i = 1;; i++)			// 최소공배수 구하기
//	{
//		if (i % num1 == 0 && i % num2 == 0)
//		{
//			GCM = i;
//			break;
//		}
//	}
//
//	for (int i = num1;; i--)			// 최대공약수 구하기
//	{
//		if (num1 % i == 0 && num2 % i == 0)
//		{
//			LCM = i;
//			break;
//		}
//	}
//
//	printf("%d와(과) %d의 최대공약수 : %d, 최소공배수 : %d입니다.",num1,num2,LCM,GCM);
//	_getch();
//}

// p68 8-6

//#include <stdio.h>
//#include <conio.h>
//
//void main()
//{
//	int result = 0;
//	bool code = 0;
//
//	for (int i = 0; i < 100; i++)
//	{
//		if (code == 0)
//		{
//			result += i;
//			code = 1;
//			continue;
//		}
//		else	// 'code'가 '1'일때
//		{
//			result -= i;
//			code = 0;
//			continue;
//		}
//	}
//	printf("1-2+3-4+...+99-100 합계는 %d입니다.",result);
//	_getch();
//}

// p68 8-7

//#include <stdio.h>
//#include <conio.h>
//
//void main()
//{
//	int result = 1;
//	bool code = 0;
//
//	for (int i = 1; i <= 10; i++)
//	{
//		if (code == 0)
//		{
//			printf("%d *",-i);
//			result *= -i;
//			code = 1;
//			continue;
//		}
//		if (code == 1)
//		{
//			printf(" %d ",i);
//			result *= i;
//			code = 0;
//			continue;
//		}
//	}
//	printf("계산결과 : %d",result);
//	_getch();
//}

// p68 8-8

//#include <stdio.h>
//#include <conio.h>
//
//void main()
//{
//	float result = 0;
//
//	for (float i = 1; i <= 100; i++)
//		result += (i / (i + 1));
//	printf("1/2+2/3+3/4+...99/100 합계는 %.1f입니다.\n",result);
//	_getch();
//}

// p68 8-9

//#include <stdio.h>
//#include <conio.h>
//
//void main()
//{
//	int result = 0;
//
//	for (int i = 1; ; i++)
//	{
//		result += i;
//		if (result >= 5000)
//		{
//			printf("5000이 넘는 최초의 N값 => %d\n",i);
//			printf("그때의 합 => %d",result);
//			break;
//		}
//	}
//	_getch();
//}

// p68 8-10

//#include <stdio.h>
//#include <conio.h>
//
//void main()
//{
//	int num;
//	int result = 1;
//
//	printf("팩토리얼 계산 프로그램(n!)\n");
//	printf("n 수 입력: "); scanf("%d",&num);
//
//	for (int i = 1; i <= num; i++)
//	{
//		if (i < num)
//		{
//			printf("%d * ",i);
//			result *= i;
//		}
//		else
//		{
//			result *= i;
//			printf("%d = %d",i,result);
//		}
//	}
//	_getch();
//}

// p68 8-11

#include <stdio.h>
#include <conio.h>

void main()
{
	int num;
	int a = 0, b = 1;
	bool count = 0;

	printf("피보나치수를 구하는 프로그램\n");
	printf("피보나치수의 개수 입력: "); scanf("%d",&num);

	for (int i = 1; i <= num; i++)
	{
		if (count == 0)
		{
			a += b;
			printf("%d\t",a);
			count = 1;
		}
		else	// 'count == 1'
		{
			b += a;
			printf("%d\t",b);
			count = 0;
		}
	}
	_getch();
}