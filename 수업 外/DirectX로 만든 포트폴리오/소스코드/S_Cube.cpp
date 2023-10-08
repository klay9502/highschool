#include "stdafx.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Sprite.h"
#include "S_Cube.h"
#include "O_Cube.h"
#include "BoxButton.h"


S_Cube::S_Cube(void)
{
	// empty...
}

S_Cube::~S_Cube(void)
{
	// empty...
}

void S_Cube::Init(void)
{
	m_sprBG = new CSprite();
	m_sprBG->CreateSprite("Resource/Cube_Background.png");
	m_sprBG->SetPosition(640, 512);

	m_objCube = new O_Cube();
	m_objCube->CreateObject();

	m_btnBack = new CBoxButton();
	m_btnBack->CreateButton("Resource/btn3_noting.png", "Resource/btn3_push.png");
	m_btnBack->SetPosition(1230, 985);
}

void S_Cube::Process(void)
{
	m_objCube->Process();

	if (!m_btnBack->Click())
	{
		SceneMgr->ChangeScene(Index_Main);
	}
}

void S_Cube::Render(void)
{
	m_sprBG->Render();
	m_btnBack->Render();
	m_objCube->Render();
}

void S_Cube::Release(void)
{
	m_btnBack->Release();
	m_sprBG->Release();
}