
// 11_24View.h : interface of the CMy11_24View class
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class CMy11_24View : public CFormView
{
protected: // create from serialization only
	CMy11_24View();
	DECLARE_DYNCREATE(CMy11_24View)

public:
	enum{ IDD = IDD_MY11_24_FORM };

// Attributes
public:
	CMy11_24Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CMy11_24View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowTable();
	afx_msg void OnBnClickedShowTable();
	CComboBox m_ctrBaseBox;
	afx_msg void OnBnClickedLength();
	afx_msg void OnBnClickedWeight();
	float m_nAfter;
	float m_nBefore;
	afx_msg void OnBnClickedConvert();
	CComboBox m_ctrChangeBox;
	int m_nChoose;
};

#ifndef _DEBUG  // debug version in 11_24View.cpp
inline CMy11_24Doc* CMy11_24View::GetDocument() const
   { return reinterpret_cast<CMy11_24Doc*>(m_pDocument); }
#endif

