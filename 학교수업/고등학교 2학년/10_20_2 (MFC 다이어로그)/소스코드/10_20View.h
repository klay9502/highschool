
// 10_20View.h : interface of the CMy10_20View class
//

#pragma once


class CMy10_20View : public CView
{
protected: // create from serialization only
	CMy10_20View();
	DECLARE_DYNCREATE(CMy10_20View)

// Attributes
public:
	CMy10_20Doc* GetDocument() const;

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
	virtual ~CMy10_20View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowDialog();
};

#ifndef _DEBUG  // debug version in 10_20View.cpp
inline CMy10_20Doc* CMy10_20View::GetDocument() const
   { return reinterpret_cast<CMy10_20Doc*>(m_pDocument); }
#endif

