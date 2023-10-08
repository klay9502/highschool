// Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "10_22.h"
#include "Dlg.h"
#include "afxdialogex.h"


// CDlg dialog

IMPLEMENT_DYNAMIC(CDlg, CDialogEx)

CDlg::CDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlg::IDD, pParent)
{

}

CDlg::~CDlg()
{
}

void CDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_TITLE, m_ctrTitle);
}


BEGIN_MESSAGE_MAP(CDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_HIDE, &CDlg::OnBnClickedButtonHide)
	ON_BN_CLICKED(IDC_BUTTON_SHOW, &CDlg::OnBnClickedButtonShow)
END_MESSAGE_MAP()


// CDlg message handlers


void CDlg::OnBnClickedButtonHide()
{
	// TODO: Add your control notification handler code here
	m_ctrTitle.ShowWindow(SW_HIDE);
}


void CDlg::OnBnClickedButtonShow()
{
	// TODO: Add your control notification handler code here
	m_ctrTitle.ShowWindow(SW_SHOW);
}
