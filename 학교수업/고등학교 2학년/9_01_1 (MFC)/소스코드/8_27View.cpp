
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
	ON_COMMAND(ID_BACK_BLACK, &CMy8_27View::OnBackBlack)
	ON_COMMAND(ID_BACK_BLUE, &CMy8_27View::OnBackBlue)
	ON_COMMAND(ID_BACK_GREEN, &CMy8_27View::OnBackGreen)
	ON_COMMAND(ID_BACK_CYAN, &CMy8_27View::OnBackCyan)
	ON_COMMAND(ID_BACK_RED, &CMy8_27View::OnBackRed)
	ON_COMMAND(ID_BACK_MAGENTA, &CMy8_27View::OnBackMagenta)
	ON_COMMAND(ID_BACK_YELLOW, &CMy8_27View::OnBackYellow)
	ON_COMMAND(ID_BACK_WHITE, &CMy8_27View::OnBackWhite)
	ON_COMMAND(ID_BACK_USER, &CMy8_27View::OnBackUser)
	ON_UPDATE_COMMAND_UI(ID_TEXT_BLACK, &CMy8_27View::OnUpdateTextBlack)
	ON_UPDATE_COMMAND_UI(ID_TEXT_BLUE, &CMy8_27View::OnUpdateTextBlue)
	ON_UPDATE_COMMAND_UI(ID_TEXT_GREEN, &CMy8_27View::OnUpdateTextGreen)
	ON_UPDATE_COMMAND_UI(ID_TEXT_CYAN, &CMy8_27View::OnUpdateTextCyan)
	ON_UPDATE_COMMAND_UI(ID_TEXT_RED, &CMy8_27View::OnUpdateTextRed)
	ON_UPDATE_COMMAND_UI(ID_TEXT_MAGENTA, &CMy8_27View::OnUpdateTextMagenta)
	ON_UPDATE_COMMAND_UI(ID_TEXT_YELLOW, &CMy8_27View::OnUpdateTextYellow)
	ON_UPDATE_COMMAND_UI(ID_TEXT_USER, &CMy8_27View::OnUpdateTextUser)
	ON_UPDATE_COMMAND_UI(ID_BACK_BLACK, &CMy8_27View::OnUpdateBackBlack)
	ON_UPDATE_COMMAND_UI(ID_BACK_BLUE, &CMy8_27View::OnUpdateBackBlue)
	ON_UPDATE_COMMAND_UI(ID_BACK_GREEN, &CMy8_27View::OnUpdateBackGreen)
	ON_UPDATE_COMMAND_UI(ID_BACK_CYAN, &CMy8_27View::OnUpdateBackCyan)
	ON_UPDATE_COMMAND_UI(ID_BACK_RED, &CMy8_27View::OnUpdateBackRed)
	ON_UPDATE_COMMAND_UI(ID_BACK_MAGENTA, &CMy8_27View::OnUpdateBackMagenta)
	ON_UPDATE_COMMAND_UI(ID_BACK_YELLOW, &CMy8_27View::OnUpdateBackYellow)
	ON_UPDATE_COMMAND_UI(ID_BACK_WHITE, &CMy8_27View::OnUpdateBackWhite)
	ON_UPDATE_COMMAND_UI(ID_BACK_USER, &CMy8_27View::OnUpdateBackUser)
END_MESSAGE_MAP()

// CMy8_27View ����/�Ҹ�

CMy8_27View::CMy8_27View()
: m_nCheck(1)
, m_nRadio(6)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	m_crBk = RGB(255, 255, 0);
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
	pDC->SetBkColor(m_crBk);
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
	m_nCheck = 0;
}


void CMy8_27View::OnTextBlue()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	pDoc->setColor(RGB(0, 0, 255));
	m_nCheck = 1;
}


void CMy8_27View::OnTextGreen()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	pDoc->setColor(RGB(0, 255, 0));
	m_nCheck = 2;
}


void CMy8_27View::OnTextCyan()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	pDoc->setColor(RGB(0, 255, 255));
	m_nCheck = 3;
}


void CMy8_27View::OnTextRed()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	pDoc->setColor(RGB(255, 0, 0));
	m_nCheck = 4;
}


void CMy8_27View::OnTextMagenta()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	pDoc->setColor(RGB(255, 0, 255));
	m_nCheck = 5;
}


void CMy8_27View::OnTextYellow()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	pDoc->setColor(RGB(255, 255, 0));
	m_nCheck = 6;
}


void CMy8_27View::OnTextUser()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		pDoc->setColor(dlg.GetColor());
		m_nCheck = 7;
	}
}


void CMy8_27View::OnBackBlack()
{
	// TODO: Add your command handler code here
	m_crBk = RGB(0, 0, 0);
	m_nRadio = 0;
	Invalidate();
}


void CMy8_27View::OnBackBlue()
{
	// TODO: Add your command handler code here
	m_crBk = RGB(0, 0, 255);
	m_nRadio = 1;
	Invalidate();
}


void CMy8_27View::OnBackGreen()
{
	// TODO: Add your command handler code here
	m_crBk = RGB(0, 255, 0);
	m_nRadio = 2;
	Invalidate();
}


void CMy8_27View::OnBackCyan()
{
	// TODO: Add your command handler code here
	m_crBk = RGB(0, 255, 255);
	m_nRadio = 3;
	Invalidate();
}


void CMy8_27View::OnBackRed()
{
	// TODO: Add your command handler code here
	m_crBk = RGB(255, 0, 0);
	m_nRadio = 4;
	Invalidate();
}


void CMy8_27View::OnBackMagenta()
{
	// TODO: Add your command handler code here
	m_crBk = RGB(255, 0, 255);
	m_nRadio = 5;
	Invalidate();
}


void CMy8_27View::OnBackYellow()
{
	// TODO: Add your command handler code here
	m_crBk = RGB(255, 255, 0);
	m_nRadio = 6;
	Invalidate();
}


void CMy8_27View::OnBackWhite()
{
	// TODO: Add your command handler code here
	m_crBk = RGB(255, 255, 255);
	m_nRadio = 7;
	Invalidate();
}


void CMy8_27View::OnBackUser()
{
	// TODO: Add your command handler code here
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		m_crBk = dlg.GetColor();
		m_nRadio = 8;
	}
	Invalidate();
}


void CMy8_27View::OnUpdateTextBlack(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nCheck == 0);
}


void CMy8_27View::OnUpdateTextBlue(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nCheck == 1);
}


void CMy8_27View::OnUpdateTextGreen(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nCheck == 2);
}


void CMy8_27View::OnUpdateTextCyan(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nCheck == 3);
}


void CMy8_27View::OnUpdateTextRed(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nCheck == 4);
}


void CMy8_27View::OnUpdateTextMagenta(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nCheck == 5);
}


void CMy8_27View::OnUpdateTextYellow(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nCheck == 6);
}


void CMy8_27View::OnUpdateTextUser(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nCheck == 7);
}


void CMy8_27View::OnUpdateBackBlack(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_nRadio == 0);
}


void CMy8_27View::OnUpdateBackBlue(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_nRadio == 1);
}


void CMy8_27View::OnUpdateBackGreen(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_nRadio == 2);
}


void CMy8_27View::OnUpdateBackCyan(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_nRadio == 3);
}


void CMy8_27View::OnUpdateBackRed(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_nRadio == 4);
}


void CMy8_27View::OnUpdateBackMagenta(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_nRadio == 5);
}


void CMy8_27View::OnUpdateBackYellow(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_nRadio == 6);
}


void CMy8_27View::OnUpdateBackWhite(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_nRadio == 7);
}


void CMy8_27View::OnUpdateBackUser(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_nRadio == 8);
}
