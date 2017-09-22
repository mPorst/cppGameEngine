#include "stdafx.h"
#include "renderObject.h"


renderObject::renderObject() { }

renderObject::renderObject(std::vector<GLfloat>* frame) : _renderFrame(frame) { } //initialisation list

renderObject::~renderObject() { }

// setters

void renderObject::setFrame(std::vector<GLfloat>* frame) { _renderFrame = frame; }

// getters

std::vector<GLfloat>* renderObject::getFrame() { return _renderFrame; }
	

