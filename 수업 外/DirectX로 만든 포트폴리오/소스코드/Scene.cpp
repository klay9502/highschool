#include "stdafx.h"
#include "Scene.h"
#include "WindowManager.h"


CScene::CScene(void)
{
	// empty...
}

CScene::~CScene(void)
{
	// empty...
}

void CScene::PreRender(void)
{
	WinMgr->m_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
	// Scene을 시작합니다.
	WinMgr->m_pd3dDevice->BeginScene();
}

void CScene::PostRender(void)
{
	// Scene을 종료합니다.
	WinMgr->m_pd3dDevice->EndScene();
	WinMgr->m_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}