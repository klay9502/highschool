
// 8_27View.h : CMy8_27View Ŭ������ �������̽�
//

#pragma once


class CMy8_27View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy8_27View();
	DECLARE_DYNCREATE(CMy8_27View)

// Ư���Դϴ�.
public:
	CMy8_27Doc* GetDocument() const;

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
	virtual ~CMy8_27View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTextBlack();
	afx_msg void OnTextBlue();
	afx_msg void OnTextGreen();
	afx_msg void OnTextCyan();
	afx_msg void OnTextRed();
	afx_msg void OnTextMagenta();
	afx_msg void OnTextYellow();
	afx_msg void OnTextUser();
};

#ifndef _DEBUG  // 8_27View.cpp�� ����� ����
inline CMy8_27Doc* CMy8_27View::GetDocument() const
   { return reinterpret_cast<CMy8_27Doc*>(m_pDocument); }
#endif

