#include "stdafx.h"

SDL_Window*		gWnd	  = NULL;
SDL_Renderer*	gRenderer = NULL;

FMOD_SYSTEM*	gFmodSystem;	// FMOD System 변수선언
FMOD_SOUND*		gFmodSound;	// 사운드 파일과 연결하기 위한 FMOD Sound
FMOD_CHANNEL*	gFmodChannel;	// 배경음의 채널, 게임이 종료될 때까지 계속 출력 되므로 전역 변수로 선언 

BOOL System_Init(void)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	FMOD_System_Create(&gFmodSystem);
	FMOD_System_Init(gFmodSystem, 32, FMOD_INIT_NORMAL, NULL);
	FMOD_System_CreateSound(gFmodSystem, "Maid with the Flaxen Hair.mp3", FMOD_LOOP_NORMAL, 0, &gFmodSound);

	gWnd = SDL_CreateWindow("1410 Kim Jong-Min", 100, 100, 640, 480, SDL_WINDOW_FULLSCREEN);
	gRenderer = SDL_CreateRenderer(gWnd, -1, SDL_RENDERER_ACCELERATED);

		// 배경음 출력
	FMOD_System_PlaySound(gFmodSystem, FMOD_CHANNEL_FREE, gFmodSound, 0, &gFmodChannel);

	return TRUE;
}

void System_Release(void)
{
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWnd);

	FMOD_Sound_Release(gFmodSound);		// FMOD sound 객체 해제

	FMOD_System_Close(gFmodSystem);		// FMOD system 객체 close
	FMOD_System_Release(gFmodSystem);	// FMOD system 객체 해제

	TTF_Quit();
	SDL_Quit();
}