#include "stdafx.h"
#include "System.h"
// Managers
#include "WindowManager.h"
#include "SceneManager.h"
#include "TextureManager.h"
#include "InputManager.h"
#include "TimeManager.h"

#define SERVER_ON_OFF false


CSystem::CSystem(void)
{
	// empty...
}

CSystem::~CSystem(void)
{
	// empty...
}

void CSystem::Init(void)
{
	WinMgr->Init();
	SceneMgr->Init();
	TimeMgr->Init();
	if (SERVER_ON_OFF)
	{
		g_pNetwork->Initialize();
		g_pBufferManager->SetBuffer(1024);
	}
}

void CSystem::MessageLoop(void)
{
	MSG msg;

	ZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Process();
			Render();
		}
	}
}

void CSystem::Process(void)
{
	SceneMgr->m_pScene->Process();
	InputMgr->Process();
	TimeMgr->Process();
	if (SERVER_ON_OFF)
	{
		g_pNetwork->Loop();
	}
}

void CSystem::Render(void)
{
	SceneMgr->m_pScene->PreRender();
	SceneMgr->m_pScene->Render();
	SceneMgr->m_pScene->PostRender();
}

void CSystem::Release(void)
{
	TimeMgr->Release();
	TextureMgr->Release();
	SceneMgr->Release();
	WinMgr->Release();
}