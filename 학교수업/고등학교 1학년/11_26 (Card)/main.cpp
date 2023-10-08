#include "Turboc.h"
#include "Screen.h"

typedef enum _CARD_STATE {OPEN, CLOSE, MATCH} CARD_STATE;

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
int g_nRow, g_nCol;

void OpenCard(int x, int y, char cMunja)
{
	char string[100];

	ScreenPrint(x, y,     "┌─┐");
	ScreenPrint(x, y + 1, "│  │");
	ScreenPrint(x, y + 2, "└─┘");
	sprintf(string, "%c", cMunja);
}

void MatchCard(int x, int y, char cMunja)
{
	char string[100];

	ScreenPrint(x, y,     "┌─┐");
	ScreenPrint(x, y + 1, "│  │");
	ScreenPrint(x, y + 2, "└─┘");
	sprintf(string, "%c", cMunja);
	ScreenPrint(x + 2, y + 1, string);
}

void CloseCard(int x, int y)
{
	ScreenPrint(x, y,     "┌─┐");
	ScreenPrint(x, y + 1, "│■│");
	ScreenPrint(x, y + 2, "└─┘");
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
	}
}

void Updata()
{
	int nIndex;

	if (g_sMatchCardInfo.nCardCount == 2)
	{
		g_sMatchCardInfo.nCardCount = 0;
	}
}

void Render()
{
	int i, nIndex;

	ScreenClear();

	for (i = 0; i < 30; i++)
	{
		CloseCard(g_sGameCard[i].nX, g_sGameCard[i].nY);
	}

	nIndex = g_nRow * 6 + g_nCol;
	ScreenPrint(g_sGameCard[nIndex].nX + 2, g_sGameCard[nIndex].nY + 3, "↑");

	if (g_sGameCard[nIndex].nCardState == MATCH)
	{
		OpenCard(g_sGameCard[nIndex].nX, g_sGameCard[nIndex].nY, g_sGameCard[nIndex].cMunja);
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
					g_sMatchCardInfo.nCardIndex[0] = nIndex;
					g_sGameCard[nIndex].nCardState = MATCH;
					g_sMatchCardInfo.nCardCount++;
					break;
				case 1:
					// 두 번재 선택된 카드
					if (g_sMatchCardInfo.nCardIndex[0] != nIndex)
					{
						g_sMatchCardInfo.OldTime = clock();
						g_sMatchCardInfo.nCardIndex[1] = nIndex;
						g_sGameCard[nIndex].nCardState = MATCH;
						g_sMatchCardInfo.nCardCount++;
					}
					break;
				}
				break;
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