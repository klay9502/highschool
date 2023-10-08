#include "stdafx.h"
#include "Ingredient.h"
#include "TimeManager.h"


CIngredient::CIngredient(void)
{
	m_vecSize = D3DXVECTOR2(1.0f, 1.0f);
	m_vecPosition = D3DXVECTOR2(0, 0);
	m_fRotation = 0.0f;
	m_bIsVisible = true;
	m_d3dColor = D3DCOLOR_ARGB(255, 255, 255, 255);
}

CIngredient::~CIngredient(void)
{
	// empty...
}

D3DXVECTOR2 CIngredient::GetSize(void)
{
	return m_vecSize;
}

void CIngredient::SetSize(D3DXVECTOR2 _size)
{
	m_vecSize = _size;
}

void CIngredient::SetSize(int _width, int _height)
{
	m_vecSize.x = _width;
	m_vecSize.y = _height;
}

D3DXVECTOR2 CIngredient::GetPosition(void)
{
	return m_vecPosition;
}

void CIngredient::SetPosition(D3DXVECTOR2 _pos)
{
	m_vecPosition = _pos;
}

void CIngredient::SetPosition(int _x, int _y)
{
	m_vecPosition.x = _x;
	m_vecPosition.y = _y;
}

float CIngredient::GetRotation(void)
{
	return m_fRotation;
}

void CIngredient::SetRotation(float _rotation)
{
	m_fRotation = _rotation;
}

D3DCOLOR CIngredient::GetColor(void)
{
	return m_d3dColor;
}

void CIngredient::SetColor(int _alpha, int _r, int _g, int _b)
{
	m_d3dColor = D3DCOLOR_ARGB(_alpha, _r, _g, _b);
}

void CIngredient::ActionFadeIn(float _time, float _startAlpha, float _endAlpha)
{
	static float sfOldTime = TimeMgr->m_fCurTick;
	float fTime = TimeMgr->m_fCurTick - sfOldTime;
	float fFPS = (_endAlpha - _startAlpha) / (_time * TimeMgr->m_fFPS);
	static float sfAlpha = _startAlpha;

	sfAlpha += fFPS;

	if (sfAlpha >= _endAlpha)
	{
		sfAlpha = _endAlpha;
	}

	this->SetColor(sfAlpha, 255, 255, 255);
}

void CIngredient::ActionFadeOut(float _time, float _startAlpha, float _endAlpha)
{
	static float sfOldTime = TimeMgr->m_fCurTick;
	float fTime = TimeMgr->m_fCurTick - sfOldTime;
	float fFPS = (_startAlpha - _endAlpha) / (_time * TimeMgr->m_fFPS);
	static float sfAlpha = _startAlpha;

	sfAlpha -= fFPS;

	if (sfAlpha <= _endAlpha)
	{
		sfAlpha = _endAlpha;
	}

	this->SetColor(sfAlpha, 255, 255, 255);
}