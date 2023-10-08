
// 9_22.h : main header file for the 9_22 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy9_22App:
// See 9_22.cpp for the implementation of this class
//

class CMy9_22App : public CWinApp
{
public:
	CMy9_22App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy9_22App theApp;
