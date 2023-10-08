#include "stdafx.h"
#include "O_Cube.h"
#include "WindowManager.h"
#include "InputManager.h"
#include "Vertex.h"


O_Cube::O_Cube(void)
{
	// empty...
}

O_Cube::~O_Cube(void)
{
	// empty...
}

void O_Cube::CreateObject(void)
{
	// 욱면체 정의
	Cube.numVertex = 8;
	Cube.numTriangle = 12;
	Cube.pVertexList = (CVertex*)malloc(Cube.numVertex * sizeof(CVertex));
	Cube.pVertexIndexList = (int*)malloc(Cube.numTriangle * sizeof(int)* 3);
	//육면체 데이터 세팅
	Cube.pVertexList[0].x = -100.0f;
	Cube.pVertexList[0].y = 100.0f;
	Cube.pVertexList[0].z = 100.0f;
	Cube.pVertexList[0].w = 1.0f; //항상 1

	Cube.pVertexList[1].x = 100.0f;
	Cube.pVertexList[1].y = 100.0f;
	Cube.pVertexList[1].z = 100.0f;
	Cube.pVertexList[1].w = 1.0f; //항상 1

	Cube.pVertexList[2].x = -100.0f;
	Cube.pVertexList[2].y = 100.0f;
	Cube.pVertexList[2].z = -100.0f;
	Cube.pVertexList[2].w = 1.0f; //항상 1

	Cube.pVertexList[3].x = 100.0f;
	Cube.pVertexList[3].y = 100.0f;
	Cube.pVertexList[3].z = -100.0f;
	Cube.pVertexList[3].w = 1.0f; //항상 1

	Cube.pVertexList[4].x = -100.0f;
	Cube.pVertexList[4].y = -100.0f;
	Cube.pVertexList[4].z = 100.0f;
	Cube.pVertexList[4].w = 1.0f; //항상 1

	Cube.pVertexList[5].x = 100.0f;
	Cube.pVertexList[5].y = -100.0f;
	Cube.pVertexList[5].z = 100.0f;
	Cube.pVertexList[5].w = 1.0f; //항상 1

	Cube.pVertexList[6].x = -100.0f;
	Cube.pVertexList[6].y = -100.0f;
	Cube.pVertexList[6].z = -100.0f;
	Cube.pVertexList[6].w = 1.0f; //항상 1

	Cube.pVertexList[7].x = 100.0f;
	Cube.pVertexList[7].y = -100.0f;
	Cube.pVertexList[7].z = -100.0f;
	Cube.pVertexList[7].w = 1.0f; //항상 1
	// 육면체 연결순서
	Cube.pVertexIndexList[0] = 0;
	Cube.pVertexIndexList[1] = 2;
	Cube.pVertexIndexList[2] = 1;

	Cube.pVertexIndexList[3] = 1;
	Cube.pVertexIndexList[4] = 2;
	Cube.pVertexIndexList[5] = 3;

	Cube.pVertexIndexList[6] = 2;
	Cube.pVertexIndexList[7] = 6;
	Cube.pVertexIndexList[8] = 3;

	Cube.pVertexIndexList[9] = 3;
	Cube.pVertexIndexList[10] = 6;
	Cube.pVertexIndexList[11] = 7;

	Cube.pVertexIndexList[12] = 3;
	Cube.pVertexIndexList[13] = 7;
	Cube.pVertexIndexList[14] = 1;

	Cube.pVertexIndexList[15] = 1;
	Cube.pVertexIndexList[16] = 7;
	Cube.pVertexIndexList[17] = 5;

	Cube.pVertexIndexList[18] = 0;
	Cube.pVertexIndexList[19] = 4;
	Cube.pVertexIndexList[20] = 2;

	Cube.pVertexIndexList[21] = 2;
	Cube.pVertexIndexList[22] = 6;
	Cube.pVertexIndexList[23] = 4;

	Cube.pVertexIndexList[24] = 0;
	Cube.pVertexIndexList[25] = 5;
	Cube.pVertexIndexList[26] = 4;

	Cube.pVertexIndexList[27] = 1;
	Cube.pVertexIndexList[28] = 5;
	Cube.pVertexIndexList[29] = 0;

	Cube.pVertexIndexList[30] = 6;
	Cube.pVertexIndexList[31] = 4;
	Cube.pVertexIndexList[32] = 7;

	Cube.pVertexIndexList[33] = 7;
	Cube.pVertexIndexList[34] = 4;
	Cube.pVertexIndexList[35] = 5;

	///////////////////////////////////////////////
	//화면 육면체
	SCube.numVertex = 8;
	SCube.numTriangle = 12;
	SCube.pVertexList = (CVertex*)malloc(Cube.numVertex * sizeof(CVertex));
	SCube.pVertexIndexList = (int*)malloc(Cube.numTriangle * sizeof(int)* 3);

	SCube = Cube;
	///////////////////////////////////////////////

	D3DXCreateLine(WinMgr->m_pd3dDevice, &m_pd3dLine);
	m_pd3dLine->SetWidth(2);
}

void O_Cube::Process(void)
{
	CMatrix CTM, RXM, RYM, RZM, TTM;
	CTM = Identity();

	int w = 400;
	int h = 500;
	
	//static int theta;
	//if (theta > 360) theta = 0;

	RXM = RotateX(InputMgr->m_nDragY);
	RYM = RotateY(InputMgr->m_nDragX);
	RZM = RotateZ(0);

	TTM = Translate(w, h, 0);	// 중심이동

	CTM = Multiply(RXM, RYM);
	CTM = Multiply(CTM, RZM);
	CTM = Multiply(CTM, TTM);

	for (int i = 0; i < Cube.numVertex; i++)
	{
		SCube.pVertexList[i] = Transform(Cube.pVertexList[i], CTM);
	}

	// theta++;
}

void O_Cube::Render(void)
{
	int w = 400;
	int h = 500;

	for (int i = 0; i < Cube.numTriangle * 3; i += 3)
	{
		Line(SCube.pVertexList[SCube.pVertexIndexList[i]].x + w,
			SCube.pVertexList[SCube.pVertexIndexList[i]].y + h,
			SCube.pVertexList[SCube.pVertexIndexList[i + 1]].x + w,
			SCube.pVertexList[SCube.pVertexIndexList[i + 1]].y + h);
		Line(SCube.pVertexList[SCube.pVertexIndexList[i + 1]].x + w,
			SCube.pVertexList[SCube.pVertexIndexList[i + 1]].y + h,
			SCube.pVertexList[SCube.pVertexIndexList[i + 2]].x + w,
			SCube.pVertexList[SCube.pVertexIndexList[i + 2]].y + h);
		Line(SCube.pVertexList[SCube.pVertexIndexList[i + 2]].x + w,
			SCube.pVertexList[SCube.pVertexIndexList[i + 2]].y + h,
			SCube.pVertexList[SCube.pVertexIndexList[i]].x + w,
			SCube.pVertexList[SCube.pVertexIndexList[i]].y + h);
	}
}

void O_Cube::Line(int x1, int y1, int x2, int y2)
{
	D3DXVECTOR2 line[2];

	line[0] = D3DXVECTOR2(x1, y1);
	line[1] = D3DXVECTOR2(x2, y2);

	m_pd3dLine->Begin();
	m_pd3dLine->Draw(line, 2, D3DCOLOR_XRGB(255, 255, 255));
	m_pd3dLine->End();
}