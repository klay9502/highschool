//	Start project since 2014 / 04 / 21 ~
//
//
//	'Project Z'
//
//	Source name 'chapter_1'
//
//
//	Created by 'Kim Jong Min'
//

#include <stdio.h>
#include <Windows.h>
#include "prototype.h"
#include "color.h"

extern void chapter_1_logo()
{	
	char ch1[] = "* CHAPTER I *";
	char ch2[] = "�ִϿ��� �������� ����";
	
	gotoxy(10,19);
	clear();
	gotoxy(35,12);
	for (int i = 0; i < 14; i++)
	{
		printf("%c",ch1[i]);
		Sleep(50);
	}
	Sleep(500);
	gotoxy(30,14);
	for (int i = 0; i < 22; i++)
	{
		printf("%c",ch2[i]);
		Sleep(50);
	}

	gotoxy(23,20);
	printf("��� �����Ͻ÷��� 'SPACE'�� �����ּ���.");
	enter();
	system("cls");
}

extern void chapter_1()
{
	char pro1[] = "���н��� ������...";
	
	char p_say1[] = "���� ��¥ �ִϿ��� �����ߴٴ°� �ǰ��� �ǳ�.";

	char h_say1[] = "�ȳ�.";

	gotoxy(12,20);
	enter();
	for (int i = 0;i < 18;i++)
	{
		printf("%c",pro1[i]);		// "���н��� ������..."
		Sleep(25);
	}
}