#pragma once

#include "physicsObject.h"
#include "renderObject.h"


class entity
{
public:
	entity(float mass, std::vector<GLfloat>* frame, int dimension);
	~entity();

private:
	physicsObject* _physicsObject;
	renderObject* _renderObject;
};

