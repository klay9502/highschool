#pragma once

typedef struct tagMatrix
{
	float m11, m12, m13, m14;
	float m21, m22, m23, m24;
	float m31, m32, m33, m34;
	float m41, m42, m43, m44;
}MATRIX;

MATRIX Identity(void);
MATRIX Translate(float dx, float dy, float dz);
MATRIX RotateX(float angle);
MATRIX RotateY(float angle);
MATRIX RotateZ(float angle);
MATRIX Multiply(MATRIX m1, MATRIX m2);
VERTEX Transform(VERTEX v, MATRIX m);