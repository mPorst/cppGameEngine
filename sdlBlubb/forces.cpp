#include "forces.h"

void applyForce(physicsObject object, glm::vec3 force) // make object move
{
	object.speed += accelerationFromForce(object,force)
}

glm::vec3 accelerationFromForce(physicsObject object, glm::vec3 force)
{
	return force / object.mass;
}
