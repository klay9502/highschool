#include "stdafx.h"
#include "O_Wall.h"


O_Wall::O_Wall(void)
{
	Active = 0;
}

O_Wall::~O_Wall(void)
{
	// empty...
}

void O_Wall::Init(void)
{
	this->CreateSprite("Resource/Prototype/pMousePointer.png");
}
