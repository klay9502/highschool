// 10_30.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	SystemInit();

	GameInit();

	GameLoop();

	GameRelease();

	SystemRelease();



	return 0;
}

