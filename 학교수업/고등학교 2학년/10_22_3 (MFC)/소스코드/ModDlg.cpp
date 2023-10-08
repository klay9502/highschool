// ModDlg.cpp : implementation file
//

#include "stdafx.h"
#include "10_22.h"
#include "ModDlg.h"
#include "afxdialogex.h"


// CModDlg dialog

IMPLEMENT_DYNAMIC(CModDlg, CDialog)

CModDlg::CModDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CModDlg::IDD, pParent)
	, m_strName(_T(""))
{

}

CModDlg::~CModDlg()
{
}

void CModDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
}


BEGIN_MESSAGE_MAP(CModDlg, CDialog)
END_MESSAGE_MAP()


// CModDlg message handlers
