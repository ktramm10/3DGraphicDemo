#pragma once
#include "Geometry.h"

void MultiplyMatrixVector(vec3d& i, vec3d& o, mat4x4& m);
float SetupRotationMatrices(mat4x4& matRotZ, mat4x4& matRotX, mat4x4& matRotY, float fTheta, float fElapsedTime, float rotSpeed);
void SetupProjMatrix(mat4x4& matProj, float screenH, float screenW);
mesh ApplyRotation(mat4x4 matRotX, mat4x4 matRotY, mat4x4 matRotZ, mesh meshShape);