#pragma once

#include "stdafx.h"

class CMesh
{
private:
	IDirect3DDevice9*		m_Device;

	ID3DXMesh*				m_Mesh;
	D3DMATERIAL9*			m_Material;
	IDirect3DTexture9**		m_Tex;
	D3DXCOLOR				m_Color;
	DWORD					m_dwMaterials;

	D3DXMATRIX				m_Proj;
	D3DXVECTOR3				m_Pos;
	D3DXVECTOR3				m_Center;
	D3DXVECTOR3				m_Scaling;
public:
	CMesh(IDirect3DDevice9* pDevice);
	~CMesh(void);

	bool Init(TCHAR *szFile);
	void GetTexPath(LPSTR szPath, LPWSTR szFile);
	void Render(void);
};

