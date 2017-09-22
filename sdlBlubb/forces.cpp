#include "forces.h"

void applyForce(physicsObject object, glm::vec3 force) // make object move
{
	object.setSpeed( object.getSpeed() + accelerationFromForce(object, force) ); // acceleration from force needs to be multiplied by frametime ! Frametimemanager !!!
}

glm::vec3 accelerationFromForce(physicsObject object, glm::vec3 force)
{
	return force / object.getMass();
}

