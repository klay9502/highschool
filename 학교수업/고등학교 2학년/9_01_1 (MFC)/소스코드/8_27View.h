
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
	COLORREF m_crBk;
	afx_msg void OnBackBlack();
	afx_msg void OnBackBlue();
	afx_msg void OnBackGreen();
	afx_msg void OnBackCyan();
	afx_msg void OnBackRed();
	afx_msg void OnBackMagenta();
	afx_msg void OnBackYellow();
	afx_msg void OnBackWhite();
	afx_msg void OnBackUser();
	afx_msg void OnUpdateTextBlack(CCmdUI *pCmdUI);
	afx_msg void OnUpdateTextBlue(CCmdUI *pCmdUI);
	afx_msg void OnUpdateTextGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateTextCyan(CCmdUI *pCmdUI);
	afx_msg void OnUpdateTextRed(CCmdUI *pCmdUI);
	afx_msg void OnUpdateTextMagenta(CCmdUI *pCmdUI);
	afx_msg void OnUpdateTextYellow(CCmdUI *pCmdUI);
	afx_msg void OnUpdateTextUser(CCmdUI *pCmdUI);
	int m_nCheck;
	int m_nRadio;
	afx_msg void OnUpdateBackBlack(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBackBlue(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBackGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBackCyan(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBackRed(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBackMagenta(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBackYellow(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBackWhite(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBackUser(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // 8_27View.cpp�� ����� ����
inline CMy8_27Doc* CMy8_27View::GetDocument() const
   { return reinterpret_cast<CMy8_27Doc*>(m_pDocument); }
#endif

