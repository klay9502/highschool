#pragma once

#define TimeMgr CTimeManager::GetInstance()

#include "Singleton.h"

class CTimeManager :
	public ISingleton <CTimeManager>
{
private: // private ����
	// �ð� ��� ����
	float m_fCurFrame;
	float m_fDateTime;
	float m_fOldTime;
	float m_fCurTime;
public: // public ����
	float m_fCurTick;	// ���� �ð� ����
	float m_fFPS;		// ���� �� FPS
public: // public �Լ�
	CTimeManager(void);
	~CTimeManager(void);

	void Init(void);
	void Process(void);
	void Release(void);
};

