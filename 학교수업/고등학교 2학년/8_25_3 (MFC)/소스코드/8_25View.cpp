
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
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMy8_25View ����/�Ҹ�

CMy8_25View::CMy8_25View()
: m_ch(0)
, m_pt(0)
, m_value(0)
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

void CMy8_25View::OnDraw(CDC* pDC)
{
	CMy8_25Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	m_ch = (rand() % 26) + 'A'; // �빮�ڸ� �������� ����
	m_pt.x = rand() & m_rect.Width(); // x ��ǥ�� �������� ����
	m_pt.y = rand() & m_rect.Height(); // y ��ǥ�� �������� ����

	CString str;
	str.Format("%c", m_ch);
	pDC->TextOutA(m_pt.x, m_pt.y, str);

	str.Format("���� = %d", m_value);
	pDC->TextOutA(m_rect.Width() / 2 - 20, 0, str);

	SetTimer(1, 500, NULL);
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
	GetClientRect(&m_rect);
}


int CMy8_25View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	srand((unsigned)time(NULL));

	return 0;
}


void CMy8_25View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);

	dc.TextOutA(m_pt.x, m_pt.y, "    "); // ������ ���ڸ� �����ش�.

	m_pt.y += 20; // y��ǥ�� ������Ų��.

	CString str;
	str.Format("%c", m_ch); // ���ڸ� ���ڿ� ���·� ��ȯ.
	dc.TextOutA(m_pt.x, m_pt.y, str); // �ٲ� ���ڿ��� ���.

	if (m_pt.y >= m_rect.bottom)
	{
		KillTimer(1);
		if (MessageBox("�ѹ� �� �ұ��?", "���ӳ�", MB_ICONQUESTION | MB_YESNO) == IDYES)
		{
			Invalidate();
			m_value = 0;
		}
		else
		{
			PostQuitMessage(0);
		}
	}

	CView::OnTimer(nIDEvent);
}


void CMy8_25View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	if (m_ch == nChar)
	{
		m_value++;
		Invalidate();
	}

	CView::OnChar(nChar, nRepCnt, nFlags);
}
