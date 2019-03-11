#include "Game.h"

OP::Game::Game(const char* gameName, int x , int y)
{
	Game::Init(gameName, x , y);
}

OP::Game::~Game()
{
	delete[] l_Layers;
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

void OP::Game::Init(const char* gameName, int x , int y )
{
	l_Window = new Window(gameName, x, y);
}

void OP::Game::Render()
{
	/* Render here */
	glClear(GL_COLOR_BUFFER_BIT);

	/* Swap front and back buffers */
	glfwSwapBuffers(l_Window->getWindow());

	/* Poll for and process events */
	glfwPollEvents();
}

void OP::Game::Update(int time)
{
	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
}
