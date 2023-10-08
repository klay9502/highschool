#pragma once

#include "Scene.h"

class CLable;
class CBoxButton;
class CSprite;
class S_Main :
	public CScene
{
public: // public 변수
	CSprite*	m_sprBG;
	CBoxButton* m_btnOption;
	CBoxButton* m_btnTetra;

	CBoxButton* m_menu_Exit;

	CBoxButton* m_menu_Cube;
	CBoxButton* m_menu_Tetra;
	CBoxButton* m_menu_Teapot;
	CBoxButton* m_menu_Torus;

	bool m_bIsOption;
	bool m_bIsTetra;
	int m_nSceneChange;
public: // public 함수
	S_Main(void);
	~S_Main(void);

	void Init(void) override;
	void Process(void) override;
	void Render(void) override;
	void Release(void) override;
};

