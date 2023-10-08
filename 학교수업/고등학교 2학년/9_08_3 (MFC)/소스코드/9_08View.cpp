
// 9_08View.cpp : implementation of the CMy9_08View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "9_08.h"
#endif

#include "9_08Doc.h"
#include "9_08View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy9_08View

IMPLEMENT_DYNCREATE(CMy9_08View, CView)

BEGIN_MESSAGE_MAP(CMy9_08View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy9_08View construction/destruction

CMy9_08View::CMy9_08View()
: m_n(0)
, m_pt(0)
{
	// TODO: add construction code here
	m_pt = CPoint(100, 100);
}

CMy9_08View::~CMy9_08View()
{
}

BOOL CMy9_08View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy9_08View drawing

void CMy9_08View::OnDraw(CDC* /*pDC*/)
{
	CMy9_08Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CClientDC ScreenDC(this);
	CDC MemoryDC;

	MemoryDC.CreateCompatibleDC(&ScreenDC);	// DC간의 호환
	CBitmap bitmap;	// 내가 그린 그림 저장 변수
	this->m_n++;

	if (m_n % 2 == 1)
	{
		bitmap.LoadBitmapA(IDB_MAN1);	// 비트맵 로드
	}
	else
	{
		bitmap.LoadBitmapA(IDB_MAN2);
	}
	MemoryDC.SelectObject(&bitmap);	// 메모리DC 비트맵을 선택
	ScreenDC.StretchBlt(m_pt.x, m_pt.y, 100, 100, &MemoryDC, 0, 0, 40, 40, SRCCOPY);
}


// CMy9_08View printing

BOOL CMy9_08View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy9_08View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy9_08View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy9_08View diagnostics

#ifdef _DEBUG
void CMy9_08View::AssertValid() const
{
	CView::AssertValid();
}

void CMy9_08View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy9_08Doc* CMy9_08View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy9_08Doc)));
	return (CMy9_08Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy9_08View message handlers


int CMy9_08View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	SetTimer(1, 100, NULL);
	return 0;
}


void CMy9_08View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
	KillTimer(1);
}


void CMy9_08View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	//CClientDC ScreenDC(this);
	//CDC MemoryDC;

	//MemoryDC.CreateCompatibleDC(&ScreenDC);	// DC간의 호환
	//CBitmap bitmap;	// 내가 그린 그림 저장 변수
	//this->m_n++;

	//if (m_n % 2 == 1)
	//{
	//	bitmap.LoadBitmapA(IDB_MAN1);	// 비트맵 로드
	//}
	//else
	//{
	//	bitmap.LoadBitmapA(IDB_MAN2);
	//}
	//MemoryDC.SelectObject(&bitmap);	// 메모리DC 비트맵을 선택
	//ScreenDC.StretchBlt(m_pt.x, m_pt.y, 100, 100, &MemoryDC, 0, 0, 40, 40, SRCCOPY);

	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CMy9_08View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_pt = point;

	CView::OnLButtonDown(nFlags, point);
}
