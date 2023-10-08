#pragma once

#include "Sprite.h"

class O_MousePointer
	: public CSprite
{
private: // private 함수
	void Move(void);
public: // public 함수
	O_MousePointer(void);
	~O_MousePointer(void);

	void Init(void);
	void Process(void);
};

