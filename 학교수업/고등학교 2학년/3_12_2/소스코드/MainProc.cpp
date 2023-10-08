#include "stdafx.h"
#include "resource.h"

#define BSIZE 40

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

extern HINSTANCE hInst;

static int x, y;
static BOOL Selection;
int mx, my;
char strBuffer[64];

float LengthPts(int x1, int y1, int x2, int y2)
{
	return (sqrt ((float)(x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

BOOL InCircle(int x, int y, int mx, int my)
{
	if (LengthPts(x, y, mx, my) < BSIZE) return TRUE;
	else return FALSE;
}

int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	InitGDI();
	x = 50;	y = 50;
	Selection = FALSE;	// 원이 선택되었나, FALSE : 아직 안되있음.

	return 0;
}

int OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;

	wmId    = LOWORD(wParam);
	wmEvent = HIWORD(wParam);
		// 메뉴 선택을 구문 분석합니다.
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

int OnPaint(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	hdc = BeginPaint(hWnd, &ps);
		 /*TODO: 여기에 그리기 코드를 추가합니다.*/
		StartDraw(hdc);

		if (Selection)
		{
			Rect(x - BSIZE, y - BSIZE, x + BSIZE, y + BSIZE);
			GreenBrush();
		}
		else
		{
			RedBrush();
		}
		Circle(x - BSIZE, y - BSIZE, x + BSIZE, y + BSIZE);

		sprintf(strBuffer, "Mouse : [%03d, %03d]", mx, my);
		TransparentText();
		TextAtPos(5, 5, strBuffer);

		StopDraw();
		EndPaint(hWnd, &ps);
	return 0;
}

int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	ReleaseGDI();

	PostQuitMessage(0);
	return 0;
}

int OnButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mx = LOWORD(lParam);
	my = HIWORD(lParam);

	if (InCircle(x, y, mx, my))
	{
		Selection = TRUE;
	}

	InvalidateRgn(hWnd, NULL, TRUE);	// 새로 그려라 (무효화 선언)
	return 0;
}

int OnButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	Selection = FALSE;
	InvalidateRgn(hWnd, NULL, TRUE);	// 새로 그려라 (무효화 선언)
	return 0;
}

int OnMouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mx = LOWORD(lParam);
	my = HIWORD(lParam);

	if (Selection)
	{
		x = mx;
		y = my;
		InvalidateRgn(hWnd, NULL, TRUE);	// 원과 사각형 그리기
	}

	return 0;
}