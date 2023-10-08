//=========================
// 날짜...2014 / 04 / 09
// 주제...'비트,대입 연산자'
// 제작...'김종민'
//=========================

// 39p 실전 3-1

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num;
	int result;
	
	printf("하나의 정수를 입력하세요. :");
	scanf("%d",&num);

	result = num & ~7;

	printf("하위 3비트를 0으로 만든값은 %d입니다\n",result);
	_getch();
}
*/

// 40p 실전 3-2

/*
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

void main()
{
	int Input_code;
	int Play_code;

	printf("아래의 게임은 결재 후 이용이 가능합니다.\n");
	printf("4개의 게임 중 결재를 원하는 하나의 게임만을 선택하세요.\n");
	printf("===========================================================\n");
	printf(": 1.스타<500원>	2. 피파<700원>	3. 카오스	4.크레이지\n");
	printf("===========================================================\n");
	scanf("%d",&Input_code);

	printf("%d 번 게임을 선택하셨습니다\n");

	printf("결재중 = >");
	Sleep(1000);
	printf(">");
	Sleep(1000);							// 결제중...
	printf(">");
	Sleep(1000);
	printf(">\n");
	Sleep(1000);

	printf("결제완료~!!\n");
	printf("게임에 접속할 권한이 생기셨습니다.\n");

	printf("게임 입장가능 = >");
	Sleep(1000);
	printf(">");
	Sleep(1000);
	printf(">");							// 가능여부 확인중...
	Sleep(1000);
	printf(">\n\n");
	Sleep(1000);

	printf("입장할 게임을 선택하세요.\n");
	printf("===========================================================\n");
	printf(": 1.스타<500원>	2. 피파<700원>	3. 카오스	4.크레이지\n");
	printf("===========================================================\n");
	scanf("%d",&Play_code);

	((Input_code & Play_code) == (Input_code | Play_code)) ?		// 고유번호 확인중...
		printf("게임로딩 중...\n") :
		printf("이 게임을 구입하지 않으셨습니다. 프로그램을 종료합니다.\n");

	_getch();
}
*/

// 40p 예제10

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	float num1, num2;
	float data1, data2;

	num1 = num2 = 4.352;
	data1 = data2 = 3.141592;

	printf("대입연산자에 대해 알아봅시다.\n");
	num1 += num2 -= data1 *= data2 /= 2;
	
	printf("num1 : [%-10.3f]\n",num1);
	printf("num2 : [%-10.3f]\n",num2);
	printf("data1 : [%-10.3f]\n",data1);
	printf("data2 : [%-10.3f]\n",data2);
	_getch();
}
*/

// 41p 예제11

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a = 1;
	float b = 3.14;
	double c = 2;
	c += -a++ + ++b;

	printf("c += -a++ + ++b 식의 c값은 %f 입니다. \n", c);
	_getch();
}
*/

// 42p 연습문제4

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void main()
{
	int Left,Right;
	int bet;
	
	printf("건전지 잔량 표시 프로그램\n");
	printf("왼쪽 건전지의 잔량을 계산합니다.\n");

	srand((int)time(NULL));
	Left = rand()%100;

	printf("오른쪽 건전지의 잔량을 계산합니다.\n");

	Right = rand()%100;

	printf("왼쪽 건전지 잔량 = %d\n",Left);
	printf("오른쪽 건전지 잔량 = %d\n",Right);

	bet = (Left + Right) / 2;

	(bet < 5) ?
		printf("건전지를 교체하세요.\n") :
		printf("현재 건전지 잔량은 %d%%입니다.\n",bet);
	_getch();
}
*/