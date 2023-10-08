#include "stdafx.h"

SDL_Rect	Animation[6];
int			Ani_Count = 0;
// ================================
// Desc : 캐릭터 생성 초기화 함수
// 인자값 : SDL_Renderer* 그러질 영역
// 리턴값 : CHARACTER구조체 포인터
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
// Desc : 캐릭터 이동 or 애니메이션 계산 함수
// 인자값 : CHARACTER 구조체 포인터
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
// Desc : 캐릭터 이미지 출력
// 인자값 : SDL_Renderer* 그러질 영역, CHARACTER 구조체 포인터
// Date : 2014.10.30
// Author : Jong-Min Kim
// E-mail : clay9502@naver.com
VOID CharRender(SDL_Renderer* pRenderer, CHARACTER* pChar)
{
	SDL_RenderCopy( pRenderer, pChar->pTexture, &Animation[Ani_Count], NULL );
}

// ================================
// Desc : 캐릭터 메모리 제거(이미지와 텍스쳐 모두 제거)
// 인자값 : CHARACTER 구조체 포인터
// Date : 2014.10.30
// Author : Jong-Min Kim
// E-mail : clay9502@naver.com
VOID CharRelease(CHARACTER* pChar)
{
	SDL_FreeSurface( pChar->pImage );
	SDL_DestroyTexture( pChar->pTexture );
	delete pChar;
}