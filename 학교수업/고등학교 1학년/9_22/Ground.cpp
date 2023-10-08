#include "stdafx.h"

//================================================
// Desc : 배경 초기화
// Return : 인스턴스 메모리 반환
// Date : 2014. 09. 22
Ground* InitGround()
{
	Ground* gr = (Ground*)malloc( sizeof(Ground) );

	gr->y = 20;
	gr->ch = (char*)malloc( sizeof(char) * 2 );
	sprintf( gr->ch, "%s", "-" );

	return gr;
}

//================================================
// Desc : 배경 그리기
// Date : 2014. 09. 22
void DrawGround(Ground* gr)
{
	for (int i = 0; i < 80; i++)
	{
		ScreenPrint( i, gr->y, gr->ch ) ;
	}
}

//================================================
// Desc : 배경 그리기
// Date : 2014. 09. 22
void ReleaseGround(Ground* gr)
{
	free( gr );
	gr = NULL;
}