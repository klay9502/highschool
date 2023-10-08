#include "stdafx.h"
#include "SceneManager.h"
// Scenes
#include "S_Engine.h"
#include "S_NULL.h"


CSceneManager::CSceneManager(void)
{
	m_pScene = nullptr;
}

CSceneManager::~CSceneManager(void)
{
	// empty...
}

void CSceneManager::Init(void)
{
	this->ChangeScene(Index_Engine);
}

void CSceneManager::Release(void)
{
	if (m_pScene != nullptr)
	{
		m_pScene->Release();
		delete m_pScene;
		m_pScene = nullptr;
	}
}

void CSceneManager::ChangeScene(SceneIndex _index)
{
	// ���� ������ ���� �ִٸ� �����Ѵ�.
	this->Release();

	switch (_index)
	{
	case Index_Engine:
		m_pScene = new S_Engine();
		break;
	case Index_NULL:
		m_pScene = new S_NULL();
		break;
	}

	m_pScene->Init();
}