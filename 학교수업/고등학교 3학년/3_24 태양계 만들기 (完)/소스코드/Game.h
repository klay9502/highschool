#pragma once

#include "DirectX.h"
#include "Mesh.h"

class CGame
{
private:
	CDirectX*				m_D3D;
	IDirect3DDevice9*		m_Device;

	CMesh*		m_Sun;
	CMesh*		m_Mercurial;	// ��
	CMesh*		m_Venus;		// ��
	CMesh*		m_Earth;		// ��
	CMesh*		m_Moon;			// ��
	CMesh*		m_Mars;			// ȭ
	CMesh*		m_Jupiter;		// ��
	CMesh*		m_Saturn;		// ��
	CMesh*		m_Uranus;		// õ
	CMesh*		m_Neptune;		// ��

public:
	CGame(void);
	~CGame(void);

	bool Init(HWND hWnd);
	void Render(void);
};