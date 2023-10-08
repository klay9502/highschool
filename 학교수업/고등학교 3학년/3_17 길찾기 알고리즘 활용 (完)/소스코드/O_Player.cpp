#include "stdafx.h"
#include "O_Player.h"
#include "InputManager.h"


O_Player::O_Player(void)
{
	// empty...
}

O_Player::~O_Player(void)
{
	// empty...
}

void O_Player::Init(void)
{
	this->CreateSprite("Resource/Player.png");
}

void O_Player::Process(void)
{
	Move();
}

void O_Player::Move(void)
{
	if (GetAsyncKeyState('W'))
	{
		if (this->GetPosition().y < 190)
		{
			return;
		}

		this->SetPosition(this->GetPosition().x, this->GetPosition().y - 10);
	}

	if (GetAsyncKeyState('S'))
	{
		if (this->GetPosition().y > 562)
		{
			return;
		}

		this->SetPosition(this->GetPosition().x, this->GetPosition().y + 10);
	}

	if (GetAsyncKeyState('A'))
	{
		if (this->GetPosition().x < 320)
		{
			return;
		}

		this->SetPosition(this->GetPosition().x - 10, this->GetPosition().y);
	}

	if (GetAsyncKeyState('D'))
	{
		if (this->GetPosition().x > 950)
		{
			return;
		}

		this->SetPosition(this->GetPosition().x + 10, this->GetPosition().y);
	}

	/*static float scaleTheta = 0.0f;
	D3DXVECTOR2 size = D3DXVECTOR2(sin(scaleTheta) * 200, sin(scaleTheta) * 400);
	scaleTheta += 0.1f;
	this->SetSize(size);

	D3DXVECTOR2 pos = D3DXVECTOR2(-cos(scaleTheta), sin(scaleTheta));
	this->SetPosition(pos * 100 + D3DXVECTOR2(640, 360));

	this->SetRotation(this->GetRotation() + 5);*/
}