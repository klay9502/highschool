#pragma once
#include <SDL.h>

typedef struct tagExp
{
	int x, y; // ȭ�鿡 �׷����� ũ��
	SDL_Surface* pSurface; // �̹���
	SDL_Rect rtImg[64]; // �̹��� ��ǥ

}EXP;

EXP* InitExp();			// �ʱ�ȭ
void Render(EXP* exp, SDL_Surface* screen);	// �׸���
void Release(EXP* exp);	// ����