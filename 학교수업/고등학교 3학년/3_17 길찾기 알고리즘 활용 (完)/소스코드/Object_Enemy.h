#pragma once
#include "Animation.h"
#include "Define.h"

class CObject_Enemy
{
protected:
	int m_nDamage;	//������Ʈ ���ݷ�

	CAnimation* mainAni;
	CAnimation* NormalImage[2];		//eFront, eBack, eLeft, eRight
	CAnimation* HitedAnimation;

	//�ִϸ��̼� ���Կ� ���ڿ�
	char str[128];

	POINT Destination;
	POINT ptDist;

	//�浹üũ
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

	//player�� ���ڷ� �־��ּ���
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

