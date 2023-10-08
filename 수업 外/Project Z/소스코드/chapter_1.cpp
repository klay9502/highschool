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
	char ch2[] = "애니원고 라이프의 시작";
	
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
	printf("계속 진행하시려면 'SPACE'를 눌러주세요.");
	enter();
	system("cls");
}

extern void chapter_1()
{
	char pro1[] = "입학식이 끝나고...";
	
	char p_say1[] = "이제 진짜 애니원고에 입학했다는게 실감이 되네.";

	char h_say1[] = "안녕.";

	gotoxy(12,20);
	enter();
	for (int i = 0;i < 18;i++)
	{
		printf("%c",pro1[i]);		// "입학식이 끝나고..."
		Sleep(25);
	}
}