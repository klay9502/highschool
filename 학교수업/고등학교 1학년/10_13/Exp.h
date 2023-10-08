#pragma once
#include <SDL.h>

typedef struct tagExp
{
	int x, y; // 화면에 그려지는 크기
	SDL_Surface* pSurface; // 이미지
	SDL_Rect rtImg[64]; // 이미지 좌표

}EXP;

EXP* InitExp();			// 초기화
void Render(EXP* exp, SDL_Surface* screen);	// 그리기
void Release(EXP* exp);	// 해제