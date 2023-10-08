
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
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

CRect rect;

// CMy8_25View ����/�Ҹ�

CMy8_25View::CMy8_25View()
: m_char(0)
, m_pt(CPoint(100, 50))
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	m_char = 'I';
	m_nMove = 5;
}

CMy8_25View::~CMy8_25View(void)
{
	// empty...
}

BOOL CMy8_25View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy8_25View �׸���

void CMy8_25View::OnDraw(CDC* pDC)
{
	CMy8_25Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	CString str;
	str.Format("%c", m_char);
	pDC->TextOutA(m_pt.x, m_pt.y, str);

	GetClientRect(&rect);

	str.Format("�ӵ� = %d", m_nMove);
	pDC->TextOutA(rect.right / 2 - 30, 0, str);
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


void CMy8_25View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	m_pt.x = cx / 2;
	m_pt.y = cy / 2;
}


void CMy8_25View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	// ������ ũ�Ⱚ�� rect�� ��ȯ
	GetClientRect(&rect);

	switch (nChar)
	{
	case VK_LEFT:
		m_pt.x -= m_nMove;
		if (m_pt.x <= rect.left /*0*/)
		{
			m_pt.x = rect.right;
		}
		break;
	case VK_RIGHT:
		m_pt.x += m_nMove;
		if (m_pt.x >= rect.right)
		{
			m_pt.x = rect.left;
		}
		break;
	case VK_UP:
		m_pt.y -= m_nMove;
		if (m_pt.y <= rect.top)
		{
			m_pt.y = rect.bottom;
		}
		break;
	case VK_DOWN:
		m_pt.y += m_nMove;
		if (m_pt.y >= rect.bottom)
		{
			m_pt.y = rect.top;
		}
		break;
	}

	// �����찡 �ٽ� �׷����� �� �ʿ䰡 ���� �� ���Ǵ� �Լ�.
	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy8_25View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	if (nChar >= '0' && nChar <= '9')
	{
		m_nMove = nChar - '0';
	}
	else
	{
		m_char = nChar;
	}

	// �����찡 �ٽ� �׷����� �� �ʿ䰡 ���� �� ���Ǵ� �Լ�. // ���൵ ��.
	Invalidate();

	CView::OnChar(nChar, nRepCnt, nFlags);
}
