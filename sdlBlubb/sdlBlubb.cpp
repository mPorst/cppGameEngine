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
	renderMain* renderer = new renderMain(); // initialisation done in constructor
	renderer->initialiseObjects(); // VAOs and VBOs, shaders...
	inputManager* input = new inputManager();

	// connect objects
	input->manager->addObserver(renderer->keyboard);

	while (true)
	{
		input->getInput();
		renderer->drawObjects();
		if (renderer->breakLoop == true) { break; }

	}

	return 0;
}
