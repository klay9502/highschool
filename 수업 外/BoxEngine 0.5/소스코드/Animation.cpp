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

	if (m_bIsFrameLoop) // 무한반복
	{
		if (m_fCurTime >= m_fFrameTime) // 프레임 간격 초과 시
		{
			m_fOldTime = TimeMgr->m_fCurTick;

			if (m_nFrameCount >= m_nFrameSize - 1) // 마지막 프레임이라면
			{
				// 처음으로
				m_nFrameCount = 0;
			}
			else // 마지막 프레임이 아니라면
			{
				// 다음 이미지
				m_nFrameCount++;
			}
		}
	}
	else // 한번만 출력
	{
		if (m_fCurTime >= m_fFrameTime) // 프레임 간격 초과 시
		{
			m_fOldTime = TimeMgr->m_fCurTick;

			if (m_nFrameCount >= m_nFrameSize - 1) // 마지막 프레임이라면
			{
				// 종료
				return;
			}
			else // 마지막 프레임이 아니라면
			{
				// 다음 이미지
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

	// 메트릭스 선언
	D3DXMATRIX matrix;

	// 회전, 이동, 센터, 역센터
	D3DXMATRIX matRotation;
	D3DXMATRIX matTransfer;
	D3DXMATRIX matCenter;
	D3DXMATRIX matCenterReverse;

	// 단위행렬로 초기화
	D3DXMatrixIdentity(&matrix);
	D3DXMatrixIdentity(&matRotation);
	D3DXMatrixIdentity(&matTransfer);
	D3DXMatrixIdentity(&matCenter);
	D3DXMatrixIdentity(&matCenterReverse);

	// Z축을 기준으로 Rotation값 만큼 회전
	D3DXMatrixRotationZ(&matRotation, degree);

	// 역행렬 적용
	D3DXMatrixInverse(&matCenterReverse, NULL, &matCenter);

	// 센터값과 위치값 적용
	D3DXMatrixTranslation(&matCenterReverse, -m_vFrame[m_nFrameCount]->GetSize().x / 2, -m_vFrame[m_nFrameCount]->GetSize().y / 2, 0);
	D3DXMatrixTranslation(&matTransfer, m_vFrame[m_nFrameCount]->GetPosition().x, m_vFrame[m_nFrameCount]->GetPosition().y, 0);

	//메트릭스 곱함
	matrix = matCenterReverse * matRotation * matCenter * matTransfer;

	WinMgr->m_pd3dSprite->SetTransform(&matrix);

	WinMgr->m_pd3dSprite->Begin(D3DXSPRITE_ALPHABLEND);

	// 출력
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