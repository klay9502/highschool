
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
END_MESSAGE_MAP()

// CMy9_10View construction/destruction

CMy9_10View::CMy9_10View()
{
	// TODO: add construction code here

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

void CMy9_10View::OnDraw(CDC* /*pDC*/)
{
	CMy9_10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
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
	UINT nID[6] = { IDB_PIC1, IDB_PIC2, IDB_PIC3, IDB_PIC4, IDB_PIC5, IDB_PIC6 };

	for (int i = 0; i < 6; i++)
	{
		m_mDC[i].CreateCompatibleDC(&dc);
		m_bit[i].LoadBitmapA(nID[i]);
		m_mDC[i].SelectObject(&m_bit[i]);

	}
	return 0;
}
