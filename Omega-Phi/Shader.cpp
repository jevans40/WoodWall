#include "Shader.h"
#include "FileLoader.h"
#include <iostream>
#include <string>
#include <GL/glew.h>
#include <vector>

OP::Shader::Shader(const char * vertShaderFile, const char * fragShaderFile)
{

	/** @brief	Get a Vert and Frag shader from files */

	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	std::string vertShader = OP::loadFile(vertShaderFile);
	std::string fragShader = OP::loadFile(fragShaderFile);

	if (vertShader == "\0" || fragShader == "\0") {
		std::cout << "FAILED TO LOAD SHADERS FRAG: " << fragShader << " VERT: " << vertShader << std::endl;
		l_ProgramID = GL_FALSE;
		return;
	}


	GLint test = GL_FALSE;
	int InfoLogLength;

	//Compile and test the Vert and Frag Shaders

	const char * VertexSource = vertShader.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSource, NULL);
	glCompileShader(VertexShaderID);


	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &test);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}


	char const * FragmentSourcePointer = fragShader.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
	glCompileShader(FragmentShaderID);


	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &test);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
		printf("%s\n", &FragmentShaderErrorMessage[0]);
	}

	//Link the Shaders
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glBindFragDataLocation(ProgramID, 0, "fragcolor");
	glLinkProgram(ProgramID);


	//Check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &test);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}

	glDetachShader(ProgramID, VertexShaderID);
	glDetachShader(ProgramID, FragmentShaderID);

	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	this->l_ProgramID = ProgramID;

}

OP::Shader::Shader(const Shader & shader)
{
	if (shader.getShaderProgram() == GL_FALSE) {
		std::cout << "WARNING ATTEMPING TO COPY A NULL SHADER" << std::endl;
	}

	this->l_ProgramID = shader.getShaderProgram();
}

GLuint OP::Shader::getShaderProgram() const
{

	if (this->l_ProgramID == GL_FALSE) {
		std::cout << "WARNING ATTEMPING TO GET A NULL SHADER" << std::endl;
	}

	return l_ProgramID;
}
