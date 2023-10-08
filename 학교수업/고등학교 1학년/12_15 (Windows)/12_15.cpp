// 12_15.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	case WM_INITDIALOG:		// ���̾�α������� �ʱ�ȭ �޽���
		hComboBox = GetDlgItem(hWnd, IDC_COMBO1);
		ComboBox_AddString(hComboBox, "���ִϿ�����б�");
		ComboBox_AddString(hComboBox, "����ʵ��б�");
		ComboBox_AddString(hComboBox, "����������б�");
		ComboBox_AddString(hComboBox, "�����б�");
		hListBox = GetDlgItem(hWnd, IDC_LIST1);
		ListBox_AddString(hListBox, "���ִϿ�����б�");
		ListBox_AddString(hListBox, "����ʵ��б�");
		ListBox_AddString(hListBox, "����������б�");
		ListBox_AddString(hListBox, "�����б�");

		return (INT_PTR)TRUE;

	case WM_CLOSE:
	case WM_DESTROY:		// ���̾�α������� �ı� �޽���
		EndDialog(hWnd, NULL);
		return (INT_PTR)TRUE;
	case WM_COMMAND:		// ���̾�α������� ��� �޽���
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

