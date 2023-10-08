#pragma once

#include "Sprite.h"

class O_Wall :
	public CSprite
{
public:
	int Active;
public:
	O_Wall(void);
	~O_Wall(void);

	void Init(void);
};

