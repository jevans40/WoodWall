#include "Window.h"
#include <FreeImage.h>

/**
 * @namespace	OP
 *
 * @brief	The engine workspace
 */

namespace OP {


	void FreeImageErrorHandler(FREE_IMAGE_FORMAT fif, const char *message) {
		printf("\n*** ");
		if (fif != FIF_UNKNOWN) {
			printf("%s Format\n", FreeImage_GetFormatFromFIF(fif));
		}
		printf(message);
		printf(" ***\n");
	}

	void GLAPIENTRY
		MessageCallback(GLenum source,
			GLenum type,
			GLuint id,
			GLenum severity,
			GLsizei length,
			const GLchar* message,
			const void* userParam)
	{
		if(severity != GL_DEBUG_SEVERITY_NOTIFICATION)
		fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
			(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
			type, severity, message);
	}


	Window::Window(const char * name = "Game name", int x = 0, int y = 0 ) {
		Init();

		l_Window = glfwCreateWindow(x, y, name, NULL, NULL);
		if (!l_Window)
		{
			glfwTerminate();
			throw std::exception("Failed to gain window Context!");
		}

		glfwMakeContextCurrent(l_Window);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

		glewExperimental = true;
		GLenum err = glewInit();

		DLL_API void DLL_CALLCONV FreeImage_Initialise(BOOL load_local_plugins_only FI_DEFAULT(FALSE));		FreeImage_SetOutputMessage(FreeImageErrorHandler);

		if (err != GLEW_OK)
		{
			//Problem: glewInit failed, something is seriously wrong.
			std::cout << "glewInit failed, aborting. Code " << glewGetErrorString(err) << ". " << std::endl;
			throw std::exception("Failed to initilize GLEW!");
		}
		printf("%s\n", glGetString(GL_VERSION));

		glfwSetErrorCallback(error_callback);
		glfwSwapInterval(1);
	// During init, enable debug output
	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(MessageCallback, 0);
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