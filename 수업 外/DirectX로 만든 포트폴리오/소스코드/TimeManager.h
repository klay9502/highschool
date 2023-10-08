#pragma once

#define TimeMgr CTimeManager::GetInstance()

#include "Singleton.h"

class CTimeManager :
	public ISingleton <CTimeManager>
{
private: // private 변수
	// 시간 계산 변수
	float m_fCurFrame;
	float m_fDateTime;
	float m_fOldTime;
	float m_fCurTime;
public: // public 변수
	float m_fCurTick;	// 현재 시간 변수
	float m_fFPS;		// 게임 내 FPS
public: // public 함수
	CTimeManager(void);
	~CTimeManager(void);

	void Init(void);
	void Process(void);
	void Release(void);
};

