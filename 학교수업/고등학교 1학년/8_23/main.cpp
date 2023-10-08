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

	strcpy(Persons[0].name, "�� ����");
	Persons[0].Language.Kor = 90;
	Persons[0].Language.Eng = 95;
	Persons[0].Society = 88;
	Persons[0].Music = 80;

	printf("������ �̸��� �����ÿ�. : "); scanf("%s", Persons[1].name);
	printf("������ ���������� �����ÿ� => "); scanf("%d", &Persons[1].Language.Kor);
	printf("������ ���������� �����ÿ� => "); scanf("%d", &Persons[1].Language.Eng);
	printf("������ ��ȸ������ �����ÿ� => "); scanf("%d", &Persons[1].Society);
	printf("������ ���������� �����ÿ� => "); scanf("%d", &Persons[1].Music);

	for (int i = 0; i < 2; i++)
	{
		Persons[i].Sum = Persons[i].Language.Kor + Persons[i].Language.Eng + Persons[i].Society + Persons[i].Music;
		Persons[i].Average = Persons[i].Sum / 4.0;
	}

	if (Persons[0].Sum > Persons[1].Sum)		// ������ �� �������� ���� ���
	{
		printf("[%s]�� �� ��� �������� ���� �������δ� %d��, ���� ��� �����δ� %f�� �����ϴ�.\n", Persons[1].name, Persons[0].Sum - Persons[1].Sum, Persons[0].Average - Persons[1].Average);
	}

	else if (Persons[0].Sum < Persons[1].Sum)		// ������ �� �������� ���� ���
	{
		printf("[%s]�� �� ��� �������� ���� �������δ� %d��, ���� ��� �����δ� %f�� �����ϴ�.\n", Persons[1].name, Persons[1].Sum - Persons[0].Sum, Persons[1].Average - Persons[0].Average);
	}

	else
	{
		printf("[%s]�� �� ��� ������ �����ϴ�.\n", Persons[1].name);
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
	printf("��µ� �ﰢ���� ���̸� �Է��Ͻÿ�.\n");
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
	{"���� Ÿ���� �⺻���� �ƴ� ����","������", "�迭","������",2,FALSE},
    {"���� �� �ݺ����� �ƴ� ����","switch", "for","while",1,FALSE},
    {"����ü�� ������ �� ����ϴ� Ű�����","int", "goto","struct",3,FALSE},
    {"���� �� ���� ũ�Ⱑ ū Ÿ����","int", "double","char",2,FALSE},
    {"�������� ������ �� ����ϴ� Ű�����","enum", "alias","define",1,FALSE},
    {"���� �� ���� �����ڴ�","++", "?","=",1,FALSE},
    {"���� �迭�� ������ �ٲ� �� ����ϴ� �Լ���","strassign", "strmove","strcpy",3,FALSE},
    {"����ü�� ����� ���� �� ����ϴ� �����ڴ�","->", "*",".",3,FALSE},
    {"������ Ÿ���� �ƴ� ����","unsigned", "short","float",3,FALSE},
    {"C ���α׷����� �ݵ�� �ʿ��� �Լ���","entry", "main","WinMain",2,FALSE}
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
