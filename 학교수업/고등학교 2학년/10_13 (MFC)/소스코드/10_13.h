
// 10_13.h : main header file for the 10_13 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy10_13App:
// See 10_13.cpp for the implementation of this class
//

class CMy10_13App : public CWinApp
{
public:
	CMy10_13App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy10_13App theApp;
