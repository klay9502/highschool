
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
END_MESSAGE_MAP()

// CMy9_08View construction/destruction

CMy9_08View::CMy9_08View()
{
	// TODO: add construction code here

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

void CMy9_08View::OnDraw(CDC* pDC)
{
	CMy9_08Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CDC mDC;
	mDC.CreateCompatibleDC(pDC);
	CBitmap bitmap;
	bitmap.LoadBitmapA(IDB_BIT);
	mDC.SelectObject(&bitmap);
	pDC->BitBlt(150, 50, 40, 40, &mDC, 0, 0, SRCCOPY);
	pDC->StretchBlt(0, 0, 100, 100, &mDC, 0, 0, 40, 40, SRCCOPY);
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
