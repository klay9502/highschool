#pragma once

#include "Ingredient.h"

class CBoxButton :
	public CIngredient
{
public: // public 변수
	bool m_bIsClick;
	LPDIRECT3DTEXTURE9 m_pd3dTexNoting;
	LPDIRECT3DTEXTURE9 m_pd3dTexPush;
public: // public 함수
	CBoxButton(void);
	~CBoxButton(void);

	void Render(void);
	void Release(void);

	void CreateButton(const char* _noting, const char* _push);
	bool Click(void);
};

