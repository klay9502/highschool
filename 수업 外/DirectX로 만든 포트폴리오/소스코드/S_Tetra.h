#pragma once

#include "Scene.h"

class CBoxButton;
class CSprite;
class O_Tetra;
class S_Tetra :
	public CScene
{
public: // public 변수
	CSprite* m_sprBG;
	O_Tetra* m_objTetra;

	CBoxButton* m_btnBack;
public: // public 함수
	S_Tetra(void);
	~S_Tetra(void);

	void Init(void) override;
	void Process(void) override;
	void Render(void) override;
	void Release(void) override;
};