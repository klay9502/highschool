#pragma once

#define SceneMgr CSceneManager::GetInstance()

#include "Singleton.h"
#include "Scene.h"

enum SceneIndex
{
	Index_Engine,
	Index_NULL,
};

class CSceneManager :
	public ISingleton <CSceneManager>
{
public: // public 변수
	CScene* m_pScene;
public: // public 함수
	CSceneManager(void);
	~CSceneManager(void);

	void Init(void);
	void Release(void);

	void ChangeScene(SceneIndex _index);
};

