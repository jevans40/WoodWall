#include "Layer.h"

namespace OP {

	Layer::Layer(Window* window, const char* name = "Default Name", int priority = 0) {
		l_Window = window;
		l_name = name;
		l_Priority = priority;
	}

	void Layer::Update(int Time) {

		//TODO
	}

	void Layer::Render() {

	}

	void Layer::AddRenderable() { //Renderable renderable
		//TODO
	}

}