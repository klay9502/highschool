
// 8_25View.cpp : CMy8_25View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "8_25.h"
#endif

#include "8_25Doc.h"
#include "8_25View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy8_25View

IMPLEMENT_DYNCREATE(CMy8_25View, CView)

BEGIN_MESSAGE_MAP(CMy8_25View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy8_25View ����/�Ҹ�

CMy8_25View::CMy8_25View()
: m_n(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy8_25View::~CMy8_25View()
{
}

BOOL CMy8_25View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy8_25View �׸���

void CMy8_25View::OnDraw(CDC* /*pDC*/)
{
	CMy8_25Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMy8_25View �μ�

BOOL CMy8_25View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy8_25View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy8_25View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMy8_25View ����

#ifdef _DEBUG
void CMy8_25View::AssertValid() const
{
	CView::AssertValid();
}

void CMy8_25View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy8_25Doc* CMy8_25View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy8_25Doc)));
	return (CMy8_25Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy8_25View �޽��� ó����


int CMy8_25View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	SetTimer(1, 500, NULL);
	return 0;
}


void CMy8_25View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
	KillTimer(1);
}


void CMy8_25View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	m_n++;
	
	if (m_n % 2 == 0)
	{
		dc.TextOutA(100, 100, "��õ�� ����");
		dc.TextOutA(300, 100, "                                ");
	}
	else
	{
		dc.TextOutA(300, 100, "��õ�� ����");
		dc.TextOutA(100, 100, "                                  ");
	}

	CView::OnTimer(nIDEvent);
}
