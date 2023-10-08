#pragma once

#include "Sprite.h"

class O_Player :
	public CSprite
{
private: // private �Լ�
	void Move(void);
	int HP;

public: // public �Լ�
	O_Player(void);
	~O_Player(void);

	void Init(void);
	void Process(void);
};