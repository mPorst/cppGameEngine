#pragma once

#include<glm\glm.hpp>

class physicsObject
{
public:
	physicsObject(float startMass, glm::vec3 centerPoint);
	physicsObject(float startMass, glm::vec2 centerPoint);
	~physicsObject();

	void setMass(float mass);
	void setSpeed(glm::vec3 speed);

	float getMass();
	glm::vec3 getSpeed();

private:
	float _mass = 0;
	glm::vec3 _centerOfMass = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 _speed = glm::vec3(0.0f, 0.0f, 0.0f);


};

