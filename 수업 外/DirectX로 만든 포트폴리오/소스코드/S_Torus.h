#pragma once

#include "Scene.h"

class CBoxButton;
class CSprite;
class O_LoadObject;
class S_Torus :
	public CScene
{
public:
	CSprite* m_sprBG;
	O_LoadObject* m_objTorus;

	CBoxButton* m_btnBack;
public:
	S_Torus(void);
	~S_Torus(void);

	void Init(void) override;
	void Process(void) override;
	void Render(void) override;
	void Release(void) override;
};

