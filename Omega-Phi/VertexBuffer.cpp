#include "VertexBuffer.h"
#include <GL/glew.h>
#include <iostream>
OP::VertexBuffer::VertexBuffer()
{

	glGenVertexArrays(1, &VertArray);
	glGenBuffers(1, &VertArrayBuffer);


	Bind();

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)( offsetof(Vertex, Vertex::texPos)));

	glVertexAttribPointer(2, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (const GLvoid*)(offsetof(Vertex, Vertex::color)));

	glVertexAttribPointer(3, 1, GL_UNSIGNED_INT, GL_FALSE, sizeof(Vertex), (const GLvoid*)(offsetof(Vertex, Vertex::texMap)));

	Unbind();
}

OP::VertexBuffer::~VertexBuffer()
{
	flush();
	glDeleteBuffers(1, &VertArrayBuffer);
	glDeleteVertexArrays(1, &VertArray);
}

void OP::VertexBuffer::Bind() const
{
	glBindVertexArray(VertArray);
	glBindBuffer(GL_ARRAY_BUFFER, VertArrayBuffer);
	glBufferData(GL_ARRAY_BUFFER, Index * sizeof(Vertex), Vertices, GL_DYNAMIC_DRAW);

}

void OP::VertexBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void OP::VertexBuffer::startBuffer(int size)
{
	flush();
	Vertices = new Vertex[size * 4];
}

void OP::VertexBuffer::submit(Vertex vertex)
{
	Vertices[Index] = vertex;
	Index++;
}

void OP::VertexBuffer::flush()
{
	if (Vertices != nullptr)
		delete[] Vertices;
	Vertices = nullptr;
	Index = 0;
}

int OP::VertexBuffer::getSize() const
{
	return Index;
}

void OP::VertexBuffer::print() const {
	for (int i = 0; i < Index; i++) {
		std::cout << Vertices[i].pos.x << " " << Vertices[i].pos.y << " " << Vertices[i].pos.z << " " << Vertices[i].color << " " << Vertices[i].texMap << " " << Vertices[i].texPos.x << " " << Vertices[i].texPos.y << " " << i << '\n';
	}
}

