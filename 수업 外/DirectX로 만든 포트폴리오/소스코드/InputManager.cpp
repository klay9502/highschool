#include "stdafx.h"
#include "InputManager.h"
#include "WindowManager.h";

/*
* INPUT 함수 반환값 사용방법
*
* GetKeyState(_key) 또는 GetAsyncKeyState(_key) 뒤에 &value 를 하면 됨.
* 0 (0x0000)	: 이전에 누른 적이 없고 호출 시점에서 안눌린 상태
* 0x8000		: 이전에 누른 적이 없고 호출 시점에서 눌린 상태
* 0x8001		: 이전에 누른 적이 있고 호출 시점에서 눌린 상태
* 1 (0x0001)	: 이전에 누른 적이 있고 호출 시점에서 안눌린 상태
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
	// 창모드 촤표 수정
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

	// 왼쪽 드래그
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