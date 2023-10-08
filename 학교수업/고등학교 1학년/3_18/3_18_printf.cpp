//작성날짜 : 2014.3.18
//작성내용 : printf 연습
//작성자 : 김종민

#include <stdio.h>
#include <Windows.h>
#include <time.h>

void main()
{
	printf("문자열 출력		:[%-20s]\n","길벗 출판사");
	printf("문자열 출력		:[%20s]\n","길벗 출판사");
	printf("문자 출력		:[%10c]\n",'a');
	printf("문자 출력		:[%-10c]\n",'a');
	printf("문자 정수값 출력	:[%-10d]\n",'a');
	printf("왼쪽 정렬		:[%-10d]\n",1234);
	printf("오른쪽 정렬		:[%10d]\n",1234);
	printf("0삽입 출력		:[%010d]\n",1234);
	printf("음수의 0삽입		:[%010d]\n",-1234);
	printf("부동소수점 출력		:[%8.2f]\n",123.4567);
	printf("부동소수점 출력		:[%-8.2f]\n",123.4567);
	printf("부동소수점 출력		:[%10.2f]\n",0.0012345);
	printf("부동소수점 출력		:[%10.2e]\n",0.0012345);
	printf("부동소수점 출력		:[%10.2g]\n",0.0012345);
	for(;;)	
	{
		system("color a6");
		Sleep(250);
		system("color b5");
		Sleep(250);
		system("color c4");
		Sleep(250);
		system("color d3");
		Sleep(250);
		system("color e2");
		Sleep(250);
		system("color f1");
		Sleep(250);
	}
}