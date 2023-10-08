/*
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

void main()
{
	int num;

	printf("0~2 사이의 난수 발생 시작~!\n");
	srand(time(NULL));
	num = rand()%3;

	switch (num) {
		case 0:
			puts("0");
			break;
		case 1:
			puts("1");
			break;
		case 2:
			puts("2");
			break;
		default:
			puts("잘못된 난수 발생"); }
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char ch;

	printf("당신은 나를 사랑하십니까? (y or n)\n");
	scanf("%c",&ch);
	switch (ch) {
	case 'y':
		puts("나도 당신을 사랑합니다.");
		break;
	case 'n':
		puts("그래도 나는 당신이 좋습니다.");
		break;
	default:
		puts("잘못된 입력."); }
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char Grade;

	printf("여러분이 받은 학점을 입력하세요.\n");
	printf("나의 학점: "); scanf("%c",&Grade);

	switch (Grade) {
	case 'A':
		printf("100점 >= 나의 성적 >= 91점");
		break;
	case 'B':
		printf("90점 >= 나의 성적 >= 81점");
		break;
	case 'C':
		printf("80점 >= 나의 성적 >= 71점");
		break;
	case 'D':
		printf("70점 >= 나의 성적 >= 61점");
		break;
	default:
		printf("나의 성적은 60점 이하"); }
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	float num,num2,result;
	char code;

	printf("사칙연산이 가능한 계산기 프로그램\n");
	printf("(실수*기호*실수) : "); scanf("%f%c%f",&num,&code,&num2);

	switch (code) {
	case '+':	// '+' 연산
		result = num + num2;
		break;
	case '-':	// '-' 연산
		result = num - num2;
		break;
	case '*':	// '*' 연산
		result = num * num2;
		break;
	case '/':	// '/' 연산
		result = num / num2;
		break;
	default:
		printf("잘못된 키워드\n"); }
	printf("%.2f %c %.2f = %.2f\n",num,code,num2,result);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int Grade;
	int code;

	printf("학점 계산기\n");
	printf("입력 : "); scanf("%d",&Grade);

	code = Grade / 10;

	switch (code) {
	case 10:	// 90 ~ 100점
	case 9:
		printf("등급 'A'");
		break;
	case 8:		// 80 ~ 89점
		printf("등급 'B'");
		break;
	case 7:		// 70 ~ 79점
		printf("등급 'C'");
		break;
	case 6:		// 60 ~ 69점
		printf("등급 'D'");
		break;
	default:	// 60점 미만
		printf("등급 'F'"); }
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num;

	for (num = 1; num <= 10; num++)
		printf("%d",num);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i;
	
	printf("i의 초기값 = 0 \n\n");
	
	for (i = 0; i < 10; i++)
		printf("%d번째 실행, 현재 i의 값: %d\n",i+1,i);
	printf("\nfor문 완료 후 i의 값 = %d\n",i);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char ch;

	printf("알파벳 출력하기\n");
	for(ch = 'A'; ch <= 'Z'; ch++)
		printf("%c",ch);
	printf("\n");
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i;
	int num;
	int b = 0;
	int c = 0;

	puts("3의 배수와 7의 배수 개수 세기. 1부터 어디까지 수 중에?");

	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		if (i % 3 == 0)
			b++;
		if (i % 7 == 0)
			c++;
	}
	printf("1부터 %d까지 3의 배수는 총 %d개, 7의 배수는 총 %d개 입니다.\n",num,b,c);
	_getch();
}
*/

#include <stdio.h>
#include <conio.h>

void main()
{
	int i;
	int num;
	int three = 0,seven = 0;
	int t_result = 0,s_result = 0;

	puts("3의 배수, 7의 배수의 총합. 1부터 어디까지 수 중에?");

	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		three++;
		seven++;
		if (i % 3 == 0)
			t_result += three;
		if (i % 7 == 0)
			s_result += seven;
	}
	printf("1부터 %d까지 3의 배수는 총합 %d, 7의 배수 총합 %d 입니다.\n",num,t_result,s_result);
	_getch();
}