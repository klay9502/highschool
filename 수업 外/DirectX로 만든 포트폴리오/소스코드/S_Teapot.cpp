#include "stdafx.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Sprite.h"
#include "S_Teapot.h"
#include "O_LoadObject.h"
#include "BoxButton.h"


S_Teapot::S_Teapot(void)
{
	// empty...
}

S_Teapot::~S_Teapot(void)
{
	// empty...
}

void S_Teapot::Init(void)
{
	m_sprBG = new CSprite();
	m_sprBG->CreateSprite("Resource/Teapot_Background.png");
	m_sprBG->SetPosition(640, 512);

	m_objTeapot = new O_LoadObject();
	m_objTeapot->CreateObject("Teapot.ASE");

	m_btnBack = new CBoxButton();
	m_btnBack->CreateButton("Resource/btn3_noting.png", "Resource/btn3_push.png");
	m_btnBack->SetPosition(1230, 985);
}

void S_Teapot::Process(void)
{
	m_objTeapot->Process();

	if (!m_btnBack->Click())
	{
		SceneMgr->ChangeScene(Index_Main);
	}
}

void S_Teapot::Render(void)
{
	m_sprBG->Render();
	m_btnBack->Render();
	m_objTeapot->Render();
}

void S_Teapot::Release(void)
{
	m_btnBack->Release();
	m_objTeapot->Release();
	m_sprBG->Release();
}
