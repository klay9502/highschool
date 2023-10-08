#include "stdafx.h"

SDL_Window*		gWnd	  = NULL;
SDL_Renderer*	gRenderer = NULL;

FMOD_SYSTEM*	gFmodSystem;	// FMOD System ��������
FMOD_SOUND*		gFmodSound;	// ���� ���ϰ� �����ϱ� ���� FMOD Sound
FMOD_CHANNEL*	gFmodChannel;	// ������� ä��, ������ ����� ������ ��� ��� �ǹǷ� ���� ������ ���� 

BOOL System_Init(void)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	FMOD_System_Create(&gFmodSystem);
	FMOD_System_Init(gFmodSystem, 32, FMOD_INIT_NORMAL, NULL);
	FMOD_System_CreateSound(gFmodSystem, "Maid with the Flaxen Hair.mp3", FMOD_LOOP_NORMAL, 0, &gFmodSound);

	gWnd = SDL_CreateWindow("1410 Kim Jong-Min", 100, 100, 640, 480, SDL_WINDOW_FULLSCREEN);
	gRenderer = SDL_CreateRenderer(gWnd, -1, SDL_RENDERER_ACCELERATED);

		// ����� ���
	FMOD_System_PlaySound(gFmodSystem, FMOD_CHANNEL_FREE, gFmodSound, 0, &gFmodChannel);

	return TRUE;
}

void System_Release(void)
{
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWnd);

	FMOD_Sound_Release(gFmodSound);		// FMOD sound ��ü ����

	FMOD_System_Close(gFmodSystem);		// FMOD system ��ü close
	FMOD_System_Release(gFmodSystem);	// FMOD system ��ü ����

	TTF_Quit();
	SDL_Quit();
}