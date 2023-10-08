#include "Turboc.h"
#include "Screen.h"

typedef struct _MANGCHI
{
	int nIsAttack;			// ��ġ ����
	clock_t StartTime;		// Ÿ�� ���°� ���۵� �ð�
	clock_t DelayTime;		// Ÿ�� ������ ���� �ð�
	int nIndex;				// ��ǥ �迭�� �����ϱ� ���� �ε���
	int nStayX, nStayY;		// ��� ������ �� ��ǥ
} MANGCHI;

typedef struct _XY
{
	int nX, nY;
} XY;

XY g_Point[9] = { {10, 15}, {25, 15}, {30, 15},
                  {10, 10}, {20, 10}, {30, 10},
                  {10, 5},{20, 5},{30, 5} 
};

MANGCHI g_Mangchi;

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

// Note: �ʱ�ȭ
void Init()
{
	// Note: ��ġ �¾�
	g_Mangchi.nIsAttack = 0;
	g_Mangchi.nIndex = 0;
	g_Mangchi.nStayX = 40;
	g_Mangchi.nStayY = 10;
	g_Mangchi.StartTime = clock();
	g_Mangchi.DelayTime = 300;
}

// Note: ������ ����
void Update()
{
	clock_t CurTime = clock();

	if (g_Mangchi.nIsAttack == 1)
	{
		if (CurTime - g_Mangchi.StartTime > g_Mangchi.DelayTime)
		{
			g_Mangchi.nIsAttack = 0;
		}
	}
}

// Note: ������
void Render()
{
	ScreenClear();

	if (g_Mangchi.nIsAttack)
		Mangchi(g_Point[g_Mangchi.nIndex].nX, g_Point[g_Mangchi.nIndex].nY);
	else
		MangchiReady(g_Mangchi.nStayX, g_Mangchi.nStayY);

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

			if (g_Mangchi.nIsAttack == 0)
			{
				if (nKey >= '1' && nKey <= '9')
				{
					g_Mangchi.nIndex = nKey - '1';
					g_Mangchi.StartTime = clock();
					g_Mangchi.nIsAttack = 1;
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