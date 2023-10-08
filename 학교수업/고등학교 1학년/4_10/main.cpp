// 주제 : 연산자 응용문제
// 날짜 : 2014 / 4 / 10
// 제작 : 김종민

// 아스키코드를 이용하되, 소문자를 이용하지 않고 소문자의 정수값을 출력하시요.

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	printf("%-14s%s\n","대문자","소문자");
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

// 지구의 몸무게를 달의 몸무게로 환산하는 프로그램을 작성하시오.

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	float earth_w;		// 지구 몸무게
	float moon_w;			// 달 몸무게
				// 달에서의 몸무게 = 지구에서의 몸무게의 12%
	printf("지구 몸무게 :");
	scanf("%f",&earth_w);

	moon_w = earth_w * 0.17;

	printf("달   몸무게 : %.2f\n",moon_w);
	_getch();
}
*/

// 정수를 5로 나눈 뒤의 몫 과 나머지 값을 구하세요.

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num;
	int quo,rem;

	printf("정수   : ");
	scanf("%d",&num);

	quo = num / 5;
	rem = num % 5;

	printf("몫     : %d\n",quo);
	printf("나머지 : %d",rem);
	_getch();
}
*/

// 1개월을 30일로 가정했을때 일 수를 개월로 환산하는 프로그램을 만드시요.


#include <stdio.h>
#include <conio.h>

void main()
{
	int day;
	int month, rem_day;
				// 30일 = 1개월
	printf("날수 : ");
	scanf("%d",&day);

	month = day / 30;
	rem_day = day % 30;

	printf("결과 : %d개월 %d일\n",month,rem_day);
	_getch();
}