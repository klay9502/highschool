#pragma once

class CGame
{
public:
	CGame(void);
	~CGame(void);

	bool Init(HWND hWnd);
	void Render(void);
};