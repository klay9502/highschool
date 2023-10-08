// 9_22.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#define PI 3.141592f
#define ESC 27

Timer* g_pTimer;
Ground* g_pGround;
float g_fSin[360], g_fCos[360];
float g_fRad;
int g_nKey;
int g_nTheta;
bool g_bIsQuit;

void PressAnyKey()
{
	puts("Press a Key!!!");
	getch();
}

void Input()
{
	if ( kbhit() ) g_nKey = getch();

	switch ( g_nKey )
	{
	case ESC:
		g_bIsQuit = true;
		break;
	}
}

void Initialize()
{
	ScreenInit();

	for ( int i = 0; i < 360; i++ )
	{
		g_fRad = i * PI / 180.0f;
		g_fSin[i] = sin( g_fRad );
		g_fCos[i] = cos( g_fRad );
	}
	g_bIsQuit = false;
	g_nKey = -1;

	g_pTimer = InitTimer();
	g_pGround = InitGround();
}

void Process()
{
	if ( ++g_nTheta >= 360 ) g_nTheta = 0;
	ProcessTimer( g_pTimer );
}

void PreRender()	// �׸��� �� ó��
{
	ScreenClear();
}

void Render()		// �׸���
{
	char strbuff[128] = "";

	ScreenPrint( 0, 0, "���ִϿ�����б�" );
	sprintf( strbuff, "1�ʴ� ����ȸ�� �� : %d", g_pTimer->nFPS );
	ScreenPrint( 0, 1, strbuff );
	sprintf( strbuff, "���α׷��� ������� %d�� ������", g_pTimer->nSec );
	ScreenPrint( 0, 2, strbuff );
	ScreenPrint( (g_fCos[g_nTheta] * 10 * 1.5f) + 40, (g_fSin[g_nTheta] * 10) + 11, "*");

	DrawGround ( g_pGround );
}

void PostRender()	// �׸��� �� ó��
{
	ScreenFlipping();
	Sleep(1000/33);
}

void Release()
{
	ReleaseGround( g_pGround );
	ReleaseTimer( g_pTimer );
	ScreenRelease();	// ȭ�� �޸� ����
}

int _tmain(int argc, _TCHAR* argv[])
{
	Initialize();

	while ( !g_bIsQuit )
	{
		Input();

		Process();

		PreRender();
		Render();
		PostRender();
	}

	Release();

	return 0;
}

