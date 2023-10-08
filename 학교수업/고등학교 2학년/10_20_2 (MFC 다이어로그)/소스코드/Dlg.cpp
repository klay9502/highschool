// Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "10_20.h"
#include "Dlg.h"
#include "afxdialogex.h"


// CDlg dialog

IMPLEMENT_DYNAMIC(CDlg, CDialog)

CDlg::CDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg::IDD, pParent)
{

}

CDlg::~CDlg()
{
}

void CDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg, CDialog)
END_MESSAGE_MAP()


// CDlg message handlers
