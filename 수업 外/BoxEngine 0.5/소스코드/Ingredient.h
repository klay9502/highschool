#pragma once

class CIngredient
{
public: // public ����
	D3DXVECTOR2 m_vecSize;			// ũ��
	D3DXVECTOR2 m_vecPosition;		// ��ġ
	float		m_fRotation;		// ����
	bool		m_bIsVisible;		// Visible
	D3DCOLOR	m_d3dColor;			// ����
public: // public �Լ�
	CIngredient(void);
	~CIngredient(void);

	void Release(void);

	D3DXVECTOR2 GetSize(void);
	void SetSize(D3DXVECTOR2 _size);
	void SetSize(int _width, int _height);

	D3DXVECTOR2 GetPosition(void);
	void SetPosition(D3DXVECTOR2 _pos);
	void SetPosition(int _x, int _y);

	float GetRotation(void);
	void SetRotation(float _rotation);

	D3DCOLOR GetColor(void);
	void SetColor(int _alpha = 255, int _r = 255, int _g = 255, int _b = 255);

	// Render�Լ��� ����� ��.
	void ActionFadeIn(float _time, float _startAlpha = 0.0f, float _endAlpha = 255.0f);
	// Render�Լ��� ����� ��.
	void ActionFadeOut(float _time, float _startAlpha = 255.0f, float _endAlpha = 0.0f);
};

