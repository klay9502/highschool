#pragma once

#include "Scene.h"

class CSprite;
class O_Player;
class O_MousePointer;
class O_Bullet;
class CEFaohu;
class CECumchuk;
class CECosplayer;
class S_Ingame :
	public CScene
{
private: // private 변수
	float m_fOldTime;
	float m_fCurTime;
	float m_fCountTime;
public: // public 변수
	CSprite* m_sprBG;
	O_Player* m_objPlayer;
	O_MousePointer* m_objMousePointer;
	vector<O_Bullet*> m_vBullet;
	vector<CEFaohu*> m_vEnemy1;
public: // public 함수
	S_Ingame(void);
	~S_Ingame(void);

	void Init(void) override;
	void Process(void) override;
	void Render(void) override;
	void Release(void) override;
};

