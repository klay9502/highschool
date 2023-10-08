// ================================
// Desc : ���� ���ۿ� �ʿ��� �Լ� ����
// Date : 2014.10.30
// Author : Jong-Min Kim
// E-mail : clay9502@naver.com
// ================================

#include "stdafx.h"

//�ܺ� ����
extern SDL_Renderer* gRenderer;

CHARACTER* gpOne;

// ================================
// Desc : ���� �ʱ�ȭ �Լ�
// Return Value : BOOL ������ FALSE;
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