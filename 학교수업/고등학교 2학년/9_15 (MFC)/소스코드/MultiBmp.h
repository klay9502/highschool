
// MultiBmp.h : MultiBmp ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMultiBmpApp:
// �� Ŭ������ ������ ���ؼ��� MultiBmp.cpp�� �����Ͻʽÿ�.
//

class CMultiBmpApp : public CWinApp
{
public:
	CMultiBmpApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMultiBmpApp theApp;
