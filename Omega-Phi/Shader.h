#pragma once
#include <GL/glew.h>


namespace OP {
	class Shader {
	private:
		GLuint l_ProgramID;
	public:

		/**
		 * @fn	Shader::Shader(char* vertShader, char* fragShader);
		 *
		 * 
		 * @brief	Constructor
		 *
		 * @param [in,out]	vertShader	If non-null, the vertex shader file location.
		 * @param [in,out]	fragShader	If non-null, the fragment shader file location.
		 */

		Shader(const char* vertShader,const char* fragShader);

		/**
		 * @fn	Shader::Shader(const Shader &shader);
		 *
		 * @brief	Copy constructor
		 *
		 * @param	shader	The shader to copy.
		 */

		Shader(const Shader &shader);



		/**
		 * @fn	GLuint Shader::getShaderProgram();
		 *
		 * @brief	Gets shader program
		 *
		 * @returns	The shader program.
		 */

		GLuint getShaderProgram() const;




	};
}