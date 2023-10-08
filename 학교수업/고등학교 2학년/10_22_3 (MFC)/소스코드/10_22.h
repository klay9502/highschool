
// 10_22.h : main header file for the 10_22 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy10_22App:
// See 10_22.cpp for the implementation of this class
//

class CMy10_22App : public CWinApp
{
public:
	CMy10_22App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy10_22App theApp;
