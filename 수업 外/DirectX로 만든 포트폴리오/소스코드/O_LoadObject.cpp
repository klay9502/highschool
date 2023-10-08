#include "stdafx.h"
#include "O_LoadObject.h"
#include "WindowManager.h"
#include "InputManager.h"
#include "Vertex.h"


O_LoadObject::O_LoadObject(void)
{
	// empty...
}

O_LoadObject::~O_LoadObject(void)
{
	// empty...
}

void O_LoadObject::CreateObject(const char* _filename)
{
	char strTemp[256];

	ifstream fp;

	fp.open(_filename, ios::in);

	while (1)
	{
		fp >> strTemp;

		if (!strcmp("*MESH_NUMVERTEX", strTemp))
		{
			fp >> Mesh.numVertex;
			Mesh.pVertexList = new CVertex[Mesh.numVertex];
		//	Mesh.pVertexList = (CVertex*)malloc(sizeof(CVertex)*Mesh.numVertex);
		}

		if (!strcmp("*MESH_NUMFACES", strTemp))
		{
			fp >> Mesh.numTriangle;
			Mesh.pVertexIndexList = new int[Mesh.numTriangle * 3];
		//	Mesh.pVertexIndexList = (int*)malloc(sizeof(int)* Mesh.numTriangle * 3);
		}

		if (!strcmp("*MESH_VERTEX_LIST", strTemp))
		{
			fp >> strTemp; // {
			for (int i = 0; i < Mesh.numVertex; i++)
			{
				fp >> strTemp;
				fp >> strTemp;
				fp >> Mesh.pVertexList[i].x;
				fp >> Mesh.pVertexList[i].z;
				fp >> Mesh.pVertexList[i].y;
			}
		}

		if (!strcmp("*MESH_FACE_LIST", strTemp))
		{
			fp >> strTemp; // {

			for (int i = 0; i < Mesh.numTriangle * 3; i += 3)
			{
				fp >> strTemp;	// *MESH_FACE
				fp >> strTemp;	// 0:
				fp >> strTemp;	// A:
				fp >> Mesh.pVertexIndexList[i];
				fp >> strTemp;	// B:
				fp >> Mesh.pVertexIndexList[i + 1];
				fp >> strTemp;	// C:
				fp >> Mesh.pVertexIndexList[i + 2];
				fp >> strTemp;	// AB:
				fp >> strTemp;	// ;
				fp >> strTemp;	// BC:
				fp >> strTemp;	// ;
				fp >> strTemp;	// CA:
				fp >> strTemp;	// ;
				fp >> strTemp;	// *MESH_SMOOTHING
				fp >> strTemp;	// 1
				fp >> strTemp;	// *MESH_MTLID
				fp >> strTemp;	// 0
			}
			fp >> strTemp;	// }
			fp >> strTemp;	// }
			fp >> strTemp;	// *PROP_MOTIONBLUR
			fp >> strTemp;	// 0
			fp >> strTemp;	// *PROP_CASTSHADOW
			fp >> strTemp;	// 1
			fp >> strTemp;	// *PROP_RECVSHADOW
			fp >> strTemp;	// 1
			fp >> strTemp;	// *WIREFRAME_COLOR
			fp >> strTemp;	// ;
			fp >> strTemp;	// ;
			fp >> strTemp;	// ;
			fp >> strTemp;	// }
			break;

			fp.close();


			/*while (1)
			{
				static int i = 0;
				fp >> strTemp;

				if (!strcmp("A:", strTemp))
				{
					fp >> Mesh.pVertexIndexList[i];
					fp >> strTemp;
				}

				if (!strcmp("B:", strTemp))
				{
					fp >> Mesh.pVertexIndexList[i + 1];
					fp >> strTemp;
				}

				if (!strcmp("C:", strTemp))
				{
					fp >> Mesh.pVertexIndexList[i + 2];
					fp >> strTemp;
					i += 3;
				}

				if (!strcmp("}", strTemp))
				{
					break;
				}
			}*/
		}
	}

	SMesh.numVertex = Mesh.numVertex;
	SMesh.numTriangle = Mesh.numTriangle;
	SMesh.pVertexList = new CVertex[Mesh.numVertex];
	SMesh.pVertexIndexList = new int[Mesh.numTriangle * 3];
	
	SMesh = Mesh;

	D3DXCreateLine(WinMgr->m_pd3dDevice, &m_pd3dLine);
	m_pd3dLine->SetWidth(2);
}

void O_LoadObject::Process(void)
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

	for (int i = 0; i < Mesh.numVertex; i++)
	{
		SMesh.pVertexList[i] = Transform(Mesh.pVertexList[i], CTM);
	}

	// theta++;
}

void O_LoadObject::Render(void)
{
	int w = 400;
	int h = 500;

	/*g_pGdi->YellowDot(STetra.pVertexList[0].x + w, STetra.pVertexList[0].y + h);
	g_pGdi->YellowDot(STetra.pVertexList[1].x + w, STetra.pVertexList[1].y + h);
	g_pGdi->YellowDot(STetra.pVertexList[2].x + w, STetra.pVertexList[2].y + h);
	g_pGdi->YellowDot(STetra.pVertexList[3].x + w, STetra.pVertexList[3].y + h);
	*/

	for (int i = 0; i < Mesh.numTriangle * 3; i += 3)
	{
		Line(SMesh.pVertexList[SMesh.pVertexIndexList[i]].x + w,
			SMesh.pVertexList[SMesh.pVertexIndexList[i]].y + h,
			SMesh.pVertexList[SMesh.pVertexIndexList[i + 1]].x + w,
			SMesh.pVertexList[SMesh.pVertexIndexList[i + 1]].y + h);
		Line(SMesh.pVertexList[SMesh.pVertexIndexList[i + 1]].x + w,
			SMesh.pVertexList[SMesh.pVertexIndexList[i + 1]].y + h,
			SMesh.pVertexList[SMesh.pVertexIndexList[i + 2]].x + w,
			SMesh.pVertexList[SMesh.pVertexIndexList[i + 2]].y + h);
		Line(SMesh.pVertexList[SMesh.pVertexIndexList[i + 2]].x + w,
			SMesh.pVertexList[SMesh.pVertexIndexList[i + 2]].y + h,
			SMesh.pVertexList[SMesh.pVertexIndexList[i]].x + w,
			SMesh.pVertexList[SMesh.pVertexIndexList[i]].y + h);
	}
}

void O_LoadObject::Release(void)
{
	SMesh.pVertexIndexList = nullptr;
	SMesh.pVertexList = nullptr;
	Mesh.pVertexIndexList = nullptr;
	Mesh.pVertexList = nullptr;
}

void O_LoadObject::Line(int x1, int y1, int x2, int y2)
{
	D3DXVECTOR2 line[2];

	line[0] = D3DXVECTOR2(x1, y1);
	line[1] = D3DXVECTOR2(x2, y2);

	m_pd3dLine->Begin();
	m_pd3dLine->Draw(line, 2, D3DCOLOR_XRGB(255, 255, 255));
	m_pd3dLine->End();
}