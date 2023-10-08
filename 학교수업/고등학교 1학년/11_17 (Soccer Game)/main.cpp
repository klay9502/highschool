#include "Turboc.h"
#include "Screen.h"
#include <fmod.h>

typedef enum GAME_STATE { INIT, READY, RUNNING, STOP, SUCCESS, FAILED, RESULT } GAME_STATE;

typedef struct _GOAL_DAE
{
	int nMoveX, nMoveY;			// �̵� ��ǥ
	int nLength;						// ��� ����
	int nLineX[7];						// ���� ���� x ��ǥ (7��)
	clock_t MoveTime;				// �̵� �ð� ����
	clock_t OldTime;					// ���� �̵� �ð�
	int nDist;							// �̵� �Ÿ�
} GOAL_DAE;

typedef struct _BALL
{
	int nIsReady;						// �غ� ���� ( 1 ), ������( 0 )
	int nMoveX, nMoveY;			// �̵� ��ǥ
	clock_t MoveTime;				// �̵� �ð� ����
	clock_t OldTime;					// ���� �̵� �ð�
} BALL;

typedef struct _PLAYER
{
	int nCenterX, nCenterY;		// �߽���ǥ
	int nMoveX, nMoveY;			// �̵���ǥ
	int nX, nY;
} PLAYER;

typedef struct _EFFECT
{
	clock_t StratTime;				// ȿ�� �߻� �ð�
	clock_t StayTime;				// ȿ�� ���� �ð�
} EFFECT;

typedef struct _STAGE_INFO
{
	int nGoalBall;						// �����ؾ� �� ���� ����
	clock_t LimitTime;				// ���� �ð�
	int nGoalDaeLength;			// ��� ����
	int nGoalDaeX;					// ��� �̵� X ��ǥ
	int nGoalDaeY;					// ��� �̵� Y ��ǥ
	clock_t MoveTime;				// ��� �̵� �ð� ����
	int nDist;							// ��� �̵� �Ÿ�
} STAGE_INFO;

BALL g_sBall;
PLAYER g_sPlayer;
GOAL_DAE g_sGoalDae;
EFFECT g_sEffect;

char g_strPlayer[] = "�����ܦ���";	// ���ΰ� ĳ����
STAGE_INFO g_sStageInfo[] = { {1, 1000 * 20, 1, 20, 3, 300, 1}, {1, 1000 * 30, 2, 20, 5, 300, 1} };
int g_nLength, g_nGoal, g_nBallCount, g_nGoalBallCount, g_nStage = -1, g_nIsGoal;
clock_t g_LimitTime, g_GameStartTime, g_UpdateOldTime;

GAME_STATE g_GameState = INIT;
FMOD_SYSTEM	*g_System;				// FMOD system ���� ����
FMOD_SOUND	*g_Sound[7];				//�������
char				*g_strFileName[7] = { "init.wav", "run.wav", "fail.wav", "ready.wav", "success.wav", "shoot.wav", "wow.wav" };
FMOD_CHANNEL *g_Channel[7];

void InitScreen()
{
	ScreenPrint(0, 0,	"����������������������������������������������");
	ScreenPrint(0, 1,	"��                                          ��");
	ScreenPrint(0, 2,	"��          �ড��������                    ��");
	ScreenPrint(0, 3,	"��                                          ��");
	ScreenPrint(0, 4,	"��                                          ��");
	ScreenPrint(0, 5,	"��                       ///.  ��~~~        ��");
	ScreenPrint(0, 6,	"��                      (^.^)               ��");
	ScreenPrint(0, 7,	"��                     ���� ����            ��");
	ScreenPrint(0, 8,	"��                        ����              ��");
	ScreenPrint(0, 9,	"��                    ��  ����              ��");
	ScreenPrint(0, 10,	"��                                          ��");
	ScreenPrint(0, 11,	"��       �� ���� ���� Go! Go!               ��");
	ScreenPrint(0, 12,	"��                                          ��");
	ScreenPrint(0, 13,	"��                                          ��");
	ScreenPrint(0, 14,	"��       j : ���� l : ������ k : ��         ��");
	ScreenPrint(0, 15,	"��                                          ��");
	ScreenPrint(0, 16,	"��                                          ��");
	ScreenPrint(0, 17,	"��                                          ��");
	ScreenPrint(0, 18,	"��        ���ܦ� space Ű�� �����ּ���      ��");
	ScreenPrint(0, 19,	"��                                          ��");
	ScreenPrint(0, 20,	"��                                          ��");
	ScreenPrint(0, 21,	"��                                          ��");
	ScreenPrint(0, 22,	"����������������������������������������������");
}

void ReadyScreen()
{
	char string[100];

	ScreenPrint(0, 0,	"����������������������������������������������");
	ScreenPrint(0, 1,	"�����������������������ᦢ");
	ScreenPrint(0, 2,	"�����������������������ᦢ");
	ScreenPrint(0, 3,	"�����������������������ᦢ");
	ScreenPrint(0, 4,	"�����������������������ᦢ");
	ScreenPrint(0, 5,	"�����������������������ᦢ");
	ScreenPrint(0, 6,	"�����������������������ᦢ");
	ScreenPrint(0, 7,	"�����������������������ᦢ");
	ScreenPrint(0, 8,	"�����������������������ᦢ");
	ScreenPrint(0, 9,	"�����������������������ᦢ");
	ScreenPrint(0, 10,	"��������                    ������ᦢ");
	sprintf(string,	    "��������    %d  ��������    ������ᦢ");
	ScreenPrint(0, 11, string);
	ScreenPrint(0, 12,	"��������                    ������ᦢ");
	ScreenPrint(0, 13,	"�����������������������ᦢ");
	ScreenPrint(0, 14,	"�����������������������ᦢ");
	ScreenPrint(0, 15,	"�����������������������ᦢ");
	ScreenPrint(0, 16,	"�����������������������ᦢ");
	ScreenPrint(0, 17,	"�����������������������ᦢ");
	ScreenPrint(0, 18,	"�����������������������ᦢ");
	ScreenPrint(0, 19,	"�����������������������ᦢ");
	ScreenPrint(0, 20,	"�����������������������ᦢ");
	ScreenPrint(0, 21,	"�����������������������ᦢ");
	ScreenPrint(0, 22,	"�����������������������ᦢ");
	ScreenPrint(0, 23,	"����������������������������������������������");
}

void BackScreen()
{
	char string[100];

	ScreenPrint(0, 0,	"����������������������������������������������");
	ScreenPrint(0, 1,	"��                                          ��");
	ScreenPrint(0, 2,	"��                                          ��");
	ScreenPrint(0, 3,	"��                                          ��");
	sprintf(string,     "��                                          ���������� : %d", g_nStage + 1);
	ScreenPrint(0, 4, string);
	ScreenPrint(0, 5,	"��                                          ��");
	sprintf(string,     "�������������������������������������������������� �ð� : %d", g_sStageInfo[g_nStage].LimitTime / 1000);
	ScreenPrint(0, 6, string);
	ScreenPrint(0, 7,	"��                                          ��");
	sprintf(string,     "��                                          ������ �ð� : %d", (clock() - g_GameStartTime) / 1000 );
	ScreenPrint(0, 8, string);
	ScreenPrint(0, 9,	"��                                          ��");
	sprintf(string,     "��                                          ����ǥ ���� : %d", g_sStageInfo[g_nStage].nGoalBall);
	ScreenPrint(0, 10, string);
	ScreenPrint(0, 11,  "��                                          ��");
	sprintf(string,     "��                                          ������ �� ���� : %d", g_nBallCount);
	ScreenPrint(0, 12, string);
	ScreenPrint(0, 13,	"��                                          ��");
	ScreenPrint(0, 14,	"��                                          ��");
	ScreenPrint(0, 15,	"��                                          ��");
	ScreenPrint(0, 16,	"��                                          ��");
	ScreenPrint(0, 17,	"��                                          ��");
	ScreenPrint(0, 18,	"��                                          ��");
	ScreenPrint(0, 19,	"��                                          ��");
	ScreenPrint(0, 20,	"��                                          ��");
	ScreenPrint(0, 21,	"��                                          ��");
	ScreenPrint(0, 22,	"��                                          ��");
	ScreenPrint(0, 23,	"����������������������������������������������");
}

void GoalMessage(int nX, int nY)
{
	ScreenPrint(nX, nY,		"�� )) ���� (( ��");
	ScreenPrint(nX, nY + 1, "��(^^')/ ��(\��*')/");
	ScreenPrint(nX, nY + 2, "   ��       ��");
	ScreenPrint(nX, nY + 3, "  ����    ����");
}

void SuccessScreen()
{
	ScreenPrint(0, 0,	"����������������������������������������������");
	ScreenPrint(0, 1,	"��                                          ��");
	ScreenPrint(0, 2,	"��                                          ��");
	ScreenPrint(0, 3,	"��                                          ��");
	ScreenPrint(0, 4,	"��                                          ��");
	ScreenPrint(0, 5,	"��                                          ��");
	ScreenPrint(0, 6,	"��                ////����                  ��");
	ScreenPrint(0, 7,	"��               q ��  �� p                 ��");
	ScreenPrint(0, 8,	"��               (��������)                 ��");
	ScreenPrint(0, 9,	"��              �ݹ̼� ������               ��");
	ScreenPrint(0, 10,	"��                                          ��");
	ScreenPrint(0, 11,  "��                                          ��");
	ScreenPrint(0, 12,	"��                                          ��");
	ScreenPrint(0, 13,	"��                                          ��");
	ScreenPrint(0, 14,	"��                                          ��");
	ScreenPrint(0, 15,	"��                                          ��");
	ScreenPrint(0, 16,	"��                                          ��");
	ScreenPrint(0, 17,	"��                                          ��");
	ScreenPrint(0, 18,	"��                                          ��");
	ScreenPrint(0, 19,	"��                                          ��");
	ScreenPrint(0, 20,	"��                                          ��");
	ScreenPrint(0, 21,	"��                                          ��");
	ScreenPrint(0, 22,	"��                                          ��");
	ScreenPrint(0, 23,	"����������������������������������������������");

}

void FailureScreen()
{
	ScreenPrint(0, 0,	"����������������������������������������������");
	ScreenPrint(0, 1,	"��                                          ��");
	ScreenPrint(0, 2,	"��                                          ��");
	ScreenPrint(0, 3,	"��                                          ��");
	ScreenPrint(0, 4,	"��                                          ��");
	ScreenPrint(0, 5,	"��                                          ��");
	ScreenPrint(0, 6,	"��                                          ��");
	ScreenPrint(0, 7,	"��                                          ��");
	ScreenPrint(0, 8,	"��                                          ��");
	ScreenPrint(0, 9,	"��                                          ��");
	ScreenPrint(0, 10,	"��                                          ��");
	ScreenPrint(0, 11,  "��                      �̼� ���� !!!       ��");
	ScreenPrint(0, 12,	"��                                          ��");
	ScreenPrint(0, 13,	"��                                          ��");
	ScreenPrint(0, 14,	"��                �ܦ�����                  ��");
	ScreenPrint(0, 15,	"��                  ��  ��                  ��");
	ScreenPrint(0, 16,	"��                 �����                 ��");
	ScreenPrint(0, 17,	"��                                          ��");
	ScreenPrint(0, 18,	"��         �ٽ� �Ͻðڽ��ϱ�? (y/n)         ��");
	ScreenPrint(0, 19,	"��                                          ��");
	ScreenPrint(0, 20,	"��                                          ��");
	ScreenPrint(0, 21,	"��                                          ��");
	ScreenPrint(0, 22,	"����������������������������������������������");
}

void ResultScreen()
{
	char string[100];
	
	ScreenPrint(0, 0,	"����������������������������������������������");
	ScreenPrint(0, 1,	"��                                          ��");
	ScreenPrint(0, 2,	"��                                          ��");
	ScreenPrint(0, 3,	"��          �ড������                      ��");
	ScreenPrint(0, 4,	"��                                          ��");
	ScreenPrint(0, 5,	"��                                          ��");
	ScreenPrint(0, 6,	"��                                          ��");
	ScreenPrint(0, 7,	"��                                          ��");
	sprintf(string,     "��         ������ �������� : %2d            ��", g_nStage);
	ScreenPrint(0, 8, string);
	ScreenPrint(0, 9,	"��                                          ��");
	ScreenPrint(0, 10,	"��                                          ��");
	ScreenPrint(0, 11,  "��   ___�ƢƢ�___                           ��");
	ScreenPrint(0, 12,	"��     (*^  ^*)                             ��");
	ScreenPrint(0, 13,	"�� =====��==��=====                         ��");
	ScreenPrint(0, 14,	"��                                          ��");
	ScreenPrint(0, 15,	"��                                          ��");
	ScreenPrint(0, 16,	"��                                          ��");
	ScreenPrint(0, 17,	"��                                          ��");
	ScreenPrint(0, 18,	"��                        ���ܦ�            ��");
	ScreenPrint(0, 19,	"��                                          ��");
	ScreenPrint(0, 20,	"��                                          ��");
	ScreenPrint(0, 21,	"��                                          ��");
	ScreenPrint(0, 22,	"����������������������������������������������");
}

void SoundInit()
{
	int i;

	FMOD_System_Create(&g_System);
	FMOD_System_Init(g_System, 32, FMOD_INIT_NORMAL, NULL);

	for (i = 0; i < 3; i++)
		FMOD_System_CreateSound(g_System, g_strFileName[i], FMOD_LOOP_NORMAL, 0, &g_Sound[i]);

	for (i = 3; i < 7; i++)
		FMOD_System_CreateSound(g_System, g_strFileName[i], FMOD_DEFAULT, 0, &g_Sound[i]);
}

// Note: �ʱ�ȭ
void Init()
{
	int nLength, i;

	if (g_nStage == -1)
	{
		SoundInit();	// ���� �ʱ�ȭ
		g_nStage = 0;
		FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[0], 0, &g_Channel[0]);	// �Ұ� ����� ��ü���� �ѹ��� �����Ѵ�.
	}

	g_LimitTime = g_sStageInfo[g_nStage].LimitTime;		// ���� �ð� ����
	g_nGoalBallCount = g_sStageInfo[g_nStage].nGoalBall;	// ��ǥ ���� ����

	g_sPlayer.nCenterX = 4;		// ���ΰ� ĳ������ �߽���ǥ
	g_sPlayer.nCenterY = 0;		// ���ΰ� ĳ������ �߽���ǥ
	g_sPlayer.nMoveX = 20;		// ���ΰ� ĳ������ �̵���ǥ �ʱ�ȭ
	g_sPlayer.nMoveY = 5;		// ���ΰ� ĳ������ �̵���ǥ �ʱ�ȭ
	g_sPlayer.nX = g_sPlayer.nMoveX - g_sPlayer.nCenterX;		// ��±�����ǥ = �̵���ǥ - �߽���ǥ
	g_nLength = strlen( g_strPlayer );		// ���ΰ� ĳ������ ��ü ����

	// ���� �ʱ�ȭ
	g_sBall.nIsReady = 1;
	g_sBall.nMoveX = g_sPlayer.nMoveX;
	g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
	g_sBall.MoveTime = 100;

	// ��� �ʱ�ȭ
	g_sGoalDae.nMoveX = g_sStageInfo[g_nStage].nGoalDaeX;			// 69
	g_sGoalDae.nMoveY = g_sStageInfo[g_nStage].nGoalDaeY;
	g_sGoalDae.nLength = g_sStageInfo[g_nStage].nGoalDaeLength;
	g_sGoalDae.MoveTime = g_sStageInfo[g_nStage].MoveTime;
	g_sGoalDae.OldTime = clock();
	g_sGoalDae.nDist = g_sStageInfo[g_nStage].nDist;
	nLength = g_sGoalDae.nLength * 2 + 1;		// Note: �迭�� �ִ� ����, ����μ� ���

	for (i = 0; i < nLength; i++)
	{
		g_sGoalDae.nLineX[i] = g_sGoalDae.nMoveX + 2 * (i + 1);
	}

	// ȿ��
	g_sEffect.StayTime = 2000;	// 2�� ����
	g_nGoal = 0;	// �������� �Ϸ� ����
	g_UpdateOldTime = clock();
	g_nBallCount = 0;	// ������ ���� ����
}

// Note: ������ ����
void Update()
{
	clock_t CurTime = clock();
	int nLength = g_sGoalDae.nLength * 2 + 1;	// Note: �迭�� �ִ� ����
	int i;

	switch(g_GameState)
	{
	case READY:
		if (CurTime - g_UpdateOldTime > 2000)	// 2��
		{
			g_GameState = RUNNING;
			g_GameStartTime = CurTime;

			FMOD_Channel_Stop(g_Channel[3]);	// ready ���� ����
			FMOD_System_PlaySound(g_System, FMOD_CHANNEL_FREE, g_Sound[1], 0, &g_Channel[1]);	// running �����
		}
		break;
	case RUNNING:
		if (CurTime - g_GameStartTime > g_LimitTime)	// Note: ���� �ð�
		{
			g_GameState = STOP;
			return ;
		}
		else
		{
			// Note: ���
			if( CurTime - g_sGoalDae.OldTime > g_sGoalDae.MoveTime)
			{
				g_sGoalDae.OldTime = CurTime;

				if (g_sGoalDae.nMoveX + g_sGoalDae.nDist >= 2 && ((g_sGoalDae.nLineX[nLength - 1] + 3) + g_sGoalDae.nDist) <= 43)
				{
					g_sGoalDae.nMoveX += g_sGoalDae.nDist;
					
					for (i = 0; i < nLength; i++)
					{
						g_sGoalDae.nLineX[i] = g_sGoalDae.nMoveX + 2 * (i + 1);
					}
				}
				else
				{
					g_sGoalDae.nDist = g_sGoalDae.nDist * -1;	// -1 �� ������ �ٲپ� ��.
				}
			}

			if (g_sBall.nIsReady == 0)	// �̵� ���� ��
			{	// �̵� �ð� ���ݿ� ���� �̵�
				if (CurTime - g_sBall.OldTime > g_sBall.MoveTime)
				{
					if(g_sBall.nMoveY - 1 > 0)
					{
						g_sBall.nMoveY--;
						g_sBall.OldTime = CurTime;	// ���� �̵� �ð��� ���ϱ� ���� ���� �ð��� ���� �ð� ������ ����

						// ��� ���� �浹

						if (g_sBall.nMoveX >= g_sGoalDae.nLineX[0] && g_sBall.nMoveX + 1 <= g_sGoalDae.nLineX[nLength - 1] + 1)
						{
							if (g_sBall.nMoveY <= g_sGoalDae.nMoveY)
							{	// �� �ʱ�ȭ
								g_sBall.nIsReady = 1;
								g_sBall.nMoveX = g_sPlayer.nMoveX;
								g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
								g_nBallCount++;		// ������ ���� ����

								if (g_nBallCount == g_nGoalBallCount)	// ���� ��ǥ ������ ������ ������ SUCCESS
								{
									g_GameState = STOP;
									g_nGoal = 1;
									return ;
								}

								// ȿ�� ���
								if (g_nIsGoal == 0)
								{
									g_nIsGoal = 1;
									g_sEffect.StratTime = CurTime;
								}

								// ���� ���� ���
								FMOD_System_PlaySound(g_System, FMOD_CHANNEL_FREE, g_Sound[6], 0, &g_Channel[6]);	// ���� ���� '�Ϳ�~'
							}
						}
						else if((g_sBall.nMoveX >= g_sGoalDae.nMoveX && g_sBall.nMoveX <= g_sGoalDae.nMoveX + 1) || 
								(g_sBall.nMoveX+1 >= g_sGoalDae.nMoveX  && g_sBall.nMoveX+1 <= g_sGoalDae.nMoveX + 1) ||
								(g_sBall.nMoveX >= g_sGoalDae.nLineX[nLength-1]+2  && g_sBall.nMoveX <= g_sGoalDae.nLineX[nLength-1]+3 ) ||
								(g_sBall.nMoveX+1 >= g_sGoalDae.nLineX[nLength-1]+2  && g_sBall.nMoveX+1 <= g_sGoalDae.nLineX[nLength-1]+3 ))
						{
							if (g_sBall.nMoveX <= g_sGoalDae.nMoveY)
							{
								// �� �ʱ�ȭ
								g_sBall.nIsReady = 1;
								g_sBall.nMoveX = g_sPlayer.nMoveX;
								g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
							}
						}
					}
					else
					{
						// �� �ʱ�ȭ
						g_sBall.nIsReady = 1;
						g_sBall.nMoveX = g_sPlayer.nMoveX;
						g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
					}
				}
			}
			else
			{
				g_sBall.nMoveX = g_sPlayer.nMoveX;
			}

			// ȿ��
			if (g_nIsGoal == 1)
			{
				if (CurTime - g_sEffect.StratTime > g_sEffect.StayTime)
					g_nIsGoal = 0;
			}
		}
		break;
	case STOP:
		if (g_nGoal == 1)
		{
			g_GameState = SUCCESS;
			g_UpdateOldTime = CurTime;
			FMOD_Channel_Stop(g_Channel[1]);		// running ���� ����
			FMOD_Channel_Stop(g_Channel[1]);		// running ���� ����

			FMOD_System_PlaySound(g_System, FMOD_CHANNEL_FREE, g_Sound[4], 0, &g_Channel[4]);	// �̼� ���� ����
		}
		else
		{
			g_GameState = FAILED;
			FMOD_Channel_Stop(g_Channel[1]);		// running ���� ����
			FMOD_System_PlaySound(g_System, FMOD_CHANNEL_FREE, g_Sound[2], 0, &g_Channel[2]);	// �̼� ���� ����
		}
		break;
	case SUCCESS:
		if(CurTime - g_UpdateOldTime > 3000)
		{
			g_UpdateOldTime = CurTime;
			++g_nStage;
			
			if (g_nStage == 2)
			{
				g_GameState = RESULT;
				break;
			}
			Init();
			g_GameState = READY;
			FMOD_Channel_Stop(g_Channel[4]);	// �̼� ���� ���� ��� ����
			FMOD_System_PlaySound(g_System, FMOD_CHANNEL_FREE, g_Sound[3], 0, &g_Channel[3]);		// READY ����
		}
		break;
	case RESULT:
		if (CurTime - g_UpdateOldTime > 3000)
			exit(0);
		break;	
	}
}

// Note: ������
void Render()
{
	char string[100] = {0, };
	int nLength, i;

	ScreenClear();

	switch(g_GameState)
	{
	case INIT:
		if (g_nStage == 0)
			InitScreen();
		break;
	case READY:
		ReadyScreen();
		break;
	case RUNNING:
		BackScreen();
		ScreenPrint(g_sGoalDae.nMoveX, g_sGoalDae.nMoveY, "��");
		nLength = g_sGoalDae.nLength * 2 + 1;

		for (i = 0; i < nLength; i++)
			ScreenPrint(g_sGoalDae.nLineX[i], g_sGoalDae.nMoveY, "��");

		ScreenPrint(g_sGoalDae.nLineX[nLength - 1] + 1, g_sGoalDae.nMoveY, "��");

		// Note: ȿ�� ���
		if (g_nIsGoal == 1)
		{
			GoalMessage(10, 10);
		}

		// Note: 2 �÷��� Ŭ����
		if (g_sPlayer.nX < 2)	// ���� Ŭ���� ó��
			ScreenPrint(2, g_sPlayer.nMoveY, &g_strPlayer[(g_sPlayer.nX - 2) * -1]);
		else if(g_sPlayer.nMoveX + (g_nLength - g_sPlayer.nCenterX + 1) > 43)		// ������ Ŭ���� ó��
		{
			strncat(string, g_strPlayer, g_nLength - ((g_sPlayer.nMoveX + g_sPlayer.nCenterX + 1) - 43));
			ScreenPrint(g_sPlayer.nX, g_sPlayer.nMoveY, string);
		}
		else	// 1 �÷��� �̵�
		{
			ScreenPrint(g_sPlayer.nX, g_sBall.nMoveY, g_strPlayer);
		}

		ScreenPrint(g_sBall.nMoveX, g_sBall.nMoveY, "��");
		break;
	case SUCCESS:
		SuccessScreen();
		break;
	case FAILED:
		FailureScreen();
		break;
	case RESULT:
		ResultScreen();
		break;
	}

	// Note: ������ ��
	ScreenFlipping();
}

// Note: ����
void Release()
{
	int i;
	
	for (i = 0; i < 7; i++)
		FMOD_Sound_Release(g_Sound[i]);

	FMOD_System_Close(g_System);
	FMOD_System_Release(g_System);
}

int main(void)
{
	int nKey, nRemain;

	ScreenInit();
	Init();				// �ʱ�ȭ

	while (1)
	{
		if (_kbhit())
		{
			nKey = _getch();

			switch(nKey)
			{
			case 'j':
				if (g_sPlayer.nMoveX > 2)	// ���� �浹 ��� ��ǥ üũ
				{
					g_sPlayer.nMoveX--;
					nRemain = g_nLength - g_sPlayer.nCenterX + 1;	// ��ü ���� - (�߽� ��ǥ + 1)�� ���� ����
					// Note: 2�÷��� �̵��ϱ� ���� �κ�(���� ��ģ ���)
					if (g_sPlayer.nMoveX - g_sPlayer.nCenterX < 2 || g_sPlayer.nMoveX + nRemain > 43)
						g_sPlayer.nMoveX--;

					g_sPlayer.nX = g_sPlayer.nMoveX - g_sPlayer.nCenterX;
				}
				break;
			case 'l':
				if (g_sPlayer.nMoveX + 1 < 43)	// ������ �浹 ��� ��ǥ üũ
				{
					g_sPlayer.nMoveX++;
					nRemain = g_nLength - g_sPlayer.nCenterX + 1;	// ��ü ���� - (�߽� ��ǥ + 1)�� ���� ����
					// Note: 2�÷��� �̵��ϱ� ���� �κ�(���� ��ģ ���)
					if (g_sPlayer.nMoveX + nRemain > 43 || (g_sPlayer.nMoveX - g_sPlayer.nCenterX < 2) )
						g_sPlayer.nMoveX++;

					g_sPlayer.nX = g_sPlayer.nMoveX - g_sPlayer.nCenterX;
				}
				break;

			case 'k':
				if (g_sBall.nIsReady && g_GameState == RUNNING)
				{
					g_sBall.nMoveX = g_sPlayer.nMoveX;
					g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
					g_sBall.OldTime = clock();
					g_sBall.nIsReady = 0;
					FMOD_System_PlaySound(g_System, FMOD_CHANNEL_FREE, g_Sound[5], 0, &g_Channel[5]);	// �� ���� �Ҹ� ���
				}
				break;
			}
		}

		Update();		// ������ ����
		Render();		// ȭ�� ���
	}

	Release();			// ����
	ScreenRelease();
	return 0;
}