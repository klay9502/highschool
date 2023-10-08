/*
#include <stdio.h>
#include <conio.h>

struct point {
	int x;
	int y;
};

struct circle {
	struct point p;
	double radius;
};

int main()
{
	struct circle c1 = {10, 10, 1.5};
	struct circle c2 = {{30, 30}, 2.4};

	printf("[circle1]\n");
	printf("x : %d, y : %d\n", c1.p.x, c1.p.y);
	printf("radius : %f\n", c1.radius);

	printf("[circle2]\n");
	printf("x : %d, y : %d\n", c2.p.x, c2.p.y);
	printf("radius : %f\n", c2.radius);

	_getch();
	return 0;
}
*/

/*
#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct _Lang {
	int Kor;
	int Eng;
} Lang;

typedef struct _Student {
	char name[20];
	Lang Language;
	int Society;
	int Music;
	int Sum;
	float Average;
} Student;

void main()
{
	Student Persons[2];

	strcpy(Persons[0].name, "반 점수");
	Persons[0].Language.Kor = 90;
	Persons[0].Language.Eng = 95;
	Persons[0].Society = 88;
	Persons[0].Music = 80;

	printf("본인의 이름을 적으시오. : "); scanf("%s", Persons[1].name);
	printf("본인의 국어점수를 적으시오 => "); scanf("%d", &Persons[1].Language.Kor);
	printf("본인의 영어점수를 적으시오 => "); scanf("%d", &Persons[1].Language.Eng);
	printf("본인의 사회점수를 적으시오 => "); scanf("%d", &Persons[1].Society);
	printf("본인의 음악점수를 적으시오 => "); scanf("%d", &Persons[1].Music);

	for (int i = 0; i < 2; i++)
	{
		Persons[i].Sum = Persons[i].Language.Kor + Persons[i].Language.Eng + Persons[i].Society + Persons[i].Music;
		Persons[i].Average = Persons[i].Sum / 4.0;
	}

	if (Persons[0].Sum > Persons[1].Sum)		// 성적이 반 총점보다 낮을 경우
	{
		printf("[%s]은 반 평균 점수보다 과목 총점으로는 %d점, 과목 평균 점수로는 %f점 낮습니다.\n", Persons[1].name, Persons[0].Sum - Persons[1].Sum, Persons[0].Average - Persons[1].Average);
	}

	else if (Persons[0].Sum < Persons[1].Sum)		// 성적이 반 총점보다 높을 경우
	{
		printf("[%s]은 반 평균 점수보다 과목 총점으로는 %d점, 과목 평균 점수로는 %f점 높습니다.\n", Persons[1].name, Persons[1].Sum - Persons[0].Sum, Persons[1].Average - Persons[0].Average);
	}

	else
	{
		printf("[%s]은 반 평균 점수와 같습니다.\n", Persons[1].name);
	}

	_getch();
}
*/

/*
#include <stdio.h>
#include <malloc.h>
#include <conio.h>

typedef struct _DATA {
	int front;
	int number;
} DATA;

void main()
{
	DATA* datum;
	int i, j;
	int height;
	printf("출력될 삼각형의 높이를 입력하시오.\n");
	scanf("%d", &height);

	datum = (DATA*)malloc(sizeof(DATA)*height);

	for (i = 0; i < height; i++)
	{
		datum[i].front = height - i - 1;
		datum[i].number = (i * 2) + 1;
		for (j = datum[i].front; j > 0; j--)
		{
			printf(" ");
		}
		
		for (j = 0; j < datum[i].number; j++)
		{
			printf("*");
		}

		printf("\n");
	}
	free(datum);
	_getch();
}
*/

#include "Turboc.h"

struct tag_Munje {
	char *Question;
	char *Case[3];
	int Answer;
	BOOL Used;
};

struct tag_Munje Munje[] = {
	{"다음 타입중 기본형이 아닌 것은","정수형", "배열","문자형",2,FALSE},
    {"다음 중 반복문이 아닌 것은","switch", "for","while",1,FALSE},
    {"구조체를 선언할 때 사용하는 키워드는","int", "goto","struct",3,FALSE},
    {"다음 중 가장 크기가 큰 타입은","int", "double","char",2,FALSE},
    {"열거형을 선언할 때 사용하는 키워드는","enum", "alias","define",1,FALSE},
    {"다음 중 단항 연산자는","++", "?","=",1,FALSE},
    {"문자 배열의 내용을 바꿀 때 사용하는 함수는","strassign", "strmove","strcpy",3,FALSE},
    {"구조체의 멤버를 읽을 때 사용하는 연산자는","->", "*",".",3,FALSE},
    {"정수형 타입이 아닌 것은","unsigned", "short","float",3,FALSE},
    {"C 프로그램에서 반드시 필요한 함수는","entry", "main","WinMain",2,FALSE}
};

void main()
{
	int num;

	for (int count = 0; count < 5; count++)
	{
		while (1)
		{
			srand(time(NULL));
			num = rand() % 10;

			if (Munje[num].Used == false)
				break;
		}

		// gotoxy(5,5);
		printf("%s\n", Munje[num].Question);
	}

	_getch();
}
