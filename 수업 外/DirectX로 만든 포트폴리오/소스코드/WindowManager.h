#pragma once

#define WinMgr CWindowManager::GetInstance()

#include "Singleton.h"

class CWindowManager :
	public ISingleton <CWindowManager>
{
public: // public ����
	// ��������
	HINSTANCE	m_hInst;
	HWND		m_hWnd;
	POINT		m_ptWindowSize;
	BOOL		m_bIsWindowMode;

	// ���̷�Ʈ X
	LPDIRECT3D9			m_pD3D;
	LPDIRECT3DDEVICE9	m_pd3dDevice;
	LPD3DXSPRITE		m_pd3dSprite;
public: // public �Լ�
	CWindowManager(void);
	~CWindowManager(void);

	void Init(void);
	void InitWindow(void);
	void InitDirectX(void);
	void Release(void);
};

