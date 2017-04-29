#pragma once

#include<SDL\SDL.h>

class renderMain
{
public:
	renderMain();
	~renderMain();
	
	void initialiseObjects();
	void drawObjects();
	
	
	bool breakLoop = false;


private:
	void initialiseSDL();
	void initialiseGLEW();


	SDL_Window* appWindow;

};

