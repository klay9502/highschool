//
// main.cpp
// project_return_Z
// Remaking 'Project Z'
//
// Created by Jong-min Kim on 2015. 1. 26
// Copyright (c) 2015 Jong-min Kim. All rights reserved.
//

#include "Turboc.h"
#include "Screen.h"
#include "function.h"
#include <fmod.h>

typedef enum _GAME_STATE
{
	WARNING,
	LOADING,
	MAINMENU,
	TUTORIAL,
	INGAME,
	INVENTORY,
	STORE,
	WORKING,
	TALK,
	GAMEOVER,
	ENDING,

} GAME_STATE;

typedef enum _STORE_STATE
{
	SLEEP,
	CHOOSE,
	NOMONEY,
} STORE_STATE;

typedef enum _INVEN_STATE
{
	NOTTING,
	INVENCHOOSE,
	NOHAVE,
	HAVE,
} INVEN_STATE;

typedef struct _ITEM
{
	int Pokacip;
	int Picnic;
	int Nacho;
	int Daije;
	int Getorade;
} ITEM;

INVEN_STATE g_nInvenState = NOTTING;
STORE_STATE g_nStoreState = SLEEP;
GAME_STATE g_nGameState = WARNING;
ITEM Item;

int Init(void);
int Update(void);
int Render(void);
int Release(void);

bool bMainMenuCheak = true;

int ChooseCheak = 0;
int IngameCheak = 1;
int StoreCheak = 1;
int InvenCheak = 1;

int EndingScene = 0;

int Score = 0;
int Money = 10000;

clock_t g_OldTime;

FMOD_SYSTEM *g_System;
FMOD_SOUND *g_Sound;
FMOD_CHANNEL *g_Channel;

int main(void)
{
	int nKey;
	int string[100];

	ScreenInit();
	Init(); // �ʱ�ȭ


	while (true)
	{
		if (_kbhit())
		{
			nKey = _getch();

			switch (nKey)
			{
			case 75: // ���� ����Ű
				if (g_nGameState == STORE && g_nStoreState == CHOOSE)
				{
					ChooseCheak = 1;
				}

				if (g_nGameState == INVENTORY && g_nInvenState == INVENCHOOSE)
				{
					ChooseCheak = 1;
				}
				break;
			case 77: // ���� ����Ű
				if (g_nGameState == STORE && g_nStoreState == CHOOSE)
				{
					ChooseCheak = 2;
				}

				if (g_nGameState == INVENTORY && g_nInvenState == INVENCHOOSE)
				{
					ChooseCheak = 2;
				}
				break;
			case 72: // ���� ����Ű
				if (g_nGameState == MAINMENU)
				{
					bMainMenuCheak = true;
				}

				if (g_nGameState == INGAME)
				{
					if (IngameCheak > 0)
					{
						IngameCheak--;
					}
				}

				if (g_nGameState == STORE && g_nStoreState != CHOOSE)
				{
					if (StoreCheak > 0)
					{
						StoreCheak--;
					}
				}

				if (g_nGameState == INVENTORY && g_nInvenState != INVENCHOOSE)
				{
					if (InvenCheak > 0)
					{
						InvenCheak--;
					}
				}
				break;
			case 80: // �Ʒ� ����Ű
				if (g_nGameState == MAINMENU)
				{
					bMainMenuCheak = false;
				}

				if (g_nGameState == INGAME)
				{
					if (IngameCheak < 4)
					{
						IngameCheak++;
					}
				}

				if (g_nGameState == STORE && g_nStoreState != CHOOSE)
				{
					if (StoreCheak < 7)
					{
						StoreCheak++;
					}
				}

				if (g_nGameState == INVENTORY && g_nInvenState != INVENCHOOSE)
				{
					if (InvenCheak < 7)
					{
						InvenCheak++;
					}
				}
				break;
			case ' ':
				if (g_nGameState == WARNING)
				{
					g_nGameState = LOADING;
					g_OldTime = clock();
				}

				if (g_nGameState == TUTORIAL)
				{
					g_nGameState = INGAME;
				}

				if (g_nGameState == MAINMENU && bMainMenuCheak == true)
				{
					g_nGameState = TUTORIAL;
				}
				else if (g_nGameState == MAINMENU && bMainMenuCheak == false)
				{
					return 0;
				}

				if (g_nGameState == STORE && ChooseCheak == 0)
				{
					g_nStoreState = CHOOSE;
				}

				if (g_nGameState == INVENTORY && ChooseCheak == 0)
				{
					g_nInvenState = INVENCHOOSE;
				}

				if (g_nGameState == STORE && g_nStoreState == CHOOSE && ChooseCheak == 1)
				{
					switch (StoreCheak)
					{
					case 1:
						if (Money < 1200)
						{
							g_nStoreState = NOMONEY;
						}
						else
						{
							Money -= 1200;
							Item.Pokacip++;
							g_nStoreState = SLEEP;
						}
						break;
					case 2:
						if (Money < 400)
						{
							g_nStoreState = NOMONEY;
						}
						else
						{
							Money -= 400;
							Item.Picnic++;
							g_nStoreState = SLEEP;
						}
						break;
					case 3:
						if (Money < 1200)
						{
							g_nStoreState = NOMONEY;
						}
						else
						{
							Money -= 1200;
							Item.Nacho++;
							g_nStoreState = SLEEP;
						}
						break;
					case 4:
						if (Money < 1800)
						{
							g_nStoreState = NOMONEY;
						}
						else
						{
							Money -= 1800;
							Item.Daije++;
							g_nStoreState = SLEEP;
						}
						break;
					case 5:
						if (Money < 1300)
						{
							g_nStoreState = NOMONEY;
						}
						else
						{
							Money -= 1300;
							Item.Getorade++;
							g_nStoreState = SLEEP;
						}
						break;
					case 6:
						g_nGameState = INGAME;
						g_nStoreState = SLEEP;
						break;
					}
					ChooseCheak = 0;
				}
				else if (g_nGameState == STORE && g_nStoreState == CHOOSE && ChooseCheak == 2)
				{
					g_nStoreState = SLEEP;
					ChooseCheak = 0;
				}

				if (g_nGameState == INVENTORY && g_nInvenState == INVENCHOOSE && ChooseCheak == 1)
				{
					switch (InvenCheak)
					{
					case 1:
						if (Item.Pokacip <= 0)
						{
							g_nInvenState = NOHAVE;
							Score -= 10;
						}
						else
						{
							Item.Pokacip--;
							Score += 10;
							g_nInvenState = HAVE;
						}
						break;
					case 2:
						if (Item.Picnic <= 0)
						{
							g_nInvenState = NOHAVE;
							Score -= 10;
						}
						else
						{
							Item.Picnic--;
							Score += 3;
							g_nInvenState = HAVE;
						}
						break;
					case 3:
						if (Item.Nacho <= 0)
						{
							g_nInvenState = NOHAVE;
							Score -= 10;
						}
						else
						{
							Item.Nacho--;
							Score += 10;
							g_nInvenState = HAVE;
						}
						break;
					case 4:
						if (Item.Daije <= 0)
						{
							g_nInvenState = NOHAVE;
							Score -= 10;
						}
						else
						{
							Item.Daije--;
							Score += 15;
							g_nInvenState = HAVE;
						}
						break;
					case 5:
						if (Item.Getorade <= 0)
						{
							g_nInvenState = NOHAVE;
							Score -= 10;
						}
						else
						{
							Item.Getorade--;
							Score += 12;
							g_nInvenState = HAVE;
						}
						break;
					case 6:
						g_nGameState = INGAME;
						g_nInvenState = NOTTING;
						break;
					}
					ChooseCheak = 0;
				}
				else if (g_nGameState == INVENTORY && g_nInvenState == INVENCHOOSE && ChooseCheak == 2)
				{
					g_nInvenState = NOTTING;
					ChooseCheak = 0;
				}

				if (g_nGameState == TALK)
				{
					Score++;
					if (Score <= -100)
					{
						g_nGameState = GAMEOVER;
					}
					else if (Score >= 100)
					{
						g_nGameState = ENDING;
					}
					else
					{
						g_nGameState = INGAME;

					}
				}

				if (g_nGameState == INGAME)
				{

					switch (IngameCheak)
					{
					case 1:
						g_nGameState = TALK;
						IngameCheak = 0;
						break;
					case 2:
						g_nGameState = STORE;
						IngameCheak = 0;
						break;
					case 3:
						g_nGameState = INVENTORY;
						IngameCheak = 0;
						break;
					case 4:
						g_nGameState = WORKING;
						g_OldTime = clock();
						IngameCheak = 0;
						break;
					}
				}

				if (g_nGameState == ENDING)
				{
					EndingScene++;

					if (EndingScene > 3)
					{
						return 0;
					}
				}

				if (g_nGameState == GAMEOVER)
				{
					return 0;
				}

				break;
			}
		}

		Update(); // ������ ����
		Render(); // ȭ�� ���
	}
	Release(); // ����
	ScreenRelease();

	_getch();
	return 0;
}

int SoundInit(void)
{
	int i;

	FMOD_System_Create(&g_System);
	FMOD_System_Init(g_System, 32, FMOD_INIT_NORMAL, NULL);

	FMOD_System_CreateSound(g_System, "BGM.mp3", FMOD_LOOP_NORMAL, 0, &g_Sound);

	return 0;
}

int Init(void)
{
	g_OldTime = clock();
	SoundInit();

	FMOD_System_PlaySound(g_System, FMOD_CHANNEL_FREE, g_Sound, 0, &g_Channel);

	return 0;
}

int Update(void)
{
	clock_t CurTime = clock();

	switch (g_nGameState)
	{
	case LOADING:
		if (CurTime - g_OldTime > 2000)
		{
			g_nGameState = MAINMENU;
		}
		break;
	case WORKING:
		if (CurTime - g_OldTime > 3000)
		{
			g_nGameState = INGAME;
			Money += 1000;
		}
		break;
	}
	return 0;
}

int Render(void)
{
	clock_t CurTime = clock();
	char string[100];

	ScreenClear();

	switch (g_nGameState)
	{
	case WARNING:
		InterfaceWarning();
		break;
	case LOADING:
		Interface();
		sprintf(string, "Loading");
		ScreenPrint(36, 11, string);
		break;
	case MAINMENU:
		InterfaceMain();
		sprintf(string, "���ӽ���");
		ScreenPrint(60, 14, string);
		sprintf(string, "��������");
		ScreenPrint(60, 16, string);
		if (bMainMenuCheak == true)
		{
			ScreenPrint(57, 14, "��");
		}
		else if (bMainMenuCheak == false)
		{
			ScreenPrint(57, 16, "��");
		}
		break;
	case TUTORIAL:
		InterfaceTutorial();
		break;
	case INGAME:
		InterfaceIngame();

		sprintf(string, "���赵 : %d", Score);
		ScreenPrint(65, 2, string);
		sprintf(string, "�� : %d", Money);
		ScreenPrint(50, 2, string);

		switch (IngameCheak)
		{
		case 1:
			ScreenPrint(14, 9, "��");
			ScreenPrint(30, 9, "��");
			break;
		case 2:
			ScreenPrint(14, 11, "��");
			ScreenPrint(30, 11, "��");
			break;
		case 3:
			ScreenPrint(14, 13, "��");
			ScreenPrint(30, 13, "��");
			break;
		case 4:
			ScreenPrint(14, 15, "��");
			ScreenPrint(30, 15, "��");
			break;
		}
		break;
	case TALK:
		InterfaceTalk();
		
		SetColor(13);
		sprintf(string, "* ������");
		ScreenPrint(3, 18, string);
		SetColor(7);

		if (Score <= -100)
		{
			sprintf(string, "����, �������.. �ƴ�ô ������!");
			ScreenPrint(5, 19, string);
		}
		else if (Score > -100 && Score <= -90)
		{
			sprintf(string, "����, �� �� �־�? �� �� ���� ���ٷ�?");
			ScreenPrint(5, 19, string);
		}
		else if (Score > -90 && Score <= -50)
		{
			sprintf(string, "....");
			ScreenPrint(5, 19, string);
		}
		else if (Score > -50 && Score <= 0)
		{
			sprintf(string, "��? �� �� �־�?");
			ScreenPrint(5, 19, string);
		}
		else if(Score > 0 && Score <= 10)
		{
			sprintf(string, "�ֺҷ�?");
			ScreenPrint(5, 19, string);
		}
		else if(Score > 10 && Score <= 50)
		{
			sprintf(string, "�ܷο�? �� ��� �ҷ�.");
			ScreenPrint(5, 19, string);
		}
		else if(Score > 50 && Score <= 80)
		{
			sprintf(string, "�ϰ� �������� �ϰ� ����ʹ�..");
			ScreenPrint(5, 19, string);
		}
		else if(Score > 80 && Score <= 90)
		{
			sprintf(string, "��... ��.. ����..");
			ScreenPrint(5, 19, string);
		}
		else if(Score > 90 && Score <= 99)
		{
			sprintf(string, "��... ��.. ����..�׷��ϱ�...");
			ScreenPrint(5, 19, string);
		}
		else if(Score <= 100)
		{
			sprintf(string, "��... ��.. ����..�׷��ϱ�... �� �ϰ� ����!! ��������!!");
			ScreenPrint(5, 19, string);
		}

		break;
	case STORE:
		InterfaceShop();

		sprintf(string, "�� : %d", Money);
		ScreenPrint(12, 2, string);

		sprintf(string, "���赵 : %d", Score);
		ScreenPrint(30, 2, string);

		SetColor(14);
		sprintf(string, "* ���ְ�");
		ScreenPrint(3, 18, string);
		SetColor(7);

		if (g_nStoreState == NOMONEY)
		{
			sprintf(string, "�ܾ��� �����Ͻó׿�. ������ �帱���?");
			ScreenPrint(5, 19, string);
		}
		else
		{
			sprintf(string, "�������. ������ �帱���?");
			ScreenPrint(5, 19, string);
		}

		switch (StoreCheak)
		{
		case 1:
			ScreenPrint(16, 5, "��");
			ScreenPrint(35, 5, "��");
			if (g_nStoreState == CHOOSE)
			{
				sprintf(string, "��ĿĨ�� 1200�� �Դϴ�. ���� �����Ͻðھ��?");
				ScreenPrint(5, 19, string);
				sprintf(string, "����");
				ScreenPrint(60, 22, string);
				sprintf(string, "���");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "��");
					ScreenPrint(65, 22, "��");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "��");
					ScreenPrint(75, 22, "��");
				}
			}
			break;
		case 2:
			ScreenPrint(16, 7, "��");
			ScreenPrint(35, 7, "��");
			if (g_nStoreState == CHOOSE)
			{
				sprintf(string, "�Ǳ״��� 400�� �Դϴ�. ���� �����Ͻðھ��?");
				ScreenPrint(5, 19, string);
				sprintf(string, "����");
				ScreenPrint(60, 22, string);
				sprintf(string, "���");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "��");
					ScreenPrint(65, 22, "��");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "��");
					ScreenPrint(75, 22, "��");
				}
			}
			break;
		case 3:
			ScreenPrint(16, 9, "��");
			ScreenPrint(35, 9, "��");
			if (g_nStoreState == CHOOSE)
			{
				sprintf(string, "������ ����Ĩ�� 1200�� �Դϴ�. ���� �����Ͻðھ��?");
				ScreenPrint(5, 19, string);
				sprintf(string, "����");
				ScreenPrint(60, 22, string);
				sprintf(string, "���");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "��");
					ScreenPrint(65, 22, "��");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "��");
					ScreenPrint(75, 22, "��");
				}
			}
			break;
		case 4:
			ScreenPrint(16, 11, "��");
			ScreenPrint(35, 11, "��");
			if (g_nStoreState == CHOOSE)
			{
				sprintf(string, "���� �پ���� 1800�� �Դϴ�. ���� �����Ͻðھ��?");
				ScreenPrint(5, 19, string);
				sprintf(string, "����");
				ScreenPrint(60, 22, string);
				sprintf(string, "���");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "��");
					ScreenPrint(65, 22, "��");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "��");
					ScreenPrint(75, 22, "��");
				}
			}
			break;
		case 5:
			ScreenPrint(16, 13, "��");
			ScreenPrint(35, 13, "��");
			if (g_nStoreState == CHOOSE)
			{
				sprintf(string, "����Ʈ���̴� 1300�� �Դϴ�. ���� �����Ͻðھ��?");
				ScreenPrint(5, 19, string);
				sprintf(string, "����");
				ScreenPrint(60, 22, string);
				sprintf(string, "���");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "��");
					ScreenPrint(65, 22, "��");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "��");
					ScreenPrint(75, 22, "��");
				}
			}
			break;
		case 6:
			ScreenPrint(16, 15, "��");
			ScreenPrint(35, 15, "��");
			if (g_nStoreState == CHOOSE)
			{
				sprintf(string, "������ ������ �����ðڽ��ϱ�?");
				ScreenPrint(5, 19, string);
				sprintf(string, "�ڷ�");
				ScreenPrint(60, 22, string);
				sprintf(string, "���");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "��");
					ScreenPrint(65, 22, "��");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "��");
					ScreenPrint(75, 22, "��");
				}
			}
			break;
		}
		break;	
	case INVENTORY:
		InterfaceInven();

		sprintf(string, "�� : %d", Money);
		ScreenPrint(12, 2, string);

		sprintf(string, "���赵 : %d", Score);
		ScreenPrint(30, 2, string);

		SetColor(13);
		sprintf(string, "* ������");
		ScreenPrint(3, 18, string);
		SetColor(7);

		if (g_nInvenState == NOHAVE)
		{
			sprintf(string, "����, ���� �����°ž�?");
			ScreenPrint(5, 19, string);
			sprintf(string, "(���赵 -10 �� ��ȭ�� �����Խ��ϴ�.)");
			ScreenPrint(5, 20, string);
		}
		else if (g_nInvenState == HAVE)
		{
			sprintf(string, "���, ��...����!");
			ScreenPrint(5, 19, string);
			sprintf(string, "                                     ");
			ScreenPrint(5, 20, string);
		}
		else
		{
			sprintf(string, "��? �� �� �θ��ž�?");
			ScreenPrint(5, 19, string);
			sprintf(string, "                                     ");
			ScreenPrint(5, 20, string);
		}

		sprintf(string, "x %d", Item.Pokacip);
		ScreenPrint(35, 5, string);
		sprintf(string, "x %d", Item.Picnic);
		ScreenPrint(35, 7, string);
		sprintf(string, "x %d", Item.Nacho);
		ScreenPrint(35, 9, string);
		sprintf(string, "x %d", Item.Daije);
		ScreenPrint(35, 11, string);
		sprintf(string, "x %d", Item.Getorade);
		ScreenPrint(35, 13, string);

		switch (InvenCheak)
		{
		case 1:
			ScreenPrint(12, 5, "��");

			if (g_nInvenState == INVENCHOOSE)
			{
				sprintf(string, "��ĿĨ�� �����̿��� �ְڽ��ϱ�?");
				ScreenPrint(5, 19, string);
				sprintf(string, "(���赵 +10 �� ��ȭ�� ��Ÿ���ϴ�.)");
				ScreenPrint(5, 20, string);
				sprintf(string, "�ֱ�");
				ScreenPrint(60, 22, string);
				sprintf(string, "���");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "��");
					ScreenPrint(65, 22, "��");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "��");
					ScreenPrint(75, 22, "��");
				}
			}
			break;
		case 2:
			ScreenPrint(12, 7, "��");

			if (g_nInvenState == INVENCHOOSE)
			{
				sprintf(string, "�Ǳ״��� �����̿��� �ְڽ��ϱ�?");
				ScreenPrint(5, 19, string);
				sprintf(string, "(���赵 +3 �� ��ȭ�� ��Ÿ���ϴ�.)");
				ScreenPrint(5, 20, string);
				sprintf(string, "�ֱ�");
				ScreenPrint(60, 22, string);
				sprintf(string, "���");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "��");
					ScreenPrint(65, 22, "��");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "��");
					ScreenPrint(75, 22, "��");
				}
			}
			break;
		case 3:
			ScreenPrint(12, 9, "��");

			if (g_nInvenState == INVENCHOOSE)
			{
				sprintf(string, "������ ����Ĩ�� �����̿��� �ְڽ��ϱ�?");
				ScreenPrint(5, 19, string);
				sprintf(string, "(���赵 +10 �� ��ȭ�� ��Ÿ���ϴ�.)");
				ScreenPrint(5, 20, string);
				sprintf(string, "�ֱ�");
				ScreenPrint(60, 22, string);
				sprintf(string, "���");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "��");
					ScreenPrint(65, 22, "��");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "��");
					ScreenPrint(75, 22, "��");
				}
			}
			break;
		case 4:
			ScreenPrint(12, 11, "��");

			if (g_nInvenState == INVENCHOOSE)
			{
				sprintf(string, "���� �پ����� �����̿��� �ְڽ��ϱ�?");
				ScreenPrint(5, 19, string);
				sprintf(string, "(���赵 +15 �� ��ȭ�� ��Ÿ���ϴ�.)");
				ScreenPrint(5, 20, string);
				sprintf(string, "�ֱ�");
				ScreenPrint(60, 22, string);
				sprintf(string, "���");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "��");
					ScreenPrint(65, 22, "��");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "��");
					ScreenPrint(75, 22, "��");
				}
			}
			break;
		case 5:
			ScreenPrint(12, 13, "��");

			if (g_nInvenState == INVENCHOOSE)
			{
				sprintf(string, "����Ʈ���� �����̿��� �ְڽ��ϱ�?");
				ScreenPrint(5, 19, string);
				sprintf(string, "(���赵 +12 �� ��ȭ�� ��Ÿ���ϴ�.)");
				ScreenPrint(5, 20, string);
				sprintf(string, "�ֱ�");
				ScreenPrint(60, 22, string);
				sprintf(string, "���");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "��");
					ScreenPrint(65, 22, "��");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "��");
					ScreenPrint(75, 22, "��");
				}
			}
			break;
		case 6:
			ScreenPrint(12, 15, "��");

			if (g_nInvenState == INVENCHOOSE)
			{
				sprintf(string, "������ �κ��丮�� �����ðڽ��ϱ�?");
				ScreenPrint(5, 19, string);
				sprintf(string, "�ڷ�");
				ScreenPrint(60, 22, string);
				sprintf(string, "���");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "��");
					ScreenPrint(65, 22, "��");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "��");
					ScreenPrint(75, 22, "��");
				}
			}
			break;
		}
		break;
	case WORKING:
		InterfaceWork();
		break;
	case GAMEOVER:
		Interface();
		sprintf(string, "GAME OVER");
		ScreenPrint(36, 11, string);
		break;
	case ENDING:
		InterfaceTalk();

		SetColor(13);
		sprintf(string, "* ������");
		ScreenPrint(3, 18, string);
		SetColor(7);

		switch (EndingScene)
		{
		case 1:
			sprintf(string, "�� ��� �� ���� ������!");
			ScreenPrint(5, 19, string);
			break;
		case 2:
			sprintf(string, "�̷� ���� �� �޾���!");
			ScreenPrint(5, 19, string);
			break;
		case 3:
			Interface();
			sprintf(string, "~ Fin ~");
			ScreenPrint(36, 11, string);
			sprintf(string, "(�� ��� ������ �����̿��� ��Ĩ�ϴ�.)");
			ScreenPrint(21, 13, string);
		}

		break;
	}

	ScreenFlipping();

	return 0;
}

int Release(void)
{
	return 0;
}