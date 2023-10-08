#include "stdafx.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Sprite.h"
#include "S_Tetra.h"
#include "O_Tetra.h"
#include "BoxButton.h"


S_Tetra::S_Tetra(void)
{
	// empty...
}

S_Tetra::~S_Tetra(void)
{
	// empty...
}

void S_Tetra::Init(void)
{
	m_sprBG = new CSprite();
	m_sprBG->CreateSprite("Resource/Tetra_Background.png");
	m_sprBG->SetPosition(640, 512);

	m_objTetra = new O_Tetra();
	m_objTetra->CreateObject();

	m_btnBack = new CBoxButton();
	m_btnBack->CreateButton("Resource/btn3_noting.png", "Resource/btn3_push.png");
	m_btnBack->SetPosition(1230, 985);
}

void S_Tetra::Process(void)
{
	m_objTetra->Process();

	if (!m_btnBack->Click())
	{
		SceneMgr->ChangeScene(Index_Main);
	}
}

void S_Tetra::Render(void)
{
	m_sprBG->Render();
	m_btnBack->Render();
	m_objTetra->Render();
}

void S_Tetra::Release(void)
{
	m_btnBack->Release();
	m_sprBG->Release();
}
