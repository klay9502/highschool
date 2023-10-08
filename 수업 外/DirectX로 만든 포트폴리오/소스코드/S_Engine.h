#pragma once

#include "Scene.h"

class CSprite;
class CLable;
class S_Engine :
	public CScene
{
public: // public ����
	CSprite*	m_sprLogo;
	CLable*		m_sprText;
public: // public �Լ�
	S_Engine(void);
	~S_Engine(void);

	void Init(void) override;
	void Process(void) override;
	void Render(void) override;
	void Release(void) override;
};

