#include "Turboc.h"
#include "Screen.h"

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

BALL g_sBall;
PLAYER g_sPlayer;
GOAL_DAE g_sGoalDae;
char g_strPlayer[] = "�����ܦ���";	// ���ΰ� ĳ����
int g_nLength;							// ���ΰ� ĳ���� ����
int Goal_number;

// Note: �ʱ�ȭ
void Init()
{
	int nLength, i;
	g_sGoalDae.nMoveX = 20;			// 69
	g_sGoalDae.nMoveY = 2;
	g_sGoalDae.nLength = 1;
	g_sGoalDae.MoveTime = 1000;		// 2000
	g_sGoalDae.OldTime = clock();
	g_sGoalDae.nDist = 1;
	nLength = g_sGoalDae.nLength * 2 + 1;		// Note: �迭�� �ִ� ����, ����μ� ���

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

	for (i = 0; i < nLength; i++)
	{
		g_sGoalDae.nLineX[i] = g_sGoalDae.nMoveX + 2 * (i + 1);
	}
}

// Note: ������ ����
void Update()
{
	clock_t CurTime = clock();
	int nLength = g_sGoalDae.nLength * 2 + 1;	// Note: �迭�� �ִ� ����
	int i;

	// ��� �̵�
	if ((CurTime - g_sGoalDae.OldTime) > g_sGoalDae.MoveTime)
	{
		g_sGoalDae.OldTime = CurTime;

		if (g_sGoalDae.nMoveX + g_sGoalDae.nDist >= 0 && ((g_sGoalDae.nLineX[nLength - 1] + 3) + g_sGoalDae.nDist) <= 79)
		{
			g_sGoalDae.nMoveX += g_sGoalDae.nDist;

			for (i = 0; i < nLength; i++)
			{
				g_sGoalDae.nLineX[i] = g_sGoalDae.nMoveX + 2 * (i + 1);
			}
		}
		else
		{
			g_sGoalDae.nDist = g_sGoalDae.nDist * -1;		// -1 �� ������ �ٲپ� ��.
		}
	}

	// ���� �̵�
	if ( g_sBall.nIsReady == 0 )		// �̵� ���� ��
	{
		if ((CurTime - g_sBall.OldTime) > g_sBall.MoveTime )
		{
			if ( g_sBall.nMoveY - 1 > 0 )		// ���� ��迵���� �������� �ʾ��� ��� �� y���� 0���� Ŭ ���
			{
				g_sBall.nMoveY--;
				g_sBall.OldTime = CurTime;	// ���� �̵� �ð��� ���ϱ� ���� ���� �ð��� ���� �ð� ������ ����
				
				if (g_sBall.nMoveX >= g_sGoalDae.nLineX[0] && g_sBall.nMoveX +1 <= g_sGoalDae.nLineX[nLength-1]+1)
				{
					if( g_sBall.nMoveY == g_sGoalDae.nMoveY)
					{
						g_sBall.nIsReady = 1;
						g_sBall.nMoveX = g_sPlayer.nMoveX;
						g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
						Goal_number++;
						g_sBall.OldTime = CurTime;
					}
				}
				if ((g_sBall.nMoveX >= g_sGoalDae.nMoveX && g_sBall.nMoveX <= g_sGoalDae.nMoveX + 1) || 
					(g_sBall.nMoveX+1 >= g_sGoalDae.nMoveX  && g_sBall.nMoveX+1 <= g_sGoalDae.nMoveX + 1) ||
					(g_sBall.nMoveX >= g_sGoalDae.nLineX[nLength-1]+2  && g_sBall.nMoveX <= g_sGoalDae.nLineX[nLength-1]+3 ) ||
					(g_sBall.nMoveX+1 >= g_sGoalDae.nLineX[nLength-1]+2  && g_sBall.nMoveX+1 <= g_sGoalDae.nLineX[nLength-1]+3 ))
				{
					if ( g_sBall.nMoveY == g_sGoalDae.nMoveY )
					{
						g_sBall.nIsReady = 1;
						g_sBall.nMoveX = g_sPlayer.nMoveX;
						g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
						g_sBall.OldTime = CurTime;
					}
				}
			}
			else
			{
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
}

// Note: ������
void Render()
{
	int nLength, i;
	char str[100];
	char string[100] = { 0, };
	ScreenClear();

	// Note: ������ ����
	ScreenPrint(g_sGoalDae.nMoveX, g_sGoalDae.nMoveY, "��");
	nLength = g_sGoalDae.nLength * 2 + 1;

	for (i = 0; i < nLength; i++)
		ScreenPrint(g_sGoalDae.nLineX[i], g_sGoalDae.nMoveY, "��");

	ScreenPrint(g_sGoalDae.nLineX[nLength - 1] + 2, g_sGoalDae.nMoveY, "��");
	
	if ( g_sPlayer.nX < 0 )
		ScreenPrint( 0, g_sPlayer.nMoveY, &g_strPlayer[g_sPlayer.nX * -1]);
	else if ( g_sPlayer.nMoveX + (g_nLength - (g_sPlayer.nCenterX + 1)) > 79 )		// ������ Ŭ���� ó��
	{
		strncat( string, g_strPlayer, g_nLength - ((g_sPlayer.nMoveX + g_sPlayer.nCenterX + 1) - 79) );
		// ������ ��迵���� ���ΰ� ĳ���Ͱ� ����� �� ����Ϸ��� ���ڸ� �Ϻ� �����Ѵ�.
		ScreenPrint ( g_sPlayer.nX, g_sPlayer.nMoveY, string );
	}
	else
	{
		// 1 Į���� �̵�
		ScreenPrint ( g_sPlayer.nX, g_sPlayer.nMoveY, g_strPlayer );
	}

	ScreenPrint ( g_sBall.nMoveX, g_sBall.nMoveY, "��" );
	sprintf(str, "Goal number : %d", Goal_number);
	ScreenPrint(0, 0, str);
	// Note: ������ ��
	ScreenFlipping();
}

// Note: ����
void Release()
{

}

int main(void)
{
	int nKey, nRemain;

	ScreenInit();
	Init();				// �ʱ�ȭ

	while (1)
	{
		if ( kbhit() )	// kbhit() Ű���� �Է½� true, ���Է½� false �̹Ƿ� ó���� ������ if���� �������� �ʴ´�.
		{
			nKey = _getch();

			if (nKey == 'q')
				break;

			switch ( nKey )
			{
			case 'j':
				g_sPlayer.nMoveX--;
				nRemain = g_nLength - ( g_sPlayer.nCenterX + 1 );		// ��ü ���� - ( �߽� ��ǥ + 1 )�� ���� ����
				// Note: 2 Į���� �̵��ϱ� ���� �κ� ( ���� ��ģ ��� )
				if ( g_sPlayer.nMoveX - g_sPlayer.nCenterX < 0 || g_sPlayer.nMoveX + nRemain > 79 )
					g_sPlayer.nMoveX--;

				g_sPlayer.nX = g_sPlayer.nMoveX - g_sPlayer.nCenterX;
				break;
			case 'l':
				g_sPlayer.nMoveX++;
				nRemain = g_nLength - ( g_sPlayer.nCenterX + 1);		// ��ü ���� - ( �߽� ��ǥ + 1 )�� ���� ����
				// Note: 2 Į���� �̵��ϱ� ���� �κ� ( ���� ��ģ ��� )
				if (g_sPlayer.nMoveX + nRemain > 79 || (g_sPlayer.nMoveX - g_sPlayer.nCenterX < 0) )
					g_sPlayer.nMoveX++;
				
				g_sPlayer.nX = g_sPlayer.nMoveX - g_sPlayer.nCenterX;
				break;
			case 'k':
				if ( g_sBall.nIsReady )
				{
					g_sBall.nMoveX = g_sPlayer.nMoveX;
					g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
					g_sBall.OldTime = clock ();
					g_sBall.nIsReady = 0;
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