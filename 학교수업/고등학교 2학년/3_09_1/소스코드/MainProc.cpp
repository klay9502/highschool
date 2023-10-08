/////////////////////////////////////////////////////////
//
//
//
//////////////////////////////////////////////////////////
#include "stdafx.h"
#include "resource.h"

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

extern HINSTANCE hInst;

HPEN hPen[16], hOldPen;
HBRUSH hBrush[16], hOldBrush;

int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//hPen[0] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));	// 노트위에 빨간펜을 놓는다.
	//hPen[1] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));	// 노트위에 파란펜을 놓는다.
	//hPen[2] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));	// 노트위에 초록펜을 놓는다.

	hBrush[0] = CreateSolidBrush(RGB(255, 0, 0));
	hBrush[1] = CreateSolidBrush(RGB(0, 255, 0));
	hBrush[2] = CreateSolidBrush(RGB(0, 0, 255));

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

		SelectObject(hdc, hOldPen);

		SelectObject(hdc, hBrush[0]);
		Rectangle(hdc, 10, 10, 210, 210);

		SelectObject(hdc, hBrush[1]);
		Rectangle(hdc, 35, 35, 185, 185);

		SelectObject(hdc, hBrush[2]);
		Ellipse(hdc, 35, 35, 185, 185);

		MoveToEx(hdc,35, 35, NULL);
		LineTo(hdc, 185, 185);

		MoveToEx(hdc, 185, 35, NULL);
		LineTo(hdc, 35, 185);

		TextOut(hdc, 250, 100, "2409 김종민", 11);


		//hOldPen = (HPEN)SelectObject(hdc, hPen[0]);	// 손에 빨간펜을 쥐면서 검은펜을 hOldPen에 놓는다.
		//hOldBrush = (HBRUSH)SelectObject(hdc, hBrush[0]);
		//Ellipse(hdc, 10, 10, 110, 110);

		//SelectObject(hdc, hPen[1]);	// 손에 파란펜을 쥔다.
		//Rectangle(hdc, 120, 10, 220, 110);

		//SelectObject(hdc, hBrush[1]);

		//SelectObject(hdc, hOldPen);	// 원래 검은색펜을 쥔다.
		//POINT tri[3] = {{100, 200}, {0, 300}, {200, 300}};
		//Polygon(hdc, tri, 3);

		//SelectObject(hdc, hOldBrush);

		EndPaint(hWnd, &ps);
	return 0;
}

int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	DeleteObject(hBrush[2]);
	DeleteObject(hBrush[1]);
	DeleteObject(hBrush[0]);
	//DeleteObject(hPen[1]);
	//DeleteObject(hPen[0]);

	PostQuitMessage(0);
	return 0;
}