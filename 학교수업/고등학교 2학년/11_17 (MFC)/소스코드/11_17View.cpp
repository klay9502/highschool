
// 11_17View.cpp : implementation of the CMy11_17View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "11_17.h"
#endif

#include "11_17Doc.h"
#include "11_17View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy11_17View

IMPLEMENT_DYNCREATE(CMy11_17View, CView)

BEGIN_MESSAGE_MAP(CMy11_17View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMy11_17View construction/destruction

CMy11_17View::CMy11_17View()
{
	// TODO: add construction code here

}

CMy11_17View::~CMy11_17View()
{
}

BOOL CMy11_17View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy11_17View drawing

void CMy11_17View::OnDraw(CDC* pDC)
{
	CMy11_17Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	pDC->TextOutA(5, 5, "그대로 나오는 View");
	pDC->TextOutA(5, 25, pDoc->m_str);
}


// CMy11_17View printing

BOOL CMy11_17View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy11_17View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy11_17View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy11_17View diagnostics

#ifdef _DEBUG
void CMy11_17View::AssertValid() const
{
	CView::AssertValid();
}

void CMy11_17View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy11_17Doc* CMy11_17View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy11_17Doc)));
	return (CMy11_17Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy11_17View message handlers


void CMy11_17View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CMy11_17Doc* pDoc = GetDocument();
	
	if (nChar == VK_ESCAPE)
	{
		pDoc->m_str = "";
	}
	else
	{
		pDoc->m_str += (TCHAR)nChar;
	}

	pDoc->UpdateAllViews(NULL);

	CView::OnChar(nChar, nRepCnt, nFlags);
}
