// CompDlg.cpp : implementation file
//

#include "stdafx.h"
#include "10_22.h"
#include "CompDlg.h"
#include "afxdialogex.h"


// CCompDlg dialog

IMPLEMENT_DYNAMIC(CCompDlg, CDialog)

CCompDlg::CCompDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCompDlg::IDD, pParent)
	, m_strList(_T(""))
	, m_strName(_T(""))
	, m_nSex(0)
{

}

CCompDlg::~CCompDlg()
{
}

void CCompDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_COMPANY, m_ctrList);
	DDX_LBString(pDX, IDC_LIST_COMPANY, m_strList);
	DDX_Control(pDX, IDC_COMBO_COMPANY, m_ctrCombo);
	DDX_Text(pDX, IDC_EDIT_COMPANY, m_strName);
	DDX_Radio(pDX, IDC_RADIO1, m_nSex);
	DDX_Control(pDX, IDC_RADIO3, m_ctrR3);
	DDX_Control(pDX, IDC_RADIO4, m_ctrR4);
}


BEGIN_MESSAGE_MAP(CCompDlg, CDialog)
	ON_LBN_SELCHANGE(IDC_LIST_COMPANY, &CCompDlg::OnLbnSelchangeListCompany)
	ON_CBN_SELCHANGE(IDC_COMBO_COMPANY, &CCompDlg::OnCbnSelchangeComboCompany)
	ON_BN_CLICKED(IDC_RADIO1, &CCompDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CCompDlg::OnBnClickedRadio2)
END_MESSAGE_MAP()


// CCompDlg message handlers


void CCompDlg::OnLbnSelchangeListCompany()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	// ���� list���� ������ �����Ͱ� m_strList�� ���� �ȴ�.
	m_strName = m_strList;
	// m_strList�� �ִ� �����͸� edit�� value�� ���� m_strName�� �ִ´�.
	UpdateData(FALSE);
	// m_strName�� �ִ� �����͸� edit �ڽ��� ��½�Ų��.
	int n = m_ctrList.GetCurSel();
	// list���� ���õ� ȸ���� index�� �����ؼ� ���� n�� ����
	m_ctrCombo.SetCurSel(n);
	// ���� n�� �ִ� index�� �޺��� ������� ��������� list���� ������ �����Ͱ� �޺��ڽ����� ���õǰԲ� �����.
}


BOOL CCompDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	CString m_strName[6] = {"Samsung", "Hyundai", "LG", "Sony", "Apple", "HP"};

	for (int i = 0; i < 6; i++)
	{
		m_ctrList.AddString(m_strName[i]);
		m_ctrCombo.AddString(m_strName[i]);
	}

	m_ctrList.SetCurSel(0);
	m_ctrCombo.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CCompDlg::OnCbnSelchangeComboCompany()
{
	// TODO: Add your control notification handler code here
	int n = m_ctrCombo.GetCurSel();
	m_ctrList.SetCurSel(n);
	UpdateData(TRUE);
	m_strName = m_strList;
	UpdateData(FALSE);
}


void CCompDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	m_ctrR3.EnableWindow(TRUE);
	m_ctrR4.EnableWindow(TRUE);
}


void CCompDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	m_ctrR3.EnableWindow(FALSE);
	m_ctrR4.EnableWindow(FALSE);
}
