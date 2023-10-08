
// 10_20.h : main header file for the 10_20 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy10_20App:
// See 10_20.cpp for the implementation of this class
//

class CMy10_20App : public CWinApp
{
public:
	CMy10_20App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strApp;
	afx_msg void OnApptoView();
	afx_msg void OnApptoDoc();
	afx_msg void OnApptoMain();
};

extern CMy10_20App theApp;
