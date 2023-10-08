#include "stdafx.h"
#include "O_Tetra.h"
#include "WindowManager.h"
#include "InputManager.h"
#include "Vertex.h"


O_Tetra::O_Tetra(void)
{
	// empty...
}

O_Tetra::~O_Tetra(void)
{
	// empty...
}

void O_Tetra::CreateObject(void)
{
	// 삼각뿔 정의
	Tetra.numVertex = 4;
	Tetra.numTriangle = 4;
	Tetra.pVertexList = (CVertex*)malloc(Tetra.numVertex * sizeof(CVertex));
	Tetra.pVertexIndexList = (int*)malloc(Tetra.numTriangle * sizeof(int)* 3);
	//삼각뿔 데이터 세팅
	Tetra.pVertexList[0].x = 0.0f;
	Tetra.pVertexList[0].y = 100.0f;
	Tetra.pVertexList[0].z = 0.0f;
	Tetra.pVertexList[0].w = 1.0f; //항상 1

	Tetra.pVertexList[1].x = 0.0f;
	Tetra.pVertexList[1].y = -100.0f;
	Tetra.pVertexList[1].z = -100.0f;
	Tetra.pVertexList[1].w = 1.0f; //항상 1

	Tetra.pVertexList[2].x = -150.0f;
	Tetra.pVertexList[2].y = -100.0f;
	Tetra.pVertexList[2].z = 100.0f;
	Tetra.pVertexList[2].w = 1.0f; //항상 1

	Tetra.pVertexList[3].x = 150.0f;
	Tetra.pVertexList[3].y = -100.0f;
	Tetra.pVertexList[3].z = 100.0f;
	Tetra.pVertexList[3].w = 1.0f; //항상 1

	//삼각형 연결 순서
	Tetra.pVertexIndexList[0] = 0;
	Tetra.pVertexIndexList[1] = 2;
	Tetra.pVertexIndexList[2] = 1;

	Tetra.pVertexIndexList[3] = 0;
	Tetra.pVertexIndexList[4] = 3;
	Tetra.pVertexIndexList[5] = 2;

	Tetra.pVertexIndexList[6] = 0;
	Tetra.pVertexIndexList[7] = 1;
	Tetra.pVertexIndexList[8] = 3;

	Tetra.pVertexIndexList[9] = 1;
	Tetra.pVertexIndexList[10] = 2;
	Tetra.pVertexIndexList[11] = 3;

	///////////////////////////////////////////////
	//화면 삼각뿔
	STetra.numVertex = 4;
	STetra.numTriangle = 4;
	STetra.pVertexList = (CVertex*)malloc(Tetra.numVertex * sizeof(CVertex));
	STetra.pVertexIndexList = (int*)malloc(Tetra.numTriangle * sizeof(int)* 3);

	STetra = Tetra;
	///////////////////////////////////////////////

	D3DXCreateLine(WinMgr->m_pd3dDevice, &m_pd3dLine);
	m_pd3dLine->SetWidth(2);
}

void O_Tetra::Process(void)
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

	for (int i = 0; i < Tetra.numVertex; i++)
	{
		STetra.pVertexList[i] = Transform(Tetra.pVertexList[i], CTM);
	}

	// theta++;
}

void O_Tetra::Render(void)
{
	int w = 400;
	int h = 500;

	/*g_pGdi->YellowDot(STetra.pVertexList[0].x + w, STetra.pVertexList[0].y + h);
	g_pGdi->YellowDot(STetra.pVertexList[1].x + w, STetra.pVertexList[1].y + h);
	g_pGdi->YellowDot(STetra.pVertexList[2].x + w, STetra.pVertexList[2].y + h);
	g_pGdi->YellowDot(STetra.pVertexList[3].x + w, STetra.pVertexList[3].y + h);
	*/

	for (int i = 0; i < Tetra.numTriangle; i++)
	{
		Line(STetra.pVertexList[STetra.pVertexIndexList[i]].x + w,
			STetra.pVertexList[STetra.pVertexIndexList[i]].y + h,
			STetra.pVertexList[STetra.pVertexIndexList[i + 1]].x + w,
			STetra.pVertexList[STetra.pVertexIndexList[i + 1]].y + h);
		Line(STetra.pVertexList[STetra.pVertexIndexList[i + 1]].x + w,
			STetra.pVertexList[STetra.pVertexIndexList[i + 1]].y + h,
			STetra.pVertexList[STetra.pVertexIndexList[i + 2]].x + w,
			STetra.pVertexList[STetra.pVertexIndexList[i + 2]].y + h);
		Line(STetra.pVertexList[STetra.pVertexIndexList[i + 2]].x + w,
			STetra.pVertexList[STetra.pVertexIndexList[i + 2]].y + h,
			STetra.pVertexList[STetra.pVertexIndexList[i]].x + w,
			STetra.pVertexList[STetra.pVertexIndexList[i]].y + h);
	}
}

void O_Tetra::Line(int x1, int y1, int x2, int y2)
{
	D3DXVECTOR2 line[2];

	line[0] = D3DXVECTOR2(x1, y1);
	line[1] = D3DXVECTOR2(x2, y2);

	m_pd3dLine->Begin();
	m_pd3dLine->Draw(line, 2, D3DCOLOR_XRGB(255, 255, 255));
	m_pd3dLine->End();
}