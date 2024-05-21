#include "Math.h"
#include "olcPixelGameEngine.h"
#include <vector>

void MultiplyMatrixVector(vec3d& i, vec3d& o, mat4x4& m)
{
	o.x = i.x * m.m[0][0] + i.y * m.m[1][0] + i.z * m.m[2][0] + m.m[3][0];
	o.y = i.x * m.m[0][1] + i.y * m.m[1][1] + i.z * m.m[2][1] + m.m[3][1];
	o.z = i.x * m.m[0][2] + i.y * m.m[1][2] + i.z * m.m[2][2] + m.m[3][2];
	float w = i.x * m.m[0][3] + i.y * m.m[1][3] + i.z * m.m[2][3] + m.m[3][3];

	if (w != 0.0f)
	{
		o.x /= w; o.y /= w; o.z /= w;
	}
}

float SetupRotationMatrices(mat4x4& matRotZ, mat4x4& matRotX, mat4x4& matRotY, float fTheta, float fElapsedTime, float rotSpeed) {
	fTheta += rotSpeed * fElapsedTime;
		
		// Rotation Y
	matRotY.m[0][0] = cosf(fTheta);
	matRotY.m[1][1] = 1;
	matRotY.m[2][2] = cosf(fTheta);
	matRotY.m[3][3] = 1;
	matRotY.m[2][0] = -sinf(fTheta);
	matRotY.m[0][2] = sinf(fTheta);

		// Rotation Z
	matRotZ.m[0][0] = cosf(fTheta);
	matRotZ.m[0][1] = sinf(fTheta);
	matRotZ.m[1][0] = -sinf(fTheta);
	matRotZ.m[1][1] = cosf(fTheta);
	matRotZ.m[2][2] = 1;
	matRotZ.m[3][3] = 1;

		// Rotation X
	matRotX.m[0][0] = 1;
	matRotX.m[1][1] = cosf(fTheta * 0.5f);
	matRotX.m[1][2] = sinf(fTheta * 0.5f);
	matRotX.m[2][1] = -sinf(fTheta * 0.5f);
	matRotX.m[2][2] = cosf(fTheta * 0.5f);
	matRotX.m[3][3] = 1;


	return fTheta;
}

void SetupProjMatrix(mat4x4& matProj, float screenH, float screenW)
{
	// Projection Matrix
	float fNear = 0.1f;
	float fFar = 1000.0f;
	float fFov = 90.f;
	float fAspectRatio = (float)screenH / (float)screenW;
	float fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * 3.14159f);
	matProj.m[0][0] = fAspectRatio * fFovRad;
	matProj.m[1][1] = fFovRad;
	matProj.m[2][2] = fFar / (fFar - fNear);
	matProj.m[3][2] = (-fFar * fNear) / (fFar - fNear);
	matProj.m[2][3] = 1.0f;
	matProj.m[3][3] = 0.0f;
}

mesh ApplyRotation(mat4x4 matRotX, mat4x4 matRotY, mat4x4 matRotZ, mesh meshShape)
{
	mesh rotatedMesh;
	for (auto tri : meshShape.tris) {
		triangle triProjected, triTranslated, firstRotTri, secondRotTri, thirdRotTri, finalTri;

		switch (meshShape.rot) {
			// X Rotation
		case 0:
			for (int i = 0; i <= 2; i++) {
				MultiplyMatrixVector(tri.p[i], firstRotTri.p[i], matRotX);
			}
			finalTri = firstRotTri;
			break;
			// Y Rotation
		case 1:
			for (int i = 0; i <= 2; i++) {
				MultiplyMatrixVector(tri.p[i], firstRotTri.p[i], matRotY);
			}
			finalTri = firstRotTri;
			break;
			// Z Rotation
		case 2:
			for (int i = 0; i <= 2; i++) {
				MultiplyMatrixVector(tri.p[i], firstRotTri.p[i], matRotZ);
			}
			finalTri = firstRotTri;
			break;
			// XY Rotation
		case 3:
			for (int i = 0; i <= 2; i++) {
				MultiplyMatrixVector(tri.p[i], firstRotTri.p[i], matRotX);
				MultiplyMatrixVector(firstRotTri.p[i], secondRotTri.p[i], matRotY);
			}
			finalTri = secondRotTri;
			break;
			// XZ Rotation
		case 4:
			for (int i = 0; i <= 2; i++) {
				MultiplyMatrixVector(tri.p[i], firstRotTri.p[i], matRotX);
				MultiplyMatrixVector(firstRotTri.p[i], secondRotTri.p[i], matRotZ);
			}
			finalTri = secondRotTri;
			break;
			// YZ Rotation
		case 5:
			for (int i = 0; i <= 2; i++) {
				MultiplyMatrixVector(tri.p[i], firstRotTri.p[i], matRotY);
				MultiplyMatrixVector(firstRotTri.p[i], secondRotTri.p[i], matRotZ);
			}
			finalTri = secondRotTri;
			break;
			// XYZ Rotation
		case 6:
			for (int i = 0; i <= 2; i++) {
				MultiplyMatrixVector(tri.p[i], firstRotTri.p[i], matRotY);
				MultiplyMatrixVector(firstRotTri.p[i], secondRotTri.p[i], matRotZ);
				MultiplyMatrixVector(secondRotTri.p[i], thirdRotTri.p[i], matRotX);
			}
			finalTri = thirdRotTri;
			break;
		}
		rotatedMesh.tris.push_back(finalTri);
	}
	return rotatedMesh;
}


