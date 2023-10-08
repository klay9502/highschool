#pragma once

#define InputMgr CInputManager::GetInstance()
#define INPUT(_key) GetAsyncKeyState(_key)

#include "Singleton.h"

class CInputManager :
	public ISingleton <CInputManager>
{
public: // public ����
	POINT	m_ptLOldMouse;		// ���� Ŭ�� �� �� ���콺 ��ġ
	POINT	m_ptROldMouse;		// ������ Ŭ�� �� �� ���콺 ��ġ
	POINT	m_ptCurMouse;		// ���� ���콺 ��ġ
	bool	m_bIsPushLButton;	// ���� ��ư Ŭ�� üũ
	bool	m_bIsPushRButton;	// ������ ��ư Ŭ�� üũ
public: // public �Լ�
	CInputManager(void);
	~CInputManager(void);

	void Process(void);
};

