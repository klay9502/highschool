
// 9_10View.h : interface of the CMy9_10View class
//

#pragma once
#include "afxwin.h"
#include "atltypes.h"


class CMy9_10View : public CView
{
protected: // create from serialization only
	CMy9_10View();
	DECLARE_DYNCREATE(CMy9_10View)

// Attributes
public:
	CMy9_10Doc* GetDocument() const;

// Operations
public:

// Overrides5
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMy9_10View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CBitmap m_bit;
	CDC m_mDC;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CBitmap m_manBit;
	CDC m_manDC;
	CPoint m_pt;
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in 9_10View.cpp
inline CMy9_10Doc* CMy9_10View::GetDocument() const
   { return reinterpret_cast<CMy9_10Doc*>(m_pDocument); }
#endif

