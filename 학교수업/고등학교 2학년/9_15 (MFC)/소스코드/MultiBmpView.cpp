
// MultiBmpView.cpp : CMultiBmpView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MultiBmp.h"
#endif

#include "MultiBmpDoc.h"
#include "MultiBmpView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMultiBmpView

IMPLEMENT_DYNCREATE(CMultiBmpView, CView)

BEGIN_MESSAGE_MAP(CMultiBmpView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_COMMAND(ID_PIC1, &CMultiBmpView::OnPic1)
	ON_COMMAND(ID_PIC2, &CMultiBmpView::OnPic2)
	ON_COMMAND(ID_PIC3, &CMultiBmpView::OnPic3)
	ON_COMMAND(ID_PIC4, &CMultiBmpView::OnPic4)
	ON_COMMAND(ID_PIC5, &CMultiBmpView::OnPic5)
	ON_COMMAND(ID_PIC6, &CMultiBmpView::OnPic6)
	ON_COMMAND(ID_PIC_PREV, &CMultiBmpView::OnPicPrev)
	ON_COMMAND(ID_PIC_NEXT, &CMultiBmpView::OnPicNext)
	ON_COMMAND(ID_PIC_ALL, &CMultiBmpView::OnPicAll)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMultiBmpView ����/�Ҹ�

CMultiBmpView::CMultiBmpView()
: a(0)
, m_nSel(0)
, m_bAllView(false)
, m_bSel(false)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMultiBmpView::~CMultiBmpView()
{
}

BOOL CMultiBmpView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMultiBmpView �׸���

void CMultiBmpView::OnDraw(CDC* pDC)
{
	CMultiBmpDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	CRect r;
	GetClientRect(&r);
	// pDC->BitBlt(0, 0, r.Width(), r.Height(), &m_mdc[m_nSel], 0, 0, SRCCOPY);
	BITMAP bm;
	if (!m_bSel)
	{
		m_bit[m_nSel].GetBitmap(&bm);
		pDC->StretchBlt(0, 0, r.Width(), r.Height(), &m_mdc[m_nSel], 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
	}
	else
	{
		//CClientDC dc(this);
		//CRect r;
		//GetClientRect(&r);
		int nW = r.Width() / 3;
		int nW1 = nW / 2;
		int nH = r.Height() / 2;
		int nH1 = nH / 2;
		int sel = 0;
		BITMAP bm;
		pDC->SelectStockObject(LTGRAY_BRUSH);
		pDC->Rectangle(r);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				m_bit[sel].GetBitmap(&bm);
				pDC->StretchBlt(nW * j + 50, nH * i + 50, nW1, nH1, &m_mdc[sel], 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
				m_r[i][j].SetRect(nW*j + 50, nH*i + 50, nW*j + 50 + nW1, nH*i + 50 + nH1);
				sel++;
			}
		}
	}
}


// CMultiBmpView �μ�

BOOL CMultiBmpView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMultiBmpView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMultiBmpView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMultiBmpView ����

#ifdef _DEBUG
void CMultiBmpView::AssertValid() const
{
	CView::AssertValid();
}

void CMultiBmpView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMultiBmpDoc* CMultiBmpView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMultiBmpDoc)));
	return (CMultiBmpDoc*)m_pDocument;
}
#endif //_DEBUG


// CMultiBmpView �޽��� ó����


int CMultiBmpView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	CClientDC dc(this);
	UINT nID[6] = { IDB_PIC1, IDB_PIC2, IDB_PIC3, IDB_PIC4, IDB_PIC5, IDB_PIC6 };

	for (int i = 0; i < 6; i++)
	{
		m_mdc[i].CreateCompatibleDC(&dc);
		m_bit[i].LoadBitmapA(nID[i]);
		m_mdc[i].SelectObject(&m_bit[i]);
	}

	return 0;
}


void CMultiBmpView::OnPic1()
{
	// TODO: Add your command handler code here
	m_nSel = 0;
	m_bAllView = false;
	m_bSel = false;
	Invalidate();
}


void CMultiBmpView::OnPic2()
{
	// TODO: Add your command handler code here
	m_nSel = 1;
	m_bAllView = false;
	m_bSel = false;
	Invalidate();
}


void CMultiBmpView::OnPic3()
{
	// TODO: Add your command handler code here
	m_nSel = 2;
	m_bAllView = false;
	m_bSel = false;
	Invalidate();
}


void CMultiBmpView::OnPic4()
{
	// TODO: Add your command handler code here
	m_nSel = 3;
	m_bAllView = false;
	m_bSel = false;
	Invalidate();
}


void CMultiBmpView::OnPic5()
{
	// TODO: Add your command handler code here
	m_nSel = 4;
	m_bAllView = false;
	m_bSel = false;
	Invalidate();
}


void CMultiBmpView::OnPic6()
{
	// TODO: Add your command handler code here
	m_nSel = 5;
	m_bAllView = false;
	m_bSel = false;
	Invalidate();
}


void CMultiBmpView::OnPicPrev()
{
	// TODO: Add your command handler code here
	if (m_nSel <= 0) m_nSel = 0;
	else m_nSel--;
	Invalidate();
}


void CMultiBmpView::OnPicNext()
{
	// TODO: Add your command handler code here
	if (m_nSel >= 5) m_nSel = 5;
	else m_nSel++;
	Invalidate();
}


void CMultiBmpView::OnPicAll()
{
	// TODO: Add your command handler code here
	m_bAllView = true;
	m_bSel = true;

	Invalidate();
	/*CClientDC dc(this);
	CRect r;
	GetClientRect(&r);
	int nW = r.Width() / 3;
	int nW1 = nW / 2;
	int nH = r.Height() / 2;
	int nH1 = nH / 2;
	int sel = 0;
	BITMAP bm;
	dc.SelectStockObject(LTGRAY_BRUSH);
	dc.Rectangle(r);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m_bit[sel].GetBitmap(&bm);
			dc.StretchBlt(nW * j + 50, nH * i + 50, nW1, nH1, &m_mdc[sel], 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
			m_r[i][j].SetRect(nW*j + 50, nH*i + 50, nW*j + 50 + nW1, nH*i + 50 + nH1);
			sel++;
		}
	}*/
}


void CMultiBmpView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (!m_bAllView) return;
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (m_r[i][j].PtInRect(point))
			{
				switch (i * 3 + j)
				{
				case 0:
					OnPic1();
					break;
				case 1:
					OnPic2();
					break;
				case 2:
					OnPic3();
					break;
				case 3:
					OnPic4();
					break;
				case 4:
					OnPic5();
					break;
				case 5:
					OnPic6();
					break;
				}
			}
		}
	}

	CView::OnLButtonDown(nFlags, point);
}
