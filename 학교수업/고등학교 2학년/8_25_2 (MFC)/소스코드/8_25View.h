
// 8_25View.h : CMy8_25View Ŭ������ �������̽�
//

#pragma once


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
	int m_n; // Ȧ, ¦�� �����ϱ� ���� ����
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // 8_25View.cpp�� ����� ����
inline CMy8_25Doc* CMy8_25View::GetDocument() const
   { return reinterpret_cast<CMy8_25Doc*>(m_pDocument); }
#endif

