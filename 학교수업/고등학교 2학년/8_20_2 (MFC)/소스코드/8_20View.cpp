
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
	ON_COMMAND(ID_TEACHER1, &CMy8_20View::OnTeacher1)
	ON_COMMAND(ID_STUDENT1, &CMy8_20View::OnStudent1)
	ON_COMMAND(ID_TEACHER2, &CMy8_20View::OnTeacher2)
	ON_COMMAND(ID_STUDENT2, &CMy8_20View::OnStudent2)
	ON_COMMAND(ID_TEACHER3, &CMy8_20View::OnTeacher3)
	ON_COMMAND(ID_STUDENT3, &CMy8_20View::OnStudent3)
END_MESSAGE_MAP()

// CMy8_20View ����/�Ҹ�

CMy8_20View::CMy8_20View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy8_20View::~CMy8_20View()
{
}

BOOL CMy8_20View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy8_20View �׸���

void CMy8_20View::OnDraw(CDC* /*pDC*/)
{
	CMy8_20Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
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


void CMy8_20View::OnTeacher1()
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	dc.TextOutA(100, 50, "1�г� ���� Ȳ���� ������");
}


void CMy8_20View::OnStudent1()
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	dc.TextOutA(100, 100, "1�г� ���� �̹α�");
}


void CMy8_20View::OnTeacher2()
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	dc.TextOutA(100, 250, "2�г� ���� ����� ������");
}


void CMy8_20View::OnStudent2()
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	dc.TextOutA(100, 300, "2�г� ���� ������");
}


void CMy8_20View::OnTeacher3()
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	dc.TextOutA(100, 450, "3�г� ���� ������ ������");
}


void CMy8_20View::OnStudent3()
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	dc.TextOutA(100, 500, "3�г� ���� �̿���");
}
