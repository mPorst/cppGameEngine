// sdlBlubb.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include <iostream>
#include <SDL/SDL.h>
#include <glew/glew.h>
#include "shaderSetup.h"
#include "dataStructures.h"
#include "renderMain.h"
#include "inputManager.h"


int main(int argc, char* argv[])
{
	/// Initialise the render object
	renderMain* renderer = new renderMain(); // Initialise new render object
	renderer->initialiseObjects(); // VAOs and VBOs, shaders... (low level)
	inputManager* input = new inputManager(); // Initialise the input manager

	// connect objects
	input->sub_manager->addObserver(renderer->obs_keyboard); // renderer registers to inputManager

	std::cout << "observer list size:" << input->sub_manager->observerListSize() << std::endl;

	while (true)
	{
		input->getInput();
		renderer->drawObjects();
		if (renderer->breakLoop == true) { break; }
	}

	std::cout << "regular shutdown" << std::endl;
	SDL_Delay(1000);

	return 0;
}
