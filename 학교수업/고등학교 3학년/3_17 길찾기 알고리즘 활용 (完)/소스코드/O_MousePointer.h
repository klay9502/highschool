#pragma once

#include "Sprite.h"

class O_MousePointer
	: public CSprite
{
private: // private �Լ�
	void Move(void);
public: // public �Լ�
	O_MousePointer(void);
	~O_MousePointer(void);

	void Init(void);
	void Process(void);
};

