#include "Layer.h"
#include "Game.h"
#include <algorithm>
#include "Simple2DPhysics.h"
namespace OP {


	Layer::~Layer()
	{
		delete[] l_name;
		delete &l_VertexBuffer;
		delete &l_Sprites;

	}

	void Layer::Update(std::chrono::milliseconds Time) {
		for (int i = 0; i < l_Sprites.size(); i++) {
			l_Sprites[i]->Update(Time);
		}
		
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
		renderable.setLayer(this);
		//std::sort(l_Sprites.begin(), l_Sprites.end(), [](Renderable * left, Renderable * right) {return  left->getZPos() < right->getZPos(); });
	}

	void Layer::removeRenderable(Renderable & renderable)
	{
		for (int i = 0; i < l_Sprites.size(); i++) {
			if (&renderable == l_Sprites[i]) {
				delete l_Sprites[i];
				l_Sprites.erase(l_Sprites.begin() + i);
				break;
			}
		}
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

	bool Layer::getKey(const char* key)
	{
		return ((Game *) p_Game)->getKey(key[0]);
	}

}