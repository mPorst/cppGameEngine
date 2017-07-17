#ifdef _WIN32
	#pragma once
#endif

#include <glm\glm.hpp>
#include "physicsObject.h"

glm::vec3 applyForce(float centerOfMass);

glm::vec3 accelerationFromForce(glm::vec3 force);