#include "stdafx.h"
#include "S_Main.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Sprite.h"
#include "BoxButton.h"
#include "Lable.h"


S_Main::S_Main(void)
{
	m_bIsOption = false;
	m_bIsTetra = false;
	m_nSceneChange = 0;
}

S_Main::~S_Main(void)
{
	// empty...
}

void S_Main::Init(void)
{
	m_sprBG = new CSprite();
	m_sprBG->CreateSprite("Resource/Main_Background.png");
	m_sprBG->SetPosition(640, 512);

	m_btnOption = new CBoxButton();
	m_btnOption->CreateButton("Resource/btn0_noting.png", "Resource/btn0_push.png");
	m_btnOption->SetPosition(90, 900);
	//m_btnOption->SetPosition(100, 924);

	m_btnTetra = new CBoxButton();
	m_btnTetra->CreateButton("Resource/btn1_noting.png", "Resource/btn1_push.png");
	m_btnTetra->SetPosition(230, 925);

	m_menu_Exit = new CBoxButton();
	m_menu_Exit->CreateButton("Resource/menu0_Exit_noting.png", "Resource/menu0_Exit_noting.png");
	m_menu_Exit->SetPosition(165, 780);
	m_menu_Exit->SetColor(0);

	m_menu_Tetra = new CBoxButton();
	m_menu_Tetra->CreateButton("Resource/menu1_Tetra_noting.png", "Resource/menu1_Tetra_noting.png");
	m_menu_Tetra->SetPosition(165, 780);
	m_menu_Tetra->SetColor(0);

	m_menu_Cube = new CBoxButton();
	m_menu_Cube->CreateButton("Resource/menu1_Cube_noting.png", "Resource/menu1_Cube_noting.png");
	m_menu_Cube->SetPosition(165, 720);
	m_menu_Cube->SetColor(0);

	m_menu_Teapot = new CBoxButton();
	m_menu_Teapot->CreateButton("Resource/menu1_Teapot_noting.png", "Resource/menu1_Teapot_noting.png");
	m_menu_Teapot->SetPosition(165, 660);
	m_menu_Teapot->SetColor(0);

	m_menu_Torus = new CBoxButton();
	m_menu_Torus->CreateButton("Resource/menu1_Torus_noting.png", "Resource/menu1_Torus_noting.png");
	m_menu_Torus->SetPosition(165, 600);
	m_menu_Torus->SetColor(0);
}

void S_Main::Process(void)
{
	if (m_bIsOption)
	{
		m_menu_Exit->SetColor(255);

		if (!m_menu_Exit->Click())
		{
			PostQuitMessage(0);
		}
	}
	else
	{
		m_menu_Exit->SetColor(0);
	}

	if (m_bIsTetra)
	{
		m_menu_Tetra->SetColor(255);
		m_menu_Cube->SetColor(255);
		m_menu_Teapot->SetColor(255);
		m_menu_Torus->SetColor(255);

		if (!m_menu_Tetra->Click())
		{
			m_nSceneChange = 1;
		}

		if (!m_menu_Cube->Click())
		{
			m_nSceneChange = 2;
		}

		if (!m_menu_Teapot->Click())
		{
			m_nSceneChange = 3;
		}

		if (!m_menu_Torus->Click())
		{
			m_nSceneChange = 4;
		}
	}
	else
	{
		m_menu_Tetra->SetColor(0);
		m_menu_Cube->SetColor(0);
		m_menu_Teapot->SetColor(0);
		m_menu_Torus->SetColor(0);
	}

	//////////////////////////////////////////////////////

	if (m_bIsOption && !m_menu_Exit->m_bIsClick)
	{
		m_bIsOption = false;
	}

	if (m_bIsTetra && !m_menu_Tetra->m_bIsClick && !m_menu_Cube->m_bIsClick && !m_menu_Teapot->m_bIsClick && !m_menu_Torus->m_bIsClick)
	{
		m_bIsTetra = false;
	}

	///////////////////////////////////////////////////////

	if (!m_btnOption->Click())
	{
		m_bIsOption = true;
		m_bIsTetra = false;
	}

	if (!m_btnTetra->Click())
	{
		m_bIsTetra = true;
		m_bIsOption = false;
	}

	if (m_nSceneChange == 1)
	{
		m_nSceneChange = 0;
		SceneMgr->ChangeScene(Index_Tetra);
	}

	if (m_nSceneChange == 2)
	{
		m_nSceneChange = 0;
		SceneMgr->ChangeScene(Index_Cube);
	}

	if (m_nSceneChange == 3)
	{
		m_nSceneChange = 0;
		SceneMgr->ChangeScene(Index_Teapot);
	}

	if (m_nSceneChange == 4)
	{
		m_nSceneChange = 0;
		SceneMgr->ChangeScene(Index_Torus);
	}
}

void S_Main::Render(void)
{
	char temp[128];
	m_sprBG->Render();
	m_btnOption->Render();
	m_btnTetra->Render();

	m_menu_Exit->Render();

	m_menu_Tetra->Render();
	m_menu_Cube->Render();
	m_menu_Teapot->Render();
	m_menu_Torus->Render();
}

void S_Main::Release(void)
{
	m_menu_Torus->Release();
	m_menu_Teapot->Release();
	m_menu_Cube->Release();
	m_menu_Tetra->Release();

	m_menu_Exit->Release();

	m_btnTetra->Release();
	m_btnOption->Release();
	m_sprBG->Release();
}