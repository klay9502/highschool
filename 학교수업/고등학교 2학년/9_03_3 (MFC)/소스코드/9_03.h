
// 9_03.h : main header file for the 9_03 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy9_03App:
// See 9_03.cpp for the implementation of this class
//

class CMy9_03App : public CWinApp
{
public:
	CMy9_03App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy9_03App theApp;
