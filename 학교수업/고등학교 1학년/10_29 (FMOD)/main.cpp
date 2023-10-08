/*
#include "Turboc.h"
#include "Screen.h"
#include <fmod.h>

FMOD_SYSTEM		*g_System;		// FMOD System 변수선언
FMOD_SOUND		*g_Sound[2];		// 두개의 사운드 파일과 연결하기 위한 FMOD Sound
FMOD_CHANNEL	*g_Channel;		// 배경음의 채널, 게임이 종료될 때까지 계속 출력 되므로 전역 변수로 선언

// Note: 초기화
void Init()
{
	// FMOD 초기화 및 사운드 파일 로딩
	FMOD_System_Create( &g_System );
	FMOD_System_Init( g_System, 32, FMOD_INIT_NORMAL, NULL );
	FMOD_System_CreateSound( g_System, "bg.mp3", FMOD_LOOP_NORMAL, 0, &g_Sound[0] );
	FMOD_System_CreateSound( g_System, "THIS!.mp3", FMOD_DEFAULT, 0, &g_Sound[1] );

	// 배경음 출력
	FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[0], 0, &g_Channel );
}

// Note: 데이터 갱신
void Update()
{

}

// Note: 렌더링
void Render()
{
	ScreenClear();
	ScreenFlipping();
}

// Note: 해제
void Release()
{
	int i;

	for ( i = 0; i < 2; i++)
		FMOD_Sound_Release( g_Sound[i] );		// FMOD sound 객체 해제

	FMOD_System_Close( g_System );		// FMOD system 객체 close
	FMOD_System_Release( g_System );	// FMOD system 객체 해제
}

int main(void)
{
	int nKey;
	FMOD_CHANNEL *pChannel;		// 효과음의 채널, 효과음은 일시적으로 사용되므로 지역변수로 선언

	ScreenInit();
	Init();

	while (1)
	{
		if ( _kbhit() )
		{
			nKey = _getch();

			if ( nKey == 's' )
				FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[1], 0, &pChannel );		// 효과음 출력
		}

		Update();
		Render();

		FMOD_System_Update( g_System );
	}

	Release();
	ScreenRelease();
	
	return 0;
}
*/

#include "Screen.h"
#include "Turboc.h"

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
char g_strPlayer[] = "└─●─┘";	// 주인공 캐릭터
int g_nLength;							// 주인공 캐릭터 길이

void Init ()
{
	g_sPlayer.nCenterX = 4;		// 주인공 캐릭터의 중심좌표
	g_sPlayer.nCenterY = 0;		// 주인공 캐릭터의 중심좌표
	g_sPlayer.nMoveX = 20;		// 주인공 캐릭터의 이동좌표 초기화
	g_sPlayer.nMoveY = 22;		// 주인공 캐릭터의 이동좌표 초기화
	g_sPlayer.nX = g_sPlayer.nMoveX - g_sPlayer.nCenterX;		// 출력기준좌표 = 이동좌표 - 중심좌표
	g_nLength = strlen( g_strPlayer );		// 주인공 캐릭터의 전체 길이

	// 공의 초기화
	g_sBall.nIsReady = 1;
	g_sBall.nMoveX = g_sPlayer.nMoveX;
	g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
	g_sBall.MoveTime = 100;
}

void Update ()
{
	clock_t CurTime = clock ();
	if ( g_sBall.nIsReady == 0 )		// 이동 중일 때
	{
		if ( (CurTime - g_sBall.OldTime) > g_sBall.MoveTime )
		{
			if ( g_sBall.nMoveY - 1 > 0 )		// 공이 경계영역에 도착하지 않았을 경우 즉 y값이 0보다 클 경우
			{
				g_sBall.nMoveY--;
				g_sBall.OldTime = CurTime;	// 다음 이동 시각과 비교하기 위해 현재 시간을 이전 시간 변수에 저장
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
void Render ()
{
	char string[100] = { 0, };
	ScreenClear();

	// Note: 렌더링 시작

	// Note: 2 컬럼씩 클리핑
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
	sprintf ( string, "주인공 이동 좌표 : %d, %d", g_sPlayer.nMoveX, g_sPlayer.nMoveY );
	ScreenPrint ( 0, 0, string );
	
	/*
	sprintf ( string, "g_nLength : %d g_sPlayer.nMoveX : %d g_sPlayer.nCenterX : %d", g_nLength, g_sPlayer.nMoveX, g_sPlayer.nCenterX );
	ScreenPrint ( 0, 1, string );
	*/

	// Note: 렌더링 끝
	ScreenFlipping ();
}

void Release ()
{

}

int main(void)
{
	int nKey, nRemain;

	ScreenInit();
	Init();				// 초기화

	while (1)
	{
		if ( _kbhit() )		// kbhit() 키보드 입력시 true, 미입력시 false 이므로 처음엔 무조건 if문을 실행하지 않는다.
		{
			nKey = _getch();

			if ( nKey == 'q' )
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

		Update ();			// 데이터 갱신
		Render ();			// 화면 출력
	}

	Release ();			// 해제
	ScreenRelease ();

	return 0;
}