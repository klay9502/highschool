#include "stdafx.h"
#include "Sprite.h"
#include "WindowManager.h"
#include "TextureManager.h"
#include "TimeManager.h"


CSprite::CSprite(void)
{
	m_pd3dTexture = nullptr;
}

CSprite::~CSprite(void)
{
	// empty...
}

void CSprite::Render(void)
{
	if (m_bIsVisible)
	{
		RECT size;
		size.top = 0;
		size.left = 0;
		size.right = GetSize().x;
		size.bottom = GetSize().y;

		float degree = D3DXToRadian(this->GetRotation());

		// ��Ʈ���� ����
		D3DXMATRIX matrix;

		// ȸ��, �̵�, ����, ������
		D3DXMATRIX matRotation;
		D3DXMATRIX matTransfer;
		D3DXMATRIX matCenter;
		D3DXMATRIX matCenterReverse;

		// ������ķ� �ʱ�ȭ
		D3DXMatrixIdentity(&matrix);
		D3DXMatrixIdentity(&matRotation);
		D3DXMatrixIdentity(&matTransfer);
		D3DXMatrixIdentity(&matCenter);
		D3DXMatrixIdentity(&matCenterReverse);

		// Z���� �������� Rotation�� ��ŭ ȸ��
		D3DXMatrixRotationZ(&matRotation, degree);

		// ����� ����
		D3DXMatrixInverse(&matCenterReverse, NULL, &matCenter);

		// ���Ͱ��� ��ġ�� ����
		D3DXMatrixTranslation(&matCenterReverse, -GetSize().x / 2, -GetSize().y / 2, 0);
		D3DXMatrixTranslation(&matTransfer, GetPosition().x, GetPosition().y, 0);
		
		//��Ʈ���� ����
		matrix = matCenterReverse * matRotation * matCenter * matTransfer;
		
		WinMgr->m_pd3dSprite->SetTransform(&matrix);

		WinMgr->m_pd3dSprite->Begin(D3DXSPRITE_ALPHABLEND);

		// ���
		WinMgr->m_pd3dSprite->Draw(m_pd3dTexture, &size, NULL, NULL, this->GetColor());

		WinMgr->m_pd3dSprite->End();
	}
}

void CSprite::Release(void)
{
	if (m_pd3dTexture != nullptr)
	{
		m_pd3dTexture = nullptr;
	}
}

void CSprite::CreateSprite(const char* _filename)
{
	m_pd3dTexture = TextureMgr->LoadTexture(_filename);
	// ���� �̹��� ������� �ʱ�ȭ
	this->SetSize(D3DXVECTOR2(TextureMgr->GetImageInfo(_filename).Width, TextureMgr->GetImageInfo(_filename).Height));
}