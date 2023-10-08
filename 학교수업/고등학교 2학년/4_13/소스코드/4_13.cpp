// 4_13.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "4_13.h"

#define MAX_LOADSTRING 100
#define PS_BUTTON1     10001
#define PS_GROUP1	   11001
#define PS_CHECK1	   11011
#define PS_CHECK2	   11012
#define PS_CHECK3	   11013
#define PS_CHECK4	   11014
#define PS_GROUP2      12001
#define PS_RADIO1      12011
#define PS_RADIO2      12012
#define PS_RADIO3      12013
#define PS_RADIO4      12014
#define PS_GROUP3      13001
#define PS_RADIO5      13011
#define PS_RADIO6      13012
#define PS_RADIO7      13013
#define PS_RADIO8      13014
#define PS_EDIT1       10101
#define PS_EDIT2	   10102
#define PS_EDIT3	   10103
#define PS_EDIT4	   10104
#define PS_GROUP3      14001




// ���� ����:
HINSTANCE hInst;								// ���� �ν��Ͻ��Դϴ�.
TCHAR szTitle[MAX_LOADSTRING];					// ���� ǥ���� �ؽ�Ʈ�Դϴ�.
TCHAR szWindowClass[MAX_LOADSTRING];			// �⺻ â Ŭ���� �̸��Դϴ�.

HWND g_hWndCheck1, g_hWndCheck2, g_hWndCheck3, g_hWndCheck4;
HWND g_hWndRadio1, g_hWndRadio2, g_hWndRadio3, g_hWndRadio4,  g_hWndRadio5,  g_hWndRadio6,  g_hWndRadio7,  g_hWndRadio8;
HWND g_hWndEdit1, g_hWndEdit2, g_hWndEdit3, g_hWndEdit4;

// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: ���⿡ �ڵ带 �Է��մϴ�.
	MSG msg;
	HACCEL hAccelTable;

	// ���� ���ڿ��� �ʱ�ȭ�մϴ�.
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_MY4_13, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY4_13));

	// �⺻ �޽��� �����Դϴ�.
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  �Լ�: MyRegisterClass()
//
//  ����: â Ŭ������ ����մϴ�.
//
//  ����:
//
//    Windows 95���� �߰��� 'RegisterClassEx' �Լ����� ����
//    �ش� �ڵ尡 Win32 �ý��۰� ȣȯ�ǵ���
//    �Ϸ��� ��쿡�� �� �Լ��� ����մϴ�. �� �Լ��� ȣ���ؾ�
//    �ش� ���� ���α׷��� �����
//    '�ùٸ� ������' ���� �������� ������ �� �ֽ��ϴ�.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY4_13));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_MY4_13);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   ����: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   ����:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   CreateWindow("static", "�г�", WS_CHILD | WS_VISIBLE,
					160, 100, 40, 20,
					hWnd, (HMENU)PS_EDIT1, hInstance, NULL);
   
   g_hWndEdit1 = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_CENTER,
					200, 100, 40, 20,
					hWnd, (HMENU)PS_EDIT1, hInstance, NULL);

   CreateWindow("static", "��", WS_CHILD | WS_VISIBLE,
					280, 100, 20, 20,
					hWnd, (HMENU)PS_EDIT1, hInstance, NULL);

   g_hWndEdit2 = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_CENTER,
					300, 100, 40, 20,
					hWnd, (HMENU)PS_EDIT2, hInstance, NULL);

   CreateWindow("static", "��ȣ", WS_CHILD | WS_VISIBLE,
					380, 100, 40, 20,
					hWnd, (HMENU)PS_EDIT1, hInstance, NULL);

   g_hWndEdit3 = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_CENTER,
					420, 100, 40, 20,
					hWnd, (HMENU)PS_EDIT3, hInstance, NULL);

   CreateWindow("static", "�̸�", WS_CHILD | WS_VISIBLE,
					500, 100, 40, 20,
					hWnd, (HMENU)PS_EDIT1, hInstance, NULL);

   g_hWndEdit4 = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_CENTER,
					540, 100, 100, 20,
					hWnd, (HMENU)PS_EDIT4, hInstance, NULL);

   CreateWindow("button", "����", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
					630, 150, 80, 30,
					hWnd, (HMENU)PS_BUTTON1, hInstance, NULL);
   /*CreateWindow("button", "�� ����� ��ư", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
					100, 140, 120, 30,
					hWnd, (HMENU)PS_BUTTON2, hInstance, NULL);*/
   CreateWindow("button", "�����ϴ� ����", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
					70, 200, 200, 150,
					hWnd, (HMENU)PS_GROUP1, hInstance, NULL);
   CreateWindow("button", "�����ϴ� ����", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
					300, 200, 200, 150,
					hWnd, (HMENU)PS_GROUP2, hInstance, NULL);
   CreateWindow("button", "�Ⱦ��ϴ� ����", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
					530, 200, 200, 150,
					hWnd, (HMENU)PS_GROUP3, hInstance, NULL);
   CreateWindow("button", "", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
					70, 370, 660, 200,
					hWnd, (HMENU)PS_GROUP3, hInstance, NULL);

   g_hWndCheck1 = CreateWindow("button", "��������������", WS_CHILD | WS_VISIBLE | BS_CHECKBOX,
					80, 220, 150, 30,
					hWnd, (HMENU)PS_CHECK1, hInstance, NULL);
   g_hWndCheck2 = CreateWindow("button", "�б��޽� ��Ŭ", WS_CHILD | WS_VISIBLE | BS_CHECKBOX,
					80, 250, 150, 30,
					hWnd, (HMENU)PS_CHECK2, hInstance, NULL);
   g_hWndCheck3 = CreateWindow("button", "�Ľ�¯���÷�", WS_CHILD | WS_VISIBLE | BS_CHECKBOX,
					80, 280, 150, 30,
					hWnd, (HMENU)PS_CHECK3, hInstance, NULL);
   g_hWndCheck4 = CreateWindow("button", "��ŭ��ŭ����", WS_CHILD | WS_VISIBLE | BS_CHECKBOX,
					80, 310, 150, 30,
					hWnd, (HMENU)PS_CHECK4, hInstance, NULL);

   g_hWndRadio1 = CreateWindow("button", "C ���", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
					310, 220, 150, 30,
					hWnd, (HMENU)PS_RADIO1, hInstance, NULL);
   g_hWndRadio2 = CreateWindow("button", "C++ ���", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
					310, 250, 150, 30,
					hWnd, (HMENU)PS_RADIO2, hInstance, NULL);
   g_hWndRadio3 = CreateWindow("button", "���α׷���", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
					310, 280, 150, 30,
					hWnd, (HMENU)PS_RADIO3, hInstance, NULL);
   g_hWndRadio4 = CreateWindow("button", "���� ���α׷���", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
					310, 310, 150, 30,
					hWnd, (HMENU)PS_RADIO4, hInstance, NULL);

   g_hWndRadio5 = CreateWindow("button", "����", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
					540, 220, 150, 30,
					hWnd, (HMENU)PS_RADIO5, hInstance, NULL);
   g_hWndRadio6 = CreateWindow("button", "����", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
					540, 250, 150, 30,
					hWnd, (HMENU)PS_RADIO6, hInstance, NULL);
   g_hWndRadio7 = CreateWindow("button", "����", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
					540, 280, 150, 30,
					hWnd, (HMENU)PS_RADIO7, hInstance, NULL);
   g_hWndRadio8 = CreateWindow("button", "�̼�", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
					540, 310, 150, 30,
					hWnd, (HMENU)PS_RADIO8, hInstance, NULL);

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����: �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND	- ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT	- �� â�� �׸��ϴ�.
//  WM_DESTROY	- ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR strGrade[128];

	switch (message)
	{
	case WM_CREATE:
		break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// �޴� ������ ���� �м��մϴ�.
		switch (wmId)
		{
		case PS_BUTTON1:
			hdc = GetDC(hWnd);
			switch(wmEvent)
			{
			case EN_CHANGE:
				GetWindowText(g_hWndEdit1, strGrade, 128);
				SetWindowText(hWnd, strGrade);
				break;
			}
			TextOut(hdc, 0, 0, strGrade, strlen(strGrade));
			ReleaseDC(hWnd, hdc);
			break;
		case PS_CHECK1:
			if (SendMessage(g_hWndCheck1, BM_GETCHECK, 0, 0) == BST_UNCHECKED)
			{
				SendMessage(g_hWndCheck1, BM_SETCHECK, BST_CHECKED, 0);
			}
			else
			{
				SendMessage(g_hWndCheck1, BM_SETCHECK, BST_UNCHECKED, 0);
			}
			break;
		case PS_CHECK2:
			if (SendMessage(g_hWndCheck2, BM_GETCHECK, 0, 0) == BST_UNCHECKED)
			{
				SendMessage(g_hWndCheck2, BM_SETCHECK, BST_CHECKED, 0);
			}
			else
			{
				SendMessage(g_hWndCheck2, BM_SETCHECK, BST_UNCHECKED, 0);
			}
			break;
		case PS_CHECK3:
			if (SendMessage(g_hWndCheck3, BM_GETCHECK, 0, 0) == BST_UNCHECKED)
			{
				SendMessage(g_hWndCheck3, BM_SETCHECK, BST_CHECKED, 0);
			}
			else
			{
				SendMessage(g_hWndCheck3, BM_SETCHECK, BST_UNCHECKED, 0);
			}
			break;
		case PS_CHECK4:
			if (SendMessage(g_hWndCheck4, BM_GETCHECK, 0, 0) == BST_UNCHECKED)
			{
				SendMessage(g_hWndCheck4, BM_SETCHECK, BST_CHECKED, 0);
			}
			else
			{
				SendMessage(g_hWndCheck4, BM_SETCHECK, BST_UNCHECKED, 0);
			}
			break;
		case PS_RADIO1:
			CheckRadioButton(hWnd, PS_RADIO1, PS_RADIO4, PS_RADIO1);
			break;
		case PS_RADIO2:
			CheckRadioButton(hWnd, PS_RADIO1, PS_RADIO4, PS_RADIO2);
			break;
		case PS_RADIO3:
			CheckRadioButton(hWnd, PS_RADIO1, PS_RADIO4, PS_RADIO3);
			break;
		case PS_RADIO4:
			CheckRadioButton(hWnd, PS_RADIO1, PS_RADIO4, PS_RADIO4);
			break;
		case PS_RADIO5:
			CheckRadioButton(hWnd, PS_RADIO5, PS_RADIO8, PS_RADIO5);
			break;
		case PS_RADIO6:
			CheckRadioButton(hWnd, PS_RADIO5, PS_RADIO8, PS_RADIO6);
			break;
		case PS_RADIO7:
			CheckRadioButton(hWnd, PS_RADIO5, PS_RADIO8, PS_RADIO7);
			break;
		case PS_RADIO8:
			CheckRadioButton(hWnd, PS_RADIO5, PS_RADIO8, PS_RADIO8);
			break;
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
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
	return (INT_PTR)FALSE;
}
