#pragma once

#include "Scene.h"

class CBoxButton;
class CSprite;
class O_Tetra;
class S_Tetra :
	public CScene
{
public: // public ����
	CSprite* m_sprBG;
	O_Tetra* m_objTetra;

	CBoxButton* m_btnBack;
public: // public �Լ�
	S_Tetra(void);
	~S_Tetra(void);

	void Init(void) override;
	void Process(void) override;
	void Render(void) override;
	void Release(void) override;
};