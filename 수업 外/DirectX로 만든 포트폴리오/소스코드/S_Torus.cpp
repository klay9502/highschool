#include "stdafx.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Sprite.h"
#include "S_Torus.h"
#include "O_LoadObject.h"
#include "BoxButton.h"


S_Torus::S_Torus(void)
{
	// empty...
}

S_Torus::~S_Torus(void)
{
	// empty...
}

void S_Torus::Init(void)
{
	m_sprBG = new CSprite();
	m_sprBG->CreateSprite("Resource/Torus_Background.png");
	m_sprBG->SetPosition(640, 512);

	m_objTorus = new O_LoadObject();
	m_objTorus->CreateObject("Torus.dat");

	m_btnBack = new CBoxButton();
	m_btnBack->CreateButton("Resource/btn3_noting.png", "Resource/btn3_push.png");
	m_btnBack->SetPosition(1230, 985);
}

void S_Torus::Process(void)
{
	m_objTorus->Process();

	if (!m_btnBack->Click())
	{
		SceneMgr->ChangeScene(Index_Main);
	}
}

void S_Torus::Render(void)
{
	m_sprBG->Render();
	m_btnBack->Render();
	m_objTorus->Render();
}

void S_Torus::Release(void)
{
	m_btnBack->Release();
	m_objTorus->Release();
	m_sprBG->Release();
}
