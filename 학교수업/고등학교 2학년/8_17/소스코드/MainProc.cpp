/////////////////////////////////////////////
// Desc : ������ ���ν��� �κ��� ó���ϴ�
//        �Լ��� MainProc.cpp�� ��� �ξ���.
//
/////////////////////////////////////////////
#include "stdafx.h"
#include "resource.h"

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

extern HINSTANCE hInst;
extern BOOL bIsActive;
extern HDC ScreenDC, MemoryDC;
extern HBITMAP hBitmap, hOldBitmap;
extern RECT rtScreen;
extern POINT ptMouse;

std::vector<POINT> vMouse;

int cheakScene = 0;

int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	InitGDI();
	GetClientRect(hWnd, &rtScreen);
	SetTimer(hWnd, 0, 100 / 33, NULL);

	// ������۸� ����
	ScreenDC = GetDC(hWnd);
	MemoryDC = CreateCompatibleDC(ScreenDC);
	hBitmap = CreateCompatibleBitmap(ScreenDC, rtScreen.right, rtScreen.bottom);
	hOldBitmap = (HBITMAP)SelectObject(MemoryDC, hBitmap);

	bIsActive = TRUE;

	return 0;
}

//==============================
// �޴� ���� �޽��� ó�� �Լ�
int OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	wmId    = LOWORD(wParam);
	wmEvent = HIWORD(wParam);
	// �޴� ������ ���� �м��մϴ�.
	switch (wmId)
	{
	case IDM_ABOUT:
		DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
		break;
	case IDM_EXIT:
		DestroyWindow(hWnd);
		break;
	case ID_ONE:
		cheakScene = 1;
		break;
	case ID_TWO:
		cheakScene = 2;
		break;
	case ID_THREE:
		cheakScene = 3;
		break;
	default:
		return DefWindowProc(hWnd, WM_COMMAND, wParam, lParam);
	}
	return 0;
}

int OnTimer(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	InvalidateRect(hWnd, NULL, true);
	return 0;
}

int OnSize(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	DeleteObject(hBitmap);
	DeleteObject(hOldBitmap);
	ReleaseDC(hWnd, MemoryDC);
	ReleaseDC(hWnd, ScreenDC);

	GetClientRect(hWnd, &rtScreen);

	ScreenDC = GetDC(hWnd);
	MemoryDC = CreateCompatibleDC(ScreenDC);
	hBitmap = CreateCompatibleBitmap(ScreenDC, rtScreen.right, rtScreen.bottom);
	hOldBitmap = (HBITMAP)SelectObject(MemoryDC, hBitmap);

	return 0;
}

int OnLButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	ptMouse.x = LOWORD(lParam);
	ptMouse.y = HIWORD(lParam);

	vMouse.push_back(ptMouse);

	return 0;
}

int OnRButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	if (!vMouse.empty())
	{
		vMouse.pop_back();
	}

	return 0;
}

//==============================
// ������ ���� �޽��� ó�� �Լ�
int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	KillTimer(hWnd, 0);

	DeleteObject(hBitmap);
	DeleteObject(hOldBitmap);
	ReleaseDC(hWnd, MemoryDC);
	ReleaseDC(hWnd, ScreenDC);

	ReleaseGDI();
	PostQuitMessage(0);
	return 0;
}

//==============================
// ���� ����
void Run(void)
{
	switch (cheakScene)
	{
	case 1:
		DrawBackground();
		break;
	case 2:
		DrawBackgroundExCross();

		for (int i = 0; i < vMouse.size(); i++)
		{
			DrawBigDot(vMouse[i].x, vMouse[i].y, red);
		}
		break;
	case 3:
		DrawBackgroundGird();
		break;
	}
}

