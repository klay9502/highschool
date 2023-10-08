#pragma once

#include "Sprite.h"
#define PI 3.141592

class O_Bullet :
	public CSprite
{
public: // public ����
	double degree;
	POINT a, b;
	float m_fMoveX, m_fMoveY;


private: // private �Լ�
	POINT pt;
	double getDegree(POINT from, POINT to)
	{
		return atan2(from.y - to.y, from.x - to.x) * (180 / PI);
	}
public: // public �Լ�
	O_Bullet(void);
	~O_Bullet(void);

	void Init(void);
	void Process(void);
	void Shot(void);
	POINT getPoint() { return pt; }
};

