#pragma once

#define InputMgr CInputManager::GetInstance()
#define INPUT(_key) GetAsyncKeyState(_key)

#include "Singleton.h"

class CInputManager :
	public ISingleton <CInputManager>
{
public: // public 변수
	POINT	m_ptLOldMouse;		// 왼쪽 클릭 후 그 마우스 위치
	POINT	m_ptROldMouse;		// 오른쪽 클릭 후 그 마우스 위치
	POINT	m_ptCurMouse;		// 현재 마우스 위치
	bool	m_bIsPushLButton;	// 왼쪽 버튼 클릭 체크
	bool	m_bIsPushRButton;	// 오른쪽 버튼 클릭 체크
public: // public 함수
	CInputManager(void);
	~CInputManager(void);

	void Process(void);
};

