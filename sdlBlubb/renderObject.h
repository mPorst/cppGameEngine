#pragma once
#include <vector>
#include <glew\glew.h>


class renderObject
{
public:
	renderObject();
	renderObject(std::vector<GLfloat>* frame);
	~renderObject();

	void setFrame(std::vector<GLfloat>* frame);
	std::vector<GLfloat>* getFrame();

private:
	std::vector<GLfloat>* _renderFrame;
};

