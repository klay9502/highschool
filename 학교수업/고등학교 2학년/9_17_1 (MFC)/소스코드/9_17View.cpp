
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

enum CUR
{
	XBOX,
	BALL,
	HI,
	PENCIL
};

// CMy9_17View

IMPLEMENT_DYNCREATE(CMy9_17View, CView)

BEGIN_MESSAGE_MAP(CMy9_17View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_CURSOR_XBOX, &CMy9_17View::OnCursorXbox)
	ON_COMMAND(ID_CURSOR_BALL, &CMy9_17View::OnCursorBall)
	ON_COMMAND(ID_CURSOR_HI, &CMy9_17View::OnCursorHi)
	ON_COMMAND(ID_CURSOR_PENCIL, &CMy9_17View::OnCursorPencil)
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()

// CMy9_17View construction/destruction

CMy9_17View::CMy9_17View()
: m_nCursor(0)
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

void CMy9_17View::OnDraw(CDC* /*pDC*/)
{
	CMy9_17Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
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


void CMy9_17View::OnCursorXbox()
{
	// TODO: Add your command handler code here
	m_nCursor = XBOX;
}


void CMy9_17View::OnCursorBall()
{
	// TODO: Add your command handler code here
	m_nCursor = BALL;
}


void CMy9_17View::OnCursorHi()
{
	// TODO: Add your command handler code here
	m_nCursor = HI;
}


void CMy9_17View::OnCursorPencil()
{
	// TODO: Add your command handler code here
	m_nCursor = PENCIL;
}


BOOL CMy9_17View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: Add your message handler code here and/or call default
	HCURSOR hCursor = NULL;

	switch (m_nCursor)
	{
	case XBOX:
		hCursor = AfxGetApp()->LoadCursorA(IDC_CURSOR1);
		break;
	case BALL:
		hCursor = AfxGetApp()->LoadCursorA(IDC_CURSOR2);
		break;
	case HI:
		hCursor = AfxGetApp()->LoadCursorA(IDC_CURSOR3);
		break;
	case PENCIL:
		hCursor = AfxGetApp()->LoadCursorA(IDC_CURSOR4);
		break;
	}

	SetCursor(hCursor);
	
	return TRUE;
	// return CView::OnSetCursor(pWnd, nHitTest, message);
}
