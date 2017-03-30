#pragma once

#include <glew\glew.h>


class shaderSetup {
	public:
	static GLuint shaderSetup::setupShaders();

	static GLboolean shaderSetup::compileShader(GLuint *shader, GLenum type, GLchar* sourceFile);

};