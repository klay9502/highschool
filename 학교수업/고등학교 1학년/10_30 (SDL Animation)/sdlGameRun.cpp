// ================================
// Desc : 게임 동작에 필요한 함수 정의
// Date : 2014.10.30
// Author : Jong-Min Kim
// E-mail : clay9502@naver.com
// ================================

#include "stdafx.h"

//외부 참조
extern SDL_Renderer* gRenderer;

CHARACTER* gpOne;

// ================================
// Desc : 게임 초기화 함수
// Return Value : BOOL 에러시 FALSE;
BOOL GameInit(void)
{
	SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
	gpOne = CharInit( gRenderer );

	if ( gpOne == NULL )
		return FALSE;

	return TRUE;
}

VOID GameLoop(void)
{
	while (1)
	{
		CharProcess( gpOne );

		SDL_RenderClear( gRenderer );	// PreRender()

		// Render()
		CharRender( gRenderer, gpOne );

		SDL_RenderPresent( gRenderer );	// PostRender()

		SDL_Delay(100);
	}
}

VOID GameRelease(void)
{
	CharRelease( gpOne );
}