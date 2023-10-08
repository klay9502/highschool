#include "stdafx.h"
#include "Mesh.h"


CMesh::CMesh(IDirect3DDevice9* pDevice)
{
	m_Device = pDevice;
	m_Mesh = NULL;
	m_dwMaterials = NULL;
}


CMesh::~CMesh()
{
	if (m_Material != NULL)
	{
		delete[] m_Material;
	}

	if (m_Tex)
	{
		for (int i = 0; i < m_dwMaterials; i++)
		{
			if (m_Tex[i])
			{
				m_Tex[i]->Release();
				m_Tex[i] = NULL;
			}
		}

		delete[] m_Tex;
	}

	if (m_Mesh != NULL)
	{
		m_Mesh->Release();
		m_Mesh = NULL;
	}
}

bool CMesh::Init(TCHAR* szFile)
{
	TCHAR   szPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, szPath);
	_tcscat(szPath, _T("\\Data\\"));
	_tcscat(szPath, szFile);

	LPD3DXBUFFER        D3DBuf;
	if (FAILED(D3DXLoadMeshFromX(szPath, D3DXMESH_MANAGED, m_Device, NULL, &D3DBuf, NULL, &m_dwMaterials, &m_Mesh)))
	{
		MessageBox(NULL, _T("D3DXLoadMeshFromX ERROR"), szFile, MB_OK);
		return false;
	}

	D3DXMATERIAL*   D3DMatrials = (D3DXMATERIAL*)D3DBuf->GetBufferPointer();
	m_Material = new D3DMATERIAL9[m_dwMaterials];

	if (m_Material == NULL)
		return false;

	m_Tex = new LPDIRECT3DTEXTURE9[m_dwMaterials];

	if (m_Tex == NULL) return false;

	for (DWORD i = 0; i < m_dwMaterials; i++)
	{
		m_Material[i] = D3DMatrials[i].MatD3D;
		m_Material[i].Ambient = m_Material[i].Diffuse;
		m_Tex[i] = NULL;

		if (D3DMatrials[i].pTextureFilename != NULL && strlen(D3DMatrials[i].pTextureFilename) > 0)
		{
			WCHAR fileName[MAX_PATH];
			GetTexPath(D3DMatrials[i].pTextureFilename, fileName);

			GetCurrentDirectory(MAX_PATH, szPath);
			_tcscat(szPath, _T("\\Data\\"));
			_tcscat(szPath, fileName);

			if (FAILED(D3DXCreateTextureFromFile(m_Device, szPath, &m_Tex[i])))
			{
				MessageBox(NULL, _T("D3DXCreateTextureFromFile"), _T("ERROR"), MB_OK);
				return false;
			}
		}
	}

	D3DBuf->Release();


	return true;
}

void CMesh::GetTexPath(LPSTR szPath, LPWSTR szFile)
{
	WCHAR wszBuf[MAX_PATH];
	MultiByteToWideChar(CP_ACP, 0, szPath, -1, wszBuf, MAX_PATH);
	wszBuf[MAX_PATH - 1] = L'\0';

	WCHAR* wszFullPath = wszBuf;

	LPWSTR pch = wcsrchr(wszFullPath, '\\');
	if (pch)
		lstrcpy(szFile, ++pch);
	else
		lstrcpy(szFile, wszFullPath);
}

void CMesh::Render(void)
{
	for (int i = 0; i < m_dwMaterials; ++i)
	{
		m_Device->SetMaterial(&m_Material[i]);
		m_Device->SetTexture(0, m_Tex[i]);
		m_Mesh->DrawSubset(i);
	}
}