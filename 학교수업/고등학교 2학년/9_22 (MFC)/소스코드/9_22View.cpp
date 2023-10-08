
// 9_22View.cpp : implementation of the CMy9_22View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "9_22.h"
#endif

#include "9_22Doc.h"
#include "9_22View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy9_22View

IMPLEMENT_DYNCREATE(CMy9_22View, CView)

BEGIN_MESSAGE_MAP(CMy9_22View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_COLOR_BLACK, &CMy9_22View::OnColorBlack)
	ON_COMMAND(ID_COLOR_PICTURE, &CMy9_22View::OnColorPicture)
	ON_WM_CREATE()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy9_22View construction/destruction

CMy9_22View::CMy9_22View()
{
	// TODO: add construction code here

}

CMy9_22View::~CMy9_22View()
{
}

BOOL CMy9_22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy9_22View drawing

void CMy9_22View::OnDraw(CDC* pDC)
{
	CMy9_22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	if (m_bIsPicture)
	{
		CDC mDC;
		mDC.CreateCompatibleDC(pDC);
		CBitmap bit;
		bit.LoadBitmapA(IDB_APPLE);
		mDC.SelectObject(&bit);
		pDC->BitBlt(0, 0, 2560, 1600, &mDC, 0, 0, SRCCOPY);
	}

	if (m_bIsBlack)
	{
		CRect r;
		r.SetRect(0, 0, 1920, 1200);
		pDC->FillSolidRect(r, RGB(0, 0, 0));
	}
}


// CMy9_22View printing

BOOL CMy9_22View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy9_22View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy9_22View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy9_22View diagnostics

#ifdef _DEBUG
void CMy9_22View::AssertValid() const
{
	CView::AssertValid();
}

void CMy9_22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy9_22Doc* CMy9_22View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy9_22Doc)));
	return (CMy9_22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy9_22View message handlers


void CMy9_22View::OnColorBlack()
{
	// TODO: Add your command handler code here
	m_bIsBlack = true;
	m_bIsPicture = false;
	Invalidate();
}


void CMy9_22View::OnColorPicture()
{
	// TODO: Add your command handler code here
	m_bIsBlack = false;
	m_bIsPicture = true;
	Invalidate();
}


int CMy9_22View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	m_bIsBlack = false;
	m_bIsPicture = true;

	return 0;
}


void CMy9_22View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	if (nFlags && m_bIsBlack)
	{
		CDC mDC;
		mDC.CreateCompatibleDC(&dc);
		CBitmap bit;
		bit.LoadBitmapA(IDB_APPLE);
		mDC.SelectObject(&bit);
		dc.BitBlt(point.x - 50, point.y - 50, 100, 100, &mDC, point.x - 50, point.y - 50, SRCCOPY);
	}
	CView::OnMouseMove(nFlags, point);
}