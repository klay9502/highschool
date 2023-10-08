#pragma once
#include "Scene.h"

class CSprite;
class O_Player;
class O_MousePointer;
class O_Bullet;
class CObject_Enemy;
class S_Stage1 :
	public CScene
{
private: // pirvate 변수
	float m_fOldTime;
	float m_fCurTime;
	float m_fCountTime;
public: // public 변수
	CSprite* m_sprBG;
	O_Player* m_objPlayer;
	O_MousePointer* m_objMousePointer;
	vector<O_Bullet*> m_vBullet;
	vector<CObject_Enemy*> m_vEnemy;

	int bltCount;
public: // public 함수
	S_Stage1(void);
	~S_Stage1(void);

	void Init(void) override;
	void Process(void) override;
	void Render(void) override;
	void Release(void) override;
};

