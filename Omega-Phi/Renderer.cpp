
#include "Renderer.h"
#include <GL/glew.h>
#include <algorithm>

OP::Renderer::Renderer()
{
	Init();
}

void OP::Renderer::Init()
{

}

void OP::Renderer::addLayer(Layer *toRender)
{
	l_Layers.push_back(toRender);
	//std::sort(l_Layers.begin(), l_Layers.end(), [](Layer layer1, Layer layer2) {return layer1.getPriority() < layer2.getPriority(); });
}

void OP::Renderer::commitRender()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//Uniforms
	for (int i = 0; i < l_Layers.size(); i++) {
		glUseProgram(l_Layers[i]->getShader().getShaderProgram());
		l_Layers[i]->getVertexBuffer().Bind();
		glDrawArrays(GL_QUADS, 0, l_Layers[i]->getVertexBuffer().getSize());
		l_Layers[i]->getVertexBuffer().Unbind();
	}
}
