#pragma once

#include "stdafx.h"

class CDirectX
{
private:
	IDirect3D9*				m_D3D;
	IDirect3DDevice9*		m_Device;
	D3DDISPLAYMODE			m_d3ddm;
	D3DPRESENT_PARAMETERS	m_d3dpp;
	RECT					m_rcClient;
public:
	CDirectX(void);
	~CDirectX(void);

	bool Init(HWND hWnd, bool bWindowed = TRUE);
	inline IDirect3DDevice9* GetDevice(void) { return m_Device; }
};

