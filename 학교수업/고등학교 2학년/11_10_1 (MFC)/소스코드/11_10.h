
// 11_10.h : main header file for the 11_10 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy11_10App:
// See 11_10.cpp for the implementation of this class
//

class CMy11_10App : public CWinApp
{
public:
	CMy11_10App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy11_10App theApp;
