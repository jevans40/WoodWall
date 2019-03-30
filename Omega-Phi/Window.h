/**
 * @file	Window.h.
 *
 * @brief	Declares the window class
 */

#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <iostream>
#include <GLFW/glfw3.h>

/**
 * @namespace	OP
 *
 * @brief	Engine Workspace
 */

namespace OP {

	/**
	 * @class	Window
	 *
	 * @brief	A window.
	 */

	class Window {
	private:
		
		/** @brief	The window */
		GLFWwindow* l_Window;


	public:

		/**
		 * @fn	Window::Window(std::string Name, int x, int y);
		 *
		 * @brief	Constructor
		 *
		 * @param	Name	The name.
		 * @param	x   	The x size.
		 * @param	y   	The y size.
		 */
		Window(const char* Name, int x, int y);

		/**
		 * @fn	Window::~Window();
		 *
		 * @brief	Destructor
		 */

		~Window();

		/**
		 * @fn	void Window::Init();
		 *
		 * @brief	Initializes the window and GLFW
		 */

		void Init();

		/**
		 * @fn	bool Window::isRunning();
		 *
		 * @brief	Query if this object is running
		 *
		 * @returns	True if running, false if not.
		 */

		bool isRunning();

		/**
		 * @fn	GLFWwindow* Window::getWindow();
		 *
		 * @brief	Gets the window
		 *
		 * @returns	Null if it fails, else the window.
		 */

		GLFWwindow* getWindow();


		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

		static void error_callback(int error, const char* description)
		{
			fprintf(stderr, "Error: %s\n", description);
		}


	};
}