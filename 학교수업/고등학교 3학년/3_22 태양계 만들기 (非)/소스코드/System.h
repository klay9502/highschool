#pragma once

#include "stdafx.h"
#include "Game.h"

class CSystem
{
private:
	HWND		m_hWnd;
	HINSTANCE	m_hInst;
	CGame		m_Game;
public:
	CSystem(void);
	~CSystem(void);

	bool Init(void);
	int MessageLoop(void);
};

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
