#include "Turboc.h"
#include "Screen.h"

typedef enum _CARD_STATE {OPEN, CLOSE, MATCH} CARD_STATE;
typedef enum _GAME_STATE {INIT, READY, CARD_OPEN, RUNNING, SUCCESS, FAILED, STOP, RESULT, END} GAME_STATE;
GAME_STATE g_nGameState = INIT;

// Note: 카드 배열 속성 정보
typedef struct _CARD_INFO
{
	CARD_STATE nCardState;
	int nUse;
	char cMunja;
	int nX, nY;
} CARD_INFO;

// Note: 알파벳 문자 배열 속성
typedef struct _ALPHA_DATA
{
	int nUse;
	char cMunja;
} ALPHA_DATA;

// Note: 카드 짝 확인 정보
typedef struct _MATCH_CARD_DATA
{
	int nCardCount;
	int nCardIndex[2];
	clock_t OldTime;
} MATCH_CARD_DATA;

ALPHA_DATA g_sAlphaData[26];	// Note: 알파벳은 26자
CARD_INFO  g_sGameCard[30];		// Note: 카드 30장
MATCH_CARD_DATA g_sMatchCardInfo;
int g_nRow, g_nCol, g_nGrade, g_nCardGoal;

int g_nStage = -1;
int g_nTotalGrade = 0;

clock_t g_GameStartTime, g_UpdateOldTime, g_RemainTime;
clock_t g_StageLimitTime[3] = { 4 * 60 * 1000, 3 * 60 * 1000, 2 * 60 * 1000 };		// 분 * 초 * 밀리세컨트

void OpenCard(int x, int y, char cMunja)
{
	char string[100];

	ScreenPrint(x, y,     "┌─┐");
	ScreenPrint(x, y + 1, "│  │");
	ScreenPrint(x, y + 2, "└─┘");
	sprintf(string, "%c", cMunja);
	ScreenPrint(x + 2, y + 1, string);
}

void MatchCard(int x, int y, char cMunja)
{
	char string[100];

	ScreenPrint(x, y,     "┎━┒");
	ScreenPrint(x, y + 1, "┃  ┃");
	ScreenPrint(x, y + 2, "┖━┚");
	sprintf(string, "%c", cMunja);
	ScreenPrint(x + 2, y + 1, string);
}

void CloseCard(int x, int y)
{
	ScreenPrint(x, y,     "┌─┐");
	ScreenPrint(x, y + 1, "│■│");
	ScreenPrint(x, y + 2, "└─┘");
}

void InitScreen()
{
	ScreenPrint(0, 0,  "┌─────────────────────────┐");
	ScreenPrint(0, 1,  "│                                                  │");
	ScreenPrint(0, 2,  "│          ┌─┐┌─┐┌─┐┌─┐┌─┐          │");
	ScreenPrint(0, 3,  "│          │^^││G ││C ││A ││♥│          │");
	ScreenPrint(0, 4,  "│          └─┘└─┘└─┘└─┘└─┘          │");
	ScreenPrint(0, 5,  "│                                                  │");
	ScreenPrint(0, 6,  "│          ┌─┐┌─┐┌─┐┌─┐┌─┐          │");
	ScreenPrint(0, 7,  "│          │♥││C ││A ││^^││G │          │");
	ScreenPrint(0, 8,  "│          └─┘└─┘└─┘└─┘└─┘          │");
	ScreenPrint(0, 9,  "│                                                  │");
	ScreenPrint(0, 10, "│                                                  │");
	ScreenPrint(0, 11, "│                  짝 맞추기 게임                  │");
	ScreenPrint(0, 12, "│                                                  │");
	ScreenPrint(0, 13, "│                                                  │");
	ScreenPrint(0, 14, "│                   ( 사용 키 )                    │");
	ScreenPrint(0, 15, "│                                                  │");
	ScreenPrint(0, 16, "│                 s : 카드 뒤집기                  │");
	ScreenPrint(0, 17, "│                 j : 좌    l : 우                 │");
	ScreenPrint(0, 18, "│                 i : 상    k : 하                 │");
	ScreenPrint(0, 19, "│                                                  │");
	ScreenPrint(0, 20, "│              Space 키를 눌러 주세요 !            │");
	ScreenPrint(0, 21, "└─────────────────────────┘");
}

void ReadyScreen()
{
	ScreenPrint(0, 0,  "┌─────────────────────────┐");
	ScreenPrint(0, 1,  "│■■■■■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 2,  "│■■■■■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 3,  "│■■■■■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 4,  "│■■■■■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 5,  "│■■■■■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 6,  "│■■■■■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 7,  "│■■■■■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 8,  "│■■■■■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 9,  "│■■■■■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 10, "│■■■■■■■■                  ■■■■■■■■│");
	ScreenPrint(0, 11, "│■■■■■■■■        스테이지  ■■■■■■■■│");
	ScreenPrint(0, 12, "│■■■■■■■■                  ■■■■■■■■│");
	ScreenPrint(0, 13, "│■■■■■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 14, "│■■■■■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 15, "│■■■■■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 16, "│■■■■■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 17, "│■■■■■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 18, "│■■■■■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 19, "│■■■■■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 20, "│■■■■■■■■■■■■■■■■■■■■■■■■■│");
	ScreenPrint(0, 21, "└─────────────────────────┘");

}

void RunningScreen()
{
	ScreenPrint(0, 0,  "┌─────────────────────────┐");
	ScreenPrint(0, 1,  "│                                                  │");
	ScreenPrint(0, 2,  "│                                                  │");
	ScreenPrint(0, 3,  "│                                                  │");
	ScreenPrint(0, 4,  "│                                                  │");
	ScreenPrint(0, 5,  "│                                                  │");
	ScreenPrint(0, 6,  "│                                                  │");
	ScreenPrint(0, 7,  "│                                                  │");
	ScreenPrint(0, 8,  "│                                                  │");
	ScreenPrint(0, 9,  "│                                                  │");
	ScreenPrint(0, 10, "│                                                  │");
	ScreenPrint(0, 11, "│                                                  │");
	ScreenPrint(0, 12, "│                                                  │");
	ScreenPrint(0, 13, "│                                                  │");
	ScreenPrint(0, 14, "│                                                  │");
	ScreenPrint(0, 15, "│                                                  │");
	ScreenPrint(0, 16, "│                                                  │");
	ScreenPrint(0, 17, "│                                                  │");
	ScreenPrint(0, 18, "│                                                  │");
	ScreenPrint(0, 19, "│                                                  │");
	ScreenPrint(0, 20, "│                                                  │");
	ScreenPrint(0, 21, "└─────────────────────────┘");
}

void FailureScreen()
{
	ScreenPrint(0, 0,  "┌─────────────────────────┐");
	ScreenPrint(0, 1,  "│                                                  │");
	ScreenPrint(0, 2,  "│                                                  │");
	ScreenPrint(0, 3,  "│                                                  │");
	ScreenPrint(0, 4,  "│                                                  │");
	ScreenPrint(0, 5,  "│                                                  │");
	ScreenPrint(0, 6,  "│                    ┌-──-┐                    │");
	ScreenPrint(0, 7,  "│                    d こ,.こ b                    │");
	ScreenPrint(0, 8,  "│                    │┬─┬│                    │");
	ScreenPrint(0, 9,  "│                    └┤│├┘                    │");
	ScreenPrint(0, 10, "│                      └┴┘                      │");
	ScreenPrint(0, 11, "│                           스테이지               │");
	ScreenPrint(0, 12, "│                                                  │");
	ScreenPrint(0, 13, "│                  미션 실패 !!!!                  │");
	ScreenPrint(0, 14, "│                                                  │");
	ScreenPrint(0, 15, "│                                                  │");
	ScreenPrint(0, 16, "│                                                  │");
	ScreenPrint(0, 17, "│             다시 하시겠습니까? (y / n)           │");
	ScreenPrint(0, 18, "│                                                  │");
	ScreenPrint(0, 19, "│                                                  │");
	ScreenPrint(0, 20, "│                                                  │");
	ScreenPrint(0, 21, "└─────────────────────────┘");
}

void ResultScreen()
{
	ScreenPrint(0, 0,  "┌─────────────────────────┐");
	ScreenPrint(0, 1,  "│                                                  │");
	ScreenPrint(0, 2,  "│                                                  │");
	ScreenPrint(0, 3,  "│       (((     짝 맞추기 게임 Score      )))      │");
	ScreenPrint(0, 4,  "│                                                  │");
	ScreenPrint(0, 5,  "│                                                  │");
	ScreenPrint(0, 6,  "│                                                  │");
	ScreenPrint(0, 7,  "│                                                  │");
	ScreenPrint(0, 8,  "│                                                  │");
	ScreenPrint(0, 9,  "│                                                  │");
	ScreenPrint(0, 10, "│                                                  │");
	ScreenPrint(0, 11, "│                총점 :                            │");
	ScreenPrint(0, 12, "│                                                  │");
	ScreenPrint(0, 13, "│                                                  │");
	ScreenPrint(0, 14, "│                                                  │");
	ScreenPrint(0, 15, "│                                                  │");
	ScreenPrint(0, 16, "│                                                  │");
	ScreenPrint(0, 17, "│                                                  │");
	ScreenPrint(0, 18, "│                                                  │");
	ScreenPrint(0, 19, "│                                                  │");
	ScreenPrint(0, 20, "│                                                  │");
	ScreenPrint(0, 21, "└─────────────────────────┘");
}

void Init()
{
	int i, j = 0;
	int nCardIndex, nAlphaIndex;

	// Note: 알파벳 문자 배열을 초기화
	for (i = 0; i < 26; i++)
	{
		g_sAlphaData[i].nUse = 0;
		g_sAlphaData[i].cMunja = 'A' + i;
	}

	// Note: 카드 배열을 초기화
	for (i = 0; i < 30; i++)
		g_sGameCard[i].nUse = 0;

	srand( (unsigned)time(NULL) );
	for (i = 0; i < 15; i++)
	{
		while (1)
		{
			// Note: 임의의 알파벳 문자 인덱스
			nAlphaIndex = rand() % 26;

			if (g_sAlphaData[nAlphaIndex].nUse == 0)
			{
				g_sAlphaData[nAlphaIndex].nUse = 1;
				break;
			}
		}

		// Note: 카드 배열
		for (j = 0; j < 2; j++)
		{
			while (1)
			{
				// Note: 임의의 카드 인덱스
				nCardIndex = rand() % 30;

				if (g_sGameCard[nCardIndex].nUse == 0)
				{
					g_sGameCard[nCardIndex].nUse = 1;
					g_sGameCard[nCardIndex].cMunja = g_sAlphaData[nAlphaIndex].cMunja;
					break;
				}
			}
		}
	}

	for (i = 0; i < 30; i++)	// 카드 초기 좌표
	{
		g_sGameCard[i].nX = (i % 6) * 8 + 3;	// 고정 x좌표를 만드는 식 0,8,16... 너무 왼쪽에 가까우므로 3을 더함
		g_sGameCard[i].nY = (i / 6) * 4 + 1;	// 각 카드의 세로 길이가 4이기 때문에 *4를 해주지만 각 행단위로 1줄의 여유를 주어 커서가 이동하게 된다.
		g_sGameCard[i].nCardState = CLOSE;
	}
}

void Updata()
{
	clock_t CurTime = clock();

	switch (g_nGameState)
	{
	case READY:
		if (CurTime - g_UpdateOldTime > 3000)
		{
			g_nGameState = CARD_OPEN;
		}
		break;
	case CARD_OPEN:
		if (CurTime - g_UpdateOldTime > 10000)
		{
			g_nGameState = RUNNING;
			g_GameStartTime = CurTime;
		}
		break;
	case RUNNING:
		g_RemainTime = (g_StageLimitTime[g_nStage] - (CurTime - g_GameStartTime) ) / 1000;		// 경과 시간 (초단위)

		// Note: 데이터 갱신
		if (CurTime - g_GameStartTime > g_StageLimitTime[g_nStage] || g_nCardGoal == 15)
		{
			g_nGameState = STOP;
			return ;
		}

		if (g_sMatchCardInfo.nCardCount == 2)
		{
			// 0,8초 동안 카드는 MATCH 상태를 유지
			if (CurTime - g_sMatchCardInfo.OldTime > 800)
			{
				g_sMatchCardInfo.nCardCount = 0;
				if (g_sGameCard[ g_sMatchCardInfo.nCardIndex[0] ].cMunja == g_sGameCard[ g_sMatchCardInfo.nCardIndex[1] ].cMunja)
				{
					g_sGameCard[ g_sMatchCardInfo.nCardIndex[0] ].nCardState = OPEN;
					g_sGameCard[ g_sMatchCardInfo.nCardIndex[1] ].nCardState = OPEN;
					g_nCardGoal++;
				}
				else
				{
					g_sGameCard[ g_sMatchCardInfo.nCardIndex[0] ].nCardState = CLOSE;
					g_sGameCard[ g_sMatchCardInfo.nCardIndex[1] ].nCardState = CLOSE;
				}
			}
		}
		break;	
	case STOP:
		if (g_nCardGoal == 15)
		{
			g_nGameState = SUCCESS;
			g_UpdateOldTime = CurTime;
		}
		break;
	case SUCCESS:
		break;
	case FAILED:
		break;
	case RESULT:
		break;
	case END:
		break;
	}
}

void Render()
{
	int i, nIndex;
	char string[100];

	ScreenClear();

	switch (g_nGameState)
	{
	case INIT:
		InitScreen();
		break;
	case READY:
		ReadyScreen();
		break;
	case CARD_OPEN:
		RunningScreen();
		for (i = 0; i < 30; i++)
		{
			OpenCard(g_sGameCard[i].nX, g_sGameCard[i].nY, g_sGameCard[i].cMunja);
		}
		break;
	case RUNNING:
		RunningScreen();
		for (i = 0; i < 30; i++)
		{
			switch (g_sGameCard[i].nCardState)
			{
			case OPEN:
				OpenCard(g_sGameCard[i].nX, g_sGameCard[i].nY, g_sGameCard[i].cMunja);
				break;
			case CLOSE:
				CloseCard(g_sGameCard[i].nX, g_sGameCard[i].nY);
				break;
			case MATCH:
				MatchCard(g_sGameCard[i].nX, g_sGameCard[i].nY, g_sGameCard[i].cMunja);
				break;
			}
		}
	
		nIndex = g_nRow * 6 + g_nCol;
		ScreenPrint(g_sGameCard[nIndex].nX + 2, g_sGameCard[nIndex].nY + 3, "↑");

		sprintf(string, "제한 시간 : %d분 %d 초", g_RemainTime / 60, g_RemainTime % 60);
		ScreenPrint( 52, 1, string);
		break;
	case FAILED:
		FailureScreen();
		break;
	case SUCCESS:
		break;
	case RESULT:
		break;
	case END:
		break;
	}

	ScreenFlipping();
}

void Release()
{

}

int main(void)
{
	int nKey, nIndex;

	ScreenInit();
	Init();			// 초기화

	while (1)
	{
		if (_kbhit())
		{
			nKey = _getch();

			switch(nKey)
			{
			case 'j':		// 왼쪽
				if (g_nCol - 1 < 0)
					g_nCol = 0;
				else
					g_nCol--;
				break;
			case 'l':		// 오른쪽
				if (g_nCol + 1 > 5)
					g_nCol = 5;
				else
					g_nCol++;
				break;
			case 'i':		// 위쪽
				if (g_nRow - 1 < 0)
					g_nRow = 0;
				else
					g_nRow--;
				break;
			case 'k':		// 아래쪽
				if (g_nRow + 1 > 4)
					g_nRow = 4;
				else
					g_nRow++;
				break;
			case 's':		// 카드 선택
				nIndex = g_nRow * 6 + g_nCol;
				switch (g_sMatchCardInfo.nCardCount)
				{
				case 0:
					// 첫 번째 선택된 카드
					if (g_sGameCard[nIndex].nCardState != OPEN)
					{
						g_sMatchCardInfo.nCardIndex[0] = nIndex;
						g_sGameCard[nIndex].nCardState = MATCH;
						g_sMatchCardInfo.nCardCount++;
					}
					break;
				case 1:
					// 두 번재 선택된 카드
					if (g_sMatchCardInfo.nCardIndex[0] != nIndex && g_sGameCard[nIndex].nCardState != OPEN)
					{
						g_sMatchCardInfo.OldTime = clock();
						g_sMatchCardInfo.nCardIndex[1] = nIndex;
						g_sGameCard[nIndex].nCardState = MATCH;
						g_sMatchCardInfo.nCardCount++;
					}
					break;
				}
				break;
			case ' ':
				if (g_nGameState == INIT)
				{
					g_nGameState = READY;
				}
			}
		}

		Updata();		// 데이터 갱신
		Render();		// 화면 출력
	}

	Release();		// 해제
	ScreenRelease();

	_getch();
	return 0;
}