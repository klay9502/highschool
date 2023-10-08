#include "stdafx.h"
#include "Matrix.h"
#include "Vertex.h"


CMatrix::CMatrix(void)
{
	// empty...
}

CMatrix::~CMatrix(void)
{
	// empty...
}

// 단위 행렬
CMatrix CMatrix::Identity(void)
{
	CMatrix m;

	m.m11 = 1.0f;	m.m12 = 0.0f;	m.m13 = 0.0f;	m.m14 = 0.0f;
	m.m21 = 0.0f;	m.m22 = 1.0f;	m.m23 = 0.0f;	m.m24 = 0.0f;
	m.m31 = 0.0f;	m.m32 = 0.0f;	m.m33 = 1.0f;	m.m34 = 0.0f;
	m.m41 = 0.0f;	m.m42 = 0.0f;	m.m43 = 0.0f;	m.m44 = 1.0f;

	return m;
}

// 이동 행렬
CMatrix CMatrix::Translate(float dx, float dy, float dz)
{
	CMatrix m;

	m.m11 = 1.0f;	m.m12 = 0.0f;	m.m13 = 0.0f;	m.m14 = 0.0f;
	m.m21 = 0.0f;	m.m22 = 1.0f;	m.m23 = 0.0f;	m.m24 = 0.0f;
	m.m31 = 0.0f;	m.m32 = 0.0f;	m.m33 = 1.0f;	m.m34 = 0.0f;
	m.m41 = dx;		m.m42 = dy;		m.m43 = dz;		m.m44 = 1.0f;

	return m;
}

// X축 회전행렬
CMatrix CMatrix::RotateX(float angle)
{
	CMatrix Matrix;
	float cos_theta = 0, sin_theta = 0;
	float theta = angle * (float)PI / 180;

	cos_theta = (float)cos(theta);
	sin_theta = (float)sin(theta);

	Matrix.m11 = 1.0f;		Matrix.m12 = 0.0f;		Matrix.m13 = 0.0f;		Matrix.m14 = 0.0f;
	Matrix.m21 = 0.0f;		Matrix.m22 = cos_theta;	Matrix.m23 = sin_theta;	Matrix.m24 = 0.0f;
	Matrix.m31 = 0.0f;		Matrix.m32 = -sin_theta; Matrix.m33 = cos_theta; Matrix.m34 = 0.0f;
	Matrix.m41 = 0.0f;		Matrix.m42 = 0.0f;		Matrix.m43 = 0.0f;		Matrix.m44 = 1.0f;

	return Matrix;
}

// Y축 회전행렬
CMatrix CMatrix::RotateY(float angle)
{
	CMatrix Matrix;
	float cos_theta = 0, sin_theta = 0;
	float theta = angle * (float)PI / 180;

	cos_theta = (float)cos(theta);
	sin_theta = (float)sin(theta);

	Matrix.m11 = cos_theta;	Matrix.m12 = 0.0f;		Matrix.m13 = -sin_theta; Matrix.m14 = 0.0f;
	Matrix.m21 = 0.0f;		Matrix.m22 = 1.0f;		Matrix.m23 = 0.0f;		Matrix.m24 = 0.0f;
	Matrix.m31 = sin_theta;	Matrix.m32 = 0.0f;		Matrix.m33 = cos_theta; Matrix.m34 = 0.0f;
	Matrix.m41 = 0.0f;		Matrix.m42 = 0.0f;		Matrix.m43 = 0.0f;		Matrix.m44 = 1.0f;

	return Matrix;
}

// Z축 회전행렬
CMatrix CMatrix::RotateZ(float angle)
{
	CMatrix Matrix;
	float cos_theta = 0, sin_theta = 0;
	float theta = angle * (float)PI / 180;

	cos_theta = (float)cos(theta);
	sin_theta = (float)sin(theta);

	Matrix.m11 = cos_theta;	Matrix.m12 = sin_theta;	Matrix.m13 = 0.0f;		Matrix.m14 = 0.0f;
	Matrix.m21 = -sin_theta; Matrix.m22 = cos_theta; Matrix.m23 = 0.0f;		Matrix.m24 = 0.0f;
	Matrix.m31 = 0.0f;		Matrix.m32 = 0.0f;		Matrix.m33 = 1.0f;		Matrix.m34 = 0.0f;
	Matrix.m41 = 0.0f;		Matrix.m42 = 0.0f;		Matrix.m43 = 0.0f;		Matrix.m44 = 1.0f;

	return Matrix;
}

// 행렬 곱셈
CMatrix CMatrix::Multiply(CMatrix m1, CMatrix m2)
{
	CMatrix m;

	m.m11 = (m1.m11 * m2.m11) + (m1.m12 * m2.m21) + (m1.m13 * m2.m31) + (m1.m14 * m2.m41);
	m.m12 = (m1.m11 * m2.m12) + (m1.m12 * m2.m22) + (m1.m13 * m2.m32) + (m1.m14 * m2.m42);
	m.m13 = (m1.m11 * m2.m13) + (m1.m12 * m2.m23) + (m1.m13 * m2.m33) + (m1.m14 * m2.m43);
	m.m14 = (m1.m11 * m2.m14) + (m1.m12 * m2.m24) + (m1.m13 * m2.m34) + (m1.m14 * m2.m44);
	m.m21 = (m1.m21 * m2.m11) + (m1.m22 * m2.m21) + (m1.m23 * m2.m31) + (m1.m24 * m2.m41);
	m.m22 = (m1.m21 * m2.m12) + (m1.m22 * m2.m22) + (m1.m23 * m2.m32) + (m1.m24 * m2.m42);
	m.m23 = (m1.m21 * m2.m13) + (m1.m22 * m2.m23) + (m1.m23 * m2.m33) + (m1.m24 * m2.m43);
	m.m24 = (m1.m21 * m2.m14) + (m1.m22 * m2.m24) + (m1.m23 * m2.m34) + (m1.m24 * m2.m44);
	m.m31 = (m1.m31 * m2.m11) + (m1.m32 * m2.m21) + (m1.m33 * m2.m31) + (m1.m34 * m2.m41);
	m.m32 = (m1.m31 * m2.m12) + (m1.m32 * m2.m22) + (m1.m33 * m2.m32) + (m1.m34 * m2.m42);
	m.m33 = (m1.m31 * m2.m13) + (m1.m32 * m2.m23) + (m1.m33 * m2.m33) + (m1.m34 * m2.m43);
	m.m34 = (m1.m31 * m2.m14) + (m1.m32 * m2.m24) + (m1.m33 * m2.m34) + (m1.m34 * m2.m44);
	m.m41 = (m1.m41 * m2.m11) + (m1.m42 * m2.m21) + (m1.m43 * m2.m31) + (m1.m44 * m2.m41);
	m.m42 = (m1.m41 * m2.m12) + (m1.m42 * m2.m22) + (m1.m43 * m2.m32) + (m1.m44 * m2.m42);
	m.m43 = (m1.m41 * m2.m13) + (m1.m42 * m2.m23) + (m1.m43 * m2.m33) + (m1.m44 * m2.m43);
	m.m44 = (m1.m41 * m2.m14) + (m1.m42 * m2.m24) + (m1.m43 * m2.m34) + (m1.m44 * m2.m44);

	return m;
}

// 행렬 변환 (버텍스*)
CVertex CMatrix::Transform(CVertex v, CMatrix m)
{
	CVertex tv;

	tv.x = v.x * m.m11 + v.y * m.m21 + v.z * m.m31, v.w * m.m41;
	tv.y = v.x * m.m12 + v.y * m.m22 + v.z * m.m32, v.w * m.m42;
	tv.z = v.x * m.m13 + v.y * m.m23 + v.z * m.m33, v.w * m.m43;
	tv.w = v.x * m.m14 + v.y * m.m24 + v.z * m.m34, v.w * m.m44;

	return tv;
}