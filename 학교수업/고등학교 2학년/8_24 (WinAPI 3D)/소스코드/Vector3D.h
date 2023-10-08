#pragma once

// 3D 점을 구성하는 구조체
typedef struct tagPOINT3D
{
	float x, y, z;
}POINT3D;

// 3D 꼭지점을 구성하는 구조체 // 점 + 동차좌표계(rhw)
typedef struct tagVERTEX
{
	float x, y, z, w;
}VERTEX;

// 삼각형을 구성 // 삼각형 연결 순서를 가짐.
typedef struct tagTRIANGLE
{
	int v1, v2, v3;
}TRIANGLE;

// 3D 오프젝트 최소의 단위 // 하나의 덩어리
typedef struct tagMESH
{
	int numVertex; // 꼭짓점의 개수
	int numTriangle; // 삼각형의 개수
	VERTEX* pVertexList; // 꼭짓점 데이터 포인터(배열)
	//TRIANGLE* pVertexIndexList; // 삼각형 연결 정보 포인터(배열)
	int* pVertexIndexList; // 삼각형 연결 정보 포인터(배열)
}MESH;