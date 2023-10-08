#include "stdafx.h"
#include "EFaohu.h"
#include "InputManager.h"

CEFaohu::CEFaohu() : CObject_Enemy()
{
	sprintf(str,"Resource/Faohu");
	setAni();

	BoundarySize.left = -27;
	BoundarySize.top = -42;
	BoundarySize.right = 27;
	BoundarySize.bottom = 42;

	m_moveSpeed = 10;
	m_nDamage = 20;
}


CEFaohu::~CEFaohu()
{
}



//bool CEFaohu::HitCheck(POINT blt)
//{
//	if ((blt.x >= BoundaryBox.left && blt.x <= BoundaryBox.right)
//		&& (btl.y >= BoundaryBox.top && blt.y <= BoundaryBox.bottom))
//	{
//		Hited();
//	}
//}