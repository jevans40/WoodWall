
#include "Renderer.h"
#include <GL/glew.h>
#include <algorithm>

OP::Renderer::Renderer(Window * window) : l_Window(window)
{
	Init();
}

void OP::Renderer::Init()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


void OP::Renderer::addLayer(Layer *toRender)
{
	l_Layers.push_back(toRender);
	//std::sort(l_Layers.begin(), l_Layers.end(), [](Layer layer1, Layer layer2) {return layer1.getPriority() < layer2.getPriority(); });
}

void OP::Renderer::commitRender()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	int width;
	int height;
	glfwGetWindowSize(l_Window->getWindow(), &width, &height);

	OP::mat4f mat;
	OP::mat4f::glOrtho(height,0,0,width,1,0,mat);
	glViewport(0, 0, width, height);


	//Uniforms
	for (int i = 0; i < l_Layers.size(); i++) {
		glUseProgram(l_Layers[i]->getShader().getShaderProgram());

		GLint loc = glGetUniformLocation(l_Layers[i]->getShader().getShaderProgram(), "MVT");
		glUniformMatrix4fv(loc,1, GL_FALSE, mat.data);

		l_Layers[i]->getVertexBuffer().Bind();
		glDrawArrays(GL_QUADS, 0, l_Layers[i]->getVertexBuffer().getSize());
		l_Layers[i]->getVertexBuffer().Unbind();
	}
}
