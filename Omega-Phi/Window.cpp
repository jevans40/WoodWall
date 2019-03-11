#include "Window.h"

/**
 * @namespace	OP
 *
 * @brief	The engine workspace
 */

namespace OP {

	Window::Window(const char * name = "Game name", int x = 0, int y = 0 ) {
		Init();

		l_Window = glfwCreateWindow(x, y, name, NULL, NULL);
		if (!l_Window)
		{
			glfwTerminate();
			throw std::exception("Failed to gain window Context!");
		}

		glfwMakeContextCurrent(l_Window);

		glewExperimental = true;
		GLenum err = glewInit();
		if (err != GLEW_OK)
		{
			//Problem: glewInit failed, something is seriously wrong.
			std::cout << "glewInit failed, aborting. Code " << glewGetErrorString(err) << ". " << std::endl;
			throw std::exception("Failed to initilize GLEW!");
		}
		printf("%s\n", glGetString(GL_VERSION));
	}

	Window::~Window() {

	}

	void Window::Init() {

		if (!glfwInit())
			throw std::exception("Failed to initilize GLFW!");

	
	}
	bool Window::isRunning()
	{
		return !glfwWindowShouldClose(l_Window);
	}
	GLFWwindow * Window::getWindow()
	{
		if (l_Window != nullptr)
			return l_Window;
		return nullptr;
	}
}