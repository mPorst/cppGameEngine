#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "dataStructures.h"

GLuint createVAO()
{
	// setup vertex array so it saves everything what happens after this point
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	return vao;
}

GLuint createVBO()
{
	//setup vertex buffer object
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	return vbo;
}