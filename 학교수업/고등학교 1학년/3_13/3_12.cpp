/*작성문 : C 프로그램은 무엇으로 이루어져 있을까?
작성일 : 3.12
작성자 : 김종민
*/

#include <stdio.h>	//전처리기
#define MAX 10

int Add(int,int);	//함수의 프로토타입
void main()
{
	int num1,num2;	//변수의 선언
	int ret;
	num1=10;	//변수의 초기화
	num2=20;

	printf("전형적인 C 프로그램입니다.\n");
	printf("num1과 num2를 덧셈한 결과를 알아봅시다.\n");	//덧셈 연산자를 이용한 변수의 연산
	ret=num1+num2;
	printf("연산자 사용 결과 : %d\n",ret);
	ret=Add(num1,num2);	// 함수 Add()의 호출
	printf("함수 사용 결과: %d\n",ret);
}

int Add(int a,int b)
{
	int ret;	//함수 Add()의 몸체
	ret=a+b;
	return(ret);
}