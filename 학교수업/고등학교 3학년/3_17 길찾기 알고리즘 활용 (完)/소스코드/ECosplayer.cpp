#include "stdafx.h"
#include "ECosplayer.h"


CECosplayer::CECosplayer()
{
	sprintf(str, "Resource/Cosplayer");
	setAni();


	BoundarySize.left = -27;
	BoundarySize.top = -30;
	BoundarySize.right = 27;
	BoundarySize.bottom = 30;

	m_moveSpeed = 30;
	m_nDamage = 25;
}


CECosplayer::~CECosplayer()
{
}
