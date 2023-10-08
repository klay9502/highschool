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
	char pro1[] = "����̶� �����ϱ�...";
	char pro2[] = "�� �ҳ�,";
	char pro3[] = "�� �������ν� ���� �λ��� �ٲ�� �����ߴ�.";
	char pro4[] = "���� �޿� �׸��� �ִϿ��� �Լ��ϴ±���...";
	char pro5[] = "���Ⱑ ���� ���� �� ���̳�...";
	char pro6[] = "�׷��� ����Ե�� �����Ʈ�� ���� �������� �����ǰ�?";
	char pro7[] = "����...";
	char pro8[] = "���� ������ �� ���ڰ� ������ ���´�.";
	char pro9[] = "�� ���� ���� �������� ù �����̿���.";

	char p_say1[] = "��...�ȳ�.";
	char p_say2[] = "�� �̸���...";
	char p_say3[] = "���� �ݰ���.";
	char p_say4[] = "�������̶�... ���� ģ���� �� ���� �� ���� �����̳�.";

	char h_say1[] = "�ȳ�.";
	char h_say2[] = "�� �̸��� �����̾�, ������. ����!";
	char h_say3[] = "�� �̸��� ����?";
	char h_say4[] = "(��)��� �ϴ±���. �ݰ���.";

	picture();

	gotoxy(12,20);
	enter();
	for (int i = 0;i < 20;i++)
	{
		printf("%c",pro1[i]);		// "����̶� �����ϱ�..."
		Sleep(25);
	}
	enter();
	gotoxy(12,21);
	for (int i = 0;i < 8;i++)
	{
		printf("%c",pro2[i]);		// "�� �ҳ�,"
		Sleep(25);
	}
	enter();
	gotoxy(21,21);
	for (int i = 0; i <6; i++)
	{
		GREEN;	printf("%c",heroine[i]);		// "������"
		Sleep(25);
	}
	for (int i = 0;i < 42;i++)
	{
		WHITE;	printf("%c",pro3[i]);			// " �� �������ν� ���� �λ��� �ٲ�� �����ߴ�."
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
		GRAY;	printf("%c",pro4[i]);			// "���� �޿� �׸��� �ִϿ��� �Լ��ϴ±���..."
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
		GRAY;	printf("%c",pro5[i]);			// "���Ⱑ ���� ���Ե� ���̳�..."
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
		GRAY;	printf("%c",pro6[i]);			// "�׷��� ����Ե�� �����Ʈ�� ���� �������� �����ǰ�?"
		Sleep(25);
	}
	enter();
	chat_clear();
	gotoxy(12,20);
	for (int i = 0;i < 7;i++)
	{
		WHITE;	printf("%c",pro7[i]);		// "����..."
		Sleep(25);
	}
	enter();
	gotoxy(12,21);
	for (int i = 0;i < 38;i++)
	{
		printf("%c",pro8[i]);		// "���� ������ �� ���ڰ� ������ ���´�."
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
		printf("%c",h_say1[i]);			// "�ȳ�."
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
		printf("%c",p_say1[i]);			// "��...�ȳ�."
		Sleep(25);
	}
	enter();
	chat_clear();
	gotoxy(12,20);
	for (int i = 0; i < 6; i++)
	{
		GREEN;	printf("%c",heroine[i]);	// "������"
		Sleep(25);
	}
	WHITE;	printf(": ");						// ": "
	for (int i = 0;i < 33;i++)
	{
		printf("%c",h_say2[i]);			// "�� �̸��� �����̾�, ������. ����!"
		Sleep(25);
	}
	enter();
	chat_clear();
	gotoxy(12,20);
	for (int i = 0; i < 6; i++)
	{
		GREEN;	printf("%c",heroine[i]);	// "������"
		Sleep(25);
	}
	WHITE;	printf(": ");						// ": "
	for (int i = 0;i < 15;i++)
	{
		printf("%c",h_say3[i]);			// "�� �̸��� ����?"
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
		printf("%c",p_say2[i]);			// "�� �̸���"
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
		GREEN;	printf("%c",heroine[i]);	// "������"
		Sleep(25);
	}
	WHITE;	printf(": ");						// ": "
	for (int i = 0; i < 6; i++)
	{
		WHITE;	printf("%c",player_name[i]);	// "(���ΰ�)"
		Sleep(25);
	}
	for (int i = 0;i < 26;i++)
	{
		printf("%c",h_say4[i]);				// "(��)��� �ϴ±���. �ݰ���."
		Sleep(25);
	}
	enter();
	chat_clear();
	gotoxy(12,20);
	for (int i = 0; i < 6; i++)
	{
		SKY;	printf("%c",player_name[i]);	// "(���ΰ�)"
		Sleep(25);
	}
	
	WHITE;	printf(": ");						// ": "
	for (int i = 0;i < 12;i++)
	{
		printf("%c",p_say3[i]);			// "���� �ݰ���."
		Sleep(25);
	}
	enter();
	chat_clear();
	gotoxy(12,20);
	for (int i = 0; i < 6; i++)
	{
		SKY;	printf("%c",player_name[i]);	// "(���ΰ�)"
		Sleep(25);
	}
	
	WHITE;	printf(": ");						// ": "
	for (int i = 0;i < 51;i++)
	{
		GRAY;	printf("%c",p_say4[i]);			// "�������̶�... ���� ģ���� �� ���� �� ���� �����̳�."
		Sleep(25);
	}
	enter();
	chat_clear();
	gotoxy(12,20);
	for (int i = 0;i < 36;i++)
	{
		WHITE;	printf("%c",pro9[i]);		// "�� ���� ���� �������� ù �����̿���."
		Sleep(25);
	}
	enter();
	chat_clear();
	system("cls");
}

void name_input()
{
	gotoxy(12,14);
	printf("  (�̸��� �ѱ۷� '�ۡۡ�' ������ 3���ڷ� �ۼ����ֽʽÿ�.)");
	gotoxy(12,10);
	printf("           �÷��̾� �̸��� �Է��ϼ��� : ");		scanf("%s",player_name);
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
	printf("��� �����Ͻ÷��� 'SPACE'�� �����ּ���.");
	enter();
	system("cls");
}