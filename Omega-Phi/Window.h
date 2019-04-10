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
#include <unordered_map>
#include "ivec2.h"

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
		OP::ivec2 size;
		GLFWwindow* l_Window;
		std::unordered_map<char, bool> l_KeyStates;


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

		/**
		 * @fn	void Window::UpdateKeys(const char* key, int action);
		 *
		 * @brief	Updates the keys
		 *
		 * @param	key   	The key.
		 * @param	action	The action.
		 */

		void UpdateKeys(char key, int action);

		bool getKey(char key);

		ivec2 getSize();

		static void error_callback(int error, const char* description)
		{
			fprintf(stderr, "Error: %s\n", description);
		}


	};
}