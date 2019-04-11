#include "Input.h"
#include <string>

std::vector<OP::Window *> OP::Input::l_Windows = std::vector<OP::Window *>();

void OP::Input::addWindow(OP::Window * window)
{
	if(window != nullptr)
	l_Windows.push_back(window);
}

void OP::Input::removeWindow(OP::Window * window)
{
	for (int i = 0; i < l_Windows.size(); i++) {
		if (l_Windows[i] == window) {
			l_Windows.erase(l_Windows.begin() +i);
		}
	}

}

void OP::Input::key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	for (int i = 0; i < l_Windows.size(); i++) {
		if (l_Windows[i]->getWindow() == window) {
				l_Windows[i]->UpdateKeys(glfwGetKeyName(key, 0)[0], action);
			if (key != int(key)) {
				//std::cout << glfwGetKeyName(key, 0) << std::endl;
			}

				//l_Windows[i]->UpdateKeys(glfwGetKeyName(std::to_string(int(key)).c_str(), 0), action);
			return;
		}
	}

}
