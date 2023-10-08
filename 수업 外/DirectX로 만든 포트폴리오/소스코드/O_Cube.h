#pragma once

#include "Matrix.h"
#include "Mesh.h"

class O_Cube :
	public CMatrix
{
public: // public ����
	CMesh Cube;
	CMesh SCube;
	LPD3DXLINE m_pd3dLine;
public: // public �Լ�
	O_Cube(void);
	~O_Cube(void);

	void CreateObject(void);
	void Process(void);
	void Render(void);

	void Line(int x1, int y1, int x2, int y2);
};

