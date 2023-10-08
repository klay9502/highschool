
// 9_22View.h : interface of the CMy9_22View class
//

#pragma once
#include "afxwin.h"


class CMy9_22View : public CView
{
protected: // create from serialization only
	CMy9_22View();
	DECLARE_DYNCREATE(CMy9_22View)

// Attributes
public:
	CMy9_22Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMy9_22View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnColorBlack();
	afx_msg void OnColorPicture();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	bool m_bIsBlack;
	bool m_bIsPicture;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in 9_22View.cpp
inline CMy9_22Doc* CMy9_22View::GetDocument() const
   { return reinterpret_cast<CMy9_22Doc*>(m_pDocument); }
#endif

