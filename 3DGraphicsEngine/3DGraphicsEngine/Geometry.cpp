#include "Geometry.h"

void InitializeMeshPyramid(mesh& meshPyramid, float const SIDE_LEN, float const offsetX, float const offsetY) {

	meshPyramid.tris = {
		// BOTTOM
		{0.0f, 0.0f, 0.0f,   0.0f, SIDE_LEN, 0.0f,   SIDE_LEN, SIDE_LEN, 0.0f },
		{0.0f, 0.0f, 0.0f,   SIDE_LEN, SIDE_LEN, 0.0f,   SIDE_LEN, 0.0f, 0.0f },

		// SOUTH
		{0.0f, 0.0f, 0.0f,   SIDE_LEN / 2, SIDE_LEN / 2, SIDE_LEN,   SIDE_LEN, 0.0f, 0.0f},

		// WEST
		{0.0f, 0.0f, 0.0f,   SIDE_LEN / 2, SIDE_LEN / 2, SIDE_LEN,   0.0f, SIDE_LEN, 0.0f},

		// NORTH
		{0.0f, SIDE_LEN, 0.0f,   SIDE_LEN / 2, SIDE_LEN / 2, SIDE_LEN,   SIDE_LEN, SIDE_LEN, 0.0f},

		// EAST
		{SIDE_LEN, 0.0f, 0.0f,   SIDE_LEN / 2, SIDE_LEN / 2, SIDE_LEN,   SIDE_LEN, SIDE_LEN, 0.0f},

	};
}
void InitializeMeshCube(mesh& meshCube, float const SIDE_LEN, float const offsetX, float const offsetY) {
	meshCube.tris = {
		// SOUTH
		{0.0f + offsetX, 0.0f + offsetY, 0.0f,   0.0f + offsetX, SIDE_LEN + offsetY, 0.0f,   SIDE_LEN + offsetX, SIDE_LEN + offsetY, 0.0f },
		{0.0f + offsetX, 0.0f + offsetY, 0.0f,   SIDE_LEN + offsetX, SIDE_LEN + offsetY, 0.0f,   SIDE_LEN + offsetX, 0.0f + offsetY, 0.0f },

		// EAST
		{SIDE_LEN + offsetX, 0.0f + offsetY, 0.0f,   SIDE_LEN + offsetX, SIDE_LEN + offsetY, 0.0f,   SIDE_LEN + offsetX, SIDE_LEN + offsetY, SIDE_LEN },
		{SIDE_LEN + offsetX, 0.0f + offsetY, 0.0f,   SIDE_LEN + offsetX, SIDE_LEN + offsetY, SIDE_LEN,   SIDE_LEN + offsetX, 0.0f + offsetY, SIDE_LEN },

		// NORTH
		{SIDE_LEN + offsetX, 0.0f + offsetY, SIDE_LEN,   SIDE_LEN + offsetX, SIDE_LEN + offsetY, SIDE_LEN,   0.0f + offsetX, SIDE_LEN + offsetY, SIDE_LEN },
		{SIDE_LEN + offsetX, 0.0f + offsetY, SIDE_LEN,   0.0f + offsetX, SIDE_LEN + offsetY, SIDE_LEN,   0.0f + offsetX, 0.0f + offsetY, SIDE_LEN },

		// WEST
		{0.0f + offsetX, 0.0f + offsetY , SIDE_LEN,    0.0f + offsetX, SIDE_LEN + offsetY, SIDE_LEN,   0.0f + offsetX, SIDE_LEN + offsetY, 0.0f },
		{0.0f + offsetX, 0.0f + offsetY, SIDE_LEN,    0.0f + offsetX, SIDE_LEN + offsetY, 0.0f,   0.0f + offsetX, 0.0f + offsetY, 0.0f },

		// TOP
		{0.0f + offsetX, SIDE_LEN + offsetY, 0.0f,    0.0f + offsetX, 0.0f + offsetY, SIDE_LEN,   0.0f + offsetX, 0.0f + offsetY, 0.0f },
		{0.0f + offsetX, SIDE_LEN + offsetY, 0.0f,    SIDE_LEN + offsetX, SIDE_LEN + offsetY, SIDE_LEN,   SIDE_LEN + offsetX, SIDE_LEN + offsetY, 0.0f },

		// BOTTOM
		{SIDE_LEN + offsetX, 0.0f + offsetY, SIDE_LEN,    0.0f + offsetX, 0.0f + offsetY, SIDE_LEN,   0.0f + offsetX, 0.0f + offsetY, 0.0f },
		{SIDE_LEN + offsetX, 0.0f + offsetY, SIDE_LEN,    0.0f + offsetX , 0.0f + offsetY, 0.0f,   SIDE_LEN + offsetX, 0.0f + offsetY, 0.0f },
	};
}

void InitializeMeshDiamond(mesh& meshDiamond, float const SIDE_LEN, float const offsetX, float const offsetY) {
	meshDiamond.tris = {
		// BOTTOM
		{0.0f, 0.0f, 0.0f,   0.0f, SIDE_LEN, 0.0f,   SIDE_LEN, SIDE_LEN, 0.0f },
		{0.0f, 0.0f, 0.0f,   SIDE_LEN, SIDE_LEN, 0.0f,   SIDE_LEN, 0.0f, 0.0f },



		// TOP SOUTH
		{0.0f, 0.0f, 0.0f,   SIDE_LEN / 2, SIDE_LEN / 2, SIDE_LEN,   SIDE_LEN, 0.0f, 0.0f},

		// TOP WEST
		{0.0f, 0.0f, 0.0f,   SIDE_LEN / 2, SIDE_LEN / 2, SIDE_LEN,   0.0f, SIDE_LEN, 0.0f},

		// TOP NORTH
		{0.0f, SIDE_LEN, 0.0f,   SIDE_LEN / 2, SIDE_LEN / 2, SIDE_LEN,   SIDE_LEN, SIDE_LEN, 0.0f},

		// TOP EAST
		{SIDE_LEN, 0.0f, 0.0f,   SIDE_LEN / 2, SIDE_LEN / 2, SIDE_LEN,  SIDE_LEN, SIDE_LEN, 0.0f},



		// BOTTOM SOUTH
		{0.0f, 0.0f, 0.0f,   SIDE_LEN / 2, SIDE_LEN / 2, -SIDE_LEN,   SIDE_LEN, 0.0f, 0.0f},

		// BOTTOM WEST
		{0.0f, 0.0f, 0.0f,   SIDE_LEN / 2, SIDE_LEN / 2, -SIDE_LEN,   0.0f, SIDE_LEN, 0.0f},

		// BOTTOM NORTH
		{0.0f, SIDE_LEN, 0.0f,   SIDE_LEN / 2, SIDE_LEN / 2, -SIDE_LEN,   SIDE_LEN, SIDE_LEN, 0.0f},

		// BOTTOM EAST
		{SIDE_LEN, 0.0f, 0.0f,   SIDE_LEN / 2, SIDE_LEN / 2, -SIDE_LEN,   SIDE_LEN, SIDE_LEN, 0.0f},
	};
}