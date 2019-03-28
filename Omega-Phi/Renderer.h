#pragma once
#include "Layer.h"
#include "Window.h"
#include <vector>

namespace OP {

	class Renderer {
	private:
		 std::vector<Layer *> l_Layers;
		 int numOfSprites;
		 Window * l_Window;
	public:
		 Renderer(Window * window);

		 void Init();

		 void addLayer(Layer *toRender);

		 void commitRender();



	};

}