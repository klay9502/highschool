
// 9_17View.cpp : implementation of the CMy9_17View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "9_17.h"
#endif

#include "9_17Doc.h"
#include "9_17View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy9_17View

IMPLEMENT_DYNCREATE(CMy9_17View, CView)

BEGIN_MESSAGE_MAP(CMy9_17View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()

// CMy9_17View construction/destruction

CMy9_17View::CMy9_17View()
{
	// TODO: add construction code here

}

CMy9_17View::~CMy9_17View()
{
}

BOOL CMy9_17View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy9_17View drawing

void CMy9_17View::OnDraw(CDC* pDC)
{
	CMy9_17Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CRect r;
	GetClientRect(&r);

	r1.SetRect(0, 0, r.Width() / 2, r.Height() / 2);
	r2.SetRect(r.Width() / 2, 0, r.Width(), r.Height() / 2);
	r3.SetRect(0, r.Height() / 2, r.Width() / 2, r.Height());
	r4.SetRect(r.Width() / 2, r.Height() / 2, r.Width(), r.Height());

	pDC->FillSolidRect(r1, RGB(255, 255, 0));
	pDC->FillSolidRect(r2, RGB(255, 0, 255));
	pDC->FillSolidRect(r3, RGB(0, 255, 255));
	pDC->FillSolidRect(r4, RGB(0, 0, 255));

	pDC->SetBkColor(RGB(255, 255, 255));

	pDC->DrawText("Cross", r1, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	pDC->DrawText("Arrow", r2, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	pDC->DrawText("Wait", r3, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	pDC->DrawText("Hand", r4, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

}


// CMy9_17View printing

BOOL CMy9_17View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy9_17View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy9_17View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy9_17View diagnostics

#ifdef _DEBUG
void CMy9_17View::AssertValid() const
{
	CView::AssertValid();
}

void CMy9_17View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy9_17Doc* CMy9_17View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy9_17Doc)));
	return (CMy9_17Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy9_17View message handlers


int CMy9_17View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	hArrow = AfxGetApp()->LoadCursorA(IDC_CURSOR2);
	hCross = AfxGetApp()->LoadCursorA(IDC_CURSOR1);
	hWait = AfxGetApp()->LoadCursorA(IDC_CURSOR3);
	hHand = AfxGetApp()->LoadCursorA(IDC_CURSOR4);

	return 0;
}


BOOL CMy9_17View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: Add your message handler code here and/or call default
	GetCursorPos(&m_pt);
	ScreenToClient(&m_pt);
	
	if (r1.PtInRect(m_pt))
	{
		SetCursor(hCross);
	}
	else if (r2.PtInRect(m_pt))
	{
		SetCursor(hArrow);
	}
	else if (r3.PtInRect(m_pt))
	{
		SetCursor(hWait);
	}
	else if (r4.PtInRect(m_pt))
	{
		SetCursor(hHand);
	}
	else
	{
		return CView::OnSetCursor(pWnd, nHitTest, message);
	}
}
