#include "stdafx.h"
#include "Lable.h"
#include "WindowManager.h"


CLable::CLable(void)
{
	m_pd3dFont = nullptr;
}

CLable::~CLable(void)
{
	// empty...
}

void CLable::Render(const char* _text)
{
	RECT size;
	size.top = 1;
	size.left = 1;
	size.right = 0;
	size.bottom = 0;

	D3DXVECTOR3 pos;

	WinMgr->m_pd3dSprite->Begin(D3DXSPRITE_ALPHABLEND);

	SetRect(&size, this->GetPosition().x, this->GetPosition().y, 0, 0);
	m_pd3dFont->DrawTextA(NULL, _text, -1, &size, DT_NOCLIP, this->GetColor());

	WinMgr->m_pd3dSprite->End();
}

void CLable::Release(void)
{
	if (m_pd3dFont != nullptr)
	{
		m_pd3dFont->Release();
		m_pd3dFont = nullptr;
	}
}

void CLable::CreateText(const char* _fontname)
{
	D3DXCreateFont(WinMgr->m_pd3dDevice,
		30,
		0,
		NULL,
		1,
		false,
		DEFAULT_CHARSET,
		NULL,
		NULL,
		NULL,
		_fontname,
		&m_pd3dFont);
}