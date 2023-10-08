#include "stdafx.h"
#include "Animation.h"
#include "TimeManager.h"
#include "WindowManager.h"
#include "Sprite.h"


CAnimation::CAnimation(void)
{
	m_nFrameCount = 0;
}

CAnimation::~CAnimation(void)
{
	// empty...
}

void CAnimation::Process(void)
{
	m_fCurTime = TimeMgr->m_fCurTick - m_fOldTime;

	if (m_bIsFrameLoop) // ���ѹݺ�
	{
		if (m_fCurTime >= m_fFrameTime) // ������ ���� �ʰ� ��
		{
			m_fOldTime = TimeMgr->m_fCurTick;

			if (m_nFrameCount >= m_nFrameSize - 1) // ������ �������̶��
			{
				// ó������
				m_nFrameCount = 0;
			}
			else // ������ �������� �ƴ϶��
			{
				// ���� �̹���
				m_nFrameCount++;
			}
		}
	}
	else // �ѹ��� ���
	{
		if (m_fCurTime >= m_fFrameTime) // ������ ���� �ʰ� ��
		{
			m_fOldTime = TimeMgr->m_fCurTick;

			if (m_nFrameCount >= m_nFrameSize - 1) // ������ �������̶��
			{
				// ����
				return;
			}
			else // ������ �������� �ƴ϶��
			{
				// ���� �̹���
				m_nFrameCount++;
			}
		}
	}
}

void CAnimation::Render(void)
{
	RECT size;
	size.top = 0;
	size.left = 0;
	size.right = m_vFrame[m_nFrameCount]->GetSize().x;
	size.bottom = m_vFrame[m_nFrameCount]->GetSize().y;

	float degree = D3DXToRadian(m_vFrame[m_nFrameCount]->GetRotation());

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
	D3DXMatrixTranslation(&matCenterReverse, -m_vFrame[m_nFrameCount]->GetSize().x / 2, -m_vFrame[m_nFrameCount]->GetSize().y / 2, 0);
	D3DXMatrixTranslation(&matTransfer, m_vFrame[m_nFrameCount]->GetPosition().x, m_vFrame[m_nFrameCount]->GetPosition().y, 0);

	//��Ʈ���� ����
	matrix = matCenterReverse * matRotation * matCenter * matTransfer;

	WinMgr->m_pd3dSprite->SetTransform(&matrix);

	WinMgr->m_pd3dSprite->Begin(D3DXSPRITE_ALPHABLEND);

	// ���
	WinMgr->m_pd3dSprite->Draw(m_vFrame[m_nFrameCount]->m_pd3dTexture, &size, NULL, NULL, m_vFrame[m_nFrameCount]->GetColor());

	WinMgr->m_pd3dSprite->End();
}

void CAnimation::Release(void)
{
	for (int i = 0; i < m_vFrame.size(); i++)
	{
		delete m_vFrame[i];
	}

	m_vFrame.clear();
}

void CAnimation::CreateAnimation(const char* _filename, float _frameTime, int _frameSize, bool _loop)
{
	m_fOldTime = TimeMgr->m_fCurTick;
	m_fFrameTime = _frameTime;
	m_nFrameSize = _frameSize;
	m_bIsFrameLoop = _loop;

	for (int i = 1; i <= m_nFrameSize; i++)
	{
		char temp[128];

		sprintf(temp, "%s (%d).png", _filename, i);

		CSprite* spr = new CSprite();
		spr->CreateSprite(temp);
		m_vFrame.push_back(spr);
	}
}

void CAnimation::SetPosition(D3DXVECTOR2 _pos)
{
	for (int i = 0; i < m_vFrame.size(); i++)
	{
		m_vFrame[i]->SetPosition(_pos);
	}
}

void CAnimation::SetPosition(int _x, int _y)
{
	for (int i = 0; i < m_vFrame.size(); i++)
	{
		m_vFrame[i]->SetPosition(_x, _y);
	}
}

void CAnimation::SetRotation(float _rotation)
{
	for (int i = 0; i < m_vFrame.size(); i++)
	{
		m_vFrame[i]->SetRotation(_rotation);
	}
}