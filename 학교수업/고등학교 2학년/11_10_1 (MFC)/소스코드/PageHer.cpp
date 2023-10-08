// PageHer.cpp : implementation file
//

#include "stdafx.h"
#include "11_10.h"
#include "PageHer.h"
#include "afxdialogex.h"


// CPageHer dialog

IMPLEMENT_DYNAMIC(CPageHer, CPropertyPage)

CPageHer::CPageHer()
	: CPropertyPage(CPageHer::IDD)
	, m_strText(_T(""))
{

}

CPageHer::~CPageHer()
{
}

void CPageHer::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_strText);
}


BEGIN_MESSAGE_MAP(CPageHer, CPropertyPage)
END_MESSAGE_MAP()


// CPageHer message handlers
