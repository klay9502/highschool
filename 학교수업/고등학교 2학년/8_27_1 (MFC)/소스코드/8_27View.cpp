
// 8_27View.cpp : CMy8_27View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "8_27.h"
#endif

#include "8_27Doc.h"
#include "8_27View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy8_27View

IMPLEMENT_DYNCREATE(CMy8_27View, CView)

BEGIN_MESSAGE_MAP(CMy8_27View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy8_27View ����/�Ҹ�

CMy8_27View::CMy8_27View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy8_27View::~CMy8_27View()
{
}

BOOL CMy8_27View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy8_27View �׸���

void CMy8_27View::OnDraw(CDC* pDC)
{
	CMy8_27Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	CString str = pDoc->getString();
	CPoint pt = pDoc->getPoint();
	pDC->TextOutA(pt.x, pt.y, str);
}


// CMy8_27View �μ�

BOOL CMy8_27View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy8_27View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy8_27View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMy8_27View ����

#ifdef _DEBUG
void CMy8_27View::AssertValid() const
{
	CView::AssertValid();
}

void CMy8_27View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy8_27Doc* CMy8_27View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy8_27Doc)));
	return (CMy8_27Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy8_27View �޽��� ó����


//void CMy8_27View::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: Add your message handler code here and/or call default
//	CMy8_27Doc* pDoc = GetDocument();
//	pDoc->setPoint(point);
//	CString str;
//	str.Format("������ǥ[%d][%d]", point.x, point.y);
//	pDoc->setString(str);
//	Invalidate();
//
//	CView::OnLButtonDown(nFlags, point);
//}


void CMy8_27View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy8_27Doc* pDoc = GetDocument();
	CString str;
	str.Format("������ǥ[%d][%d]", point.x, point.y);
	pDoc->setString(str);
	Invalidate();


	CView::OnMouseMove(nFlags, point);
}
