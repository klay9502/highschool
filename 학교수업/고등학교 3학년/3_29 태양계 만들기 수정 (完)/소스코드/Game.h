#pragma once

#include "DirectX.h"
#include "Mesh.h"

class CGame
{
private:
	CDirectX*				m_D3D;
	IDirect3DDevice9*		m_Device;

	CMesh*		m_Sun;			// �¾�
	CMesh*		m_Mercurial;	// ����
	CMesh*		m_Venus;		// �ݼ�
	CMesh*		m_Earth;		// ����
	CMesh*		m_Moon;			// ��
	CMesh*		m_Mars;			// ȭ��
	CMesh*		m_Jupiter;		// ��
	CMesh*		m_Saturn;		// �伺
	CMesh*		m_Uranus;		// õ�ռ�
	CMesh*		m_Neptune;		// �ؿռ�
public:
	CGame(void);
	~CGame(void);

	bool Init(HWND hWnd);
	void Render(void);
};