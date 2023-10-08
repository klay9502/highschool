#pragma once

#include "Matrix.h"
#include "Mesh.h"

class O_LoadObject :
	public CMatrix
{
public: // public 변수
	CMesh Mesh;
	CMesh SMesh;
	LPD3DXLINE m_pd3dLine;
public: // public 함수
	O_LoadObject(void);
	~O_LoadObject(void);

	void CreateObject(const char* _filename);
	void Process(void);
	void Render(void);
	void Release(void);

	void Line(int x1, int y1, int x2, int y2);
};

