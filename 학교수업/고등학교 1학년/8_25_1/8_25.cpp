// 8_25.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

/*
#include "stdafx.h"

#pragma comment(lib, "winmm.lib")
#define ESC 27
#define ONE 49
#define TWO 50
#define TRE 51
#define FOR 52
#define FIV 53

void PlaySoundOne()
{
	sndPlaySound(TEXT("Speech On.wav"), SND_ASYNC );
}

void PlaySoundTwo()
{
	sndPlaySound(TEXT("Windows Ding.wav"), SND_ASYNC );
}

void PlaySoundTre()
{
	sndPlaySound(TEXT("ir_begin.wav"), SND_ASYNC );
}

void PlaySoundFor()
{
	sndPlaySound(TEXT("Windows Logon Sound.wav"), SND_ASYNC );
}

void PlaySoundFiv()
{
	sndPlaySound(TEXT("Windows Default.wav"), SND_ASYNC );
}

int main(int argc, _TCHAR* argv[])
{
	int nKey;

	printf("ESC를 누르면 종료\t다른키를 누르면 소리재생\n");
	while(1)
	{
		if( kbhit() )
		{
			nKey = getch();
			switch( nKey )
			{
				case ESC: exit(0); break;
				case ONE: PlaySoundOne(); break;
				case TWO: PlaySoundTwo(); break;
				case TRE: PlaySoundTre(); break;
				case FOR: PlaySoundFor(); break;
				case FIV: PlaySoundFiv(); break;
			}
		}
	}
	return 0;
}
*/

/*
#include "stdafx.h"
#define ESC 27
#define ENTER 13
#define SPACE 32

void PlaySound()
{
	mciSendString("play opening.mp3", NULL, 0, NULL);
}

void StopSound()
{
	mciSendString("stop opening.mp3", NULL, 0, NULL);
}

int main(int argc, _TCHAR* argv[])
{
	int nKey;

	printf("ESC를 누르면 종료\tENTER 음악재생\tSPACE 음악종료\n");
	while(1)
	{
		if( kbhit() )
		{
			nKey = getch();
			switch( nKey )
			{
				case ESC: exit(0); break; 
				case ENTER: PlaySound(); break;
				case SPACE: StopSound(); break;
			}
		}
	}
	return 0;
}
*/

/*
#include "stdafx.h"
#define ESC 27
#define ENTER 13
#define SPACE 32

HWND hWndAVI = NULL;

void Play()
{
	if(hWndAVI) MCIWndPlay(hWndAVI);
}

void Stop()
{
	if(hWndAVI) MCIWndStop(hWndAVI);
}

void Exit()
{
	MCIWndClose(hWndAVI);
	MCIWndDestroy(hWndAVI);
	hWndAVI = NULL;
}

int _tmain(int argc, _TCHAR argv[])
{
	int nKey;

	HINSTANCE hInst = GetModuleHandle(NULL);
	char path[1024] = "";
	printf("재생할 동영상의 경로와 이름은?\n");
	scanf("%s", path);

	hWndAVI = MCIWndCreate(NULL, hInst, MCIWNDF_NOTIFYANSI | MCIWNDF_NOMENU | MCIWNDF_NOTIFYALL | MCIWNDF_NOPLAYBAR, path);

	if(hWndAVI)
	{
		printf("ESC 종료\tENTER 영상재생\tSPACE 영상정지\n");
	}

	while (hWndAVI)
	{
		if (kbhit())
		{
			nKey = getch();

			switch (nKey)
			{
			case ESC: Exit(); break;
			case ENTER: Play(); break;
			case SPACE: Stop(); break;
			}
		}
	}

	return 0;
}
*/