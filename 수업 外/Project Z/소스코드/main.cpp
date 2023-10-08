//	Start project since 2014 / 04 / 21 ~
//
//
//	'Project Z' Alpha 0.01 ver
//
//
//	Created by 'Kim Jong Min'
//

#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include "prototype.h"
#include "color.h"

void main()
{
	loading();
	Sleep(500);
	Interface();
	prolog_logo();
	Interface();
	warning();
	prolog();
	Interface();
	chapter_1_logo();
	Interface();
	chapter_1();
	_getch();
}

void warning()
{
	system("color C");
	gotoxy(10,19);
	clear();

	gotoxy(36,5);
	printf("! Warning !");
	gotoxy(16,10);
	printf("이 게임에서 등장하는 인물, 장소는 모두 픽션입니다.");
	gotoxy(12,12);
	printf("이 게임은 사회생활에 다소 부정적인 영향을 미칠 수 있습니다.");
	gotoxy(21,14);
	printf("임산부나 노약자는 게임을 권하지 않습니다.");
	gotoxy(14,16);
	printf("이 게임으로 인해 발생하는 피해는 일체 책임지지 않습니다.");
	gotoxy(23,20);

	printf("계속 진행하시려면 'SPACE'를 눌러주세요.");
	enter();
	system("cls");
	system("color 7");
	Interface();
}

void clear()
{
	printf("								");
}

void enter()
{
	while (1)
	{
		if (getch() == VK_SPACE)
			break;
	}
}

void chat_clear()
{
	gotoxy(12,20);
	printf("                                                            ");
	gotoxy(12,21);
	printf("                                                            ");
	gotoxy(12,22);
	printf("                                                            ");
	gotoxy(12,20);
}
void screen_clear()
{
	gotoxy(12,2);
	printf("                                                            ");
	gotoxy(12,3);
	printf("                                                            ");
	gotoxy(12,4);
	printf("                                                            ");
	gotoxy(12,5);
	printf("                                                            ");
	gotoxy(12,6);
	printf("                                                            ");
	gotoxy(12,7);
	printf("                                                            ");
	gotoxy(12,8);
	printf("                                                            ");
	gotoxy(12,9);
	printf("                                                            ");
	gotoxy(12,10);
	printf("                                                            ");
	gotoxy(12,11);
	printf("                                                            ");
	gotoxy(12,12);
	printf("                                                            ");
	gotoxy(12,13);
	printf("                                                            ");
	gotoxy(12,14);
	printf("                                                            ");
	gotoxy(12,15);
	printf("                                                            ");
	gotoxy(12,16);
	printf("                                                            ");
	gotoxy(12,17);
	printf("                                                            ");
	gotoxy(12,18);
	printf("                                                            ");
}