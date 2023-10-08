
// 9_01View.h : interface of the CMy9_01View class
//

#pragma once
#include "atltypes.h"


class CMy9_01View : public CView
{
protected: // create from serialization only
	CMy9_01View();
	DECLARE_DYNCREATE(CMy9_01View)

// Attributes
public:
	CMy9_01Doc* GetDocument() const;

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
	virtual ~CMy9_01View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnColorsBlack();
	afx_msg void OnColorsBlue();
	afx_msg void OnColorsGreen();
	afx_msg void OnColorsCyan();
	afx_msg void OnColorsRed();
	afx_msg void OnColorsMagenta();
	afx_msg void OnColorsYellow();
	afx_msg void OnColorsUser();
	afx_msg void OnUpdateColorsBlack(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorsBlue(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorsGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorsCyan(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorsRed(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorsMagenta(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorsYellow(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorsUser(CCmdUI *pCmdUI);
	int m_nCheck;
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in 9_01View.cpp
inline CMy9_01Doc* CMy9_01View::GetDocument() const
   { return reinterpret_cast<CMy9_01Doc*>(m_pDocument); }
#endif

