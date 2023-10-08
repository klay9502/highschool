#pragma once

#include "Matrix.h"
#include "Mesh.h"

class O_Tetra :
	public CMatrix
{
public: // public ����
	CMesh Tetra;
	CMesh STetra;
	LPD3DXLINE m_pd3dLine;
public: // public �Լ�
	O_Tetra(void);
	~O_Tetra(void);

	void CreateObject(void);
	void Process(void);
	void Render(void);

	void Line(int x1, int y1, int x2, int y2);
};

