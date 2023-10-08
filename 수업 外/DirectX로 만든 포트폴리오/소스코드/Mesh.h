#pragma once

class CVertex;
class CMesh
{
public:
	int numVertex; //�������� ����
	int numTriangle; //�ﰢ���� ����
	CVertex* pVertexList; //������ ������ ������(�迭)
	int* pVertexIndexList;//�ﰢ�� ���� ���� ������(�迭)
public:
	CMesh(void);
	~CMesh(void);

	CMesh& operator=(const CMesh& ref)
	{
		pVertexIndexList = ref.pVertexIndexList;

		return *this;
	}
};

