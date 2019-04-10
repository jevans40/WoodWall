#pragma once
#include <unordered_map>
#include "Window.h"


namespace OP {
	class Input {
		static std::vector<OP::Window *> l_Windows;

	public:
		
		static void addWindow(OP::Window * window);

		static void removeWindow(OP::Window * window);

		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);


	};
}