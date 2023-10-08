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
	Init(); // 초기화


	while (true)
	{
		if (_kbhit())
		{
			nKey = _getch();

			switch (nKey)
			{
			case 75: // 좌측 방향키
				if (g_nGameState == STORE && g_nStoreState == CHOOSE)
				{
					ChooseCheak = 1;
				}

				if (g_nGameState == INVENTORY && g_nInvenState == INVENCHOOSE)
				{
					ChooseCheak = 1;
				}
				break;
			case 77: // 우측 방향키
				if (g_nGameState == STORE && g_nStoreState == CHOOSE)
				{
					ChooseCheak = 2;
				}

				if (g_nGameState == INVENTORY && g_nInvenState == INVENCHOOSE)
				{
					ChooseCheak = 2;
				}
				break;
			case 72: // 위쪽 방향키
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
			case 80: // 아래 방향키
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

		Update(); // 데이터 갱신
		Render(); // 화면 출력
	}
	Release(); // 해제
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
		sprintf(string, "게임시작");
		ScreenPrint(60, 14, string);
		sprintf(string, "게임종료");
		ScreenPrint(60, 16, string);
		if (bMainMenuCheak == true)
		{
			ScreenPrint(57, 14, "→");
		}
		else if (bMainMenuCheak == false)
		{
			ScreenPrint(57, 16, "→");
		}
		break;
	case TUTORIAL:
		InterfaceTutorial();
		break;
	case INGAME:
		InterfaceIngame();

		sprintf(string, "관계도 : %d", Score);
		ScreenPrint(65, 2, string);
		sprintf(string, "돈 : %d", Money);
		ScreenPrint(50, 2, string);

		switch (IngameCheak)
		{
		case 1:
			ScreenPrint(14, 9, "▶");
			ScreenPrint(30, 9, "◀");
			break;
		case 2:
			ScreenPrint(14, 11, "▶");
			ScreenPrint(30, 11, "◀");
			break;
		case 3:
			ScreenPrint(14, 13, "▶");
			ScreenPrint(30, 13, "◀");
			break;
		case 4:
			ScreenPrint(14, 15, "▶");
			ScreenPrint(30, 15, "◀");
			break;
		}
		break;
	case TALK:
		InterfaceTalk();
		
		SetColor(13);
		sprintf(string, "* 박지혁");
		ScreenPrint(3, 18, string);
		SetColor(7);

		if (Score <= -100)
		{
			sprintf(string, "꺼져, 더러운놈.. 아는척 하지마!");
			ScreenPrint(5, 19, string);
		}
		else if (Score > -100 && Score <= -90)
		{
			sprintf(string, "뭐야, 할 말 있어? 할 말 없음 가줄래?");
			ScreenPrint(5, 19, string);
		}
		else if (Score > -90 && Score <= -50)
		{
			sprintf(string, "....");
			ScreenPrint(5, 19, string);
		}
		else if (Score > -50 && Score <= 0)
		{
			sprintf(string, "응? 할 말 있어?");
			ScreenPrint(5, 19, string);
		}
		else if(Score > 0 && Score <= 10)
		{
			sprintf(string, "왜불러?");
			ScreenPrint(5, 19, string);
		}
		else if(Score > 10 && Score <= 50)
		{
			sprintf(string, "외로워? 왜 계속 불러.");
			ScreenPrint(5, 19, string);
		}
		else if(Score > 50 && Score <= 80)
		{
			sprintf(string, "니가 없을때도 니가 보고싶다..");
			ScreenPrint(5, 19, string);
		}
		else if(Score > 80 && Score <= 90)
		{
			sprintf(string, "아... 저.. 저기..");
			ScreenPrint(5, 19, string);
		}
		else if(Score > 90 && Score <= 99)
		{
			sprintf(string, "아... 저.. 저기..그러니까...");
			ScreenPrint(5, 19, string);
		}
		else if(Score <= 100)
		{
			sprintf(string, "아... 저.. 저기..그러니까... 난 니가 좋아!! 정말좋아!!");
			ScreenPrint(5, 19, string);
		}

		break;
	case STORE:
		InterfaceShop();

		sprintf(string, "돈 : %d", Money);
		ScreenPrint(12, 2, string);

		sprintf(string, "관계도 : %d", Score);
		ScreenPrint(30, 2, string);

		SetColor(14);
		sprintf(string, "* 김주관");
		ScreenPrint(3, 18, string);
		SetColor(7);

		if (g_nStoreState == NOMONEY)
		{
			sprintf(string, "잔액이 부족하시네요. 무엇을 드릴까요?");
			ScreenPrint(5, 19, string);
		}
		else
		{
			sprintf(string, "어서오세요. 무엇을 드릴까요?");
			ScreenPrint(5, 19, string);
		}

		switch (StoreCheak)
		{
		case 1:
			ScreenPrint(16, 5, "▶");
			ScreenPrint(35, 5, "◀");
			if (g_nStoreState == CHOOSE)
			{
				sprintf(string, "포커칩은 1200원 입니다. 정말 구입하시겠어요?");
				ScreenPrint(5, 19, string);
				sprintf(string, "구입");
				ScreenPrint(60, 22, string);
				sprintf(string, "취소");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "▶");
					ScreenPrint(65, 22, "◀");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "▶");
					ScreenPrint(75, 22, "◀");
				}
			}
			break;
		case 2:
			ScreenPrint(16, 7, "▶");
			ScreenPrint(35, 7, "◀");
			if (g_nStoreState == CHOOSE)
			{
				sprintf(string, "피그닉은 400원 입니다. 정말 구입하시겠어요?");
				ScreenPrint(5, 19, string);
				sprintf(string, "구입");
				ScreenPrint(60, 22, string);
				sprintf(string, "취소");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "▶");
					ScreenPrint(65, 22, "◀");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "▶");
					ScreenPrint(75, 22, "◀");
				}
			}
			break;
		case 3:
			ScreenPrint(16, 9, "▶");
			ScreenPrint(35, 9, "◀");
			if (g_nStoreState == CHOOSE)
			{
				sprintf(string, "뻑뻑한 나쵸칩은 1200원 입니다. 정말 구입하시겠어요?");
				ScreenPrint(5, 19, string);
				sprintf(string, "구입");
				ScreenPrint(60, 22, string);
				sprintf(string, "취소");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "▶");
					ScreenPrint(65, 22, "◀");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "▶");
					ScreenPrint(75, 22, "◀");
				}
			}
			break;
		case 4:
			ScreenPrint(16, 11, "▶");
			ScreenPrint(35, 11, "◀");
			if (g_nStoreState == CHOOSE)
			{
				sprintf(string, "초코 다아재는 1800원 입니다. 정말 구입하시겠어요?");
				ScreenPrint(5, 19, string);
				sprintf(string, "구입");
				ScreenPrint(60, 22, string);
				sprintf(string, "취소");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "▶");
					ScreenPrint(65, 22, "◀");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "▶");
					ScreenPrint(75, 22, "◀");
				}
			}
			break;
		case 5:
			ScreenPrint(16, 13, "▶");
			ScreenPrint(35, 13, "◀");
			if (g_nStoreState == CHOOSE)
			{
				sprintf(string, "게이트웨이는 1300원 입니다. 정말 구입하시겠어요?");
				ScreenPrint(5, 19, string);
				sprintf(string, "구입");
				ScreenPrint(60, 22, string);
				sprintf(string, "취소");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "▶");
					ScreenPrint(65, 22, "◀");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "▶");
					ScreenPrint(75, 22, "◀");
				}
			}
			break;
		case 6:
			ScreenPrint(16, 15, "▶");
			ScreenPrint(35, 15, "◀");
			if (g_nStoreState == CHOOSE)
			{
				sprintf(string, "정말로 매점을 떠나시겠습니까?");
				ScreenPrint(5, 19, string);
				sprintf(string, "뒤로");
				ScreenPrint(60, 22, string);
				sprintf(string, "취소");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "▶");
					ScreenPrint(65, 22, "◀");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "▶");
					ScreenPrint(75, 22, "◀");
				}
			}
			break;
		}
		break;	
	case INVENTORY:
		InterfaceInven();

		sprintf(string, "돈 : %d", Money);
		ScreenPrint(12, 2, string);

		sprintf(string, "관계도 : %d", Score);
		ScreenPrint(30, 2, string);

		SetColor(13);
		sprintf(string, "* 박지혁");
		ScreenPrint(3, 18, string);
		SetColor(7);

		if (g_nInvenState == NOHAVE)
		{
			sprintf(string, "뭐야, 지금 사람놀리는거야?");
			ScreenPrint(5, 19, string);
			sprintf(string, "(관계도 -10 의 변화를 가져왔습니다.)");
			ScreenPrint(5, 20, string);
		}
		else if (g_nInvenState == HAVE)
		{
			sprintf(string, "어라, 고...고마워!");
			ScreenPrint(5, 19, string);
			sprintf(string, "                                     ");
			ScreenPrint(5, 20, string);
		}
		else
		{
			sprintf(string, "응? 나 왜 부른거야?");
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
			ScreenPrint(12, 5, "▶");

			if (g_nInvenState == INVENCHOOSE)
			{
				sprintf(string, "포커칩을 지혁이에게 주겠습니까?");
				ScreenPrint(5, 19, string);
				sprintf(string, "(관계도 +10 의 변화가 나타납니다.)");
				ScreenPrint(5, 20, string);
				sprintf(string, "주기");
				ScreenPrint(60, 22, string);
				sprintf(string, "취소");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "▶");
					ScreenPrint(65, 22, "◀");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "▶");
					ScreenPrint(75, 22, "◀");
				}
			}
			break;
		case 2:
			ScreenPrint(12, 7, "▶");

			if (g_nInvenState == INVENCHOOSE)
			{
				sprintf(string, "피그닉을 지혁이에게 주겠습니까?");
				ScreenPrint(5, 19, string);
				sprintf(string, "(관계도 +3 의 변화가 나타납니다.)");
				ScreenPrint(5, 20, string);
				sprintf(string, "주기");
				ScreenPrint(60, 22, string);
				sprintf(string, "취소");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "▶");
					ScreenPrint(65, 22, "◀");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "▶");
					ScreenPrint(75, 22, "◀");
				}
			}
			break;
		case 3:
			ScreenPrint(12, 9, "▶");

			if (g_nInvenState == INVENCHOOSE)
			{
				sprintf(string, "뻑뻑한 나쵸칩을 지혁이에게 주겠습니까?");
				ScreenPrint(5, 19, string);
				sprintf(string, "(관계도 +10 의 변화가 나타납니다.)");
				ScreenPrint(5, 20, string);
				sprintf(string, "주기");
				ScreenPrint(60, 22, string);
				sprintf(string, "취소");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "▶");
					ScreenPrint(65, 22, "◀");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "▶");
					ScreenPrint(75, 22, "◀");
				}
			}
			break;
		case 4:
			ScreenPrint(12, 11, "▶");

			if (g_nInvenState == INVENCHOOSE)
			{
				sprintf(string, "초코 다아재을 지혁이에게 주겠습니까?");
				ScreenPrint(5, 19, string);
				sprintf(string, "(관계도 +15 의 변화가 나타납니다.)");
				ScreenPrint(5, 20, string);
				sprintf(string, "주기");
				ScreenPrint(60, 22, string);
				sprintf(string, "취소");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "▶");
					ScreenPrint(65, 22, "◀");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "▶");
					ScreenPrint(75, 22, "◀");
				}
			}
			break;
		case 5:
			ScreenPrint(12, 13, "▶");

			if (g_nInvenState == INVENCHOOSE)
			{
				sprintf(string, "게이트웨이 지혁이에게 주겠습니까?");
				ScreenPrint(5, 19, string);
				sprintf(string, "(관계도 +12 의 변화가 나타납니다.)");
				ScreenPrint(5, 20, string);
				sprintf(string, "주기");
				ScreenPrint(60, 22, string);
				sprintf(string, "취소");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "▶");
					ScreenPrint(65, 22, "◀");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "▶");
					ScreenPrint(75, 22, "◀");
				}
			}
			break;
		case 6:
			ScreenPrint(12, 15, "▶");

			if (g_nInvenState == INVENCHOOSE)
			{
				sprintf(string, "정말로 인벤토리를 떠나시겠습니까?");
				ScreenPrint(5, 19, string);
				sprintf(string, "뒤로");
				ScreenPrint(60, 22, string);
				sprintf(string, "취소");
				ScreenPrint(70, 22, string);

				if (ChooseCheak == 1)
				{
					ScreenPrint(57, 22, "▶");
					ScreenPrint(65, 22, "◀");
				}

				if (ChooseCheak == 2)
				{
					ScreenPrint(67, 22, "▶");
					ScreenPrint(75, 22, "◀");
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
		sprintf(string, "* 박지혁");
		ScreenPrint(3, 18, string);
		SetColor(7);

		switch (EndingScene)
		{
		case 1:
			sprintf(string, "나 사실 너 많이 좋아해!");
			ScreenPrint(5, 19, string);
			break;
		case 2:
			sprintf(string, "이런 나라도 날 받아줘!");
			ScreenPrint(5, 19, string);
			break;
		case 3:
			Interface();
			sprintf(string, "~ Fin ~");
			ScreenPrint(36, 11, string);
			sprintf(string, "(이 모든 영광을 지혁이에게 받칩니다.)");
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