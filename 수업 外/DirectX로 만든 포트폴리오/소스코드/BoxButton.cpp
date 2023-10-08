#include "stdafx.h"
#include "BoxButton.h"
#include "WindowManager.h"
#include "TextureManager.h"
#include "InputManager.h"


CBoxButton::CBoxButton(void)
{
	m_bIsClick = false;
}

CBoxButton::~CBoxButton(void)
{
	// empty...
}

void CBoxButton::Render(void)
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
		if (m_bIsClick)
		{
			WinMgr->m_pd3dSprite->Draw(m_pd3dTexPush, &size, NULL, NULL, this->GetColor());
		}
		else
		{
			WinMgr->m_pd3dSprite->Draw(m_pd3dTexNoting, &size, NULL, NULL, this->GetColor());
		}

		WinMgr->m_pd3dSprite->End();
	}
}

void CBoxButton::Release(void)
{
	if (m_pd3dTexNoting != nullptr)
	{
		m_pd3dTexNoting = nullptr;
	}

	if (m_pd3dTexPush != nullptr)
	{
		m_pd3dTexPush = nullptr;
	}
}

void CBoxButton::CreateButton(const char* _noting, const char* _push)
{
	m_pd3dTexNoting = TextureMgr->LoadTexture(_noting);
	// ���� �̹��� ������� �ʱ�ȭ
	this->SetSize(D3DXVECTOR2(TextureMgr->GetImageInfo(_noting).Width, TextureMgr->GetImageInfo(_noting).Height));

	m_pd3dTexPush = TextureMgr->LoadTexture(_push);
	// ���� �̹��� ������� �ʱ�ȭ
	this->SetSize(D3DXVECTOR2(TextureMgr->GetImageInfo(_push).Width, TextureMgr->GetImageInfo(_push).Height));
}

bool CBoxButton::Click(void)
{
	if (InputMgr->m_ptLOldMouse.x > this->GetPosition().x - this->GetSize().x / 2 &&
		InputMgr->m_ptLOldMouse.x < this->GetPosition().x + this->GetSize().x / 2 &&
		InputMgr->m_ptLOldMouse.y > this->GetPosition().y - this->GetSize().y / 2 &&
		InputMgr->m_ptLOldMouse.y < this->GetPosition().y + this->GetSize().y / 2 &&
		InputMgr->m_bIsPushLButton)
	{
		m_bIsClick = true;
		return true;
	}

	if (!(InputMgr->m_ptLOldMouse.x > this->GetPosition().x - this->GetSize().x / 2 &&
		InputMgr->m_ptLOldMouse.x < this->GetPosition().x + this->GetSize().x / 2 &&
		InputMgr->m_ptLOldMouse.y > this->GetPosition().y - this->GetSize().y / 2 &&
		InputMgr->m_ptLOldMouse.y < this->GetPosition().y + this->GetSize().y / 2) &&
		InputMgr->m_bIsPushLButton)
	{
		m_bIsClick = false;
	}

	if (InputMgr->m_ptLOldMouse.x > this->GetPosition().x - this->GetSize().x / 2 &&
		InputMgr->m_ptLOldMouse.x < this->GetPosition().x + this->GetSize().x / 2 &&
		InputMgr->m_ptLOldMouse.y > this->GetPosition().y - this->GetSize().y / 2 &&
		InputMgr->m_ptLOldMouse.y < this->GetPosition().y + this->GetSize().y / 2 &&
		!InputMgr->m_bIsPushLButton)
	{
		return false;
	}
}