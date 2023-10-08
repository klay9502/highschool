#pragma once

#include "Ingredient.h"

class CSprite :
	public CIngredient
{
public: // public 변수
	LPDIRECT3DTEXTURE9 m_pd3dTexture;
public: // public 함수
	CSprite(void);
	~CSprite(void);

	void Render(void);
	void Release(void);

	void CreateSprite(const char* _filename);
};

