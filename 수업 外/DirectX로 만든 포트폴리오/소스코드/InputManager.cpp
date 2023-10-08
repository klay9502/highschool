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
	m_nDragX = 0;
	m_nDragY = 0;
}

CInputManager::~CInputManager(void)
{
	// empty...
}

void CInputManager::Process(void)
{
	GetCursorPos(&m_ptCurMouse);
	// â��� ��ǥ ����
	if (!WinMgr->m_bIsWindowMode)
	{
		ScreenToClient(WinMgr->m_hWnd, &m_ptCurMouse);
	}

	if (INPUT(VK_LBUTTON) & 1)
	{
		m_ptLOldMouse = m_ptCurMouse;
		m_bIsPushLButton = true;
		//printf("LButton\n");
		printf("%d %d\n", m_ptLOldMouse.x, m_ptLOldMouse.y);
	}
	else
	{
		m_bIsPushLButton = false;
	}

	// ���� �巡��
	if (m_bIsDrag && INPUT(VK_LBUTTON) & 0x8001)
	{
		m_nDragX = m_ptLOldMouse.x - m_ptCurMouse.x;
		m_nDragY = m_ptLOldMouse.y - m_ptCurMouse.y;
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