#include "Turboc.h"
#include "Screen.h"
#include <fmod.h>

typedef enum GAME_STATE { INIT, READY, RUNNING, STOP, SUCCESS, FAILED, RESULT } GAME_STATE;

typedef struct _GOAL_DAE
{
	int nMoveX, nMoveY;			// 이동 좌표
	int nLength;						// 골대 길이
	int nLineX[7];						// 골인 라인 x 좌표 (7개)
	clock_t MoveTime;				// 이동 시간 간격
	clock_t OldTime;					// 이전 이동 시간
	int nDist;							// 이동 거리
} GOAL_DAE;

typedef struct _BALL
{
	int nIsReady;						// 준비 상태 ( 1 ), 슛상태( 0 )
	int nMoveX, nMoveY;			// 이동 좌표
	clock_t MoveTime;				// 이동 시간 간격
	clock_t OldTime;					// 이전 이동 시각
} BALL;

typedef struct _PLAYER
{
	int nCenterX, nCenterY;		// 중심좌표
	int nMoveX, nMoveY;			// 이동좌표
	int nX, nY;
} PLAYER;

typedef struct _EFFECT
{
	clock_t StratTime;				// 효과 발생 시각
	clock_t StayTime;				// 효과 지속 시간
} EFFECT;

typedef struct _STAGE_INFO
{
	int nGoalBall;						// 골인해야 할 볼의 개수
	clock_t LimitTime;				// 제한 시간
	int nGoalDaeLength;			// 골대 길이
	int nGoalDaeX;					// 골대 이동 X 좌표
	int nGoalDaeY;					// 골대 이동 Y 좌표
	clock_t MoveTime;				// 골대 이동 시간 간격
	int nDist;							// 골대 이동 거리
} STAGE_INFO;

BALL g_sBall;
PLAYER g_sPlayer;
GOAL_DAE g_sGoalDae;
EFFECT g_sEffect;

char g_strPlayer[] = "└─●─┘";	// 주인공 캐릭터
STAGE_INFO g_sStageInfo[] = { {1, 1000 * 20, 1, 20, 3, 300, 1}, {1, 1000 * 30, 2, 20, 5, 300, 1} };
int g_nLength, g_nGoal, g_nBallCount, g_nGoalBallCount, g_nStage = -1, g_nIsGoal;
clock_t g_LimitTime, g_GameStartTime, g_UpdateOldTime;

GAME_STATE g_GameState = INIT;
FMOD_SYSTEM	*g_System;				// FMOD system 변수 선언
FMOD_SOUND	*g_Sound[7];				//배경음악
char				*g_strFileName[7] = { "init.wav", "run.wav", "fail.wav", "ready.wav", "success.wav", "shoot.wav", "wow.wav" };
FMOD_CHANNEL *g_Channel[7];

void InitScreen()
{
	ScreenPrint(0, 0,	"┌─────────────────────┐");
	ScreenPrint(0, 1,	"│                                          │");
	ScreenPrint(0, 2,	"│          □────□                    │");
	ScreenPrint(0, 3,	"│                                          │");
	ScreenPrint(0, 4,	"│                                          │");
	ScreenPrint(0, 5,	"│                       ///.  슛~~~        │");
	ScreenPrint(0, 6,	"│                      (^.^)               │");
	ScreenPrint(0, 7,	"│                     └┤ ├┐            │");
	ScreenPrint(0, 8,	"│                        ┌┘              │");
	ScreenPrint(0, 9,	"│                    ◎  ┘＼              │");
	ScreenPrint(0, 10,	"│                                          │");
	ScreenPrint(0, 11,	"│       슛 골인 게임 Go! Go!               │");
	ScreenPrint(0, 12,	"│                                          │");
	ScreenPrint(0, 13,	"│                                          │");
	ScreenPrint(0, 14,	"│       j : 왼쪽 l : 오른쪽 k : 슛         │");
	ScreenPrint(0, 15,	"│                                          │");
	ScreenPrint(0, 16,	"│                                          │");
	ScreenPrint(0, 17,	"│                                          │");
	ScreenPrint(0, 18,	"│        └●┘ space 키를 눌러주세요      │");
	ScreenPrint(0, 19,	"│                                          │");
	ScreenPrint(0, 20,	"│                                          │");
	ScreenPrint(0, 21,	"│                                          │");
	ScreenPrint(0, 22,	"└─────────────────────┘");
}

void ReadyScreen()
{
	char string[100];

	ScreenPrint(0, 0,	"┌─────────────────────┐");
	ScreenPrint(0, 1,	"│■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 2,	"│■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 3,	"│■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 4,	"│■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 5,	"│■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 6,	"│■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 7,	"│■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 8,	"│■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 9,	"│■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 10,	"│■■■■■                    ■■■■■■│");
	sprintf(string,	    "│■■■■■    %d  스테이지    ■■■■■■│");
	ScreenPrint(0, 11, string);
	ScreenPrint(0, 12,	"│■■■■■                    ■■■■■■│");
	ScreenPrint(0, 13,	"│■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 14,	"│■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 15,	"│■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 16,	"│■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 17,	"│■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 18,	"│■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 19,	"│■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 20,	"│■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 21,	"│■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 22,	"│■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 23,	"└─────────────────────┘");
}

void BackScreen()
{
	char string[100];

	ScreenPrint(0, 0,	"┌─────────────────────┐");
	ScreenPrint(0, 1,	"│                                          │");
	ScreenPrint(0, 2,	"│                                          │");
	ScreenPrint(0, 3,	"│                                          │");
	sprintf(string,     "│                                          │스테이지 : %d", g_nStage + 1);
	ScreenPrint(0, 4, string);
	ScreenPrint(0, 5,	"│                                          │");
	sprintf(string,     "├─────────────────────┤제한 시간 : %d", g_sStageInfo[g_nStage].LimitTime / 1000);
	ScreenPrint(0, 6, string);
	ScreenPrint(0, 7,	"│                                          │");
	sprintf(string,     "│                                          │현재 시간 : %d", (clock() - g_GameStartTime) / 1000 );
	ScreenPrint(0, 8, string);
	ScreenPrint(0, 9,	"│                                          │");
	sprintf(string,     "│                                          │목표 골인 : %d", g_sStageInfo[g_nStage].nGoalBall);
	ScreenPrint(0, 10, string);
	ScreenPrint(0, 11,  "│                                          │");
	sprintf(string,     "│                                          │골인 공 개수 : %d", g_nBallCount);
	ScreenPrint(0, 12, string);
	ScreenPrint(0, 13,	"│                                          │");
	ScreenPrint(0, 14,	"│                                          │");
	ScreenPrint(0, 15,	"│                                          │");
	ScreenPrint(0, 16,	"│                                          │");
	ScreenPrint(0, 17,	"│                                          │");
	ScreenPrint(0, 18,	"│                                          │");
	ScreenPrint(0, 19,	"│                                          │");
	ScreenPrint(0, 20,	"│                                          │");
	ScreenPrint(0, 21,	"│                                          │");
	ScreenPrint(0, 22,	"│                                          │");
	ScreenPrint(0, 23,	"└─────────────────────┘");
}

void GoalMessage(int nX, int nY)
{
	ScreenPrint(nX, nY,		"☆ )) 골인 (( ★");
	ScreenPrint(nX, nY + 1, "＼(^^')/ ＼(\“*')/");
	ScreenPrint(nX, nY + 2, "   ■       ■");
	ScreenPrint(nX, nY + 3, "  ┘┐    ┌└");
}

void SuccessScreen()
{
	ScreenPrint(0, 0,	"┌─────────────────────┐");
	ScreenPrint(0, 1,	"│                                          │");
	ScreenPrint(0, 2,	"│                                          │");
	ScreenPrint(0, 3,	"│                                          │");
	ScreenPrint(0, 4,	"│                                          │");
	ScreenPrint(0, 5,	"│                                          │");
	ScreenPrint(0, 6,	"│                ////＼＼                  │");
	ScreenPrint(0, 7,	"│               q ∧  ∧ p                 │");
	ScreenPrint(0, 8,	"│               (└──┘)                 │");
	ScreenPrint(0, 9,	"│              ♬미션 성공♪               │");
	ScreenPrint(0, 10,	"│                                          │");
	ScreenPrint(0, 11,  "│                                          │");
	ScreenPrint(0, 12,	"│                                          │");
	ScreenPrint(0, 13,	"│                                          │");
	ScreenPrint(0, 14,	"│                                          │");
	ScreenPrint(0, 15,	"│                                          │");
	ScreenPrint(0, 16,	"│                                          │");
	ScreenPrint(0, 17,	"│                                          │");
	ScreenPrint(0, 18,	"│                                          │");
	ScreenPrint(0, 19,	"│                                          │");
	ScreenPrint(0, 20,	"│                                          │");
	ScreenPrint(0, 21,	"│                                          │");
	ScreenPrint(0, 22,	"│                                          │");
	ScreenPrint(0, 23,	"└─────────────────────┘");

}

void FailureScreen()
{
	ScreenPrint(0, 0,	"┌─────────────────────┐");
	ScreenPrint(0, 1,	"│                                          │");
	ScreenPrint(0, 2,	"│                                          │");
	ScreenPrint(0, 3,	"│                                          │");
	ScreenPrint(0, 4,	"│                                          │");
	ScreenPrint(0, 5,	"│                                          │");
	ScreenPrint(0, 6,	"│                                          │");
	ScreenPrint(0, 7,	"│                                          │");
	ScreenPrint(0, 8,	"│                                          │");
	ScreenPrint(0, 9,	"│                                          │");
	ScreenPrint(0, 10,	"│                                          │");
	ScreenPrint(0, 11,  "│                      미션 실패 !!!       │");
	ScreenPrint(0, 12,	"│                                          │");
	ScreenPrint(0, 13,	"│                                          │");
	ScreenPrint(0, 14,	"│                ●┬─┐                  │");
	ScreenPrint(0, 15,	"│                  ┘  └                  │");
	ScreenPrint(0, 16,	"│                 ■■■■                 │");
	ScreenPrint(0, 17,	"│                                          │");
	ScreenPrint(0, 18,	"│         다시 하시겠습니까? (y/n)         │");
	ScreenPrint(0, 19,	"│                                          │");
	ScreenPrint(0, 20,	"│                                          │");
	ScreenPrint(0, 21,	"│                                          │");
	ScreenPrint(0, 22,	"└─────────────────────┘");
}

void ResultScreen()
{
	char string[100];
	
	ScreenPrint(0, 0,	"┌─────────────────────┐");
	ScreenPrint(0, 1,	"│                                          │");
	ScreenPrint(0, 2,	"│                                          │");
	ScreenPrint(0, 3,	"│          □───□                      │");
	ScreenPrint(0, 4,	"│                                          │");
	ScreenPrint(0, 5,	"│                                          │");
	ScreenPrint(0, 6,	"│                                          │");
	ScreenPrint(0, 7,	"│                                          │");
	sprintf(string,     "│         성공한 스테이지 : %2d            │", g_nStage);
	ScreenPrint(0, 8, string);
	ScreenPrint(0, 9,	"│                                          │");
	ScreenPrint(0, 10,	"│                                          │");
	ScreenPrint(0, 11,  "│   ___▒▒▒___                           │");
	ScreenPrint(0, 12,	"│     (*^  ^*)                             │");
	ScreenPrint(0, 13,	"│ =====○==○=====                         │");
	ScreenPrint(0, 14,	"│                                          │");
	ScreenPrint(0, 15,	"│                                          │");
	ScreenPrint(0, 16,	"│                                          │");
	ScreenPrint(0, 17,	"│                                          │");
	ScreenPrint(0, 18,	"│                        └●┘            │");
	ScreenPrint(0, 19,	"│                                          │");
	ScreenPrint(0, 20,	"│                                          │");
	ScreenPrint(0, 21,	"│                                          │");
	ScreenPrint(0, 22,	"└─────────────────────┘");
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

// Note: 초기화
void Init()
{
	int nLength, i;

	if (g_nStage == -1)
	{
		SoundInit();	// 사운드 초기화
		g_nStage = 0;
		FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[0], 0, &g_Channel[0]);	// 소개 사운드는 전체에서 한번만 실행한다.
	}

	g_LimitTime = g_sStageInfo[g_nStage].LimitTime;		// 제한 시간 설정
	g_nGoalBallCount = g_sStageInfo[g_nStage].nGoalBall;	// 목표 골인 개수

	g_sPlayer.nCenterX = 4;		// 주인공 캐릭터의 중심좌표
	g_sPlayer.nCenterY = 0;		// 주인공 캐릭터의 중심좌표
	g_sPlayer.nMoveX = 20;		// 주인공 캐릭터의 이동좌표 초기화
	g_sPlayer.nMoveY = 5;		// 주인공 캐릭터의 이동좌표 초기화
	g_sPlayer.nX = g_sPlayer.nMoveX - g_sPlayer.nCenterX;		// 출력기준좌표 = 이동좌표 - 중심좌표
	g_nLength = strlen( g_strPlayer );		// 주인공 캐릭터의 전체 길이

	// 공의 초기화
	g_sBall.nIsReady = 1;
	g_sBall.nMoveX = g_sPlayer.nMoveX;
	g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
	g_sBall.MoveTime = 100;

	// 골대 초기화
	g_sGoalDae.nMoveX = g_sStageInfo[g_nStage].nGoalDaeX;			// 69
	g_sGoalDae.nMoveY = g_sStageInfo[g_nStage].nGoalDaeY;
	g_sGoalDae.nLength = g_sStageInfo[g_nStage].nGoalDaeLength;
	g_sGoalDae.MoveTime = g_sStageInfo[g_nStage].MoveTime;
	g_sGoalDae.OldTime = clock();
	g_sGoalDae.nDist = g_sStageInfo[g_nStage].nDist;
	nLength = g_sGoalDae.nLength * 2 + 1;		// Note: 배열의 최대 길이, 골라인수 계산

	for (i = 0; i < nLength; i++)
	{
		g_sGoalDae.nLineX[i] = g_sGoalDae.nMoveX + 2 * (i + 1);
	}

	// 효과
	g_sEffect.StayTime = 2000;	// 2초 설정
	g_nGoal = 0;	// 스테이지 완료 변수
	g_UpdateOldTime = clock();
	g_nBallCount = 0;	// 골인한 공의 개수
}

// Note: 데이터 갱신
void Update()
{
	clock_t CurTime = clock();
	int nLength = g_sGoalDae.nLength * 2 + 1;	// Note: 배열의 최대 길이
	int i;

	switch(g_GameState)
	{
	case READY:
		if (CurTime - g_UpdateOldTime > 2000)	// 2초
		{
			g_GameState = RUNNING;
			g_GameStartTime = CurTime;

			FMOD_Channel_Stop(g_Channel[3]);	// ready 사운드 중지
			FMOD_System_PlaySound(g_System, FMOD_CHANNEL_FREE, g_Sound[1], 0, &g_Channel[1]);	// running 배경음
		}
		break;
	case RUNNING:
		if (CurTime - g_GameStartTime > g_LimitTime)	// Note: 제한 시간
		{
			g_GameState = STOP;
			return ;
		}
		else
		{
			// Note: 골대
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
					g_sGoalDae.nDist = g_sGoalDae.nDist * -1;	// -1 이 방향을 바꾸어 줌.
				}
			}

			if (g_sBall.nIsReady == 0)	// 이동 중일 때
			{	// 이동 시간 간격에 의한 이동
				if (CurTime - g_sBall.OldTime > g_sBall.MoveTime)
				{
					if(g_sBall.nMoveY - 1 > 0)
					{
						g_sBall.nMoveY--;
						g_sBall.OldTime = CurTime;	// 다음 이동 시각과 비교하기 위해 현재 시간을 이전 시간 변수에 저장

						// 골대 라인 충돌

						if (g_sBall.nMoveX >= g_sGoalDae.nLineX[0] && g_sBall.nMoveX + 1 <= g_sGoalDae.nLineX[nLength - 1] + 1)
						{
							if (g_sBall.nMoveY <= g_sGoalDae.nMoveY)
							{	// 공 초기화
								g_sBall.nIsReady = 1;
								g_sBall.nMoveX = g_sPlayer.nMoveX;
								g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
								g_nBallCount++;		// 골인한 공의 개수

								if (g_nBallCount == g_nGoalBallCount)	// 공의 목표 공과의 개수가 같으면 SUCCESS
								{
									g_GameState = STOP;
									g_nGoal = 1;
									return ;
								}

								// 효과 출력
								if (g_nIsGoal == 0)
								{
									g_nIsGoal = 1;
									g_sEffect.StratTime = CurTime;
								}

								// 골인 사운드 출력
								FMOD_System_PlaySound(g_System, FMOD_CHANNEL_FREE, g_Sound[6], 0, &g_Channel[6]);	// 골인 사운드 '와우~'
							}
						}
						else if((g_sBall.nMoveX >= g_sGoalDae.nMoveX && g_sBall.nMoveX <= g_sGoalDae.nMoveX + 1) || 
								(g_sBall.nMoveX+1 >= g_sGoalDae.nMoveX  && g_sBall.nMoveX+1 <= g_sGoalDae.nMoveX + 1) ||
								(g_sBall.nMoveX >= g_sGoalDae.nLineX[nLength-1]+2  && g_sBall.nMoveX <= g_sGoalDae.nLineX[nLength-1]+3 ) ||
								(g_sBall.nMoveX+1 >= g_sGoalDae.nLineX[nLength-1]+2  && g_sBall.nMoveX+1 <= g_sGoalDae.nLineX[nLength-1]+3 ))
						{
							if (g_sBall.nMoveX <= g_sGoalDae.nMoveY)
							{
								// 공 초기화
								g_sBall.nIsReady = 1;
								g_sBall.nMoveX = g_sPlayer.nMoveX;
								g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
							}
						}
					}
					else
					{
						// 공 초기화
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

			// 효과
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
			FMOD_Channel_Stop(g_Channel[1]);		// running 사운드 중지
			FMOD_Channel_Stop(g_Channel[1]);		// running 사운드 중지

			FMOD_System_PlaySound(g_System, FMOD_CHANNEL_FREE, g_Sound[4], 0, &g_Channel[4]);	// 미션 성공 사운드
		}
		else
		{
			g_GameState = FAILED;
			FMOD_Channel_Stop(g_Channel[1]);		// running 사운드 중지
			FMOD_System_PlaySound(g_System, FMOD_CHANNEL_FREE, g_Sound[2], 0, &g_Channel[2]);	// 미션 실패 사운드
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
			FMOD_Channel_Stop(g_Channel[4]);	// 미션 성공 사운드 출력 중지
			FMOD_System_PlaySound(g_System, FMOD_CHANNEL_FREE, g_Sound[3], 0, &g_Channel[3]);		// READY 사운드
		}
		break;
	case RESULT:
		if (CurTime - g_UpdateOldTime > 3000)
			exit(0);
		break;	
	}
}

// Note: 렌더링
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
		ScreenPrint(g_sGoalDae.nMoveX, g_sGoalDae.nMoveY, "□");
		nLength = g_sGoalDae.nLength * 2 + 1;

		for (i = 0; i < nLength; i++)
			ScreenPrint(g_sGoalDae.nLineX[i], g_sGoalDae.nMoveY, "─");

		ScreenPrint(g_sGoalDae.nLineX[nLength - 1] + 1, g_sGoalDae.nMoveY, "□");

		// Note: 효과 출력
		if (g_nIsGoal == 1)
		{
			GoalMessage(10, 10);
		}

		// Note: 2 컬럼씩 클리핑
		if (g_sPlayer.nX < 2)	// 왼쪽 클리핑 처리
			ScreenPrint(2, g_sPlayer.nMoveY, &g_strPlayer[(g_sPlayer.nX - 2) * -1]);
		else if(g_sPlayer.nMoveX + (g_nLength - g_sPlayer.nCenterX + 1) > 43)		// 오른쪽 클리핑 처리
		{
			strncat(string, g_strPlayer, g_nLength - ((g_sPlayer.nMoveX + g_sPlayer.nCenterX + 1) - 43));
			ScreenPrint(g_sPlayer.nX, g_sPlayer.nMoveY, string);
		}
		else	// 1 컬럼씩 이동
		{
			ScreenPrint(g_sPlayer.nX, g_sBall.nMoveY, g_strPlayer);
		}

		ScreenPrint(g_sBall.nMoveX, g_sBall.nMoveY, "◎");
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

	// Note: 렌더링 끝
	ScreenFlipping();
}

// Note: 해제
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
	Init();				// 초기화

	while (1)
	{
		if (_kbhit())
		{
			nKey = _getch();

			switch(nKey)
			{
			case 'j':
				if (g_sPlayer.nMoveX > 2)	// 왼쪽 충돌 경계 좌표 체크
				{
					g_sPlayer.nMoveX--;
					nRemain = g_nLength - g_sPlayer.nCenterX + 1;	// 전체 길이 - (중심 좌표 + 1)은 남은 길이
					// Note: 2컬럼씩 이동하기 위한 부분(팔이 걸친 경우)
					if (g_sPlayer.nMoveX - g_sPlayer.nCenterX < 2 || g_sPlayer.nMoveX + nRemain > 43)
						g_sPlayer.nMoveX--;

					g_sPlayer.nX = g_sPlayer.nMoveX - g_sPlayer.nCenterX;
				}
				break;
			case 'l':
				if (g_sPlayer.nMoveX + 1 < 43)	// 오른족 충돌 경계 좌표 체크
				{
					g_sPlayer.nMoveX++;
					nRemain = g_nLength - g_sPlayer.nCenterX + 1;	// 전체 길이 - (중심 좌표 + 1)은 남은 길이
					// Note: 2컬럼씩 이동하기 위한 부분(팔이 걸친 경우)
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
					FMOD_System_PlaySound(g_System, FMOD_CHANNEL_FREE, g_Sound[5], 0, &g_Channel[5]);	// 슛 동작 소리 출력
				}
				break;
			}
		}

		Update();		// 데이터 갱신
		Render();		// 화면 출력
	}

	Release();			// 해제
	ScreenRelease();
	return 0;
}