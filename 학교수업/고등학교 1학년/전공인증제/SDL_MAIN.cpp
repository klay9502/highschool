// 1410.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	System_Init();		// �ý��� �ʱ�ȭ

	Game_Init();		// �ΰ��� �ʱ�ȭ

	Game_Loop();		// �ΰ��� �ݺ�����

	Game_Release();		// �ΰ��� ������

	System_Release();	// �ý��� ������

	return 0;
}

