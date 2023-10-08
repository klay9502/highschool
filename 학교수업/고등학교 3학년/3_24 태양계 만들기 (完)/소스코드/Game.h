#pragma once

#include "DirectX.h"
#include "Mesh.h"

class CGame
{
private:
	CDirectX*				m_D3D;
	IDirect3DDevice9*		m_Device;

	CMesh*		m_Sun;
	CMesh*		m_Mercurial;	// 수
	CMesh*		m_Venus;		// 금
	CMesh*		m_Earth;		// 지
	CMesh*		m_Moon;			// 달
	CMesh*		m_Mars;			// 화
	CMesh*		m_Jupiter;		// 목
	CMesh*		m_Saturn;		// 토
	CMesh*		m_Uranus;		// 천
	CMesh*		m_Neptune;		// 해

public:
	CGame(void);
	~CGame(void);

	bool Init(HWND hWnd);
	void Render(void);
};