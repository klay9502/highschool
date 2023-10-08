#include "Turboc.h"
#include "Screen.h"

typedef enum _CARD_STATE {OPEN, CLOSE, MATCH} CARD_STATE;

// Note: ī�� �迭 �Ӽ� ����
typedef struct _CARD_INFO
{
	CARD_STATE nCardState;
	int nUse;
	char cMunja;
	int nX, nY;
} CARD_INFO;

// Note: ���ĺ� ���� �迭 �Ӽ�
typedef struct _ALPHA_DATA
{
	int nUse;
	char cMunja;
} ALPHA_DATA;

// Note: ī�� ¦ Ȯ�� ����
typedef struct _MATCH_CARD_DATA
{
	int nCardCount;
	int nCardIndex[2];
	clock_t OldTime;
} MATCH_CARD_DATA;

ALPHA_DATA g_sAlphaData[26];	// Note: ���ĺ��� 26��
CARD_INFO  g_sGameCard[30];		// Note: ī�� 30��
MATCH_CARD_DATA g_sMatchCardInfo;
int g_nRow, g_nCol;

void OpenCard(int x, int y, char cMunja)
{
	char string[100];

	ScreenPrint(x, y,     "������");
	ScreenPrint(x, y + 1, "��  ��");
	ScreenPrint(x, y + 2, "������");
	sprintf(string, "%c", cMunja);
}

void MatchCard(int x, int y, char cMunja)
{
	char string[100];

	ScreenPrint(x, y,     "������");
	ScreenPrint(x, y + 1, "��  ��");
	ScreenPrint(x, y + 2, "������");
	sprintf(string, "%c", cMunja);
	ScreenPrint(x + 2, y + 1, string);
}

void CloseCard(int x, int y)
{
	ScreenPrint(x, y,     "������");
	ScreenPrint(x, y + 1, "���ᦢ");
	ScreenPrint(x, y + 2, "������");
}

void Init()
{
	int i, j = 0;
	int nCardIndex, nAlphaIndex;

	// Note: ���ĺ� ���� �迭�� �ʱ�ȭ
	for (i = 0; i < 26; i++)
	{
		g_sAlphaData[i].nUse = 0;
		g_sAlphaData[i].cMunja = 'A' + i;
	}

	// Note: ī�� �迭�� �ʱ�ȭ
	for (i = 0; i < 30; i++)
		g_sGameCard[i].nUse = 0;

	srand( (unsigned)time(NULL) );
	for (i = 0; i < 15; i++)
	{
		while (1)
		{
			// Note: ������ ���ĺ� ���� �ε���
			nAlphaIndex = rand() % 26;

			if (g_sAlphaData[nAlphaIndex].nUse == 0)
			{
				g_sAlphaData[nAlphaIndex].nUse = 1;
				break;
			}
		}

		// Note: ī�� �迭
		for (j = 0; j < 2; j++)
		{
			while (1)
			{
				// Note: ������ ī�� �ε���
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

	for (i = 0; i < 30; i++)	// ī�� �ʱ� ��ǥ
	{
		g_sGameCard[i].nX = (i % 6) * 8 + 3;	// ���� x��ǥ�� ����� �� 0,8,16... �ʹ� ���ʿ� �����Ƿ� 3�� ����
		g_sGameCard[i].nY = (i / 6) * 4 + 1;	// �� ī���� ���� ���̰� 4�̱� ������ *4�� �������� �� ������� 1���� ������ �־� Ŀ���� �̵��ϰ� �ȴ�.
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
	ScreenPrint(g_sGameCard[nIndex].nX + 2, g_sGameCard[nIndex].nY + 3, "��");

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
	Init();			// �ʱ�ȭ

	while (1)
	{
		if (_kbhit())
		{
			nKey = _getch();

			switch(nKey)
			{
			case 'j':		// ����
				if (g_nCol - 1 < 0)
					g_nCol = 0;
				else
					g_nCol--;
				break;
			case 'l':		// ������
				if (g_nCol + 1 > 5)
					g_nCol = 5;
				else
					g_nCol++;
				break;
			case 'i':		// ����
				if (g_nRow - 1 < 0)
					g_nRow = 0;
				else
					g_nRow--;
				break;
			case 'k':		// �Ʒ���
				if (g_nRow + 1 > 4)
					g_nRow = 4;
				else
					g_nRow++;
				break;
			case 's':		// ī�� ����
				nIndex = g_nRow * 6 + g_nCol;
				switch (g_sMatchCardInfo.nCardCount)
				{
				case 0:
					// ù ��° ���õ� ī��
					g_sMatchCardInfo.nCardIndex[0] = nIndex;
					g_sGameCard[nIndex].nCardState = MATCH;
					g_sMatchCardInfo.nCardCount++;
					break;
				case 1:
					// �� ���� ���õ� ī��
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

		Updata();		// ������ ����
		Render();		// ȭ�� ���
	}

	Release();		// ����
	ScreenRelease();

	_getch();
	return 0;
}