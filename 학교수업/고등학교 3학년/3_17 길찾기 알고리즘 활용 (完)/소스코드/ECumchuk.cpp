#include "stdafx.h"
#include "ECumchuk.h"


CECumchuk::CECumchuk()
{
	//HitedAnimation = new CAnimation();
	//HitedAnimation->CreateAnimation(strFront, 0.3, 3, false);
	//DeathAnimation = new CAnimation();
	//DeathAnimation->CreateAnimation(strFront, 0.3, 3, false);
	sprintf(str, "Resource/Cumchuk");
	setAni();

	BoundarySize.left = -27;
	BoundarySize.top = -52;
	BoundarySize.right = 27;
	BoundarySize.bottom = 52;

	m_moveSpeed = 50;
	m_nDamage = 10;
}


CECumchuk::~CECumchuk()
{
}