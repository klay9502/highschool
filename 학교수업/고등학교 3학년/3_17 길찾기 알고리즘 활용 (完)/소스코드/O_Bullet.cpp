#include "stdafx.h"
#include "O_Bullet.h"
#include "InputManager.h"


O_Bullet::O_Bullet(void)
{
	// empty...
}

O_Bullet::~O_Bullet(void)
{
	// empty...
}

void O_Bullet::Init(void)
{
	this->CreateSprite("Resource/Prototype/pMousePointer.png");
}

void O_Bullet::Process(void)
{
	degree = getDegree(a, b);
	Shot();
}

void O_Bullet::Shot(void)
{	
	m_fMoveX = cos(degree * (PI / 180)) * 20;
	m_fMoveY = -sin(degree * (PI / 180)) * 20;
	// printf("%f %f\n", m_fMoveX, m_fMoveX);

	pt.x = this->GetPosition().x - m_fMoveX;
	pt.y = this->GetPosition().y + m_fMoveY;

	this->SetPosition(pt.x, pt.y);
}
