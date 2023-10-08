#include "stdafx.h"
#include "SceneManager.h"
// Scenes
#include "S_Engine.h"
#include "S_Main.h"
#include "S_Tetra.h"
#include "S_Cube.h"
#include "S_Teapot.h"
#include "S_Torus.h"


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
	this->ChangeScene(Index_Main);
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
	// 만약 이전에 씬이 있다면 해제한다.
	this->Release();

	switch (_index)
	{
	case Index_Engine:
		m_pScene = new S_Engine();
		break;
	case Index_Main:
		m_pScene = new S_Main();
		break;
	case Index_Tetra:
		m_pScene = new S_Tetra();
		break;
	case Index_Cube:
		m_pScene = new S_Cube();
		break;
	case Index_Teapot:
		m_pScene = new S_Teapot();
		break;
	case Index_Torus:
		m_pScene = new S_Torus();
		break;
	}

	m_pScene->Init();
}