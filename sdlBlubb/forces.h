#pragma once


#include <glm\glm.hpp>
#include "physicsObject.h"

void applyForce(physicsObject object, glm::vec3 force);

glm::vec3 accelerationFromForce(physicsObject object, glm::vec3 force);