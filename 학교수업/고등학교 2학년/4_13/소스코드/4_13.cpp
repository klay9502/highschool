// 4_13.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
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




// 전역 변수:
HINSTANCE hInst;								// 현재 인스턴스입니다.
TCHAR szTitle[MAX_LOADSTRING];					// 제목 표시줄 텍스트입니다.
TCHAR szWindowClass[MAX_LOADSTRING];			// 기본 창 클래스 이름입니다.

HWND g_hWndCheck1, g_hWndCheck2, g_hWndCheck3, g_hWndCheck4;
HWND g_hWndRadio1, g_hWndRadio2, g_hWndRadio3, g_hWndRadio4,  g_hWndRadio5,  g_hWndRadio6,  g_hWndRadio7,  g_hWndRadio8;
HWND g_hWndEdit1, g_hWndEdit2, g_hWndEdit3, g_hWndEdit4;

// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
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

 	// TODO: 여기에 코드를 입력합니다.
	MSG msg;
	HACCEL hAccelTable;

	// 전역 문자열을 초기화합니다.
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_MY4_13, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 응용 프로그램 초기화를 수행합니다.
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY4_13));

	// 기본 메시지 루프입니다.
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
//  함수: MyRegisterClass()
//
//  목적: 창 클래스를 등록합니다.
//
//  설명:
//
//    Windows 95에서 추가된 'RegisterClassEx' 함수보다 먼저
//    해당 코드가 Win32 시스템과 호환되도록
//    하려는 경우에만 이 함수를 사용합니다. 이 함수를 호출해야
//    해당 응용 프로그램에 연결된
//    '올바른 형식의' 작은 아이콘을 가져올 수 있습니다.
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
//   함수: InitInstance(HINSTANCE, int)
//
//   목적: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   설명:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   CreateWindow("static", "학년", WS_CHILD | WS_VISIBLE,
					160, 100, 40, 20,
					hWnd, (HMENU)PS_EDIT1, hInstance, NULL);
   
   g_hWndEdit1 = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_CENTER,
					200, 100, 40, 20,
					hWnd, (HMENU)PS_EDIT1, hInstance, NULL);

   CreateWindow("static", "반", WS_CHILD | WS_VISIBLE,
					280, 100, 20, 20,
					hWnd, (HMENU)PS_EDIT1, hInstance, NULL);

   g_hWndEdit2 = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_CENTER,
					300, 100, 40, 20,
					hWnd, (HMENU)PS_EDIT2, hInstance, NULL);

   CreateWindow("static", "번호", WS_CHILD | WS_VISIBLE,
					380, 100, 40, 20,
					hWnd, (HMENU)PS_EDIT1, hInstance, NULL);

   g_hWndEdit3 = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_CENTER,
					420, 100, 40, 20,
					hWnd, (HMENU)PS_EDIT3, hInstance, NULL);

   CreateWindow("static", "이름", WS_CHILD | WS_VISIBLE,
					500, 100, 40, 20,
					hWnd, (HMENU)PS_EDIT1, hInstance, NULL);

   g_hWndEdit4 = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_CENTER,
					540, 100, 100, 20,
					hWnd, (HMENU)PS_EDIT4, hInstance, NULL);

   CreateWindow("button", "결정", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
					630, 150, 80, 30,
					hWnd, (HMENU)PS_BUTTON1, hInstance, NULL);
   /*CreateWindow("button", "글 지우기 버튼", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
					100, 140, 120, 30,
					hWnd, (HMENU)PS_BUTTON2, hInstance, NULL);*/
   CreateWindow("button", "좋아하는 음식", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
					70, 200, 200, 150,
					hWnd, (HMENU)PS_GROUP1, hInstance, NULL);
   CreateWindow("button", "좋아하는 과목", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
					300, 200, 200, 150,
					hWnd, (HMENU)PS_GROUP2, hInstance, NULL);
   CreateWindow("button", "싫어하는 과목", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
					530, 200, 200, 150,
					hWnd, (HMENU)PS_GROUP3, hInstance, NULL);
   CreateWindow("button", "", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
					70, 370, 660, 200,
					hWnd, (HMENU)PS_GROUP3, hInstance, NULL);

   g_hWndCheck1 = CreateWindow("button", "예전에먹은피자", WS_CHILD | WS_VISIBLE | BS_CHECKBOX,
					80, 220, 150, 30,
					hWnd, (HMENU)PS_CHECK1, hInstance, NULL);
   g_hWndCheck2 = CreateWindow("button", "학교급식 피클", WS_CHILD | WS_VISIBLE | BS_CHECKBOX,
					80, 250, 150, 30,
					hWnd, (HMENU)PS_CHECK2, hInstance, NULL);
   g_hWndCheck3 = CreateWindow("button", "후식짱요플레", WS_CHILD | WS_VISIBLE | BS_CHECKBOX,
					80, 280, 150, 30,
					hWnd, (HMENU)PS_CHECK3, hInstance, NULL);
   g_hWndCheck4 = CreateWindow("button", "상큼상큼과일", WS_CHILD | WS_VISIBLE | BS_CHECKBOX,
					80, 310, 150, 30,
					hWnd, (HMENU)PS_CHECK4, hInstance, NULL);

   g_hWndRadio1 = CreateWindow("button", "C 언어", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
					310, 220, 150, 30,
					hWnd, (HMENU)PS_RADIO1, hInstance, NULL);
   g_hWndRadio2 = CreateWindow("button", "C++ 언어", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
					310, 250, 150, 30,
					hWnd, (HMENU)PS_RADIO2, hInstance, NULL);
   g_hWndRadio3 = CreateWindow("button", "프로그래밍", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
					310, 280, 150, 30,
					hWnd, (HMENU)PS_RADIO3, hInstance, NULL);
   g_hWndRadio4 = CreateWindow("button", "게임 프로그래밍", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
					310, 310, 150, 30,
					hWnd, (HMENU)PS_RADIO4, hInstance, NULL);

   g_hWndRadio5 = CreateWindow("button", "문학", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
					540, 220, 150, 30,
					hWnd, (HMENU)PS_RADIO5, hInstance, NULL);
   g_hWndRadio6 = CreateWindow("button", "수학", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
					540, 250, 150, 30,
					hWnd, (HMENU)PS_RADIO6, hInstance, NULL);
   g_hWndRadio7 = CreateWindow("button", "영어", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
					540, 280, 150, 30,
					hWnd, (HMENU)PS_RADIO7, hInstance, NULL);
   g_hWndRadio8 = CreateWindow("button", "미술", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
					540, 310, 150, 30,
					hWnd, (HMENU)PS_RADIO8, hInstance, NULL);

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  목적: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND	- 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT	- 주 창을 그립니다.
//  WM_DESTROY	- 종료 메시지를 게시하고 반환합니다.
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
		// 메뉴 선택을 구문 분석합니다.
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
		// TODO: 여기에 그리기 코드를 추가합니다.
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

// 정보 대화 상자의 메시지 처리기입니다.
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
