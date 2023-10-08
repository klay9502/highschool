
// 9_10View.cpp : implementation of the CMy9_10View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "9_10.h"
#endif

#include "9_10Doc.h"
#include "9_10View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy9_10View

IMPLEMENT_DYNCREATE(CMy9_10View, CView)

BEGIN_MESSAGE_MAP(CMy9_10View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMy9_10View construction/destruction

CMy9_10View::CMy9_10View()
: m_pt(0)
{
	// TODO: add construction code here
	m_pt = CPoint(400, 50);
}

CMy9_10View::~CMy9_10View()
{
}

BOOL CMy9_10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy9_10View drawing

void CMy9_10View::OnDraw(CDC* pDC)
{
	CMy9_10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CRect r;
	GetClientRect(&r);
	BITMAP bm;
	m_bit.GetBitmap(&bm);
	pDC->StretchBlt(0, 0, r.right, r.bottom, &m_mDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);

	pDC->BitBlt(m_pt.x, m_pt.y, 60, 60, &m_manDC, 60, 0, SRCAND);
	pDC->BitBlt(m_pt.x, m_pt.y, 60, 60, &m_manDC, 0, 0, SRCPAINT);
}


// CMy9_10View printing

BOOL CMy9_10View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy9_10View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy9_10View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy9_10View diagnostics

#ifdef _DEBUG
void CMy9_10View::AssertValid() const
{
	CView::AssertValid();
}

void CMy9_10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy9_10Doc* CMy9_10View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy9_10Doc)));
	return (CMy9_10Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy9_10View message handlers


int CMy9_10View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	CClientDC dc(this);
	m_mDC.CreateCompatibleDC(&dc);
	m_bit.LoadBitmapA(IDB_BACK);
	m_mDC.SelectObject(&m_bit);

	m_manDC.CreateCompatibleDC(&dc);
	m_manBit.LoadBitmapA(IDB_MAN);
	m_manDC.SelectObject(&m_manBit);

	return 0;
}


void CMy9_10View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	switch (nChar)
	{
	case VK_RIGHT:
		m_pt.x += 10;
		break;
	case VK_LEFT:
		m_pt.x -= 10;
		break;
	case VK_UP:
		m_pt.y -= 10;
		break;
	case VK_DOWN:
		m_pt.y += 10;
		break;
	}

	Invalidate(FALSE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
