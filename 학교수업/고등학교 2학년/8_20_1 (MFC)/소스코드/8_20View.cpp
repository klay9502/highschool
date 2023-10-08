
// 8_20View.cpp : CMy8_20View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "8_20.h"
#endif

#include "8_20Doc.h"
#include "8_20View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy8_20View

IMPLEMENT_DYNCREATE(CMy8_20View, CView)

BEGIN_MESSAGE_MAP(CMy8_20View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy8_20View ����/�Ҹ�

CMy8_20View::CMy8_20View(void)
	: m_n(18)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	m_strName = "������";
}

CMy8_20View::~CMy8_20View(void)
{
	// empty...
}

BOOL CMy8_20View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy8_20View �׸���

void CMy8_20View::OnDraw(CDC* pDC)
{
	CMy8_20Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	pDC->TextOutA(100, 100, "Hello World!");
	pDC->TextOutA(100, 150, "�� �̸��� " + m_strName + "�Դϴ�.");
	CString str;
	str.Format("�� ���̴� %d�� �Դϴ�.", m_n);
	pDC->TextOutA(100, 200, str);

	Display();
}


// CMy8_20View �μ�

BOOL CMy8_20View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy8_20View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy8_20View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMy8_20View ����

#ifdef _DEBUG
void CMy8_20View::AssertValid() const
{
	CView::AssertValid();
}

void CMy8_20View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy8_20Doc* CMy8_20View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy8_20Doc)));
	return (CMy8_20Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy8_20View �޽��� ó����


void CMy8_20View::Display(void)
{
	CClientDC dc(this);
	dc.TextOutA(100, 250, "����� Display �Լ��Դϴ�.");
}


void CMy8_20View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	dc.TextOutA(point.x, point.y, "���ʹ�ư");
	CView::OnLButtonDown(nFlags, point);
}


void CMy8_20View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	dc.TextOutA(point.x, point.y, "�����ʹ�ư");
	CView::OnRButtonDown(nFlags, point);
}


void CMy8_20View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	if (nFlags == TRUE)
	{
		dc.TextOutA(point.x, point.y, "������");
	}
	CView::OnMouseMove(nFlags, point);
}
