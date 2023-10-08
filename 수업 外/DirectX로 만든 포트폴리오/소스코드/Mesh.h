#pragma once

class CVertex;
class CMesh
{
public:
	int numVertex; //꼭지점의 개수
	int numTriangle; //삼각형의 개수
	CVertex* pVertexList; //꼭지점 데이터 포인터(배열)
	int* pVertexIndexList;//삼각형 연결 정보 포인터(배열)
public:
	CMesh(void);
	~CMesh(void);

	CMesh& operator=(const CMesh& ref)
	{
		pVertexIndexList = ref.pVertexIndexList;

		return *this;
	}
};

