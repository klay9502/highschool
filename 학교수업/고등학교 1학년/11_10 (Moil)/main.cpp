#include "Turboc.h"
#include "Screen.h"

typedef struct _MANGCHI
{
	int nIsAttack;			// 망치 상태
	clock_t StartTime;		// 타격 상태가 시작된 시각
	clock_t DelayTime;		// 타격 상태의 지연 시각
	int nIndex;				// 좌표 배열에 접근하기 위한 인덱스
	int nStayX, nStayY;		// 대기 상태일 때 좌표
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

// Note: 초기화
void Init()
{
	// Note: 망치 셋업
	g_Mangchi.nIsAttack = 0;
	g_Mangchi.nIndex = 0;
	g_Mangchi.nStayX = 40;
	g_Mangchi.nStayY = 10;
	g_Mangchi.StartTime = clock();
	g_Mangchi.DelayTime = 300;
}

// Note: 데이터 갱신
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

// Note: 렌더링
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
	Init();			// 초기화

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

		Update();		// 데이터 갱신
		Render();		// 화면 출력
	}

	Release();			// 해제
	ScreenRelease();
	return 0;
}