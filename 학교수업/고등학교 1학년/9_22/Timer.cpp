#include "stdafx.h"


//================================================
// Desc : 타이머 초기화
// Return : 인스턴스 메모리 반환
// Date : 2014. 09. 22

Timer* InitTimer()
{
	Timer* pT = (Timer*)malloc( sizeof(Timer) );
	memset ( pT, 0, sizeof(Timer) );
	pT->dStartTime = pT->dTime = GetTickCount();
	return pT;
}

//================================================
// Desc : 타이머 연산 // 1초마다 Reset
// Date : 2014. 09. 22
void ProcessTimer(Timer* pT)
{
	pT->oldTime = GetTickCount() - pT->dTime;
	
	if (pT->oldTime >= 1000)		// 1초마다
	{
		pT->dTime = GetTickCount();
		pT->nFPS = pT->nCount;
		pT->nCount = 0;
		pT->nSec++;
	}
	pT->nCount++;
}

//================================================
// Desc : 타이머 해제
// Date : 2014. 09. 22
void ReleaseTimer(Timer* pT)
{
	free( pT );
	pT = NULL;
}
