#include "stdafx.h"
#include "entity.h"


entity::entity(float mass, std::vector<GLfloat>* frame, int dimension)
{
	GLfloat vecEntry;
	int counter = 0;
	glm::vec2 center2d = { 0,0 };
	glm::vec3 center3d = { 0,0,0 };

	if(dimension == 2){
		for (const auto& vecEntry : *frame) // beatiful range based for loop
		{
			if (counter % 2 == 0) {
				center2d.x += vecEntry;
			}
			else {
				center2d.y += vecEntry;
			}
			counter++;
		}
		center2d /= (counter / 2); // normalise for number of vertices
		_physicsObject = new physicsObject(mass, center2d);
	}


	else if (dimension == 3) {
		for (const auto& vecEntry : *frame) // beatiful range based for loop
		{
			if (counter % 3 == 0) {
				center3d.x += vecEntry;
			}
			else if (counter % 3 == 1) {
				center3d.y += vecEntry;
			}
			else {
				center3d.z += vecEntry;
			}
			counter++;
		}
		center3d /= (counter / 2); // normalise for number of vertices
		_physicsObject = new physicsObject(mass, center3d);
	}

	_renderObject = new renderObject();
}


entity::~entity()
{
	_renderObject->~renderObject();
	_physicsObject->~physicsObject();
}
