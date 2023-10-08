#pragma once

#include "Sprite.h"

class O_Player :
	public CSprite
{
private: // private 함수
	void Move(void);
	int HP;

public: // public 함수
	O_Player(void);
	~O_Player(void);

	void Init(void);
	void Process(void);
};