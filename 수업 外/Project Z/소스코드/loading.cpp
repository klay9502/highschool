//	Start project since 2014 / 04 / 21 ~
//
//
//	'Project Z'
//
//	Source name 'Loading'
//
//
//	Created by 'Kim Jong Min'
//

#include <stdio.h>
#include <Windows.h>
#include "prototype.h"

extern void loading()
{
	char lode[] = "Loading";

	gotoxy(36,12);
	for (int i = 0; i < 7; i++)
	{
		printf("%c",lode[i]);
		Sleep(25);
	}
	gotoxy(43,12);
	for (int i = 0; i < 3; i++)
	{
		for (int i = 0; i < 3; i++)
		{
			printf("%c",'.');
			Sleep(500);
		}
		gotoxy(43,12);
		clear();
		gotoxy(43,12);
	}
	system("cls");
}