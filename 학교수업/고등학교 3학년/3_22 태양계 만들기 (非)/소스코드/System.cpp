#include "stdafx.h"
#include "System.h"


CSystem::CSystem(void)
{
	// empty...
}

CSystem::~CSystem(void)
{
	// empty...
}

bool CSystem::Init(void)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = m_hInst;
	wcex.hIcon = LoadIcon(m_hInst, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = NULL;
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDI_APPLICATION);
	wcex.lpszClassName = "WindowClass";
	wcex.hIconSm = LoadIcon(m_hInst, MAKEINTRESOURCE(IDI_APPLICATION));

	RegisterClassEx(&wcex);

	DWORD dwScreenX = GetSystemMetrics(SM_CXFULLSCREEN);
	DWORD dwScreenY = GetSystemMetrics(SM_CYFULLSCREEN);

	DWORD dwMainX = (dwScreenX - _MAIN_WIDTH_) / 2;
	DWORD dwMainY = (dwScreenY - _MAIN_HEIGHT_) / 2;

	DWORD dwStyle = WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_THICKFRAME;

	m_hWnd = CreateWindow("WindowClass", "Solar System", dwStyle,
		dwMainX, dwMainY, _MAIN_WIDTH_, _MAIN_HEIGHT_, NULL, NULL, m_hInst, NULL);

	m_Game.Init(m_hWnd);

	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);
	
	return true;
}

int CSystem::MessageLoop(void)
{
	MSG msg;

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (NULL == GetMessage(&msg, NULL, 0, 0))
			{
				return (int)msg.wParam;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			// Render...
			m_Game.Render();
		}
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
#if _DEBUG
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
#endif
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	return true;
}