#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "transformations.h"

glm::mat4 rotation(float angle, glm::vec3 axis)
{
	glm::mat4 rot;
	return glm::rotate(rot, angle, axis);
}

glm::mat4 translation(float x, float y, float z)
{
	glm::mat4 trans;
	return glm::translate(trans, glm::vec3(x,y,z));
}

glm::mat4 translation(float x, float y)
{
	glm::mat4 trans;
	return glm::translate(trans, glm::vec3(x, y, 0));
}