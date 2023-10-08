#pragma once

// 3D ���� �����ϴ� ����ü
typedef struct tagPOINT3D
{
	float x, y, z;
}POINT3D;

// 3D �������� �����ϴ� ����ü // �� + ������ǥ��(rhw)
typedef struct tagVERTEX
{
	float x, y, z, w;
}VERTEX;

// �ﰢ���� ���� // �ﰢ�� ���� ������ ����.
typedef struct tagTRIANGLE
{
	int v1, v2, v3;
}TRIANGLE;

// 3D ������Ʈ �ּ��� ���� // �ϳ��� ���
typedef struct tagMESH
{
	int numVertex; // �������� ����
	int numTriangle; // �ﰢ���� ����
	VERTEX* pVertexList; // ������ ������ ������(�迭)
	//TRIANGLE* pVertexIndexList; // �ﰢ�� ���� ���� ������(�迭)
	int* pVertexIndexList; // �ﰢ�� ���� ���� ������(�迭)
}MESH;