/////////////////////////////////////////////////////////
//
//
//
//////////////////////////////////////////////////////////
#include "stdafx.h"
#include "resource.h"

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

extern HINSTANCE hInst;

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
		// TODO: 여기에 그리기 코드를 추가합니다.
		SetTextAlign(hdc, TA_CENTER);
		SetTextColor(hdc, RGB(255, 0, 255));
		TextOut(hdc, 60, 20, L"ㅇㅇㅇ고등학교", 7);
		SetTextColor(hdc, RGB(255, 255, 128));
		SetBkColor(hdc, RGB(0, 0, 255));
		TextOut(hdc, 60, 40, L"2학년 4반", 6);
		SetTextColor(hdc, RGB(255, 255, 128));
		SetBkColor(hdc, RGB(0, 0, 255));
		TextOut(hdc, 60, 40, L"김종민", 3);
		EndPaint(hWnd, &ps);

		for (int i = 0; i < 100000; i++)
		{
			SetPixel(hdc, rand()%200, rand()%200, RGB(rand()%255, rand()%255, rand()%255) );
		}
		Rectangle(hdc, 500, 0, 300, 200);

		MoveToEx(hdc, 300, 200, NULL);
		LineTo(hdc, 500, 0);

	return 0;
}

int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
	return 0;
}