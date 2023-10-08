//============================
//Today...2014 / 04 / 08
//Subject...'Operator'
//Make by...김종민
//============================

// 38p 예제9

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i = 10;			// 10 = 00000000000010110
	
	printf("i << 2의 값 : %d\n",i<<2);		// 101000 = 40
	printf("i >> 2의 값 : %d\n",i>>2);		// 000010 = 2
	_getch();
}
*/

// 프레젠 예제

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a = 0xF0;			// 이진수 : 11110000
	int b = 0x0F;			// 이진수 : 00001111

	int c = 0x0A;			// 이진수 : 00001010
	int d = 0x0B;			// 이진수 : 00001011

	int e = 0x02;			// 이진수 : 00000010
	int f = 0x08;			// 이진수 : 00001000

	printf("a & b의 결과는 : %x\n", a&b);
	printf("a | b의 결과는 : %x\n\n", a|b);

	printf("c ^ d의 결과는 : %x\n",c^d);
	printf("~a의 결과는 %x\n\n",~a);

	printf("e<<2의 결과는 : %x\n",e<<2);
	printf("f>>2의 결과는 : %x\n",f>>2);
	_getch();
}
*/

// 39p 연습문제3

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int left, right;

	printf("왼쪽 전선의 상태는 어떠합니까? 양호: 1, 불량: 0\n입력: ");
	scanf("%d",&left);
	printf("오른쪽 전선의 상태는 어떠합니까? 양호: 1, 불량: 0\n입력: ");
	scanf("%d",&right);

	(left & right)==1 ? puts("전구에 불이 들어왔습니다~"):
						puts("전선 불량으로 불을 밝힐 수 없습니다.");
	_getch();
}
*/