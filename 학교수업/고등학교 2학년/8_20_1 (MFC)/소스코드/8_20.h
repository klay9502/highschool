
// 8_20.h : 8_20 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy8_20App:
// �� Ŭ������ ������ ���ؼ��� 8_20.cpp�� �����Ͻʽÿ�.
//

class CMy8_20App : public CWinApp
{
public:
	CMy8_20App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy8_20App theApp;
