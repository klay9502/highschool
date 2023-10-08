#include "stdafx.h"
#include "S_Stage1.h"
#include "InputManager.h"
#include "WindowManager.h"
#include "TimeManager.h"
#include "O_Player.h"
#include "O_MousePointer.h"
#include "O_Bullet.h"
#include "Object_Enemy.h"
#include "EFaohu.h"
#include "ECumchuk.h"
#include "ECosplayer.h"


S_Stage1::S_Stage1(void)
{
	m_fCountTime = 0.5f;
	m_fOldTime = 0.0f;
	bltCount = 0;
}

S_Stage1::~S_Stage1(void)
{
	// empty...
}

void S_Stage1::Init(void)
{
	m_sprBG = new CSprite();
	m_sprBG->CreateSprite("Resource/Prototype/pBG.jpg");
	m_sprBG->SetPosition(640, 360);

	m_objPlayer = new O_Player();
	m_objPlayer->Init();
	m_objPlayer->SetPosition(640, 360);

	m_objMousePointer = new O_MousePointer();
	m_objMousePointer->Init();
	m_objMousePointer->SetPosition(0, 0);
}

void S_Stage1::Process(void)
{
	m_objPlayer->Process();
	m_objMousePointer->Process();

	// 총알 초기화
	if (InputMgr->m_bIsPushLButton)
	{
		if (bltCount < 2)		//총알 최대 발사 갯수는 2(한 발당 침생 50퍼)
		{
			O_Bullet* temp;
			temp = new O_Bullet();
			temp->Init();
			temp->SetPosition(m_objPlayer->GetPosition().x, m_objPlayer->GetPosition().y);
			temp->a.x = temp->GetPosition().x;
			temp->a.y = temp->GetPosition().y;
			temp->b.x = InputMgr->m_ptLOldMouse.x;
			temp->b.y = InputMgr->m_ptLOldMouse.y;
			m_vBullet.push_back(temp);

			bltCount++;
		}
	}

	// 총알 발사
	for (int i = 0; i < m_vBullet.size(); i++)
	{
		m_vBullet[i]->Process();

		if (m_vBullet[i]->GetPosition().x > WinMgr->m_ptWindowSize.x ||
			m_vBullet[i]->GetPosition().y > WinMgr->m_ptWindowSize.y ||
			m_vBullet[i]->GetPosition().x < 0 ||
			m_vBullet[i]->GetPosition().y < 0)
		{
			m_vBullet[i]->Release();
			m_vBullet[i] = nullptr;
			delete m_vBullet[i];
			m_vBullet.erase(m_vBullet.begin() + i);
			bltCount--;
		}
	}

	m_fCurTime = TimeMgr->m_fCurTick - m_fOldTime;

	// Enemy1 초기화
	if (m_fCurTime >= m_fCountTime)
	{
		int num = rand() % 3;

		m_fOldTime = TimeMgr->m_fCurTick;

		CObject_Enemy* enemy;

		switch (num)
		{
		case 0:
			enemy = new CECosplayer();
			break;
		case 1:
			enemy = new CEFaohu();
			break;
		case 2:
			enemy = new CECumchuk();
			break;
		}

		enemy->changeAnimation(eLeft);
		enemy->Set();
		enemy->Active();
		m_vEnemy.push_back(enemy);
	}

	for (int i = 0; i < m_vEnemy.size(); i++)
	{
		POINT pt;
		pt.x = m_objPlayer->GetPosition().x;
		pt.y = m_objPlayer->GetPosition().y;

		m_vEnemy[i]->Process(pt);
		
		for (int j = 0; j < m_vBullet.size(); j++)
		{
			if (!m_vEnemy[i]->getIsHited())
				m_vEnemy[i]->BltBound(m_vBullet[j]->getPoint());
		}


		if (m_vEnemy[i]->getPoint().x > WinMgr->m_ptWindowSize.x ||
			m_vEnemy[i]->getPoint().y > WinMgr->m_ptWindowSize.y ||
			m_vEnemy[i]->getPoint().x < 0 ||
			m_vEnemy[i]->getPoint().y < 0)
		{
			m_vEnemy[i]->Release();
			m_vEnemy[i] = nullptr;
			delete m_vEnemy[i];
			m_vEnemy.erase(m_vEnemy.begin() + i);
		}
	}
}

void S_Stage1::Render(void)
{
	m_sprBG->Render();
	m_objPlayer->Render();
	m_objMousePointer->Render();

	for (int i = 0; i < m_vBullet.size(); i++)
	{
		m_vBullet[i]->Render();
	}

	for (int i = 0; i < m_vEnemy.size(); i++)
	{
		m_vEnemy[i]->Render();
	}
}

void S_Stage1::Release(void)
{
	for (int i = 0; i < m_vEnemy.size(); i++)
	{
		if (m_vEnemy[i] != nullptr)
		{
			m_vEnemy[i]->Release();
			m_vEnemy[i] = nullptr;
			delete m_vEnemy[i];
		}
	}

	for (int i = 0; i < m_vBullet.size(); i++)
	{
		if (m_vBullet[i] != nullptr)
		{
			m_vBullet[i]->Release();
			m_vBullet[i] = nullptr;
			delete m_vBullet[i];
		}
	}

	if (m_objMousePointer != nullptr)
	{
		m_objMousePointer->Release();
		m_objMousePointer = nullptr;
		delete m_objMousePointer;
	}

	if (m_objPlayer != nullptr)
	{
		m_objPlayer->Release();
		m_objPlayer = nullptr;
		delete m_objPlayer;
	}

	if (m_sprBG != nullptr)
	{
		m_sprBG->Release();
		m_sprBG = nullptr;
		delete m_sprBG;
	}
}