/*
#include "Turboc.h"
#include "Screen.h"
#include <fmod.h>

FMOD_SYSTEM		*g_System;		// FMOD System ��������
FMOD_SOUND		*g_Sound[2];		// �ΰ��� ���� ���ϰ� �����ϱ� ���� FMOD Sound
FMOD_CHANNEL	*g_Channel;		// ������� ä��, ������ ����� ������ ��� ��� �ǹǷ� ���� ������ ����

// Note: �ʱ�ȭ
void Init()
{
	// FMOD �ʱ�ȭ �� ���� ���� �ε�
	FMOD_System_Create( &g_System );
	FMOD_System_Init( g_System, 32, FMOD_INIT_NORMAL, NULL );
	FMOD_System_CreateSound( g_System, "bg.mp3", FMOD_LOOP_NORMAL, 0, &g_Sound[0] );
	FMOD_System_CreateSound( g_System, "THIS!.mp3", FMOD_DEFAULT, 0, &g_Sound[1] );

	// ����� ���
	FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[0], 0, &g_Channel );
}

// Note: ������ ����
void Update()
{

}

// Note: ������
void Render()
{
	ScreenClear();
	ScreenFlipping();
}

// Note: ����
void Release()
{
	int i;

	for ( i = 0; i < 2; i++)
		FMOD_Sound_Release( g_Sound[i] );		// FMOD sound ��ü ����

	FMOD_System_Close( g_System );		// FMOD system ��ü close
	FMOD_System_Release( g_System );	// FMOD system ��ü ����
}

int main(void)
{
	int nKey;
	FMOD_CHANNEL *pChannel;		// ȿ������ ä��, ȿ������ �Ͻ������� ���ǹǷ� ���������� ����

	ScreenInit();
	Init();

	while (1)
	{
		if ( _kbhit() )
		{
			nKey = _getch();

			if ( nKey == 's' )
				FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[1], 0, &pChannel );		// ȿ���� ���
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
char g_strPlayer[] = "�����ܦ���";	// ���ΰ� ĳ����
int g_nLength;							// ���ΰ� ĳ���� ����

void Init ()
{
	g_sPlayer.nCenterX = 4;		// ���ΰ� ĳ������ �߽���ǥ
	g_sPlayer.nCenterY = 0;		// ���ΰ� ĳ������ �߽���ǥ
	g_sPlayer.nMoveX = 20;		// ���ΰ� ĳ������ �̵���ǥ �ʱ�ȭ
	g_sPlayer.nMoveY = 22;		// ���ΰ� ĳ������ �̵���ǥ �ʱ�ȭ
	g_sPlayer.nX = g_sPlayer.nMoveX - g_sPlayer.nCenterX;		// ��±�����ǥ = �̵���ǥ - �߽���ǥ
	g_nLength = strlen( g_strPlayer );		// ���ΰ� ĳ������ ��ü ����

	// ���� �ʱ�ȭ
	g_sBall.nIsReady = 1;
	g_sBall.nMoveX = g_sPlayer.nMoveX;
	g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
	g_sBall.MoveTime = 100;
}

void Update ()
{
	clock_t CurTime = clock ();
	if ( g_sBall.nIsReady == 0 )		// �̵� ���� ��
	{
		if ( (CurTime - g_sBall.OldTime) > g_sBall.MoveTime )
		{
			if ( g_sBall.nMoveY - 1 > 0 )		// ���� ��迵���� �������� �ʾ��� ��� �� y���� 0���� Ŭ ���
			{
				g_sBall.nMoveY--;
				g_sBall.OldTime = CurTime;	// ���� �̵� �ð��� ���ϱ� ���� ���� �ð��� ���� �ð� ������ ����
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
void Render ()
{
	char string[100] = { 0, };
	ScreenClear();

	// Note: ������ ����

	// Note: 2 �÷��� Ŭ����
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
	sprintf ( string, "���ΰ� �̵� ��ǥ : %d, %d", g_sPlayer.nMoveX, g_sPlayer.nMoveY );
	ScreenPrint ( 0, 0, string );
	
	/*
	sprintf ( string, "g_nLength : %d g_sPlayer.nMoveX : %d g_sPlayer.nCenterX : %d", g_nLength, g_sPlayer.nMoveX, g_sPlayer.nCenterX );
	ScreenPrint ( 0, 1, string );
	*/

	// Note: ������ ��
	ScreenFlipping ();
}

void Release ()
{

}

int main(void)
{
	int nKey, nRemain;

	ScreenInit();
	Init();				// �ʱ�ȭ

	while (1)
	{
		if ( _kbhit() )		// kbhit() Ű���� �Է½� true, ���Է½� false �̹Ƿ� ó���� ������ if���� �������� �ʴ´�.
		{
			nKey = _getch();

			if ( nKey == 'q' )
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

		Update ();			// ������ ����
		Render ();			// ȭ�� ���
	}

	Release ();			// ����
	ScreenRelease ();

	return 0;
}