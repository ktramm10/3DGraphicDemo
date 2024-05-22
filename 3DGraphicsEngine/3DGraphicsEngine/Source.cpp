

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "Geometry.h"
#include "Math.h"
#include <string>


class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "3D Engine";
	}
private:
	mesh meshShape;
	mesh meshShape_;
	std::string sRot;

	mat4x4 matProj;

	float fTheta;
	float const observer_dist = 10.0f;
	


public:
	void DrawShapes(mesh& meshShape, mat4x4 matRotZ, mat4x4 matRotX, mat4x4 matRotY) {
		triangle triProjected, triTranslated, triRotated;
		mesh rotatedMesh;

		// Rotate Shape

		rotatedMesh = ApplyRotation(matRotX, matRotY, matRotZ, meshShape);

		for (auto tri : rotatedMesh.tris) {

			// Offset into the screen

			triTranslated = tri;
			triTranslated.p[0].z = tri.p[0].z + observer_dist;
			triTranslated.p[1].z = tri.p[1].z + observer_dist;
			triTranslated.p[2].z = tri.p[2].z + observer_dist;

			// Project triangles from 3D --> 2D

			MultiplyMatrixVector(triTranslated.p[0], triProjected.p[0], matProj);
			MultiplyMatrixVector(triTranslated.p[1], triProjected.p[1], matProj);
			MultiplyMatrixVector(triTranslated.p[2], triProjected.p[2], matProj);

			// Moves Shape into Center of Screen

			for (int i = 0; i < 3; i++) {
				triProjected.p[i].x += 1.0f;
				triProjected.p[i].x *= 0.5f * (float)ScreenWidth();

				triProjected.p[i].y += 1.0f;
				triProjected.p[i].y *= 0.5f * (float)ScreenHeight();

			}

			// Draw Shape

			DrawTriangle(triProjected.p[0].x, triProjected.p[0].y,
				triProjected.p[1].x, triProjected.p[1].y,
				triProjected.p[2].x, triProjected.p[2].y,
				olc::PixelF(100, 0, 20));
			
		}
	}

	bool OnUserCreate() override
	{
		/*
		* Rotation Key:
		* 0 = X
		* 1 = Y
		* 2 = Z
		* 3 = XY
		* 4 = ZX
		* 5 = YZ
		*/

		InitializeMeshCube(meshShape_, 2.0f, 1.0f, 1.0f, 0);
		sRot = DetermineTitle(meshShape_);
		SetupProjMatrix(matProj, ScreenHeight(), ScreenWidth());
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override {
		// Clear Screen 

		Clear(olc::BLACK);

		// Draw Title
		//DrawString(0, 5, sRot, olc::WHITE, 2);

		// Setup Rotation Matrix

		mat4x4 matRotZ, matRotX, matRotY;
		fTheta = SetupRotationMatrices(matRotZ, matRotX, matRotY, fTheta, fElapsedTime, 2.0f);

		// Rotate and Draw Shapes

		DrawShapes(meshShape_, matRotZ, matRotX, matRotY);

		return true;
	}
};


int main()
{
	Example demo;
	if (demo.Construct(400, 392, 2, 2))
		demo.Start();

	return 0;
}

