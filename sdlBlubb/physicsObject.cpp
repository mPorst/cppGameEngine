#include "stdafx.h"
#include "physicsObject.h"


physicsObject::physicsObject(float startMass, glm::vec3 centerPoint) {  }

physicsObject::physicsObject(float startMass, glm::vec2 centerPoint) {  }


physicsObject::~physicsObject()  { }

//setters

void physicsObject::setMass(float mass) { _mass = mass; }

void physicsObject::setSpeed(glm::vec3 speed) {	_speed = speed; }

// getters

float physicsObject::getMass() { return _mass; }

glm::vec3 physicsObject::getSpeed() { return _speed; }