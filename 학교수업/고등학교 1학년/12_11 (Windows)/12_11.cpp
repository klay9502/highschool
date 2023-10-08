// 12_11.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

INT_PTR CALLBACK DlgTest(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	char	strBuffer[128];
	char	strTemp[128];
	int		nGrade;
	int		nClass;
	int		nNumber;

	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_CLOSE:
	case WM_DESTROY:
		EndDialog ( hWnd, LOWORD(wParam) );
		break;
	case WM_COMMAND:
		switch ( LOWORD(wParam) )
		{
		case IDOK:
			GetDlgItemText( hWnd, IDC_EDIT1, strTemp, 128);
			strcpy( strBuffer, strTemp);
			sprintf(strTemp, "\n");
			strcat( strBuffer, strTemp);
			GetDlgItemText( hWnd, IDC_EDIT2, strTemp, 128);
			strcat( strBuffer, strTemp);
			sprintf(strTemp, "\n");
			strcat( strBuffer, strTemp);
			nGrade = GetDlgItemInt( hWnd, IDC_EDIT3, NULL, false);
			nClass = GetDlgItemInt( hWnd, IDC_EDIT4, NULL, false);
			nNumber = GetDlgItemInt( hWnd, IDC_EDIT5, NULL, false);
			sprintf( strTemp, "%d학년 %d반 %d번\n", nGrade, nClass, nNumber);
			strcat( strBuffer, strTemp);
			GetDlgItemText( hWnd, IDC_EDIT6, strTemp, 128);
			strcat( strBuffer, strTemp);
			SetDlgItemText( hWnd, IDC_OUTPUT, strBuffer);
			break;
		case IDCANCEL:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

int _tmain(int argc, _TCHAR* argv[])
{
	HINSTANCE hInst = GetModuleHandle( NULL );

	DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgTest );

	return 0;
}

