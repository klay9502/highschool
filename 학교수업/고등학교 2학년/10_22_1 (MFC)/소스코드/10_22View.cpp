
// 10_22View.cpp : implementation of the CMy10_22View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "10_22.h"
#endif

#include "10_22Doc.h"
#include "10_22View.h"
#include "Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy10_22View

IMPLEMENT_DYNCREATE(CMy10_22View, CView)

BEGIN_MESSAGE_MAP(CMy10_22View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_DIALOG_SHOW, &CMy10_22View::OnDialogShow)
END_MESSAGE_MAP()

// CMy10_22View construction/destruction

CMy10_22View::CMy10_22View()
{
	// TODO: add construction code here

}

CMy10_22View::~CMy10_22View()
{
}

BOOL CMy10_22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy10_22View drawing

void CMy10_22View::OnDraw(CDC* /*pDC*/)
{
	CMy10_22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMy10_22View printing

BOOL CMy10_22View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy10_22View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy10_22View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy10_22View diagnostics

#ifdef _DEBUG
void CMy10_22View::AssertValid() const
{
	CView::AssertValid();
}

void CMy10_22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy10_22Doc* CMy10_22View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy10_22Doc)));
	return (CMy10_22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy10_22View message handlers


void CMy10_22View::OnDialogShow()
{
	// TODO: Add your command handler code here
	CDlg dlg;
	dlg.DoModal();
}
