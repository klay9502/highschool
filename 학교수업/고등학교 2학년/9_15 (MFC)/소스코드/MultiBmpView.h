
// MultiBmpView.h : CMultiBmpView Ŭ������ �������̽�
//

#pragma once


class CMultiBmpView : public CView
{
protected: // serialization������ ��������ϴ�.
	CMultiBmpView();
	DECLARE_DYNCREATE(CMultiBmpView)

// Ư���Դϴ�.
public:
	CMultiBmpDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMultiBmpView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	int a;
	CDC m_mdc[6];
	CBitmap m_bit[6];
	CRect m_r[2][3];
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	int m_nSel;
	afx_msg void OnPic1();
	afx_msg void OnPic2();
	afx_msg void OnPic3();
	afx_msg void OnPic4();
	afx_msg void OnPic5();
	afx_msg void OnPic6();
	afx_msg void OnPicPrev();
	afx_msg void OnPicNext();
	afx_msg void OnPicAll();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	bool m_bAllView;
	bool m_bSel;
};

#ifndef _DEBUG  // MultiBmpView.cpp�� ����� ����
inline CMultiBmpDoc* CMultiBmpView::GetDocument() const
   { return reinterpret_cast<CMultiBmpDoc*>(m_pDocument); }
#endif

