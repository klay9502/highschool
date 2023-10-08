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
extern HDC ScreenDC, MemoryDC;
extern HBITMAP hBitmap, hOldBitmap;
extern RECT rtScreen;

extern MESH gTetra;

int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	InitGDI();
	GetClientRect(hWnd, &rtScreen);
	SetTimer(hWnd, 0, 100 / 33, NULL);

	// 더블버퍼링 설정
	ScreenDC = GetDC(hWnd);
	MemoryDC = CreateCompatibleDC(ScreenDC);
	hBitmap = CreateCompatibleBitmap(ScreenDC, rtScreen.right, rtScreen.bottom);
	hOldBitmap = (HBITMAP)SelectObject(MemoryDC, hBitmap);

	//////////////////////////////////////////////
	// 삼각뿔 정의
	gTetra.numVertex = 4;
	gTetra.numTriangle = 4;
	gTetra.pVertexList = (VERTEX*)malloc(gTetra.numVertex * sizeof(VERTEX));
	gTetra.pVertexIndexList = (int*)malloc(gTetra.numTriangle * sizeof(int)* 3);
	// 삼각뿔 데이터 세팅
	gTetra.pVertexList[0].x = 0.0f;
	gTetra.pVertexList[0].y = 0.0f;
	gTetra.pVertexList[0].z = 0.0f;
	gTetra.pVertexList[0].w = 0.0f;

	gTetra.pVertexList[1].x = 0.0f;
	gTetra.pVertexList[1].y = 50.0f;
	gTetra.pVertexList[1].z = 0.0f;
	gTetra.pVertexList[1].w = 1.0f;

	gTetra.pVertexList[2].x = -80.0f;
	gTetra.pVertexList[2].y = -50.0f;
	gTetra.pVertexList[2].z = 50.0f;
	gTetra.pVertexList[2].w = 1.0f;

	gTetra.pVertexList[3].x = 80.0f;
	gTetra.pVertexList[3].y = -50.0f;
	gTetra.pVertexList[3].z = 50.0f;
	gTetra.pVertexList[3].w = 1.0f;

	gTetra.pVertexIndexList[0] = 0;
	gTetra.pVertexIndexList[1] = 2;
	gTetra.pVertexIndexList[2] = 1;

	gTetra.pVertexIndexList[3] = 0;
	gTetra.pVertexIndexList[4] = 3;
	gTetra.pVertexIndexList[5] = 2;

	gTetra.pVertexIndexList[6] = 0;
	gTetra.pVertexIndexList[7] = 1;
	gTetra.pVertexIndexList[8] = 3;

	gTetra.pVertexIndexList[9] = 1;
	gTetra.pVertexIndexList[10] = 2;
	gTetra.pVertexIndexList[11] = 3;
	//////////////////////////////////////////////

	bIsActive = TRUE;

	return 0;
}

//==============================
// 메뉴 선택 메시지 처리 함수
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

//==============================
// 윈도우 종료 메시지 처리 함수
int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	ReleaseGDI();
	PostQuitMessage(0);
	return 0;
}