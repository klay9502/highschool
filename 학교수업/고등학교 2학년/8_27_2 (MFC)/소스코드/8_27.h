
// 8_27.h : 8_27 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy8_27App:
// �� Ŭ������ ������ ���ؼ��� 8_27.cpp�� �����Ͻʽÿ�.
//

class CMy8_27App : public CWinApp
{
public:
	CMy8_27App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy8_27App theApp;
