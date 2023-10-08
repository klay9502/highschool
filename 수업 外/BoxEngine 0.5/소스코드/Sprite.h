#pragma once

#include "Ingredient.h"

class CSprite :
	public CIngredient
{
public: // public ����
	LPDIRECT3DTEXTURE9 m_pd3dTexture;
public: // public �Լ�
	CSprite(void);
	~CSprite(void);

	void Render(void);
	void Release(void);

	void CreateSprite(const char* _filename);
};

