#pragma once

#include "Scene.h"

class CBoxButton;
class CSprite;
class O_LoadObject;
class S_Teapot :
	public CScene
{
public: // public ����
	CSprite* m_sprBG;
	O_LoadObject* m_objTeapot;

	CBoxButton* m_btnBack;
public: // public �Լ�
	S_Teapot(void);
	~S_Teapot(void);

	void Init(void) override;
	void Process(void) override;
	void Render(void) override;
	void Release(void) override;
};

