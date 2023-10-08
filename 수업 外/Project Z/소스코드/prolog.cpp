//	Start project since 2014 / 04 / 21 ~
//
//
//	'Project Z'
//
//	Source name 'prolog'
//
//
//	Created by 'Kim Jong Min'
//

#include <stdio.h>
#include <Windows.h>
#include "prototype.h"
#include "color.h"
#include "character.h"

extern void prolog()
{
	char pro1[] = "사랑이란 무엇일까...";
	char pro2[] = "그 소년,";
	char pro3[] = "을 만남으로써 나의 인생은 바뀌기 시작했다.";
	char pro4[] = "드디어 꿈에 그리던 애니원고에 입성하는구나...";
	char pro5[] = "여기가 내가 쓰게 될 방이네...";
	char pro6[] = "그런데 선배님들과 룸메이트는 아직 도착하지 않은건가?";
	char pro7[] = "끼익...";
	char pro8[] = "문이 열리고 한 남자가 방으로 들어온다.";
	char pro9[] = "이 것이 나와 지혁이의 첫 만남이였다.";

	char p_say1[] = "어...안녕.";
	char p_say2[] = "내 이름은...";
	char p_say3[] = "나도 반가워.";
	char p_say4[] = "박지혁이라... 왠지 친해질 수 있을 것 같은 느낌이네.";

	char h_say1[] = "안녕.";
	char h_say2[] = "내 이름은 지혁이야, 박지혁. 히힛!";
	char h_say3[] = "네 이름은 뭐니?";
	char h_say4[] = "(이)라고 하는구나. 반가워.";

	picture();

	gotoxy(12,20);
	enter();
	for (int i = 0;i < 20;i++)
	{
		printf("%c",pro1[i]);		// "사랑이란 무엇일까..."
		Sleep(25);
	}
	enter();
	gotoxy(12,21);
	for (int i = 0;i < 8;i++)
	{
		printf("%c",pro2[i]);		// "그 소년,"
		Sleep(25);
	}
	enter();
	gotoxy(21,21);
	for (int i = 0; i <6; i++)
	{
		GREEN;	printf("%c",heroine[i]);		// "박지혁"
		Sleep(25);
	}
	for (int i = 0;i < 42;i++)
	{
		WHITE;	printf("%c",pro3[i]);			// " 을 만남으로써 나의 인생은 바뀌기 시작했다."
		Sleep(25);
	}
	enter();
	screen_clear();
	time_dormitory();
	chat_clear();
	gotoxy(12,20);
	for (int i = 0; i < 6; i++)
	{
		SKY;	printf("%c",player_name[i]);	// "???"
		Sleep(25);
	}
	
	WHITE;	printf(": ");						// ": "
	for (int i = 0;i < 45;i++)
	{
		GRAY;	printf("%c",pro4[i]);			// "드디어 꿈에 그리던 애니원고에 입성하는구나..."
		Sleep(25);
	}
	enter();
	chat_clear();
	gotoxy(12,20);
	for (int i = 0; i < 6; i++)
	{
		SKY;	printf("%c",player_name[i]);	// "???"
		Sleep(25);
	}
	
	WHITE;	printf(": ");						// ": "
	for (int i = 0;i < 29;i++)
	{
		GRAY;	printf("%c",pro5[i]);			// "여기가 내가 쓰게될 방이네..."
		Sleep(25);
	}
	enter();
	chat_clear();
	gotoxy(12,20);
	for (int i = 0; i < 6; i++)
	{
		SKY;	printf("%c",player_name[i]);	// "???"
		Sleep(25);
	}
	
	WHITE;	printf(": ");						// ": "
	for (int i = 0;i < 53;i++)
	{
		GRAY;	printf("%c",pro6[i]);			// "그런데 선배님들과 룸메이트는 아직 도착하지 않은건가?"
		Sleep(25);
	}
	enter();
	chat_clear();
	gotoxy(12,20);
	for (int i = 0;i < 7;i++)
	{
		WHITE;	printf("%c",pro7[i]);		// "끼익..."
		Sleep(25);
	}
	enter();
	gotoxy(12,21);
	for (int i = 0;i < 38;i++)
	{
		printf("%c",pro8[i]);		// "문이 열리고 한 남자가 방으로 들어온다."
		Sleep(25);
	}
	enter();
	chat_clear();
	gotoxy(12,20);
	for (int i = 0; i < 6; i++)
	{
		GREEN;	printf("%c",player_name[i]);	// "???"
		Sleep(25);
	}
	WHITE;	printf(": ");						// ": "
	for (int i = 0;i < 5;i++)
	{
		printf("%c",h_say1[i]);			// "안녕."
		Sleep(25);
	}
	enter();
	chat_clear();
	gotoxy(12,20);
	for (int i = 0; i < 6; i++)
	{
		SKY;	printf("%c",player_name[i]);	// "???"
		Sleep(25);
	}
	
	WHITE;	printf(": ");						// ": "
	for (int i = 0;i < 10;i++)
	{
		printf("%c",p_say1[i]);			// "어...안녕."
		Sleep(25);
	}
	enter();
	chat_clear();
	gotoxy(12,20);
	for (int i = 0; i < 6; i++)
	{
		GREEN;	printf("%c",heroine[i]);	// "박지혁"
		Sleep(25);
	}
	WHITE;	printf(": ");						// ": "
	for (int i = 0;i < 33;i++)
	{
		printf("%c",h_say2[i]);			// "내 이름은 지혁이야, 박지혁. 히힛!"
		Sleep(25);
	}
	enter();
	chat_clear();
	gotoxy(12,20);
	for (int i = 0; i < 6; i++)
	{
		GREEN;	printf("%c",heroine[i]);	// "박지혁"
		Sleep(25);
	}
	WHITE;	printf(": ");						// ": "
	for (int i = 0;i < 15;i++)
	{
		printf("%c",h_say3[i]);			// "네 이름은 뭐니?"
		Sleep(25);
	}
	enter();
	chat_clear();
	gotoxy(12,20);
	for (int i = 0; i < 6; i++)
	{
		SKY;	printf("%c",player_name[i]);	// "???"
		Sleep(25);
	}
	
	WHITE;	printf(": ");						// ": "
	for (int i = 0;i < 12;i++)
	{
		printf("%c",p_say2[i]);			// "내 이름은"
		Sleep(25);
	}
	enter();
	screen_clear();
	name_input();
	screen_clear();
	chat_clear();
	gotoxy(12,20);
	for (int i = 0; i < 6; i++)
	{
		GREEN;	printf("%c",heroine[i]);	// "박지혁"
		Sleep(25);
	}
	WHITE;	printf(": ");						// ": "
	for (int i = 0; i < 6; i++)
	{
		WHITE;	printf("%c",player_name[i]);	// "(주인공)"
		Sleep(25);
	}
	for (int i = 0;i < 26;i++)
	{
		printf("%c",h_say4[i]);				// "(이)라고 하는구나. 반가워."
		Sleep(25);
	}
	enter();
	chat_clear();
	gotoxy(12,20);
	for (int i = 0; i < 6; i++)
	{
		SKY;	printf("%c",player_name[i]);	// "(주인공)"
		Sleep(25);
	}
	
	WHITE;	printf(": ");						// ": "
	for (int i = 0;i < 12;i++)
	{
		printf("%c",p_say3[i]);			// "나도 반가워."
		Sleep(25);
	}
	enter();
	chat_clear();
	gotoxy(12,20);
	for (int i = 0; i < 6; i++)
	{
		SKY;	printf("%c",player_name[i]);	// "(주인공)"
		Sleep(25);
	}
	
	WHITE;	printf(": ");						// ": "
	for (int i = 0;i < 51;i++)
	{
		GRAY;	printf("%c",p_say4[i]);			// "박지혁이라... 왠지 친해질 수 있을 것 같은 느낌이네."
		Sleep(25);
	}
	enter();
	chat_clear();
	gotoxy(12,20);
	for (int i = 0;i < 36;i++)
	{
		WHITE;	printf("%c",pro9[i]);		// "이 것이 나와 지혁이의 첫 만남이였다."
		Sleep(25);
	}
	enter();
	chat_clear();
	system("cls");
}

void name_input()
{
	gotoxy(12,14);
	printf("  (이름은 한글로 '○○○' 형식의 3글자로 작성해주십시오.)");
	gotoxy(12,10);
	printf("           플레이어 이름을 입력하세요 : ");		scanf("%s",player_name);
}

extern void prolog_logo()
{
	char prolog[] = "* Prolog *";

	gotoxy(10,19);
	clear();
	gotoxy(36,12);

	for (int i = 0; i < 11; i++)
	{
		printf("%c",prolog[i]);
		Sleep(50);
	}

	gotoxy(23,20);
	printf("계속 진행하시려면 'SPACE'를 눌러주세요.");
	enter();
	system("cls");
}