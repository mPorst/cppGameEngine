#pragma once

#include "observerPattern.h"
#include <SDL/SDL.h>

class inputManager
{
public:
	inputManager();
	~inputManager();

	void getInput();

	//variables
	subject* sub_manager;

private:

	SDL_Event windowEvent;
};

