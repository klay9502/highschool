#pragma once

#include "Ingredient.h"

class CLable :
	public CIngredient
{
public: // public 변수
	LPD3DXFONT m_pd3dFont;
public: // public 함수
	CLable(void);
	~CLable(void);

	void Render(const char* _text);
	void Release(void);

	void CreateText(const char* _fontname);
};

