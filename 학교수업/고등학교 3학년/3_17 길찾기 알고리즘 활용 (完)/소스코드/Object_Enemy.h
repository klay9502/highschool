#pragma once
#include "Animation.h"
#include "Define.h"

class CObject_Enemy
{
protected:
	int m_nDamage;	//오브젝트 공격력

	CAnimation* mainAni;
	CAnimation* NormalImage[2];		//eFront, eBack, eLeft, eRight
	CAnimation* HitedAnimation;

	//애니메이션 삽입용 문자열
	char str[128];

	POINT Destination;
	POINT ptDist;

	//충돌체크
	RECT BoundarySize;
	RECT BoundaryBox;

	bool bIsActive;
	bool bIsSetPath;
	bool bIsHited;

	int m_moveSpeed;

	float DeadTime;
public:
	CObject_Enemy();
	~CObject_Enemy();

	void setAni();

	inline int getDamage()	{ return m_nDamage; }
	inline POINT getPoint()	{ return ptDist; }
	inline CAnimation* getAni(){ return mainAni; }

	void setPoint(POINT pt);
	void setPoint(int x, int y);

	bool setPath(POINT player);

	void Active()	{ bIsActive = true; }
	void unActive()	{ bIsActive = false; }

	bool getIsActive(){ return bIsActive; }
	bool getIsHited(){ return bIsHited; }

	void BltBound(POINT Bullet);

	//player를 인자로 넣어주세요
	void Process(POINT player);
	void Render();
	void Release();

	void Hited();
	void Move();
	void Set();
	void Set(int x, int y);
	//virtual bool HitCheck(	blt) = 0;
	void changeAnimation(eAniType type);
};

