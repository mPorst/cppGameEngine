#pragma once

#include<SDL\SDL.h>
#include "observerPattern.h"

class renderMain
{
public:
	renderMain();
	~renderMain();
	
	void initialiseObjects();
	void drawObjects();
	
	
	bool breakLoop = false;
	observer* keyboard;

private:
	void initialiseSDL();
	void initialiseGLEW();


	SDL_Window* appWindow;

};

