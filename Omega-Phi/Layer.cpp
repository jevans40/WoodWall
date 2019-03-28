#include "Layer.h"
#include <algorithm>
namespace OP {


	Layer::~Layer()
	{
		delete[] l_name;
		delete &l_VertexBuffer;
		delete &l_Sprites;

	}

	void Layer::Update(int Time) {

		//TODO
	}

	void Layer::Render() {
		l_VertexBuffer.startBuffer(l_Sprites.size());
		for (size_t i = 0; i < l_Sprites.size(); i++) {
			Vertex* vert = l_Sprites[i]->getVertexArray();
			l_VertexBuffer.submit(vert[0]);
			l_VertexBuffer.submit(vert[1]);
			l_VertexBuffer.submit(vert[2]);
			l_VertexBuffer.submit(vert[3]);
		}
		//l_VertexBuffer.flush();
	}

	void Layer::AddRenderable(Renderable &renderable) { //Renderable renderable
		l_Sprites.push_back(&renderable);
		//std::sort(l_Sprites.begin(), l_Sprites.end(), [](Renderable * left, Renderable * right) {return  left->getZPos() < right->getZPos(); });
	}

	int Layer::getPriority() const
	{
		return l_Priority;
	}

	void Layer::AddTexture(GLuint texID, GLuint texUnit)
	{
		glUseProgram(l_Shader.getShaderProgram());
		glActiveTexture(GL_TEXTURE0 + texUnit);
		glBindTexture(GL_TEXTURE_2D, texID);
		glUniform1i(texUnit, 0);
	}

	const Shader &Layer::getShader()
	{
		return l_Shader;
	}

	const VertexBuffer &Layer::getVertexBuffer()
	{
		return l_VertexBuffer;
	}

}