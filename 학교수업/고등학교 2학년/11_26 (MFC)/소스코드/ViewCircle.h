#pragma once


// CViewCircle view

class CViewCircle : public CView
{
	DECLARE_DYNCREATE(CViewCircle)

protected:
	CViewCircle();           // protected constructor used by dynamic creation
	virtual ~CViewCircle();

public:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};


