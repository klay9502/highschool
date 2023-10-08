
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
	ON_COMMAND(ID_TEXT_BLACK, &CMy8_27View::OnTextBlack)
	ON_COMMAND(ID_TEXT_BLUE, &CMy8_27View::OnTextBlue)
	ON_COMMAND(ID_TEXT_GREEN, &CMy8_27View::OnTextGreen)
	ON_COMMAND(ID_TEXT_CYAN, &CMy8_27View::OnTextCyan)
	ON_COMMAND(ID_TEXT_RED, &CMy8_27View::OnTextRed)
	ON_COMMAND(ID_TEXT_MAGENTA, &CMy8_27View::OnTextMagenta)
	ON_COMMAND(ID_TEXT_YELLOW, &CMy8_27View::OnTextYellow)
	ON_COMMAND(ID_TEXT_USER, &CMy8_27View::OnTextUser)
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
	pDC->SetTextColor(pDoc->getColor());
	pDC->TextOutA(pDoc->getPoint().x, pDoc->getPoint().y, pDoc->getString());
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


void CMy8_27View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy8_27Doc* pDoc = GetDocument();
	pDoc->setPoint(point);

	CView::OnLButtonDown(nFlags, point);
}


void CMy8_27View::OnTextBlack()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	pDoc->setColor(RGB(0, 0, 0));
}


void CMy8_27View::OnTextBlue()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	pDoc->setColor(RGB(0, 0, 255));
}


void CMy8_27View::OnTextGreen()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	pDoc->setColor(RGB(0, 255, 0));
}


void CMy8_27View::OnTextCyan()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	pDoc->setColor(RGB(0, 255, 255));
}


void CMy8_27View::OnTextRed()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	pDoc->setColor(RGB(255, 0, 0));
}


void CMy8_27View::OnTextMagenta()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	pDoc->setColor(RGB(255, 0, 255));
}


void CMy8_27View::OnTextYellow()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	pDoc->setColor(RGB(255, 255, 0));
}


void CMy8_27View::OnTextUser()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		pDoc->setColor(dlg.GetColor());
	}
}
