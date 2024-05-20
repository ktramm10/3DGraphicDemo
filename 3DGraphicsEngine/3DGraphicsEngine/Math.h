#pragma once
#include "Geometry.h"

void MultiplyMatrixVector(vec3d& i, vec3d& o, mat4x4& m);
float SetupRotationMatrices(mat4x4& matRotZ, mat4x4& matRotX, mat4x4& reverseMatRotZ, mat4x4& reverseMatRotX, float fTheta, float fElapsedTime);