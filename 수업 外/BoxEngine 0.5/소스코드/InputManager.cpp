#include "stdafx.h"
#include "InputManager.h"
#include "WindowManager.h";

/*
* INPUT �Լ� ��ȯ�� �����
*
* GetKeyState(_key) �Ǵ� GetAsyncKeyState(_key) �ڿ� &value �� �ϸ� ��.
* 0 (0x0000)	: ������ ���� ���� ���� ȣ�� �������� �ȴ��� ����
* 0x8000		: ������ ���� ���� ���� ȣ�� �������� ���� ����
* 0x8001		: ������ ���� ���� �ְ� ȣ�� �������� ���� ����
* 1 (0x0001)	: ������ ���� ���� �ְ� ȣ�� �������� �ȴ��� ����
*/

CInputManager::CInputManager(void)
{
	// empty...
}

CInputManager::~CInputManager(void)
{
	// empty...
}

void CInputManager::Process(void)
{
	GetCursorPos(&m_ptCurMouse);
	// â��� ��ǥ ����
	ScreenToClient(WinMgr->m_hWnd, &m_ptCurMouse);

	if (INPUT(VK_LBUTTON) & 1)
	{
		m_ptLOldMouse = m_ptCurMouse;
		m_bIsPushLButton = true;
		printf("LButton\n");
	}
	else
	{
		m_bIsPushLButton = false;
	}

	if (INPUT(VK_RBUTTON) & 1)
	{
		m_ptROldMouse = m_ptCurMouse;
		m_bIsPushRButton = true;
		printf("RButton\n");
	}
	else
	{
		m_bIsPushRButton = false;
	}
}