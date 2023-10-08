#include "stdafx.h"


//================================================
// Desc : Ÿ�̸� �ʱ�ȭ
// Return : �ν��Ͻ� �޸� ��ȯ
// Date : 2014. 09. 22

Timer* InitTimer()
{
	Timer* pT = (Timer*)malloc( sizeof(Timer) );
	memset ( pT, 0, sizeof(Timer) );
	pT->dStartTime = pT->dTime = GetTickCount();
	return pT;
}

//================================================
// Desc : Ÿ�̸� ���� // 1�ʸ��� Reset
// Date : 2014. 09. 22
void ProcessTimer(Timer* pT)
{
	pT->oldTime = GetTickCount() - pT->dTime;
	
	if (pT->oldTime >= 1000)		// 1�ʸ���
	{
		pT->dTime = GetTickCount();
		pT->nFPS = pT->nCount;
		pT->nCount = 0;
		pT->nSec++;
	}
	pT->nCount++;
}

//================================================
// Desc : Ÿ�̸� ����
// Date : 2014. 09. 22
void ReleaseTimer(Timer* pT)
{
	free( pT );
	pT = NULL;
}
