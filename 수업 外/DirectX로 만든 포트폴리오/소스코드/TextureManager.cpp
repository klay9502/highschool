#include "stdafx.h"
#include "TextureManager.h"
#include "WindowManager.h"


CTextureManager::CTextureManager(void)
{
	// empty...
}

CTextureManager::~CTextureManager(void)
{
	// empty...
}

void CTextureManager::Release(void)
{
	for (int i = 0; i < m_vTextureInfo.size(); i++)
	{
		m_vTextureInfo[i].Texture->Release();
	}

	m_vTextureInfo.clear();
}

LPDIRECT3DTEXTURE9 CTextureManager::LoadTexture(const char* _filename)
{
	// �������� ����
	string error;
	error.append("Imagefile '");
	error.append(_filename);
	error.append("' Load Failed!\nError::m_pd3dTexture == NULL");

	// �ؽ��� �ߺ� �� �ٷ� ����
	for (int i = 0; i < m_vTextureInfo.size(); i++)
	{
		if (m_vTextureInfo[i].Filename == _filename)
		{
			return m_vTextureInfo[i].Texture;
		}
	}

	// �ߺ��� �ƴ� �� ���� ����
	TextureInfo info;

	info.Filename = _filename;

	if (FAILED(D3DXCreateTextureFromFileEx(WinMgr->m_pd3dDevice,
											info.Filename.c_str(),
											D3DX_DEFAULT_NONPOW2,
											D3DX_DEFAULT_NONPOW2,
											1,
											0,
											D3DFMT_UNKNOWN,
											D3DPOOL_MANAGED,
											D3DX_FILTER_NONE,
											D3DX_FILTER_NONE,
											NULL,
											&info.ImageInfo,
											NULL,
											&info.Texture)))
	{
#if _DEBUG
		MessageBox(NULL, error.c_str(), "ERROR", MB_ICONERROR);
		return NULL;
#endif
	}

	// ���Ϳ� �߰�
	m_vTextureInfo.push_back(info);
	
	for (int i = 0; i < m_vTextureInfo.size(); i++)
	{
		if (m_vTextureInfo[i].Filename == _filename)
		{
			return m_vTextureInfo[i].Texture;
		}
	}
}

D3DXIMAGE_INFO CTextureManager::GetImageInfo(const char* _filename)
{
	for (int i = 0; i < m_vTextureInfo.size(); i++)
	{
		if (m_vTextureInfo[i].Filename == _filename)
		{
			return m_vTextureInfo[i].ImageInfo;
		}
	}
}