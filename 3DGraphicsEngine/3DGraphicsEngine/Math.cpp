#include "Math.h"
#include "olcPixelGameEngine.h"

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

float SetupRotationMatrices(mat4x4& matRotZ, mat4x4& matRotX, mat4x4& reverseMatRotZ, mat4x4& reverseMatRotX, float fTheta, float fElapsedTime) {
	fTheta += 1.0f * fElapsedTime;
		// Reverse Rotation Z
		reverseMatRotZ.m[0][0] = cosf(fTheta * 0.5f);
		reverseMatRotZ.m[0][1] = sinf(fTheta * 0.5f);
		reverseMatRotZ.m[1][0] = -sinf(fTheta * 0.5f);
		reverseMatRotZ.m[1][1] = cosf(fTheta * 0.5f);
		reverseMatRotZ.m[2][2] = 1;
		reverseMatRotZ.m[3][3] = 1;

		// Reverse Rotation X
		reverseMatRotX.m[0][0] = 1;
		reverseMatRotX.m[1][1] = cosf(fTheta);
		reverseMatRotX.m[1][2] = sinf(fTheta);
		reverseMatRotX.m[2][1] = -sinf(fTheta);
		reverseMatRotX.m[2][2] = cosf(fTheta);
		reverseMatRotX.m[3][3] = 1;

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


