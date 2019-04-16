#pragma once
#include "Renderable.h"
#include "OPMath.h"
#include <GL/glew.h>
namespace OP {



	class VertexBuffer {
	private:
		GLuint VertArrayBuffer;
		GLuint VertArray;
		unsigned int MaxSize = 4000;
		unsigned int Index = 0;
		Vertex* Vertices;

	public:

		/**
		 * @fn	VertexBuffer::VertexBuffer();
		 *
		 * @brief	Default constructor
		 */

		VertexBuffer();

		/**
		 * @fn	VertexBuffer::~VertexBuffer();
		 *
		 * @brief	Destructor
		 */

		~VertexBuffer();

		/**
		 * @fn	void VertexBuffer::Bind();
		 *
		 * @brief	Binds this Vertex Array
		 */

		void Bind() const;

		/**
		 * @fn	void VertexBuffer::Unbind();
		 *
		 * @brief	Unbinds this Vertex Array
		 */

		void Unbind() const;

		/**
		 * @fn	void VertexBuffer::startBuffer(int size);
		 *
		 * @brief	Starts a new buffer
		 *
		 * @param	size	The size in sprites.
		 */

		void startBuffer(int size);

		/**
		 * @fn	void VertexBuffer::submit(Vertex);
		 *
		 * @brief	Submits the given Vertex
		 *
		 * @param	Vertex	The Vertex.
		 */

		void submit(Vertex);

		/**
		 * @fn	void VertexBuffer::flush();
		 *
		 * @brief	Flushes the Vertex Buffer
		 */

		void flush();

		/**
		 * @fn	int VertexBuffer::getSize();
		 *
		 * @brief	Gets the size
		 *
		 * @returns	The size.
		 */

		int getSize() const;


		void print() const;
	};
}