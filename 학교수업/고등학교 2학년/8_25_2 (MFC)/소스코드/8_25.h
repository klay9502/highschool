
// 8_25.h : 8_25 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy8_25App:
// �� Ŭ������ ������ ���ؼ��� 8_25.cpp�� �����Ͻʽÿ�.
//

class CMy8_25App : public CWinAppEx
{
public:
	CMy8_25App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy8_25App theApp;
