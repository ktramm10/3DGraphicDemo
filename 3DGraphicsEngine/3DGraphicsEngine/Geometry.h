#pragma once
#include <vector>
struct vec3d
{
	float x, y, z;
};

struct triangle
{
	vec3d p[3];
};

struct mesh
{
	std::vector<triangle> tris;
	// 0 = x, 1 = y, 2 = z, 3 = xy
	int rot;
};

struct mat4x4
{
	float m[4][4] = { 0 };
};



void InitializeMeshCube(mesh& meshCube, float const SIDE_LEN, float const offsetX, float const offsetY, int rot);
void InitializeMeshPyramid(mesh& meshPyramid, float const SIDE_LEN, float const offsetX, float const offsetY);
void InitializeMeshDiamond(mesh& meshDiamond, float const SIDE_LEN, float const offsetX, float const offsetY);
