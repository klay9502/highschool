
// 8_25View.h : CMy8_25View Ŭ������ �������̽�
//

#pragma once
#include "atltypes.h"


class CMy8_25View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy8_25View();
	DECLARE_DYNCREATE(CMy8_25View)

// Ư���Դϴ�.
public:
	CMy8_25Doc* GetDocument() const;

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
	virtual ~CMy8_25View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	char m_char;	// ���� ����
	int  m_nMove;	// �ӵ�

	CPoint m_pt;	// ��ǥ�� �����ϴ� ��ü
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // 8_25View.cpp�� ����� ����
inline CMy8_25Doc* CMy8_25View::GetDocument() const
   { return reinterpret_cast<CMy8_25Doc*>(m_pDocument); }
#endif

