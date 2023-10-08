#pragma once

#define TextureMgr CTextureManager::GetInstance()

#include "Singleton.h"

struct TextureInfo
{
	// ���, �ؽ���, ����
	string Filename;
	LPDIRECT3DTEXTURE9 Texture;
	D3DXIMAGE_INFO ImageInfo;
};

class CTextureManager :
	public ISingleton <CTextureManager>
{
public: // public ����
	vector<TextureInfo> m_vTextureInfo;
public: // public �Լ�
	CTextureManager(void);
	~CTextureManager(void);

	void Release(void);

	LPDIRECT3DTEXTURE9 LoadTexture(const char* _filename);

	D3DXIMAGE_INFO GetImageInfo(const char* _filename);
};

