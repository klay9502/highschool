#include "Turboc.h"
#include "Screen.h"

typedef enum _GAME_STATE { INIT, READY, RUNNING, SUCCESS, FAILED, STOP, RESULT } GAME_STATE;

typedef struct _STAGE_INFO
{
	int nCatchDudagi;
	clock_t LimitTime;
	clock_t UpLimitTime;
	clock_t DownLimitTime;
} STAGE_INFO;

STAGE_INFO g_StageInfo[3] = { {2, 1000 * 10, 6000, 4000},
							  {5, 1000 * 15, 2000, 2000},
							  {10, 1000 * 30, 1000, 1000} };

typedef enum _DUDAGI_STATE {SETUP, UP, DOWN,} DUDAGI_STATE;

typedef struct _DUDAGI
{
	DUDAGI_STATE nState;	// Note: 두더지 상태
	clock_t StayTime;		// Note: 들어갔을 대 대기 시간
	clock_t OutputTime;		// Note: 나왔을 대 대기 시간
	clock_t OldTime;		// Note: 이전 시각
} DUDAGI;

typedef struct _XY
{
	int nX, nY;
} XY;

XY g_Point[9] = { {10, 15}, {20, 15}, {30, 15},
                  {10, 10}, {20, 10}, {30, 10},
                  {10, 5}, {20, 5},{30, 5} 
};

typedef struct _MANGCHI
{
	int nIsAttack;			// 망치 상태
	clock_t StartTime;		// 타격 상태가 시작된 시각
	clock_t DelayTime;		// 타격 상태의 지연 시각
	int nIndex;				// 좌표 배열에 접근하기 위한 인덱스
	int nStayX, nStayY;		// 대기 상태일 때 좌표
} MANGCHI;

void Mangchi(int x, int y)
{
	ScreenPrint(x - 4, y - 1, "☆┌─┐");
	ScreenPrint(x - 4, y,     "⊂│꽝│＝＝⊂⊃");
	ScreenPrint(x - 4, y + 1, "☆└─┘");
}

void MangchiReady(int x, int y)
{
	ScreenPrint(x - 4, y - 2, "    ∩");
	ScreenPrint(x - 4, y - 1, "  ┌─┐");
	ScreenPrint(x - 4, y,     "  │  │");
	ScreenPrint(x - 4, y + 1, "  └─┘");
	ScreenPrint(x - 4, y + 2, "    ∏");
	ScreenPrint(x - 4, y + 3, "    ∥");
	ScreenPrint(x - 4, y + 4, "    ∩");
	ScreenPrint(x - 4, y + 5, "    ∪");
}

GAME_STATE g_GameState = INIT;

MANGCHI g_Mangchi;
DUDAGI g_Dudagi[9];

int		g_nStage = 0;
clock_t	g_GameStartTime, g_OldTime, g_RemainTime;

int		nCatchedDudagi = 0;
int		nScore = 0;

char g_strMessage[100];		// 게임 상태를 저장하는 문자열

void InitScreen()
{
	ScreenPrint(0, 0,	"┌─────────────────────┐");
	ScreenPrint(0, 1,	"│                                          │");
	ScreenPrint(0, 2,	"│                                          │");
	ScreenPrint(0, 3,	"│                                          │");
	ScreenPrint(0, 4,	"│                                          │");
	ScreenPrint(0, 5,	"│                                          │");
	ScreenPrint(0, 6,	"│                                          │");
	ScreenPrint(0, 7,	"│                                          │");
	ScreenPrint(0, 8,	"│            ////////                      │");
	ScreenPrint(0, 9,	"│            │＼ /│  ＼│/               │");
	ScreenPrint(0, 10,	"│            │ . .│ ┌┬┬┐             │");
	ScreenPrint(0, 11,	"│            └┐┌┘ └┐┌┘             │");
	ScreenPrint(0, 12,	"│                                          │");
	ScreenPrint(0, 13,	"│                                          │");
	ScreenPrint(0, 14,	"│                                          │");
	ScreenPrint(0, 15,	"│             두더지 잡기 게임             │");
	ScreenPrint(0, 16,	"│                                          │");
	ScreenPrint(0, 17,	"│                                          │");
	ScreenPrint(0, 18,	"│           space 키를 눌러주세요          │");
	ScreenPrint(0, 19,	"│                                          │");
	ScreenPrint(0, 20,	"│                                          │");
	ScreenPrint(0, 21,	"│                                          │");
	ScreenPrint(0, 22,	"│                                          │");
	ScreenPrint(0, 23,	"└─────────────────────┘");
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
	sprintf(string,	    "│■■■■■    %d  스테이지     ■■■■■■│", g_nStage + 1);
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

void RunningScreen()
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
	ScreenPrint(0, 11,	"│                                          │");
	ScreenPrint(0, 12,	"│                                          │");
	ScreenPrint(0, 13,	"│                                          │");
	ScreenPrint(0, 14,	"│                                          │");
	ScreenPrint(0, 15,	"│                                          │");
	ScreenPrint(0, 16,	"│                                          │");
	ScreenPrint(0, 17,	"│                                          │");
	ScreenPrint(0, 18,	"│                                          │");
	ScreenPrint(0, 19,	"│                               ○    ●   │");
	ScreenPrint(0, 20,	"│                             ┌■┘┌□┘ │");
	ScreenPrint(0, 21,	"│                               ┘┐  ┘┐ │");
	ScreenPrint(0, 22,	"│                                          │");
	ScreenPrint(0, 23,	"└─────────────────────┘");
}

void SuccessScreen()
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
	ScreenPrint(0, 11,	"│                                          │");
	ScreenPrint(0, 12,	"│                                          │");
	ScreenPrint(0, 13,	"│                                          │");
	ScreenPrint(0, 14,	"│                                          │");
	ScreenPrint(0, 15,	"│                                          │");
	ScreenPrint(0, 16,	"│                                          │");
	ScreenPrint(0, 17,	"│       잡은 두더지 :                       │");
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
	ScreenPrint(0, 6,	"│                ┌-──-┐                │");
	ScreenPrint(0, 7,	"│                d こ,.こ b                │");
	ScreenPrint(0, 8,	"│                │┬─┬│                │");
	ScreenPrint(0, 9,	"│                └┤│├┘                │");
	ScreenPrint(0, 10,	"│                  └┴┘                  │");
	ScreenPrint(0, 11,	"│                       스테이지           │");
	ScreenPrint(0, 12,	"│                                          │");
	ScreenPrint(0, 13,	"│              미션 실패 !!!!              │");
	ScreenPrint(0, 14,	"│                                          │");
	ScreenPrint(0, 15,	"│                                          │");
	ScreenPrint(0, 16,	"│                                          │");
	ScreenPrint(0, 17,	"│         다시 하시겠습니까? (y/n)         │");
	ScreenPrint(0, 18,	"│                                          │");
	ScreenPrint(0, 19,	"│                                          │");
	ScreenPrint(0, 20,	"│                                          │");
	ScreenPrint(0, 21,	"│                                          │");
	ScreenPrint(0, 22,	"│                                          │");
	ScreenPrint(0, 23,	"└─────────────────────┘");
}

void Init()
{
	int i;
	g_OldTime = clock();

	// Note: 망치 셋업
	g_Mangchi.nIsAttack = 0;
	g_Mangchi.nIndex = 0;
	g_Mangchi.nStayX = 40;
	g_Mangchi.nStayY = 10;
	g_Mangchi.StartTime = clock();
	g_Mangchi.DelayTime = 300;

	// Note: 데이터 초기화
	for (i = 0; i < 9; i++)
	{
		g_Dudagi[i].StayTime = rand() % (int)g_StageInfo[g_nStage].DownLimitTime + 10; // Note: 최소 10은 된다.
		g_Dudagi[i].OldTime = clock();
		g_Dudagi[i].nState = SETUP;
		g_Dudagi[i].OutputTime = rand() % (int)g_StageInfo[g_nStage].UpLimitTime + 10;	// 최소 10은 된다.
	}
}

void Update()
{
	int i;
	clock_t CurTime = clock();

	switch (g_GameState)
	{
	case READY:
		if (CurTime - g_OldTime > 2000)
		{
			g_GameState = RUNNING;
			g_GameStartTime= CurTime;
		}
		break;

	case RUNNING:
		if ((CurTime - g_GameStartTime) > g_StageInfo[g_nStage].LimitTime)		// Note: 제한 시간
		{
			g_GameState = STOP;
			return;
		}
		else
		{
			for (i = 0; i < 9; i++)
			{
				switch (g_Dudagi[i].nState)
				{
				case SETUP:
					g_Dudagi[i].nState = UP;
					g_Dudagi[i].OldTime = CurTime;
					g_Dudagi[i].OutputTime = rand() % (int)g_StageInfo[g_nStage].UpLimitTime + 10;
					g_Dudagi[i].StayTime = rand() % (int)g_StageInfo[g_nStage].DownLimitTime + 10;
					break;
				case UP:
					if ((CurTime - g_Dudagi[i].OldTime) > g_Dudagi[i].OutputTime)
					{
						g_Dudagi[i].OldTime = CurTime;
						g_Dudagi[i].nState = DOWN;
					}
					break;
				case DOWN:
					if ((CurTime - g_Dudagi[i].OldTime) > g_Dudagi[i].StayTime && g_Mangchi.nIsAttack != 1)
						g_Dudagi[i].nState = SETUP;
					break;
				}
			}

			if (g_Mangchi.nIsAttack == 1)
			{
				for (i = 0; i < 9; i++)
				{
					if (g_Dudagi[i].nState == UP && i == g_Mangchi.nIndex)
					{
						nCatchedDudagi++;
						nScore += 10;
						g_Dudagi[i].nState = DOWN;
					}
				}

				if (CurTime - g_Mangchi.StartTime > g_Mangchi.DelayTime)
				{
					g_Mangchi.nIsAttack = 0;
				}
			}

			g_RemainTime = (g_StageInfo[g_nStage].LimitTime - (CurTime - g_GameStartTime)) / 1000;		// 게임 진행 남은 시간
		}
		break;

	case STOP:
		if (nCatchedDudagi >= g_StageInfo[g_nStage].nCatchDudagi)
		{
			g_OldTime = CurTime;
			nCatchedDudagi = 0;
			g_GameState = SUCCESS;
		}
		else
		{
			g_GameState = FAILED;
		}
		break;
		
	case SUCCESS:
		sprintf(g_strMessage, "%s", "미션 성공!");
		
		if (CurTime - g_OldTime > 3000)
		{
			g_OldTime = CurTime;
			g_GameState = INIT;
			nScore = 0;
			++g_nStage;
			Init();

			if (g_nStage == 3)
				g_GameState = RESULT;
			else
				g_GameState = READY;
		}

		break;

	case FAILED:
		break;

	case RESULT:
		sprintf(g_strMessage, "%s", "게임 결과 화면");

		if (CurTime - g_OldTime > 3000)
		{
			exit(0);
		}
		break;
	}
}

void Render()
{
	int i;

	ScreenClear();

	switch (g_GameState)
	{
	case INIT:
		if (g_nStage == 0)
			InitScreen();
		break;
	case READY:
		ReadyScreen();
		break;
	case RUNNING:
		RunningScreen();

		sprintf(g_strMessage, "목표 두더지 : %d, 잡은 두더지: %d", g_StageInfo[g_nStage].nCatchDudagi, nCatchedDudagi);
		ScreenPrint(2, 1, g_strMessage);
		sprintf(g_strMessage, "스테이지 : %d, 남은 시간 : %d", g_nStage + 1, g_RemainTime);
		ScreenPrint(2, 2, g_strMessage);

		for (i = 0; i < 9; i++)
		{
			if (g_Dudagi[i].nState == UP)
			{
				ScreenPrint(g_Point[i].nX, g_Point[i].nY, "●");
			}
	
			ScreenPrint(g_Point[i].nX, g_Point[i].nY + 1, "♨");
		}

		if (g_Mangchi.nIsAttack)
			Mangchi(g_Point[g_Mangchi.nIndex].nX, g_Point[g_Mangchi.nIndex].nY);
		else
			MangchiReady(g_Mangchi.nStayX, g_Mangchi.nStayY);
		break;
	case FAILED:
		FailureScreen();
	}

	ScreenFlipping();
}

void Release()
{

}

int main(void)
{
	int nKey;

	ScreenInit();
	Init();		// 초기화

	while (1)
	{
		if (_kbhit())
		{
			nKey = _getch();
			
			if (nKey == 'q')
				break;

			if (g_GameState == RESULT)
				break;

			switch (nKey)
			{
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				if (g_Mangchi.nIsAttack == 0 && g_GameState == RUNNING)
				{
					g_Mangchi.nIndex = nKey - '1';
					g_Mangchi.StartTime = clock();
					g_Mangchi.nIsAttack = 1;
				}
				break;
			case 'y':
			case 'Y':
				if (g_GameState == FAILED)
				{
					g_GameState = INIT;
					g_OldTime = clock();
				}
				break;

			case 'n':
			case 'N':
				if (g_GameState == FAILED)
				{
					g_GameState = RESULT;
					g_OldTime = clock();
				}
				break;
				
			case ' ':
				if (g_GameState == INIT && g_nStage == 0)
				{
					g_GameState = READY;
				}
			}
		}

		Update();		// 데이터 갱신
		Render();		// 화면 출력
	}

	Release();			// 해제
	ScreenRelease();

	return 0;
}