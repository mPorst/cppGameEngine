// sdlBlubb.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//

#include "stdafx.h"

#include <iostream>
#include <SDL/SDL.h>
#include <glew/glew.h>
#include "shaderSetup.h"
#include "dataStructures.h"


/*****GLint handleSDL::initializeSDL()
{
	GLint errorCode = SDL_Init(SDL_INIT_VIDEO);
	if (errorCode != 0)
	{
		printErrorMessage(errorCode, "SDL initialization");
		return 1;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

	Window = SDL_CreateWindow(
		"SDL2 WINDOW",
		50,
		50,
		400,
		400,
		SDL_WINDOW_OPENGL
		);

	context = SDL_GL_CreateContext(Window);

	glewExperimental = GL_TRUE; // tell glew I use modern oGL
	GLint glewErr = glewInit(); // glew needs to be initialised after context creation
	if (glewErr)
	{
		printErrorMessage(glewErr, "GLEW");
		SDL_Delay(3000);
		SDL_Quit();
		return 1;
	}

	return 0;
}******/

int main(int argc, char* argv[])
{
		/// Initialization stuff
	/// SDL setup
	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) == -1) 
	{
		std::cout << "SDL failed to initialize due to following reason:" << std::endl;
		std::cout << SDL_GetError() << std::endl;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

	// get an SDL window
	SDL_Window* appWindow = SDL_CreateWindow("app window", 50, 50, 800, 600, SDL_WINDOW_OPENGL);
	// create the context for the window
	SDL_GLContext appContext = SDL_GL_CreateContext(appWindow);

	// after context creation GLEW can be handled
	/// GLEW setup
	glewExperimental = GL_TRUE;
	GLint glewError = glewInit();
	if (glewError != GLEW_OK) 
	{
		std::cout << "glew did not initialize due to following error:" << std::endl;
		std::cout << glewError << std::endl;
		SDL_Delay(5000);
		exit(1);
	}

	/// get VAOs and VBOs up.
	GLuint vbo, vao;
	
	vao = createVAO();
	vbo = createVBO();
	
	// set data
	GLfloat triangle[6] = { 1.0, 1.0, 0.0, 0.0, 1.0, 0.0 };
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);

	// initialize shaders
	GLuint shaderProgram = shaderSetup::setupShaders();

	// tell how the input for the vertex shader is called
	glBindAttribLocation(shaderProgram, 1, "Position");
	GLint posAttrib = glGetAttribLocation(shaderProgram, "Position");

	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(posAttrib);
	
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_Event windowEvent;

	while (true)
	{
		//glClearColor(0.0, 1.0, 0.0, 1.0);
		//glClear(GL_COLOR_BUFFER_BIT);
		if (SDL_PollEvent(&windowEvent))
		{
			if (windowEvent.type == SDL_QUIT) break;
		}
		if (windowEvent.type == SDL_KEYDOWN)
		{
			glClearColor(0.0, 0.0, 1.0, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			//SDL_Delay(1000);
			std::cout << "Button press" << std::endl;
		}
		SDL_GL_SwapWindow(appWindow); 
	}

	return 0;
}