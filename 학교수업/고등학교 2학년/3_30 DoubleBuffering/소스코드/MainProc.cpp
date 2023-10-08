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
extern HDC  hScreenDC, hMemoryDC;	// System of DC
extern HDC  hImageDC1, hImageDC2;	// Image of DC
extern HBITMAP hMemoryBitmap;
extern HBITMAP hImageBitmap1, hImageBitmap2;

static HDC hdc, memdc;
static HBITMAP hBitmap;

int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// �ý��� DC // ������۸� ����
	hScreenDC = GetDC(hWnd);
	hMemoryDC = CreateCompatibleDC(hScreenDC);
	hMemoryBitmap = CreateCompatibleBitmap(hScreenDC, 1024, 768);
	SelectObject(hMemoryDC, hMemoryBitmap);

	// �̹���DC�� ���� ����
	hImageDC1 = CreateCompatibleDC(hScreenDC);
	hImageBitmap1 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP2));
	SelectObject(hImageDC1, hImageBitmap1);

	hImageDC2 = CreateCompatibleDC(hScreenDC);
	hImageBitmap2 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
	SelectObject(hImageDC2, hImageBitmap2);

	bIsActive = true;
	return 0;
}

int OnLButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

POINT ptMouse;
int OnMouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	ptMouse.x = LOWORD(lParam);
	ptMouse.y = HIWORD(lParam);

	return 0;
}

//==============================
// ������ ���� �޽��� ó�� �Լ�
int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	DeleteObject(hImageBitmap1);
	ReleaseDC(hWnd, hImageDC1);
	DeleteObject(hMemoryBitmap);
	ReleaseDC(hWnd, hMemoryDC);
	ReleaseDC(hWnd, hScreenDC);
	PostQuitMessage(0);
	return 0;
}

int GameRun()
{
	// �̹������ۿ��� �̹����� �ĸ���۷� ����
	StretchBlt(hMemoryDC, 0, 0, 1024, 768, hImageDC1, 0, 0, 512, 384, SRCCOPY);
	BitBlt(hMemoryDC, 0, 0, ptMouse.x, ptMouse.y, hImageDC2, 0, 0, SRCCOPY);

	// �ĸ���۸� ȭ�� ���۷� ����
	// �����������۸� �����̸Ӹ����۷� ����
	BitBlt(hScreenDC, 0, 0, 1024, 768, hMemoryDC, 0, 0, SRCCOPY);
	return 0;
}