// 12_04.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <Windows.h>
#include "resource.h"

INT_PTR CALLBACK MyDialogBox(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	HINSTANCE hInst;
	hInst = GetModuleHandle( NULL );

	DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, MyDialogBox);

	return 0;
}

