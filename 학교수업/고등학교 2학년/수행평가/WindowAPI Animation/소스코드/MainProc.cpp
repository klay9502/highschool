/////////////////////////////////////////////
// Desc : 윈도우 프로시저 부분을 처리하는
//        함수를 MainProc.cpp에 모아 두었음.
//
/////////////////////////////////////////////
#include "stdafx.h"
#include "resource.h"

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

extern HINSTANCE hInst;
extern BOOL bIsActive;
HDC  hScreenDC, hMemoryDC;	// System of DC
HDC  hImageDC1, hImageDC2;	// Image of DC
HBITMAP hMemoryBitmap;
HBITMAP hImageBitmap1, hImageBitmap2;

int x, y, h;
bool bIsKeyDown = false;
bool bIsReverse = false;
bool bIsGuitar = false;

int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// 시스템 DC // 더블버퍼링 설정
	hScreenDC = GetDC(hWnd);
	hMemoryDC = CreateCompatibleDC(hScreenDC);
	hMemoryBitmap = CreateCompatibleBitmap(hScreenDC, 1024, 768);
	SelectObject(hMemoryDC, hMemoryBitmap);

	// 이미지DC와 버퍼 설정
	hImageDC1 = CreateCompatibleDC(hScreenDC);
	hImageBitmap1 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP2));
	SelectObject(hImageDC1, hImageBitmap1);

	hImageDC2 = CreateCompatibleDC(hScreenDC);
	hImageBitmap2 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
	SelectObject(hImageDC2, hImageBitmap2);

	bIsActive = true;
	return 0;
}

int OnKeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case VK_RIGHT:
		h = 170;
		x += 10;
		bIsKeyDown = true;
		bIsReverse = false;
		break;
	case VK_LEFT:
		h = 170;
		x -= 10;
		bIsKeyDown = true;
		bIsReverse = true;
		break;
	case VK_SPACE:
		bIsKeyDown = true;
		bIsGuitar = true;
		break;
	}

	return 0;
}

//==============================
// 윈도우 종료 메시지 처리 함수
int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	bIsActive = false;
	DeleteObject(hImageBitmap2);
	ReleaseDC(hWnd, hImageDC2);

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
	static int nCount = 1;

	// 이미지버퍼에서 이미지를 후면버퍼로 복사
	StretchBlt(hMemoryDC, 0, 0, 1344, 360, hImageDC1, 0, 0, 1344, 360, SRCCOPY);
	switch (bIsKeyDown)
	{
	case true:
		if (bIsGuitar == true)
		{
			TransparentBlt(hMemoryDC, 100 + x, 225 + y, 95, 120, hImageDC2, 30 + (nCount * 95), 250, 95, 120, RGB(255, 255, 255));
			if (++nCount > 5)
				nCount = 1;
		}

		if (bIsReverse == true && bIsGuitar == false)
		{
			TransparentBlt(hMemoryDC, 100 + x, 275 + y, 47, 60, hImageDC2, 815 - (nCount * 47), h, 47, 60, RGB(255, 255, 255));
			if (++nCount > 7)
				nCount = 1;
		}
		else if (bIsReverse == false && bIsGuitar == false)
		{
			TransparentBlt(hMemoryDC, 100 + x, 275 + y, 47, 60, hImageDC2, 35 + (nCount * 47), h, 47, 60, RGB(255, 255, 255));
			if (++nCount > 7)
				nCount = 1;
		}
		break;
	case false:
		if (bIsReverse == true)
		{
			TransparentBlt(hMemoryDC, 100 + x, 275 + y, 40, 60, hImageDC2, 684 - (nCount * 40), h, 40, 60, RGB(255, 255, 255));
			if (++nCount > 7)
				nCount = 1;
		}
		else if (bIsReverse == false)
		{
			TransparentBlt(hMemoryDC, 100 + x, 275 + y, 40, 60, hImageDC2, 34 + (nCount * 40), h, 40, 60, RGB(255, 255, 255));
			if (++nCount > 7)
				nCount = 0;
		}
		break;
	}

	Sleep(50);

	// 후면버퍼를 화면 버퍼로 복사
	// 세컨더리버퍼를 프라이머리버퍼로 복사
	BitBlt(hScreenDC, 0, 0, 1344, 360, hMemoryDC, 0, 0, SRCCOPY);

	h = 90;
	bIsKeyDown = false;
	bIsGuitar = false;

	return 0;
}