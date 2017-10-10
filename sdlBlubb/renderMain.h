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
	GLint transMatrixLocation;

private:
	void initialiseSDL();
	void initialiseGLEW();


	SDL_Window* appWindow;
	SDL_Event windowEvent;

};

