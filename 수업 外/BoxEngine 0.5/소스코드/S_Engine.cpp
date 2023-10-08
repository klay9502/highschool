#include "stdafx.h"
#include "S_Engine.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "Sprite.h"
#include "Lable.h"


S_Engine::S_Engine(void)
{
	// empty...
}

S_Engine::~S_Engine(void)
{
	// empty...
}

void S_Engine::Init(void)
{
	m_sprLogo = new CSprite();
	m_sprLogo->CreateSprite("Resource/BoxEngine.png");
	m_sprLogo->SetPosition(640, 360);

	m_sprText = new CLable();
	m_sprText->CreateText("µ¸À½");
	m_sprText->SetPosition(5, 5);
}

void S_Engine::Process(void)
{
	
}

void S_Engine::Render(void)
{
	m_sprLogo->ActionFadeIn(0.5);

	if (TimeMgr->m_fCurTick >= 3.0f)
	{
		m_sprLogo->ActionFadeOut(0.5);
	}

	m_sprLogo->Render();
	m_sprText->Render("0.5");

	if (TimeMgr->m_fCurTick >= 4.0f)
	{
		SceneMgr->ChangeScene(Index_NULL);
	}
}

void S_Engine::Release(void)
{
	m_sprLogo->Release();
}