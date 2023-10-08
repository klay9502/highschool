#include "stdafx.h"
#include "Game.h"


CGame::CGame(void)
{
	m_D3D = NULL;

	m_Sun = NULL;
	m_Mercurial = NULL;
	m_Venus = NULL;
	m_Earth = NULL;
	m_Moon = NULL;
	m_Mars = NULL;
	m_Jupiter = NULL;
	m_Saturn = NULL;
	m_Uranus = NULL;
	m_Neptune = NULL;
}

CGame::~CGame(void)
{
	delete m_Neptune;
	delete m_Uranus;
	delete m_Saturn;
	delete m_Jupiter;
	delete m_Mars;
	delete m_Moon;
	delete m_Earth;
	delete m_Venus;
	delete m_Mercurial;
	delete m_Sun;
	delete m_D3D;
}

bool CGame::Init(HWND hWnd)
{
	m_D3D = new CDirectX();
	m_D3D->Init(hWnd);
	m_Device = m_D3D->GetDevice();

	m_Sun = new CMesh(m_Device);
	m_Sun->Init(_T("Sun.X"));

	m_Mercurial = new CMesh(m_Device);
	m_Mercurial->Init(_T("mercury.X"));

	m_Venus = new CMesh(m_Device);
	m_Venus->Init(_T("venus.X"));

	m_Earth = new CMesh(m_Device);
	m_Earth->Init(_T("Earth.X"));

	m_Moon = new CMesh(m_Device);
	m_Moon->Init(_T("Moon.X"));

	m_Mars = new CMesh(m_Device);
	m_Mars->Init(_T("mars.X"));

	m_Jupiter = new CMesh(m_Device);
	m_Jupiter->Init(_T("Jupiter.X"));

	m_Saturn = new CMesh(m_Device);
	m_Saturn->Init(_T("Saturn.X"));

	m_Uranus = new CMesh(m_Device);
	m_Uranus->Init(_T("Uranus.X"));

	m_Neptune = new CMesh(m_Device);
	m_Neptune->Init(_T("Neptune.X"));

	return true;
}

void CGame::Render(void)
{
	m_Device->Clear(NULL, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, NULL);
	m_Device->BeginScene();

	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld);

	D3DXVECTOR3 vEyePt(0.0f, 180.f, -800.0f);
	D3DXVECTOR3 vLookatPt(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vUpVec(0.0f, 1.0f, 0.0f);
	D3DXMATRIX  matView;
	D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);
	m_Device->SetTransform(D3DTS_VIEW, &matView);

	D3DXMATRIX matProj;
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 1.5f, 0.72f, 2000.0f);
	m_Device->SetTransform(D3DTS_PROJECTION, &matProj);

	UINT iTime = timeGetTime() % 25000;
	FLOAT fTime = iTime * (2.0f * D3DX_PI) / 25000.0f;

	//=========================================================
	// 태양

	D3DXMATRIX matSunScale;
	D3DXMatrixScaling(&matSunScale, 1.0f, 1.0f, 1.0f);

	D3DXMATRIX matSunRotation;
	D3DXMatrixRotationY(&matSunRotation, fTime);

	D3DXMATRIX matSunTranslation;
	D3DXMatrixTranslation(&matSunTranslation, 0, 0, 0);

	D3DXMATRIX matSun;
	matSun = matSunScale * matSunRotation * matSunTranslation;
	m_Device->SetTransform(D3DTS_WORLD, &matSun);

	m_Sun->Render();

	//=========================================================
	// 수성
 
	D3DXMATRIX matMercurialScale;
	D3DXMatrixScaling(&matMercurialScale, 1.0f, 1.0f, 1.0f);

	D3DXMATRIX matMercurialRotation;
	D3DXMatrixRotationY(&matMercurialRotation, 1.5f * fTime);

	D3DXMATRIX matMercurialTranslation;
	D3DXMatrixTranslation(&matMercurialTranslation, 0, 0, 60);

	D3DXMATRIX matMercurialRotSun;
	D3DXMatrixRotationY(&matMercurialRotSun, timeGetTime() % 5000 * (2.0f * D3DX_PI) / 5000.0f);
 
	D3DXMATRIX matMercurial;
	matMercurial = matMercurialScale * matMercurialRotation * matMercurialTranslation * matMercurialRotSun;
	m_Device->SetTransform(D3DTS_WORLD, &matMercurial);

	m_Mercurial->Render();

	//=========================================================
	// 금성

	D3DXMATRIX matVenusScale;
	D3DXMatrixScaling(&matVenusScale, 1.0f, 1.0f, 1.0f);
 
	D3DXMATRIX matVenusRotation;
	D3DXMatrixRotationY(&matVenusRotation, 1.5f * fTime);

	D3DXMATRIX matVenusTranslation;
	D3DXMatrixTranslation(&matVenusTranslation, 0, 0, 120);
 
	D3DXMATRIX matVenusRotSun;
	D3DXMatrixRotationY(&matVenusRotSun, timeGetTime() % 5800 * (2.0f * D3DX_PI) / 5800.0f);

	D3DXMATRIX matVenus;
	matVenus = matVenusScale * matVenusRotation * matVenusTranslation * matVenusRotSun;
	m_Device->SetTransform(D3DTS_WORLD, &matVenus);

	m_Venus->Render();

	//=========================================================
	// 지구

	D3DXMATRIX matEarthScale;
	D3DXMatrixScaling(&matEarthScale, 1.0f, 1.0f, 1.0f);

	D3DXMATRIX matEarthRotation;
	D3DXMatrixRotationY(&matEarthRotation, 1.5f * fTime);

	D3DXMATRIX matEarthTranslation;
	D3DXMatrixTranslation(&matEarthTranslation, 0, 0, 160);

	D3DXMATRIX matEarthRotSun;
	D3DXMatrixRotationY(&matEarthRotSun, fTime);

	D3DXMATRIX matEarth;
	matEarth = matEarthScale * matEarthRotation * matEarthTranslation * matEarthRotSun;
	m_Device->SetTransform(D3DTS_WORLD, &matEarth);

	m_Earth->Render();

	//=========================================================
	// 달

	D3DXMATRIX matMoonScale;
	D3DXMatrixScaling(&matMoonScale, 1.0f, 1.0f, 1.0f);

	D3DXMATRIX matMoonRotation;
	D3DXMatrixRotationY(&matMoonRotation, 10.0f * fTime);

	D3DXMATRIX matMoonTranslation;
	D3DXMatrixTranslation(&matMoonTranslation, 0, 0, 20);

	D3DXMATRIX matMoonRotEarth;
	D3DXMatrixRotationY(&matMoonRotEarth, timeGetTime() % 28000 * (2.0f * D3DX_PI) / 1000.0f);

	D3DXMATRIX matMoon;
	matMoon = matMoonScale * matMoonRotation * matMoonTranslation * matMoonRotEarth * matEarth;
	m_Device->SetTransform(D3DTS_WORLD, &matMoon);

	m_Moon->Render();

	//=========================================================
	// 화성

	D3DXMATRIX matMarsScale;
	D3DXMatrixScaling(&matMarsScale, 1.0f, 1.0f, 1.0f);

	D3DXMATRIX matMarsRotation;
	D3DXMatrixRotationY(&matMarsRotation, 1.5f * fTime);

	D3DXMATRIX matMarsTranslation;
	D3DXMatrixTranslation(&matMarsTranslation, 0, 0, 200);
 
	D3DXMATRIX matMarsRotSun;
	D3DXMatrixRotationY(&matMarsRotSun, timeGetTime() % 28000 * (2.0f * D3DX_PI) / 28000.0f);
 
	D3DXMATRIX matMars;
	matMars = matMarsScale * matMarsRotation * matMarsTranslation * matMarsRotSun;
	m_Device->SetTransform(D3DTS_WORLD, &matMars);

	m_Mars->Render();

	//=========================================================
	// 목성

	D3DXMATRIX matJupiterScale;
	D3DXMatrixScaling(&matJupiterScale, 1.0f, 1.0f, 1.0f);

	D3DXMATRIX matJupiterRotation;
	D3DXMatrixRotationY(&matJupiterRotation, 0.5f * fTime);

	D3DXMATRIX matJupiterTranslation;
	D3DXMatrixTranslation(&matJupiterTranslation, 0, 0, 300);

	D3DXMATRIX matJupiterSun;
	D3DXMatrixRotationY(&matJupiterSun, timeGetTime() % 38000 * (2.0f * D3DX_PI) / 38000.0f);

	D3DXMATRIX matJupiter;
	matJupiter = matJupiterScale * matJupiterRotation * matJupiterTranslation * matJupiterSun;
	m_Device->SetTransform(D3DTS_WORLD, &matJupiter);

	m_Jupiter->Render();

	//=========================================================
	// 토성

	D3DXMATRIX matSaturnScale;
	D3DXMatrixScaling(&matSaturnScale, 1.0f, 1.0f, 1.0f);
 
	D3DXMATRIX matSaturnRotation;
	D3DXMatrixRotationY(&matSaturnRotation, 0.5f * fTime);

	D3DXMATRIX matSaturnTranslation;
	D3DXMatrixTranslation(&matSaturnTranslation, 0, 0, 350);
 
	D3DXMATRIX matSaturnSun;
	D3DXMatrixRotationY(&matSaturnSun, timeGetTime() % 48000 * (2.0f * D3DX_PI) / 48000.0f);

 
	D3DXMATRIX matSatrun;
	matSatrun = matSaturnScale * matSaturnRotation * matSaturnTranslation * matSaturnSun;
	m_Device->SetTransform(D3DTS_WORLD, &matSatrun);

	m_Saturn->Render();

	//=========================================================
	// 천왕성

	D3DXMATRIX matUranusScale;
	D3DXMatrixScaling(&matUranusScale, 1.0f, 1.0f, 1.0f);

	D3DXMATRIX matUranusRotation;
	D3DXMatrixRotationY(&matUranusRotation, fTime);

	D3DXMATRIX matUranusTranslation;
	D3DXMatrixTranslation(&matUranusTranslation, 0, 1, 400);
  
	D3DXMATRIX matUranusSun;
	D3DXMatrixRotationY(&matUranusSun, timeGetTime() % 58000 * (2.0f * D3DX_PI) / 58000.0f);
 
	D3DXMATRIX matUranus;
	matUranus = matUranusScale * matUranusRotation * matUranusTranslation * matUranusSun;
	m_Device->SetTransform(D3DTS_WORLD, &matUranus);

	m_Uranus->Render();

	//=========================================================
	// 해왕성
	D3DXMATRIX matNeptuneScale;
	D3DXMatrixScaling(&matNeptuneScale, 1.0f, 1.0f, 1.0f);

	D3DXMATRIX matNeptuneRotation;
	D3DXMatrixRotationY(&matNeptuneRotation, fTime);

	D3DXMATRIX matNeptuneTranslation;
	D3DXMatrixTranslation(&matNeptuneTranslation, 0, 0, 450);
 
	D3DXMATRIX matNeptuneSun;
	D3DXMatrixRotationY(&matNeptuneSun, timeGetTime() % 68000 * (2.0f * D3DX_PI) / 68000.0f);

	D3DXMATRIX matNeptune;
	matNeptune = matNeptuneScale * matNeptuneRotation * matNeptuneTranslation * matNeptuneSun;
	m_Device->SetTransform(D3DTS_WORLD, &matNeptune);
 
	m_Neptune->Render();

	//=========================================================

	m_Device->EndScene();
	m_Device->Present(NULL, NULL, NULL, NULL);
}
