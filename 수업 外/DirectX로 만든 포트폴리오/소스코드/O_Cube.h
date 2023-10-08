#pragma once

#include "Matrix.h"
#include "Mesh.h"

class O_Cube :
	public CMatrix
{
public: // public 변수
	CMesh Cube;
	CMesh SCube;
	LPD3DXLINE m_pd3dLine;
public: // public 함수
	O_Cube(void);
	~O_Cube(void);

	void CreateObject(void);
	void Process(void);
	void Render(void);

	void Line(int x1, int y1, int x2, int y2);
};

