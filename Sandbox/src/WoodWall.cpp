#include <sp/sparky.h>
#include <sp/app/Application.h>

#include "TestLayer.h"

using namespace sp;
using namespace graphics;
using namespace maths;

#define WIDTH 960
#define HEIGHT 540

class WoodWall : public Application
{
public:
	WoodWall()
		: Application("Sandbox", WIDTH, HEIGHT)
	{
	}

	~WoodWall()
	{
	}

	void Init() override
	{
		Application::Init();
		//PushLayer(new TestLayer());
		PushLayer(new TestLayer());
	}
};

int main()
{
	WoodWall Woodwall;
	Woodwall.Start();
	return 0;
}