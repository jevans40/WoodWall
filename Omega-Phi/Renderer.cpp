#include "Renderer.h"
#include <GL/glew.h>

OP::Renderer::Renderer()
{
	Init();
}

void OP::Renderer::Init()
{

	glGenVertexArrays(1, &vertexArray);
	glGenBuffers(1, &vertexArrayBuffer);
	//glGenBuffers(1, &elementArrayBuffer);

	//GLuint elements[] = { 0, 1, 2, 2, 3, 0 };



	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(vertexArray);

	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffer);



	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Converting Vertex into a OpenGL readable object

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)(offsetof(Vertex, Vertex::texPos)));

	glVertexAttribPointer(2, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (const GLvoid*)(offsetof(Vertex, Vertex::color)));

	glVertexAttribPointer(3, 1, GL_UNSIGNED_INT, GL_FALSE, sizeof(Vertex), (const GLvoid*)(offsetof(Vertex, Vertex::texMap)));


	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
