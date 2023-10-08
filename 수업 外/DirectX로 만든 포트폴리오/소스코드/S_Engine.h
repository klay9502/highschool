#pragma once

#include "Scene.h"

class CSprite;
class CLable;
class S_Engine :
	public CScene
{
public: // public 변수
	CSprite*	m_sprLogo;
	CLable*		m_sprText;
public: // public 함수
	S_Engine(void);
	~S_Engine(void);

	void Init(void) override;
	void Process(void) override;
	void Render(void) override;
	void Release(void) override;
};

