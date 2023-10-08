#include "stdafx.h"
#include "TimeManager.h"


CTimeManager::CTimeManager(void)
{
	m_fCurFrame	= 0.0f;
	m_fDateTime = 0.0f;
	m_fOldTime	= 0.0f;
	m_fCurTime	= 0.0f;
	m_fCurTick	= 0.0f;
	m_fFPS		= 0.0f;
}

CTimeManager::~CTimeManager(void)
{
	// empty...
}

void CTimeManager::Init(void)
{
	m_fOldTime = GetTickCount();
}

void CTimeManager::Process(void)
{
	float temp = GetTickCount();
	m_fDateTime = temp - m_fOldTime;
	m_fOldTime = temp;

	m_fCurTime += m_fDateTime;
	m_fCurFrame++;

	m_fFPS = m_fCurFrame / (m_fCurTime / 1000.0f);
	m_fCurTick = m_fCurTime / 1000.0f;
}

void CTimeManager::Release(void)
{
	m_fCurFrame	= NULL;
	m_fDateTime = NULL;
	m_fOldTime	= NULL;
	m_fCurTime	= NULL;
	m_fCurTick	= NULL;
	m_fFPS		= NULL;
}