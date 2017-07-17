#ifdef _WIN32
	#pragma once
#endif

#include<glm\glm.hpp>

class physicsObject
{
public:
	physicsObject(float startMass, glm::vec3 centerPoint);
	~physicsObject();

	float mass = 0;
	glm::vec3 centerOfMass = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 speed = 0;


};

