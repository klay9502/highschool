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
	size.top = this->GetPosition().x;
	size.left = this->GetPosition().y;
	size.right = 0;
	size.bottom = 0;

	WinMgr->m_pd3dSprite->Begin(D3DXSPRITE_ALPHABLEND);

	m_pd3dFont->DrawTextA(WinMgr->m_pd3dSprite, _text, -1, &size, DT_NOCLIP, this->GetColor());

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