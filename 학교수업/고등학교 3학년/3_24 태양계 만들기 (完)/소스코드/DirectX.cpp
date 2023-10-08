#include "stdafx.h"
#include "DirectX.h"


CDirectX::CDirectX(void)
{
	m_D3D = NULL;
	m_Device = NULL;
	memset(&m_d3dpp, 0, sizeof(m_d3dpp));
}


CDirectX::~CDirectX(void)
{
	if (m_Device != NULL)
	{
		m_Device->Release();
		m_Device = NULL;
	}

	if (m_D3D != NULL)
	{
		m_D3D->Release();
		m_D3D = NULL;
	}
}

bool CDirectX::Init(HWND hWnd, bool bWindowed)
{
	if (hWnd == NULL)
	{
		return false;
	}

	GetClientRect(hWnd, &m_rcClient);

	if (NULL == (m_D3D = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		MessageBox(NULL, _T("NULL == (m_D3D = Direct3DCreate9(D3D_SDK_VERSION)"), _T("ERROR"), MB_OK);
		return false;
	}

	if (FAILED(m_D3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &m_d3ddm)))
	{
		if (NULL == (m_D3D = Direct3DCreate9(D3D_SDK_VERSION)))
		{
			MessageBox(NULL, _T("FAILED(m_D3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &m_d3ddm))"), _T("ERROR"), MB_OK);
			return false;
		}
	}

	m_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	m_d3dpp.BackBufferCount = 1;
	m_d3dpp.BackBufferFormat = m_d3ddm.Format;
	m_d3dpp.BackBufferHeight = m_rcClient.bottom;
	m_d3dpp.BackBufferWidth = m_rcClient.right;
	m_d3dpp.EnableAutoDepthStencil = TRUE;
	m_d3dpp.Flags = D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL;
	m_d3dpp.FullScreen_RefreshRateInHz = 0;
	m_d3dpp.hDeviceWindow = hWnd;
	m_d3dpp.MultiSampleQuality = 0;
	m_d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	m_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	m_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	m_d3dpp.Windowed = bWindowed;

	if (!bWindowed)
	{
		m_d3dpp.BackBufferHeight = m_d3ddm.Height;
		m_d3dpp.BackBufferWidth = m_d3ddm.Width;
		m_d3dpp.FullScreen_RefreshRateInHz = m_d3ddm.RefreshRate;
	}

	if (FAILED(m_D3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&m_d3dpp, &m_Device)))
	{
		MessageBox(NULL, _T("m_D3D->CreateDevice(...)"), _T("ERROR"), MB_OK);
		return false;
	}

	m_Device->SetRenderState(D3DRS_AMBIENT, 0xFFFFFFFF);
	m_Device->SetRenderState(D3DRS_LIGHTING, FALSE);

	return true;
}
