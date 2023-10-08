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
							  {30, 1000 * 15, 2000, 2000},
							  {50, 1000 * 30, 1000, 1000} };

typedef enum _DUDAGI_STATE {SETUP, UP, DOWN,} DUDAGI_STATE;

typedef struct _DUDAGI
{
	DUDAGI_STATE nState;	// Note: �δ��� ����
	clock_t StayTime;		// Note: ���� �� ��� �ð�
	clock_t OutputTime;		// Note: ������ �� ��� �ð�
	clock_t OldTime;		// Note: ���� �ð�
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
	int nIsAttack;			// ��ġ ����
	clock_t StartTime;		// Ÿ�� ���°� ���۵� �ð�
	clock_t DelayTime;		// Ÿ�� ������ ���� �ð�
	int nIndex;				// ��ǥ �迭�� �����ϱ� ���� �ε���
	int nStayX, nStayY;		// ��� ������ �� ��ǥ
} MANGCHI;

void Mangchi(int x, int y)
{
	ScreenPrint(x - 4, y - 1, "�٦�����");
	ScreenPrint(x - 4, y,     "�����Φ���������");
	ScreenPrint(x - 4, y + 1, "�٦�����");
}

void MangchiReady(int x, int y)
{
	ScreenPrint(x - 4, y - 2, "    ��");
	ScreenPrint(x - 4, y - 1, "  ������");
	ScreenPrint(x - 4, y,     "  ��  ��");
	ScreenPrint(x - 4, y + 1, "  ������");
	ScreenPrint(x - 4, y + 2, "    ��");
	ScreenPrint(x - 4, y + 3, "    ��");
	ScreenPrint(x - 4, y + 4, "    ��");
	ScreenPrint(x - 4, y + 5, "    ��");
}

GAME_STATE g_GameState = INIT;

MANGCHI g_Mangchi;
DUDAGI g_Dudagi[9];

int		g_nStage = 0;
clock_t	g_GameStartTime, g_OldTime;
int		g_nIsSuccess = 0;

char g_strMessage[100];		// ���� ���¸� �����ϴ� ���ڿ�

void InitScreen()
{
	ScreenPrint(0, 0,	"����������������������������������������������");
	ScreenPrint(0, 1,	"��                                          ��");
	ScreenPrint(0, 2,	"��                                          ��");
	ScreenPrint(0, 3,	"��                                          ��");
	ScreenPrint(0, 4,	"��                                          ��");
	ScreenPrint(0, 5,	"��                                          ��");
	ScreenPrint(0, 6,	"��                                          ��");
	ScreenPrint(0, 7,	"��                                          ��");
	ScreenPrint(0, 8,	"��            ////////                      ��");
	ScreenPrint(0, 9,	"��            ���� /��  ����/               ��");
	ScreenPrint(0, 10,	"��            �� . .�� ��������             ��");
	ScreenPrint(0, 11,	"��            �������� ��������             ��");
	ScreenPrint(0, 12,	"��                                          ��");
	ScreenPrint(0, 13,	"��                                          ��");
	ScreenPrint(0, 14,	"��                                          ��");
	ScreenPrint(0, 15,	"��             �δ��� ��� ����             ��");
	ScreenPrint(0, 16,	"��                                          ��");
	ScreenPrint(0, 17,	"��                                          ��");
	ScreenPrint(0, 18,	"��           space Ű�� �����ּ���          ��");
	ScreenPrint(0, 19,	"��                                          ��");
	ScreenPrint(0, 20,	"��                                          ��");
	ScreenPrint(0, 21,	"��                                          ��");
	ScreenPrint(0, 22,	"��                                          ��");
	ScreenPrint(0, 23,	"����������������������������������������������");
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
	sprintf(string,	    "��������    %d  ��������     ������ᦢ", g_nStage);
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

void RunningScreen()
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
	ScreenPrint(0, 11,	"��                                          ��");
	ScreenPrint(0, 12,	"��                                          ��");
	ScreenPrint(0, 13,	"��                                          ��");
	ScreenPrint(0, 14,	"��                                          ��");
	ScreenPrint(0, 15,	"��                                          ��");
	ScreenPrint(0, 16,	"��                                          ��");
	ScreenPrint(0, 17,	"��                                          ��");
	ScreenPrint(0, 18,	"��                                          ��");
	ScreenPrint(0, 19,	"��                               ��    ��   ��");
	ScreenPrint(0, 20,	"��                             ���ᦥ���থ ��");
	ScreenPrint(0, 21,	"��                               ����  ���� ��");
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
	ScreenPrint(0, 6,	"��                ��-����-��                ��");
	ScreenPrint(0, 7,	"��                d ��,.�� b                ��");
	ScreenPrint(0, 8,	"��                ����������                ��");
	ScreenPrint(0, 9,	"��                ����������                ��");
	ScreenPrint(0, 10,	"��                  ������                  ��");
	ScreenPrint(0, 11,	"��                       ��������           ��");
	ScreenPrint(0, 12,	"��                                          ��");
	ScreenPrint(0, 13,	"��              �̼� ���� !!!!              ��");
	ScreenPrint(0, 14,	"��                                          ��");
	ScreenPrint(0, 15,	"��                                          ��");
	ScreenPrint(0, 16,	"��                                          ��");
	ScreenPrint(0, 17,	"��         �ٽ� �Ͻðڽ��ϱ�? (y/n)         ��");
	ScreenPrint(0, 18,	"��                                          ��");
	ScreenPrint(0, 19,	"��                                          ��");
	ScreenPrint(0, 20,	"��                                          ��");
	ScreenPrint(0, 21,	"��                                          ��");
	ScreenPrint(0, 22,	"��                                          ��");
	ScreenPrint(0, 23,	"����������������������������������������������");
}

void Init()
{
	int i;
	g_OldTime = clock();

	// Note: ��ġ �¾�
	g_Mangchi.nIsAttack = 0;
	g_Mangchi.nIndex = 0;
	g_Mangchi.nStayX = 40;
	g_Mangchi.nStayY = 10;
	g_Mangchi.StartTime = clock();
	g_Mangchi.DelayTime = 300;

	// Note: ������ �ʱ�ȭ
	for (i = 0; i < 9; i++)
	{
		g_Dudagi[i].StayTime = rand() % g_StageInfo[g_nStage].DownLimitTime + 10; // Note: �ּ� 10�� �ȴ�.
		g_Dudagi[i].OldTime = clock();
		g_Dudagi[i].nState = SETUP;
		g_Dudagi[i].OutputTime = rand() % g_StageInfo[g_nStage].UpLimitTime + 10;	// �ּ� 10�� �ȴ�.
	}
}

void Update()
{
	int i;
	clock_t CurTime = clock();

	switch (g_GameState)
	{
	case INIT:
		g_OldTime = CurTime;
		break;
	case READY:
		if (CurTime - g_OldTime > 3000)
		{
			g_OldTime = CurTime;
			g_GameState = RUNNING;
			g_GameStartTime= CurTime;
		}
		break;

	case RUNNING:
		if ((CurTime - g_GameStartTime) > g_StageInfo[g_nStage - 1].LimitTime)		// Note: ���� �ð�
		{
			g_GameState = STOP;
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
					g_Dudagi[i].OutputTime = rand() % 2000 + 50;
					g_Dudagi[i].StayTime = rand() % 1000 + 30;
					break;
				case UP:
					if ((CurTime - g_Dudagi[i].OldTime) > g_Dudagi[i].OutputTime)
					{
						g_Dudagi[i].OldTime = CurTime;
						g_Dudagi[i].nState = DOWN;
					}
					break;
				case DOWN:
					if ((CurTime - g_Dudagi[i].OldTime) > g_Dudagi[i].StayTime)
					{
						g_Dudagi[i].OldTime = CurTime;
						g_Dudagi[i].nState = SETUP;
					}
					break;
				}
			}

			if (g_Mangchi.nIsAttack == 1)
			{
				if (CurTime - g_Mangchi.StartTime > g_Mangchi.DelayTime)
				{
					g_Mangchi.nIsAttack = 0;
				}
			}

		}
		break;

	case STOP:
		if (g_nIsSuccess == 1)
			g_GameState = SUCCESS;
		else
			g_GameState = FAILED;
		break;
		
	case SUCCESS:
		sprintf(g_strMessage, "%s", "�̼� ����!");
		
		if (CurTime - g_OldTime > 3000)
		{
			g_OldTime = CurTime;
			g_GameState = INIT;
			++g_nStage;

			if (g_nStage == 4)
				g_GameState = RESULT;
			else
				g_GameState = READY;
		}

		break;

	case FAILED:
		break;

	case RESULT:
		sprintf(g_strMessage, "%s", "���� ��� ȭ��");

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

	ScreenPrint(1, 1, g_strMessage);

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

		for (i = 0; i < 9; i++)
		{
			if (g_Dudagi[i].nState == UP)
			{
				ScreenPrint(g_Point[i].nX, g_Point[i].nY, "��");
			}
	
			ScreenPrint(g_Point[i].nX, g_Point[i].nY + 1, "��");
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
	Init();		// �ʱ�ȭ

	while (1)
	{
		if (_kbhit())
		{
			nKey = _getch();
			
			if (nKey == 'q')
				break;

			if (g_Mangchi.nIsAttack == 0)
			{
				if (nKey >= '1' && nKey <= '9')
				{
					g_Mangchi.nIndex = nKey - '1';
					g_Mangchi.StartTime = clock();
					g_Mangchi.nIsAttack = 1;
				}
			}

			switch (nKey)
			{
			case 's':
				g_nIsSuccess = 1;
				break;

			case 'f':
				g_nIsSuccess = 0;
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
					g_nStage = 1;
					g_GameState = READY;
				}
			}
		}

		Update();		// ������ ����
		Render();		// ȭ�� ���
	}

	Release();			// ����
	ScreenRelease();

	return 0;
}