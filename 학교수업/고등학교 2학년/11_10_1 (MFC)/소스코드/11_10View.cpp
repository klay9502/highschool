
// 11_10View.cpp : implementation of the CMy11_10View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "11_10.h"
#endif

#include "11_10Doc.h"
#include "11_10View.h"

#include "Sheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy11_10View

IMPLEMENT_DYNCREATE(CMy11_10View, CView)

BEGIN_MESSAGE_MAP(CMy11_10View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SHOW_PROPERTY, &CMy11_10View::OnShowProperty)
END_MESSAGE_MAP()

// CMy11_10View construction/destruction

CMy11_10View::CMy11_10View()
: m_str(_T(""))
{
	// TODO: add construction code here

}

CMy11_10View::~CMy11_10View()
{
}

BOOL CMy11_10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy11_10View drawing

void CMy11_10View::OnDraw(CDC* pDC)
{
	CMy11_10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	pDC->TextOutA(10, 10, m_str);
}


// CMy11_10View printing

BOOL CMy11_10View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy11_10View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy11_10View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy11_10View diagnostics

#ifdef _DEBUG
void CMy11_10View::AssertValid() const
{
	CView::AssertValid();
}

void CMy11_10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy11_10Doc* CMy11_10View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy11_10Doc)));
	return (CMy11_10Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy11_10View message handlers


void CMy11_10View::OnShowProperty()
{
	// TODO: Add your command handler code here
	CSheet dlg("Property Sheet º¸±â");
	if (dlg.DoModal() == IDOK)
	{
		m_str = dlg.m_pageHer.m_strText;
		Invalidate();
	}
}
