#include "stdafx.h"
#include "O_MousePointer.h"
#include "InputManager.h"


O_MousePointer::O_MousePointer(void)
{
	// empty...
}

O_MousePointer::~O_MousePointer(void)
{
	// empty...
}

void O_MousePointer::Init(void)
{
	this->CreateSprite("Resource/Prototype/pMousePointer.png");
	this->SetPosition(InputMgr->m_ptCurMouse.x, InputMgr->m_ptCurMouse.y);
}

void O_MousePointer::Process(void)
{
	Move();
}

void O_MousePointer::Move(void)
{
	int width = InputMgr->m_ptCurMouse.x - this->GetPosition().x;
	int height = InputMgr->m_ptCurMouse.y - this->GetPosition().y;

	//float X = width / 10;
	//float Y = height / 10;

	this->SetPosition(this->GetPosition().x + width, this->GetPosition().y + height);
}