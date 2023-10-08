#include "stdafx.h"
#include "InputManager.h"
#include "WindowManager.h"
#include "TimeManager.h"
#include "S_Ingame.h"
#include "O_Player.h"
#include "O_MousePointer.h"
#include "O_Bullet.h"
#include "EFaohu.h"
#include "ECumchuk.h"
#include "ECosplayer.h"


S_Ingame::S_Ingame(void)
{
	m_fCountTime = 0.5f;
	m_fOldTime = 0.0f;
}

S_Ingame::~S_Ingame(void)
{
	// empty...
}

void S_Ingame::Init(void)
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

void S_Ingame::Process(void)
{
	m_objPlayer->Process();
	m_objMousePointer->Process();

	// 총알 초기화
	if (InputMgr->m_bIsPushLButton)
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
		}
	}

	m_fCurTime = TimeMgr->m_fCurTick - m_fOldTime;

	// Enemy1 초기화
	if (m_fCurTime >= m_fCountTime)
	{
		m_fOldTime = TimeMgr->m_fCurTick;
		
		CEFaohu* enemy1;
		enemy1 = new CEFaohu();
		enemy1->changeAnimation(eLeft);
		enemy1->Set();
		enemy1->Active();
		m_vEnemy1.push_back(enemy1);
	}

	for (int i = 0; i < m_vEnemy1.size(); i++)
	{
		POINT pt;
		pt.x = m_objPlayer->GetPosition().x;
		pt.y = m_objPlayer->GetPosition().y;

		m_vEnemy1[i]->Process(pt);

		if (m_vEnemy1[i]->getPoint().x > WinMgr->m_ptWindowSize.x ||
			m_vEnemy1[i]->getPoint().y > WinMgr->m_ptWindowSize.y ||
			m_vEnemy1[i]->getPoint().x < 0 ||
			m_vEnemy1[i]->getPoint().y < 0)
		{
			m_vEnemy1[i]->Release();
			m_vEnemy1[i] = nullptr;
			delete m_vEnemy1[i];
			m_vEnemy1.erase(m_vEnemy1.begin() + i);
		}
	}

	// printf("%d\n", m_vEnemy1.size());
}

void S_Ingame::Render(void)
{
	m_sprBG->Render();
	m_objPlayer->Render();
	m_objMousePointer->Render();

	for (int i = 0; i < m_vBullet.size(); i++)
	{
		m_vBullet[i]->Render();
	}

	for (int i = 0; i < m_vEnemy1.size(); i++)
	{
		m_vEnemy1[i]->Render();
	}
}

void S_Ingame::Release(void)
{
	for (int i = 0; i < m_vEnemy1.size(); i++)
	{
		if (m_vEnemy1[i] != nullptr)
		{
			m_vEnemy1[i]->Release();
			m_vEnemy1[i] = nullptr;
			delete m_vEnemy1[i];
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