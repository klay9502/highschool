
// 9_03View.h : interface of the CMy9_03View class
//

#pragma once


class CMy9_03View : public CView
{
protected: // create from serialization only
	CMy9_03View();
	DECLARE_DYNCREATE(CMy9_03View)

// Attributes
public:
	CMy9_03Doc* GetDocument() const;

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
	virtual ~CMy9_03View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CString m_strTime;
	afx_msg void OnUpdateIndicatorTime(CCmdUI *pCmdUI);
	afx_msg void OnTimerOn();
	afx_msg void OnTimerOff();
};

#ifndef _DEBUG  // debug version in 9_03View.cpp
inline CMy9_03Doc* CMy9_03View::GetDocument() const
   { return reinterpret_cast<CMy9_03Doc*>(m_pDocument); }
#endif

