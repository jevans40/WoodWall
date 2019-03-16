#include "Game.h"
#include <cstdint>
#include <cassert>
#include <FreeImage.h>

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
	shader = new OP::Shader("VertexShader.vert", "FragShader.frag");
}

#pragma pack(push, 0)

struct Vertex {
	float Pos[2];
	float TexPos[2];
	unsigned int Color;
	unsigned int TexMap;
};

#pragma pack(pop)

void OP::Game::Render()
{

	/* Render here */
	int Height, Width;
	glfwGetFramebufferSize(l_Window->getWindow() , &Width, &Height);
	glViewport(0, 0, Width,Height);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	GLuint vertexArrayBuffer;
	GLuint vertexArray;
	//GLuint elementArrayBuffer;

	glGenVertexArrays(1, &vertexArray);
	glGenBuffers(1, &vertexArrayBuffer);
	//glGenBuffers(1, &elementArrayBuffer);

	//GLuint elements[] = { 0, 1, 2, 2, 3, 0 };

	Vertex vertices[] = {
		{-0.5f,  0.5f, 0.0f, 0.0f, 0xf0ff0000,0 }, // Top-left
		{0.5f,  0.5f, 1.0f, 0.0f, 0xf000ff00,0}, // Top-right
		{0.5f,  -0.5f, 1.0f, 1.0f, 0xff0000ff,0 }, // Bottom-right
		{-0.5f,  -0.5f, 0.0f, 1.0f, 0xffffffff,0}  // Bottom-left
	};
	

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(vertexArray);
	 
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffer);



	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Converting Vertex into a OpenGL readable object

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);
	
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)(offsetof(Vertex, Vertex::TexPos)));

	glVertexAttribPointer(2, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (const GLvoid*)(offsetof(Vertex, Vertex::Color)));

	glVertexAttribPointer(3, 1, GL_UNSIGNED_INT, GL_FALSE, sizeof(Vertex), (const GLvoid*)(offsetof(Vertex, Vertex::TexMap)));


	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);




	glUseProgram(shader->getShaderProgram());
	glBindVertexArray(vertexArray);
	glDrawArrays(GL_QUADS, 0,4);
	glBindVertexArray(0);


	/* Poll for and process events */
	glDeleteBuffers(1, &vertexArrayBuffer);
	glDeleteVertexArrays(1, &vertexArray);
	glfwPollEvents();

	/* Swap front and back buffers */
	glfwSwapBuffers(l_Window->getWindow());
}

void OP::Game::Update(int time)
{


}
