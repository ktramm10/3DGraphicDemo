

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Example";
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override;
};


int main()
{
	Example demo;
	if (demo.Construct(400, 392, 2, 2))
		demo.Start();

	return 0;
}

inline bool Example::OnUserUpdate(float fElapsedTime)
{
	// called once per frame
	for (int x = 0; x < ScreenWidth(); x++)
		for (int y = 0; y < ScreenHeight(); y++)
			Draw(x, y, olc::Pixel(150, 1, 255));
	return true;
}
