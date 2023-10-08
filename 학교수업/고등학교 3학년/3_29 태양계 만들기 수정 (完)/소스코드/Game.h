#pragma once

#include "DirectX.h"
#include "Mesh.h"

class CGame
{
private:
	CDirectX*				m_D3D;
	IDirect3DDevice9*		m_Device;

	CMesh*		m_Sun;			// 태양
	CMesh*		m_Mercurial;	// 수성
	CMesh*		m_Venus;		// 금성
	CMesh*		m_Earth;		// 지구
	CMesh*		m_Moon;			// 달
	CMesh*		m_Mars;			// 화성
	CMesh*		m_Jupiter;		// 목성
	CMesh*		m_Saturn;		// 토성
	CMesh*		m_Uranus;		// 천왕성
	CMesh*		m_Neptune;		// 해왕성
public:
	CGame(void);
	~CGame(void);

	bool Init(HWND hWnd);
	void Render(void);
};