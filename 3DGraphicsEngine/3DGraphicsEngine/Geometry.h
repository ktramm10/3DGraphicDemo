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
};

struct mat4x4
{
	float m[4][4] = { 0 };
};

void InitializeMeshCube(mesh& meshCube, float const SIDE_LEN);
void InitializeMeshPyramid(mesh& meshPyramid, float const SIDE_LEN);
void InitializeMeshDiamond(mesh& meshDiamond, float const SIDE_LEN);
