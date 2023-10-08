#include "Turboc.h"
#include "Screen.h"

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

BALL g_sBall;
PLAYER g_sPlayer;
GOAL_DAE g_sGoalDae;
char g_strPlayer[] = "└─●─┘";	// 주인공 캐릭터
int g_nLength;							// 주인공 캐릭터 길이
int Goal_number;

// Note: 초기화
void Init()
{
	int nLength, i;
	g_sGoalDae.nMoveX = 20;			// 69
	g_sGoalDae.nMoveY = 2;
	g_sGoalDae.nLength = 1;
	g_sGoalDae.MoveTime = 1000;		// 2000
	g_sGoalDae.OldTime = clock();
	g_sGoalDae.nDist = 1;
	nLength = g_sGoalDae.nLength * 2 + 1;		// Note: 배열의 최대 길이, 골라인수 계산

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

	for (i = 0; i < nLength; i++)
	{
		g_sGoalDae.nLineX[i] = g_sGoalDae.nMoveX + 2 * (i + 1);
	}
}

// Note: 데이터 갱신
void Update()
{
	clock_t CurTime = clock();
	int nLength = g_sGoalDae.nLength * 2 + 1;	// Note: 배열의 최대 길이
	int i;

	// 골대 이동
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
			g_sGoalDae.nDist = g_sGoalDae.nDist * -1;		// -1 이 방향을 바꾸어 줌.
		}
	}

	// 공의 이동
	if ( g_sBall.nIsReady == 0 )		// 이동 중일 때
	{
		if ((CurTime - g_sBall.OldTime) > g_sBall.MoveTime )
		{
			if ( g_sBall.nMoveY - 1 > 0 )		// 공이 경계영역에 도착하지 않았을 경우 즉 y값이 0보다 클 경우
			{
				g_sBall.nMoveY--;
				g_sBall.OldTime = CurTime;	// 다음 이동 시각과 비교하기 위해 현재 시간을 이전 시간 변수에 저장
				
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

// Note: 렌더링
void Render()
{
	int nLength, i;
	char str[100];
	char string[100] = { 0, };
	ScreenClear();

	// Note: 렌더링 시작
	ScreenPrint(g_sGoalDae.nMoveX, g_sGoalDae.nMoveY, "□");
	nLength = g_sGoalDae.nLength * 2 + 1;

	for (i = 0; i < nLength; i++)
		ScreenPrint(g_sGoalDae.nLineX[i], g_sGoalDae.nMoveY, "─");

	ScreenPrint(g_sGoalDae.nLineX[nLength - 1] + 2, g_sGoalDae.nMoveY, "□");
	
	if ( g_sPlayer.nX < 0 )
		ScreenPrint( 0, g_sPlayer.nMoveY, &g_strPlayer[g_sPlayer.nX * -1]);
	else if ( g_sPlayer.nMoveX + (g_nLength - (g_sPlayer.nCenterX + 1)) > 79 )		// 오른족 클리핑 처리
	{
		strncat( string, g_strPlayer, g_nLength - ((g_sPlayer.nMoveX + g_sPlayer.nCenterX + 1) - 79) );
		// 오른쪽 경계영역에 주인공 캐릭터가 닿았을 때 출력하려는 문자를 일부 복사한다.
		ScreenPrint ( g_sPlayer.nX, g_sPlayer.nMoveY, string );
	}
	else
	{
		// 1 칼럼식 이동
		ScreenPrint ( g_sPlayer.nX, g_sPlayer.nMoveY, g_strPlayer );
	}

	ScreenPrint ( g_sBall.nMoveX, g_sBall.nMoveY, "◎" );
	sprintf(str, "Goal number : %d", Goal_number);
	ScreenPrint(0, 0, str);
	// Note: 렌더링 끝
	ScreenFlipping();
}

// Note: 해제
void Release()
{

}

int main(void)
{
	int nKey, nRemain;

	ScreenInit();
	Init();				// 초기화

	while (1)
	{
		if ( kbhit() )	// kbhit() 키보드 입력시 true, 미입력시 false 이므로 처음엔 무조건 if문을 실행하지 않는다.
		{
			nKey = _getch();

			if (nKey == 'q')
				break;

			switch ( nKey )
			{
			case 'j':
				g_sPlayer.nMoveX--;
				nRemain = g_nLength - ( g_sPlayer.nCenterX + 1 );		// 전체 길이 - ( 중심 좌표 + 1 )은 남은 길이
				// Note: 2 칼럼씩 이동하기 위한 부분 ( 팔이 걸친 경우 )
				if ( g_sPlayer.nMoveX - g_sPlayer.nCenterX < 0 || g_sPlayer.nMoveX + nRemain > 79 )
					g_sPlayer.nMoveX--;

				g_sPlayer.nX = g_sPlayer.nMoveX - g_sPlayer.nCenterX;
				break;
			case 'l':
				g_sPlayer.nMoveX++;
				nRemain = g_nLength - ( g_sPlayer.nCenterX + 1);		// 전체 길이 - ( 중심 좌표 + 1 )은 남은 길이
				// Note: 2 칼럼씩 이동하기 위한 부분 ( 팔이 걸친 경우 )
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

		Update();		// 데이터 갱신
		Render();		// 화면 출력
	}

	Release();			// 해제
	ScreenRelease();
	return 0;
}