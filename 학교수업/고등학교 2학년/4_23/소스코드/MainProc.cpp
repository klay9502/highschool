/////////////////////////////////////////////
// Desc : ������ ���ν��� �κ��� ó���ϴ�
//        �Լ��� MainProc.cpp�� ��� �ξ���.
//
/////////////////////////////////////////////
#include "stdafx.h"
#include "resource.h"

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

extern HINSTANCE hInst;
extern HDC hScreenDC;
extern HDC hMemoryDC;
extern HBITMAP hMemoryBMP;
extern BOOL bIsMouseLB;
extern POINT ptMStart;
extern POINT ptMEnd;

extern HBITMAP hImageBMP;
extern HDC hImageDC;

int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	InitGDI();
	hScreenDC = GetDC(hWnd);
	hMemoryDC = CreateCompatibleDC(hScreenDC);
	hMemoryBMP = CreateCompatibleBitmap(hScreenDC, 800, 600);
	SelectObject(hMemoryDC, hMemoryBMP);
	StartDraw(hMemoryDC);
	hImageDC = CreateCompatibleDC(hScreenDC);
	hImageBMP = (HBITMAP)LoadImage(hInst, L"OIng.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	SelectObject(hImageDC, hImageBMP);

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
	default:
		return DefWindowProc(hWnd, WM_COMMAND, wParam, lParam);
	}
	return 0;
}

//==============================
// �׸��� �޽��� ó�� �Լ�
int OnPaint(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
	WhitePen();
	WhiteBrush();
	Rect(0, 0, 800, 600);
	BitBlt(hMemoryDC, 0, 0, 800, 600, hImageDC, 0, 0, SRCCOPY);

	if (bIsMouseLB)
	{
		BluePen();
		Line(ptMStart.x, ptMStart.y, ptMEnd.x, ptMEnd.y);
	}
	else
	{
		RedPen();
		Line(ptMStart.x, ptMStart.y, ptMEnd.x, ptMEnd.y);
	}
	Blt(hScreenDC, 800, 600);

	EndPaint(hWnd, &ps);
	return 0;
}

//==============================
// ������ ���� �޽��� ó�� �Լ�
int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	StopDraw();
	DeleteObject(hMemoryBMP);
	ReleaseDC(hWnd, hMemoryDC);
	ReleaseDC(hWnd, hScreenDC);
	ReleaseGDI();
	PostQuitMessage(0);
	return 0;
}

int OnLButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	bIsMouseLB = true;
	ptMStart.x = LOWORD(lParam);
	ptMStart.y = HIWORD(lParam);
	return 0;
}

int OnLButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	bIsMouseLB = false;

	InvalidateRect(hWnd, NULL, true);
	return 0;
}

int OnMouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	if (bIsMouseLB)
	{
		ptMEnd.x = LOWORD(lParam);
		ptMEnd.y = HIWORD(lParam);
	}

	InvalidateRect(hWnd, NULL, true);
	return 0;
}