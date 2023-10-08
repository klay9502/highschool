// 4_16.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

INT_PTR CALLBACK MyDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

int _tmain(int argc, _TCHAR* argv[])
{
	HINSTANCE hInst;
	hInst = GetModuleHandle(NULL);
	DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)MyDlgProc);
	return 0;
}

INT_PTR CALLBACK MyDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	HDC hdc;
	static TCHAR strBuffer[1024];
	TCHAR strTemp[128];
	switch (message)
	{
	case WM_INITDIALOG:
		// GetDlgItem(hDlg, );
		// SetDlgItemInt();
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDOK:
			GetDlgItemText(hDlg, IDC_EDIT1, strTemp, 128);
			strcpy(strBuffer, strTemp);
			strcat(strBuffer, "학년 ");
			GetDlgItemText(hDlg, IDC_EDIT2, strTemp, 128);
			strcat(strBuffer, strTemp);
			strcat(strBuffer, "반 ");
			GetDlgItemText(hDlg, IDC_EDIT3, strTemp, 128);
			strcat(strBuffer, strTemp);

			SetDlgItemText(hDlg, IDC_EDIT4, strBuffer);
			break;
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			break;
		}
		return (INT_PTR)TRUE;
	}
	return (INT_PTR)FALSE;
}