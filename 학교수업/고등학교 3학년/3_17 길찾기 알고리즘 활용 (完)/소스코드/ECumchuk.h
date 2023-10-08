#pragma once
#include "Object_Enemy.h"
class CECumchuk :
	public CObject_Enemy
{
private:
	CAnimation* HitedAnimation;
	CAnimation* DeathAnimation;
public:
	CECumchuk();
	~CECumchuk();

	//virtual void Hited();
	//virtual void Death();
	//virtual void HitCheck(	blt);s
	//virtual void changeAnimation(eAniType type);
};

