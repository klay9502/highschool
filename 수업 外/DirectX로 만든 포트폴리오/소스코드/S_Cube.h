#pragma once

#include "Scene.h"

class CBoxButton;
class CSprite;
class O_Cube;
class S_Cube :
	public CScene
{
public: // public 변수
	CSprite*	m_sprBG;
	O_Cube*		m_objCube;

	CBoxButton* m_btnBack;
public: // public 함수
	S_Cube(void);
	~S_Cube(void);

	void Init(void) override;
	void Process(void) override;
	void Render(void) override;
	void Release(void) override;
};
