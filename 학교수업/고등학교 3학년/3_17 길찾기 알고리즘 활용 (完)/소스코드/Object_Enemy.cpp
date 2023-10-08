#include "stdafx.h"
#include "Object_Enemy.h"
#include "Define.h"
#include "TimeManager.h"

CObject_Enemy::CObject_Enemy()
{
	DeadTime = 0.0f;
	m_nDamage = 0;
	ptDist.x = 0;
	ptDist.y = 0;
	bIsActive = false;
	bIsSetPath = false;
	bIsHited = false;
	
}

void CObject_Enemy::setAni()
{
	char buf[128] = "";

	sprintf(buf, "%s_Hited", str);
	HitedAnimation = new CAnimation();
	HitedAnimation->CreateAnimation(buf, 0.3, 2, true);
	sprintf(buf, "%s_Left", str);
	NormalImage[eLeft] = new CAnimation();
	NormalImage[eLeft]->CreateAnimation(buf, 0.3, 2, true);
	sprintf(buf, "%s_Right", str);
	NormalImage[eRight] = new CAnimation();
	NormalImage[eRight]->CreateAnimation(buf, 0.3, 2, true);
}

CObject_Enemy::~CObject_Enemy()
{
}

void CObject_Enemy::setPoint(POINT pt)
{
	ptDist.x = pt.x;
	ptDist.y = pt.y;
	mainAni->SetPosition(pt.x, pt.y);

	BoundaryBox.left = getPoint().x + BoundarySize.left;
	BoundaryBox.top = getPoint().y + BoundarySize.top;
	BoundaryBox.right = getPoint().x + BoundarySize.right;
	BoundaryBox.bottom = getPoint().y + BoundarySize.bottom;
}

void CObject_Enemy::setPoint(int x, int y)
{
	ptDist.x = x;
	ptDist.y = y;

	BoundaryBox.left = BoundarySize.left + ptDist.x;
	BoundaryBox.right = BoundarySize.right + ptDist.x;
	BoundaryBox.top = BoundarySize.top + ptDist.y;
	BoundaryBox.bottom = BoundarySize.bottom + ptDist.y;

	mainAni->SetPosition(x, y);
}

bool CObject_Enemy::setPath(POINT player)
{
	POINT temp;
	temp.x = this->getPoint().x;
	temp.y = this->getPoint().y;

	int width = player.x - this->getPoint().x;
	int height = player.y - this->getPoint().y;

	while (1)
	{
		if (temp.x < 0 || temp.x > 1280)
			break;
		if (temp.y < 0 || temp.y > 720)
			break;

		temp.x += width / 5;
		temp.y += height / 5;
	}
	Destination.x = temp.x - this->getPoint().x;
	Destination.y = temp.y - this->getPoint().y;

	return true;
}

void CObject_Enemy::Move()
{
	float X = Destination.x / (200 - m_moveSpeed);
	float Y = Destination.y / (200 - m_moveSpeed);

	// printf("%f, %f\n", X, Y);

	BoundaryBox.left = BoundarySize.left + this->getPoint().x + X;
	BoundaryBox.right = BoundarySize.right + this->getPoint().x + X;
	BoundaryBox.top = BoundarySize.top + this->getPoint().y + Y;
	BoundaryBox.bottom = BoundarySize.bottom + this->getPoint().y + Y;

	this->setPoint(this->getPoint().x + X, this->getPoint().y + Y);
}

//player를 인자로 넣어주세요
void CObject_Enemy::Process(POINT player)
{
	mainAni->Process();
	if (bIsActive)
	{
		if (!bIsSetPath)
		{
			bIsSetPath = setPath(player);
		}
		if (!bIsHited)
		{
			Move();
		}
		Hited();
	}
}

void CObject_Enemy::Set()
{
	int type = rand() % 4;
	int temp;
	switch (type)
	{
	case eFront:
		temp = rand() % 1280;
		if (temp < 640) mainAni = NormalImage[eRight];
		else			mainAni = NormalImage[eLeft];
		this->setPoint(temp, 0);
		break;
	case eBack:
		temp = rand() % 1280;
		if (temp < 640) mainAni = NormalImage[eRight];
		else			mainAni = NormalImage[eLeft];
		this->setPoint(temp, 720);
		break;
	case eLeft:
		mainAni = NormalImage[eLeft];
		this->setPoint(1280, rand() % 720);
		break;
	case eRight:
		mainAni = NormalImage[eRight];
		this->setPoint(0, rand() % 720);
		break;
	}

	bIsSetPath = false;
}

void CObject_Enemy::Set(int x, int y)
{
	if (x < 640) mainAni = NormalImage[eRight];
	else			mainAni = NormalImage[eLeft];
	this->setPoint(x, y);

	bIsSetPath = false;
	//bIsActive = false;
}

void CObject_Enemy::Hited()
{
	if (bIsHited)
	{
		changeAnimation(eHited);
		DeadTime += TimeMgr->m_fDateTime / 1000;
		if (DeadTime >= 2.0f)
		{
			bIsActive = false;
		}
	}
}

void CObject_Enemy::changeAnimation(eAniType type)
{
	switch (type)
	{
	case eLeft:
		mainAni = NormalImage[type];
		break;
	case eRight:
		mainAni = NormalImage[type];
		break;
	case eHited:
		mainAni = HitedAnimation;
		break;
	}
}

void CObject_Enemy::BltBound(POINT Bullet)
{
	if (Bullet.x > this->BoundaryBox.left && Bullet.x < this->BoundaryBox.right
		&& Bullet.y > this->BoundaryBox.top && Bullet.y < this->BoundaryBox.bottom)
	{
		bIsHited = true;
	}
}

void CObject_Enemy::Render()
{
	if (bIsActive)
		mainAni->Render();
}

void CObject_Enemy::Release()
{
	if (HitedAnimation != nullptr)
	{
		HitedAnimation->Release();
		HitedAnimation = nullptr;
		delete HitedAnimation;
	}

	if (NormalImage[2] != nullptr)
	{
		NormalImage[2]->Release();
		NormalImage[2] = nullptr;
		delete NormalImage[3];
	}

	if (NormalImage[3] != nullptr)
	{
		NormalImage[3]->Release();
		NormalImage[3] = nullptr;
		delete NormalImage[3];
	}

	if (mainAni != nullptr)
	{
		mainAni->Release();
		mainAni = nullptr;
		delete mainAni;
	}
}