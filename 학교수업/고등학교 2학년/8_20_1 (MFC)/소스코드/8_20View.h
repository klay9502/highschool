
// 8_20View.h : CMy8_20View Ŭ������ �������̽�
//

#pragma once


class CMy8_20View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy8_20View();
	DECLARE_DYNCREATE(CMy8_20View)

// Ư���Դϴ�.
public:
	CMy8_20Doc* GetDocument() const;

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
	virtual ~CMy8_20View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	int m_n;
	CString m_strName;
	void Display(void);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 8_20View.cpp�� ����� ����
inline CMy8_20Doc* CMy8_20View::GetDocument() const
   { return reinterpret_cast<CMy8_20Doc*>(m_pDocument); }
#endif

