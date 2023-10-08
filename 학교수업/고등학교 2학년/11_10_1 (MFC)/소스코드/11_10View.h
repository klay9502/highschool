
// 11_10View.h : interface of the CMy11_10View class
//

#pragma once


class CMy11_10View : public CView
{
protected: // create from serialization only
	CMy11_10View();
	DECLARE_DYNCREATE(CMy11_10View)

// Attributes
public:
	CMy11_10Doc* GetDocument() const;

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
	virtual ~CMy11_10View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowProperty();
	CString m_str;
};

#ifndef _DEBUG  // debug version in 11_10View.cpp
inline CMy11_10Doc* CMy11_10View::GetDocument() const
   { return reinterpret_cast<CMy11_10Doc*>(m_pDocument); }
#endif

