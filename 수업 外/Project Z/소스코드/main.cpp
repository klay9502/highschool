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
	printf("�� ���ӿ��� �����ϴ� �ι�, ��Ҵ� ��� �ȼ��Դϴ�.");
	gotoxy(12,12);
	printf("�� ������ ��ȸ��Ȱ�� �ټ� �������� ������ ��ĥ �� �ֽ��ϴ�.");
	gotoxy(21,14);
	printf("�ӻ�γ� ����ڴ� ������ ������ �ʽ��ϴ�.");
	gotoxy(14,16);
	printf("�� �������� ���� �߻��ϴ� ���ش� ��ü å������ �ʽ��ϴ�.");
	gotoxy(23,20);

	printf("��� �����Ͻ÷��� 'SPACE'�� �����ּ���.");
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