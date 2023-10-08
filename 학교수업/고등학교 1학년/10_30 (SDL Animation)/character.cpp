#include "stdafx.h"

SDL_Rect	Animation[6];
int			Ani_Count = 0;
// ================================
// Desc : ĳ���� ���� �ʱ�ȭ �Լ�
// ���ڰ� : SDL_Renderer* �׷��� ����
// ���ϰ� : CHARACTER����ü ������
// Date : 2014.10.30
// Author : Jong-Min Kim
// E-mail : clay9502@naver.com
CHARACTER*	CharInit(SDL_Renderer* pRenderer)
{
	CHARACTER* pChar;
	pChar = new CHARACTER;

	pChar->pImage = SDL_LoadBMP( "./char.bmp" );
	pChar->colorKey = SDL_MapRGB(pChar->pImage->format, 50, 150, 200);
	SDL_SetColorKey(pChar->pImage, SDL_RLEACCEL, pChar->colorKey);

	pChar->pTexture = SDL_CreateTextureFromSurface( pRenderer, pChar->pImage );

	pChar->SpriteWidth = 165;
	pChar->SpriteHeight = 170;

	for (int i = 0; i < 6; i++)
	{
		Animation[i].x = i * pChar->SpriteWidth;
		Animation[i].y = 2 * pChar->SpriteHeight;
		Animation[i].w = pChar->SpriteWidth;
		Animation[i].h = pChar->SpriteHeight;
	}

	return pChar;
}

// ================================
// Desc : ĳ���� �̵� or �ִϸ��̼� ��� �Լ�
// ���ڰ� : CHARACTER ����ü ������
// Date : 2014.10.30
// Author : Jong-Min Kim
// E-mail : clay9502@naver.com
VOID CharProcess(CHARACTER* pChar)
{
	if (++Ani_Count >= 6)
	{
		Ani_Count = 0;
	}
}

// ================================
// Desc : ĳ���� �̹��� ���
// ���ڰ� : SDL_Renderer* �׷��� ����, CHARACTER ����ü ������
// Date : 2014.10.30
// Author : Jong-Min Kim
// E-mail : clay9502@naver.com
VOID CharRender(SDL_Renderer* pRenderer, CHARACTER* pChar)
{
	SDL_RenderCopy( pRenderer, pChar->pTexture, &Animation[Ani_Count], NULL );
}

// ================================
// Desc : ĳ���� �޸� ����(�̹����� �ؽ��� ��� ����)
// ���ڰ� : CHARACTER ����ü ������
// Date : 2014.10.30
// Author : Jong-Min Kim
// E-mail : clay9502@naver.com
VOID CharRelease(CHARACTER* pChar)
{
	SDL_FreeSurface( pChar->pImage );
	SDL_DestroyTexture( pChar->pTexture );
	delete pChar;
}