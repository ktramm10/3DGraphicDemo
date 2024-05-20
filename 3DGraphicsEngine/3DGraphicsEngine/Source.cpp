

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "Geometry.h"
#include "Math.h"


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

	mat4x4 matProj;

	float fTheta;
	float const observer_dist = 10.0f;


public:
	void DrawShapes(mesh& meshShape, mat4x4 matRotZ, mat4x4 matRotX) {
		for (auto tri : meshShape.tris) {
			triangle triProjected, triTranslated, triRotatedZ, triRotatedZX;


			// Rotate in Z-Axis
			MultiplyMatrixVector(tri.p[0], triRotatedZ.p[0], matRotZ);
			MultiplyMatrixVector(tri.p[1], triRotatedZ.p[1], matRotZ);
			MultiplyMatrixVector(tri.p[2], triRotatedZ.p[2], matRotZ);

			// Rotate in X-Axis
			MultiplyMatrixVector(triRotatedZ.p[0], triRotatedZX.p[0], matRotX);
			MultiplyMatrixVector(triRotatedZ.p[1], triRotatedZX.p[1], matRotX);
			MultiplyMatrixVector(triRotatedZ.p[2], triRotatedZX.p[2], matRotX);

			// Offset into the screen
			triTranslated = triRotatedZX;
			triTranslated.p[0].z = triRotatedZX.p[0].z + observer_dist;
			triTranslated.p[1].z = triRotatedZX.p[1].z + observer_dist;
			triTranslated.p[2].z = triRotatedZX.p[2].z + observer_dist;

			// Project triangles from 3D --> 2D
			MultiplyMatrixVector(triTranslated.p[0], triProjected.p[0], matProj);
			MultiplyMatrixVector(triTranslated.p[1], triProjected.p[1], matProj);
			MultiplyMatrixVector(triTranslated.p[2], triProjected.p[2], matProj);

			// Scale into view

			// Moves Shape into Center of Screen
			triProjected.p[0].x += 1.0f;
			triProjected.p[0].y += 1.0f;
			triProjected.p[1].x += 1.0f;
			triProjected.p[1].y += 1.0f;
			triProjected.p[2].x += 1.0f;
			triProjected.p[2].y += 1.0f;

			triProjected.p[0].x *= 0.5f * (float)ScreenWidth();
			triProjected.p[0].y *= 0.5f * (float)ScreenHeight();
			triProjected.p[1].x *= 0.5f * (float)ScreenWidth();
			triProjected.p[1].y *= 0.5f * (float)ScreenHeight();
			triProjected.p[2].x *= 0.5f * (float)ScreenWidth();
			triProjected.p[2].y *= 0.5f * (float)ScreenHeight();


			DrawTriangle(triProjected.p[0].x, triProjected.p[0].y,
				triProjected.p[1].x, triProjected.p[1].y,
				triProjected.p[2].x, triProjected.p[2].y,
				olc::PixelF(100, 0, 20));
		}
	}
	bool OnUserCreate() override
	{
		// Initialize Mesh
		
		//InitializeMeshDiamond(meshShape, 2.0f);
		InitializeMeshCube(meshShape, 2.0f, 2.0f, -5.0f);
		InitializeMeshCube(meshShape_, 2.0f, 0.0f, 0.0f);
		//InitializeMeshPyramid(meshShape, 2.0f);
		
		// Projection Matrix
		float fNear = 0.1f;
		float fFar = 1000.0f;
		float fFov = 90.f;
		float fAspectRatio = (float)ScreenHeight() / (float)ScreenWidth();
		float fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * 3.14159f);
		matProj.m[0][0] = fAspectRatio * fFovRad;
		matProj.m[1][1] = fFovRad;
		matProj.m[2][2] = fFar / (fFar - fNear);
		matProj.m[3][2] = (-fFar * fNear) / (fFar - fNear);
		matProj.m[2][3] = 1.0f;
		matProj.m[3][3] = 0.0f;

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override {
		// Clear Screen 
		Clear(olc::BLACK);

		// Setup Rotation Matrix
		mat4x4 matRotZ, matRotX, reverseMatRotZ, reverseMatRotX;
		fTheta = SetupRotationMatrices(matRotZ, matRotX, reverseMatRotZ, reverseMatRotX, fTheta, fElapsedTime);
		DrawShapes(meshShape, matRotZ, matRotX);
		DrawShapes(meshShape_, matRotZ, matRotX);
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

