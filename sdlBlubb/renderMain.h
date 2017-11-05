#pragma once

#include<SDL\SDL.h>
#include "observerPattern.h"
#include <iostream>
#include <SDL/SDL.h>
#include <glew/glew.h>
#include "shaderSetup.h"
#include "dataStructures.h"
#include "transformations.h"

class renderMain
{
public:
	renderMain();
	~renderMain();
	
	void initialiseObjects();
	void drawObjects();
	
	
	bool breakLoop = false;
	observer* obs_keyboard;
	GLint shaderProg;

	glm::mat4 trans;
	glm::mat4 orthoMatrix;
	GLint mvpLocation;
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;
	glm::mat4 mvp;

private:
	void initialiseSDL();
	void initialiseGLEW();

	float fovy;
	float aspectRatio;
	float zNear;
	float zFar;

	glm::vec3 cameraPos;
	glm::vec3 target;
	glm::vec3 up;


	SDL_Window* appWindow;
	SDL_Event windowEvent;

};

