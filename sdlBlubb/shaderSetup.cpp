#include "stdafx.h"
#include "shaderSetup.h"

#include "errorHandling.h"
#include "fileIO.h"

#include <glew/glew.h>
#include <string>
#include <iostream>


GLuint shaderSetup::setupShaders()
{
	// the shader program "connects the shaders, that are supposed to work together"
	GLuint shaderProgram = glCreateProgram();
	GLuint vertexShader = 0, fragmentShader = 0;
	//compilation
	shaderSetup::compileShader(&vertexShader, GL_VERTEX_SHADER, "shader.vert");
	shaderSetup::compileShader(&fragmentShader, GL_FRAGMENT_SHADER, "shader.frag");
	// attaching
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	// output for fragment shader (in minimal example not necessary
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	//linking
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	return shaderProgram;
}

GLboolean shaderSetup::compileShader(GLuint *shader, GLenum type, GLchar* sourceFile)
{
	//setup shader objects
	*shader = glCreateShader(type); // assign a value to shader that references the actual shader
	std::string fullShaderCode; // variable for shader code
	fullShaderCode = readFullFile(sourceFile); // read in shader code
												  // some dirty conversion shit has to be done for glShaderSource:
												  // note that this is only for data structure reasons. Usually you would want to feed the string right into that function glShaderSource
												  // instead you have to use that dirty compatibilityChar
	const GLchar *compatibilityChar = fullShaderCode.c_str();
	glShaderSource(*shader, 1, &compatibilityChar, 0); //tell oGL where the shader code for shader is, there is only 1 piece of code which is stored in compatibility char
	glCompileShader(*shader);
	// variables needed for error checking
	GLint result;
	GLsizei infoLength;
	GLchar infoLog[2000];
	// get some results for error checking
	glGetShaderiv(*shader, GL_COMPILE_STATUS, &result);
	glGetShaderiv(*shader, GL_INFO_LOG_LENGTH, &infoLength);
	// actual error checking
	if (result == GL_FALSE) {
		glGetShaderInfoLog(*shader, 2000, &infoLength, infoLog);
		std::cout << infoLog << std::endl;
		if (type == GL_VERTEX_SHADER || type == GL_FRAGMENT_SHADER)
		{
			std::string errorMessage = "Fatal shader compilation error in vertex or fragment shader. Can't procced.";
			std::cout << result << std::endl;
			fatalError(errorMessage);
		}
	}
	return result;
}


