// sdlBlubb.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

#include <iostream>
#include <SDL/SDL.h>
#include <glew/glew.h>
#include "shaderSetup.h"
#include "dataStructures.h"
#include "renderMain.h"


int main(int argc, char* argv[])
{
	/// Initialise the render object
	renderMain* renderer = new renderMain(); // initialisation done in constructor
	renderer->initialiseObjects();

	while (true)
	{
		renderer->drawObjects();
		if (renderer->breakLoop == true) { break; }

	}

	return 0;
}
