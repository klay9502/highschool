
// 9_03View.cpp : implementation of the CMy9_03View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "9_03.h"
#endif

#include "9_03Doc.h"
#include "9_03View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define STEP 5
#define R 20


// CMy9_03View

IMPLEMENT_DYNCREATE(CMy9_03View, CView)

BEGIN_MESSAGE_MAP(CMy9_03View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_PRINT_START, &CMy9_03View::OnPrintStart)
	ON_COMMAND(ID_PRINT_STOP, &CMy9_03View::OnPrintStop)
END_MESSAGE_MAP()

// CMy9_03View construction/destruction

CMy9_03View::CMy9_03View()
: nX(0)
, nY(0)
{
	// TODO: add construction code here
	nX = nY = R;
	nMx = nMy = STEP;
}

CMy9_03View::~CMy9_03View()
{
}

BOOL CMy9_03View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy9_03View drawing

void CMy9_03View::OnDraw(CDC* /*pDC*/)
{
	CMy9_03Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMy9_03View printing

BOOL CMy9_03View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy9_03View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy9_03View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy9_03View diagnostics

#ifdef _DEBUG
void CMy9_03View::AssertValid() const
{
	CView::AssertValid();
}

void CMy9_03View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy9_03Doc* CMy9_03View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy9_03Doc)));
	return (CMy9_03Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy9_03View message handlers


int CMy9_03View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	SetTimer(1, 10, NULL);
	return 0;
}


void CMy9_03View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
	KillTimer(1);
}


void CMy9_03View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CRect rect;
	GetClientRect(&rect);

	CBrush brush, *pOldB;
	brush.CreateSolidBrush(RGB(255, 255, 255));
	pOldB = dc.SelectObject(&brush);
	dc.SelectStockObject(WHITE_PEN);
	dc.SelectObject(pOldB);

	dc.Ellipse(nX - R, nY - R, nX + R, nY + R);

	nX += nMx;
	nY += nMy;

	if (nY + R >= rect.bottom)
	{
		nMy = -STEP;
	}

	if (nY - R <= rect.top)
	{
		nMy = STEP;
	}

	if (nX + R >= rect.right)
	{
		nMx = -STEP;
	}

	if (nX - R <= rect.left)
	{
		nMx = STEP;
	}

	CBrush redB;
	redB.CreateSolidBrush(RGB(255, 0, 0));
	dc.SelectObject(&redB);
	dc.SelectStockObject(BLACK_PEN);
	dc.Ellipse(nX - R, nY - R, nX + R, nY + R);

	CView::OnTimer(nIDEvent);
}


void CMy9_03View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMenu menu, *pSub;
	menu.LoadMenu(IDR_MAINFRAME);
	pSub = menu.GetSubMenu(4);
	CPoint ptMenu = point;
	ClientToScreen(&ptMenu);
	pSub->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, ptMenu.x, ptMenu.y, this);

	CView::OnRButtonDown(nFlags, point);
}


void CMy9_03View::OnPrintStart()
{
	// TODO: Add your command handler code here
	SetTimer(1, 10, NULL);
}


void CMy9_03View::OnPrintStop()
{
	// TODO: Add your command handler code here
	KillTimer(1);
}
