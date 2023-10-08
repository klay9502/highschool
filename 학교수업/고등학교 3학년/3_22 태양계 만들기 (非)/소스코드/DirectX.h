#pragma once

#include "stdafx.h"

class CDirectX
{
private:
	IDirect3D9*			m_D3D;
	IDirect3DDevice9*	m_Device;
public:
	CDirectX(void);
	~CDirectX(void);
};

