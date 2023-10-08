#include "Turboc.h"
#include "Screen.h"

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
DUDAGI g_Dudagi[2];

// Note: �ʱ�ȭ
void Init()
{
	int i;

	// Note: ������ �ʱ�ȭ
	for (i = 0; i < 2; i++)
		g_Dudagi[i].nState = SETUP;
}

// Note: ������ ����
void Update()
{
	int i;
	clock_t CurTime = clock();

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
}

// Note: ������
void Render()
{
	int i;
	ScreenClear();

	for (i = 0; i < 9; i++)
	{
		if (g_Dudagi[i].nState == UP)
		{
			ScreenPrint(g_Point[i].nX, g_Point[i].nY, "��");
		}

		ScreenPrint(g_Point[i].nX, g_Point[i].nY + 1, "��");
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
	Init();			// �ʱ�ȭ

	while(1)
	{
		if ( _kbhit() )
		{
			nKey = _getch();
			if (nKey == 'q')
				break;
		}

		Update();		// ������ ����
		Render();		// ȭ�� ���
	}

	Release();			// ����
	ScreenRelease();
	return 0;
}