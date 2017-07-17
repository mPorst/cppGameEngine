#ifdef _WIN32
	#pragma once
#endif

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

glm::mat4 rotation (float angle, glm::vec3 axis);
glm::mat4 translation (float x, float y, float z);