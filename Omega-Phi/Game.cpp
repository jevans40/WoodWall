#include "Game.h"
#include <cstdint>
#include <cassert>
#include <FreeImage.h>

OP::Game::Game(const char* gameName, int x , int y)
{
	l_Window = new Window(gameName, x, y);
}

OP::Game::~Game()
{
	delete &l_Layers;
	glfwTerminate();
}

void OP::Game::Start()
{
	int time = 1;
	while (l_Window->isRunning()) {
		//TODO  add a timer
		
		Render();
		Update(time);
		time++;

	}
}

void OP::Game::Init()
{
	//~~~To be implemented
}

void OP::Game::AddLayer(Layer &newLayer)
{
	l_Renderer.addLayer(&newLayer);
	l_Layers.push_back(&newLayer);
}


void OP::Game::Render()
{
	//Ready the layers for Rendering
	for (int i = 0; i < l_Layers.size(); i++) {
		l_Layers[i]->Render();
	}

	//Render the layers	
	l_Renderer.commitRender();

	/* Swap front and back buffers */
	glfwSwapBuffers(l_Window->getWindow());



}

void OP::Game::Update(int time)
{
	glfwPollEvents();


}
