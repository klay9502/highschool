#pragma once

#define PI 3.141592

class CVertex;
class CMatrix
{
public: // public 변수
	float m11, m12, m13, m14;
	float m21, m22, m23, m24;
	float m31, m32, m33, m34;
	float m41, m42, m43, m44;
public: // public 함수
	CMatrix(void);
	~CMatrix(void);

	CMatrix Identity(void);
	CMatrix Translate(float dx, float dy, float dz);
	CMatrix RotateX(float angle);
	CMatrix RotateY(float angle);
	CMatrix RotateZ(float angle);
	CMatrix Multiply(CMatrix m1, CMatrix m2);
	CVertex Transform(CVertex v, CMatrix m);
};

