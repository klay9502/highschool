
// 11_24View.cpp : implementation of the CMy11_24View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "11_24.h"
#endif

#include "11_24Doc.h"
#include "11_24View.h"

#include "UnitTable.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

enum { M = 0, INCH, YD };
enum { G = 0, OZ, LB};
enum { LENGTH = 0, WEIGHT, NOPE};

// CMy11_24View

IMPLEMENT_DYNCREATE(CMy11_24View, CFormView)

BEGIN_MESSAGE_MAP(CMy11_24View, CFormView)
	ON_COMMAND(ID_SHOW_TABLE, &CMy11_24View::OnShowTable)
	ON_BN_CLICKED(ID_SHOW_TABLE, &CMy11_24View::OnBnClickedShowTable)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_LENGTH, &CMy11_24View::OnBnClickedLength)
	ON_BN_CLICKED(IDC_WEIGHT, &CMy11_24View::OnBnClickedWeight)
	ON_BN_CLICKED(IDC_CONVERT, &CMy11_24View::OnBnClickedConvert)
END_MESSAGE_MAP()

// CMy11_24View construction/destruction

CMy11_24View::CMy11_24View()
	: CFormView(CMy11_24View::IDD)
	, m_nAfter(0)
	, m_nBefore(0)
	, m_nChoose(2)
{
	// TODO: add construction code here

}

CMy11_24View::~CMy11_24View()
{
}

void CMy11_24View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_ctrBaseBox);
	DDX_Text(pDX, IDC_AFTER, m_nAfter);
	DDX_Text(pDX, IDC_BEFORE, m_nBefore);
	DDX_Control(pDX, IDC_COMBO2, m_ctrChangeBox);
}

BOOL CMy11_24View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMy11_24View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CMy11_24View diagnostics

#ifdef _DEBUG
void CMy11_24View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy11_24View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy11_24Doc* CMy11_24View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy11_24Doc)));
	return (CMy11_24Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy11_24View message handlers


void CMy11_24View::OnShowTable()
{
	// TODO: Add your command handler code here
	CUnitTable dlg;
	dlg.DoModal();
}


void CMy11_24View::OnBnClickedShowTable()
{
	// TODO: Add your control notification handler code here
}


void CMy11_24View::OnBnClickedLength()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	m_nChoose = LENGTH;

	m_ctrBaseBox.ResetContent();
	m_ctrChangeBox.ResetContent();

	CString str[3] = { "m", "in", "yd" };

	for (int i = 0; i < 3; i++)
	{
		m_ctrBaseBox.AddString(str[i]);
		m_ctrChangeBox.AddString(str[i]);
	}

	m_ctrBaseBox.SetCurSel(0);
	m_ctrChangeBox.SetCurSel(0);

	UpdateData(FALSE);
}


void CMy11_24View::OnBnClickedWeight()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	m_nChoose = WEIGHT;

	m_ctrBaseBox.ResetContent();
	m_ctrChangeBox.ResetContent();

	CString str[3] = { "g", "oz", "lb" };

	for (int i = 0; i < 3; i++)
	{
		m_ctrBaseBox.AddString(str[i]);
		m_ctrChangeBox.AddString(str[i]);
	}

	m_ctrBaseBox.SetCurSel(0);
	m_ctrChangeBox.SetCurSel(0);

	UpdateData(FALSE);
}

void CMy11_24View::OnBnClickedConvert()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if (m_nChoose == 2)
	{
		MessageBox("Setting Plz");
	}

	switch (m_nChoose)
	{
	case LENGTH:
		switch (m_ctrBaseBox.GetCurSel())
		{
		case M:
			switch (m_ctrChangeBox.GetCurSel())
			{
			case M:
				m_nAfter = m_nBefore;
				break;
			case INCH:
				m_nAfter = m_nBefore * 39.370079;
				break;
			case YD:
				m_nAfter = m_nBefore * 1.093613;
				break;
			}
			break;
		case INCH:
			switch (m_ctrChangeBox.GetCurSel())
			{
			case M:
				m_nAfter = m_nBefore * 0.0254;
				break;
			case INCH:
				m_nAfter = m_nBefore;
				break;
			case YD:
				m_nAfter = m_nBefore * 0.027778;
				break;
			}
			break;
		case YD:
			switch (m_ctrChangeBox.GetCurSel())
			{
			case M:
				m_nAfter = m_nBefore * 0.9144;
				break;
			case INCH:
				m_nAfter = m_nBefore * 36;
				break;
			case YD:
				m_nAfter = m_nBefore;
				break;
			}
			break;
		}
		break;
	case WEIGHT:
		switch (m_ctrBaseBox.GetCurSel())
		{
		case G:
			switch (m_ctrChangeBox.GetCurSel())
			{
			case G:
				m_nAfter = m_nBefore;
				break;
			case OZ:
				m_nAfter = m_nBefore * 0.035274;
				break;
			case LB:
				m_nAfter = m_nBefore * 0.002205;
				break;
			}
			break;
		case OZ:
			switch (m_ctrChangeBox.GetCurSel())
			{
			case G:
				m_nAfter = m_nBefore * 28.349523;
				break;
			case OZ:
				m_nAfter = m_nBefore;
				break;
			case LB:
				m_nAfter = m_nBefore * 0.0625;
				break;
			}
			break;
		case LB:
			switch (m_ctrChangeBox.GetCurSel())
			{
			case G:
				m_nAfter = m_nBefore * 453.59237;
				break;
			case OZ:
				m_nAfter = m_nBefore * 16;
				break;
			case LB:
				m_nAfter = m_nBefore;
				break;
			}
			break;
		}
		break;
	}

	UpdateData(FALSE);
}
