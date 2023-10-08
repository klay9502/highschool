#pragma once

#include "Ingredient.h"

class CLable :
	public CIngredient
{
public: // public ����
	LPD3DXFONT m_pd3dFont;
public: // public �Լ�
	CLable(void);
	~CLable(void);

	void Render(const char* _text);
	void Release(void);

	void CreateText(const char* _fontname);
};

