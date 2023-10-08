// 12_15.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <Windows.h>
#include <WindowsX.h>
#include "resource.h"

INT_PTR CALLBACK MyDlg(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HWND hComboBox;
	HWND hListBox;
	char strBuffer[128];
	int  nCount;

	switch (message)
	{
	case WM_INITDIALOG:		// 다이얼로그윈도우 초기화 메시지
		hComboBox = GetDlgItem(hWnd, IDC_COMBO1);
		ComboBox_AddString(hComboBox, "울산애니원고등학교");
		ComboBox_AddString(hComboBox, "백양초등학교");
		ComboBox_AddString(hComboBox, "울산공업고등학교");
		ComboBox_AddString(hComboBox, "울산대학교");
		hListBox = GetDlgItem(hWnd, IDC_LIST1);
		ListBox_AddString(hListBox, "울산애니원고등학교");
		ListBox_AddString(hListBox, "백양초등학교");
		ListBox_AddString(hListBox, "울산공업고등학교");
		ListBox_AddString(hListBox, "울산대학교");

		return (INT_PTR)TRUE;

	case WM_CLOSE:
	case WM_DESTROY:		// 다이얼로그윈도우 파괴 메시지
		EndDialog(hWnd, NULL);
		return (INT_PTR)TRUE;
	case WM_COMMAND:		// 다이얼로그윈도우 명령 메시지
		if ( LOWORD(wParam) == IDCANCEL)
		{
			EndDialog( hWnd, NULL);
		}
		switch ( LOWORD(wParam))
		{
		case IDOK:
			GetDlgItemText(hWnd, IDC_LIST1, strBuffer, 128);
			SetWindowText(hWnd, strBuffer);
			break;
		}

		return (INT_PTR)TRUE;
	}

	return (INT_PTR)FALSE;
}

int _tmain(int argc, _TCHAR* argv[])
{
	HINSTANCE hInst = GetModuleHandle(NULL);

	DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, MyDlg);

	return 0;
}

