#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "renderMain.h"



renderMain::renderMain() 
{
	obs_keyboard = new observer();
	initialiseSDL();
	initialiseGLEW();
	orthoMatrix = glm::mat4(1.0f);
	trans = glm::mat4(1.0f);
	model = glm::mat4(1.0f);
	view = glm::mat4(1.0f);
	projection = glm::mat4(1.0f);
	fovy = glm::radians(45.0f);
	aspectRatio = 800 / 600; //(fixed ratio)
	zNear = 0.1f;
	zFar = 100.0f;
	cameraPos = glm::vec3(1.0f, 1.0f, 1.0f);
	target = glm::vec3(0.0f, 0.0f, 0.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
}


renderMain::~renderMain()
{
}

void renderMain::initialiseSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		std::cout << "SDL failed to initialise due to following reason:" << std::endl;
		std::cout << SDL_GetError() << std::endl;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

	// get an SDL window
	appWindow = SDL_CreateWindow("app window", 50, 50, 800, 600, SDL_WINDOW_OPENGL);
	// create the context for the window
	SDL_GLContext appContext = SDL_GL_CreateContext(appWindow);
}

void renderMain::initialiseGLEW()
{
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
}

void renderMain::initialiseObjects()
{
	/// get VAOs and VBOs up.
	GLuint vbo, vao;
	
	vao = createVAO();
	vbo = createVBO();

	// set data
	GLfloat triangle[12] = { 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0 };
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);

	// initialise shaders
	GLuint shaderProgram = shaderSetup::setupShaders();
	shaderProg = shaderProgram;

	// tell how the input for the vertex shader is called
	glBindAttribLocation(shaderProgram, 1, "Position");
	GLint posAttrib = glGetAttribLocation(shaderProgram, "Position");

	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(posAttrib);

	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

}

void renderMain::drawObjects()
{
	mvpLocation = glGetUniformLocation(shaderProg, "mvp");
	sysKey keyboardInput = obs_keyboard->getKey();
	sysKey nilSysKey = { NIL_SYS, NO_KEY };
	const float MOVEMENT_STEP = 0.1;
	if (keyboardInput != nilSysKey) // This acts as "pull event" -> actually done in input manager
	{
		if (keyboardInput.key == GAME_EXIT) 
		{
			breakLoop = true;
		}
		else if (keyboardInput.key == MOVE_FORWARD)
		{ // move forward
			trans *= glm::translate(orthoMatrix, glm::vec3(0, 0, MOVEMENT_STEP));
			std::cout << "translation Matrix:" << trans[3][0] << " " << trans[3][1] << " " << trans[3][2] << std::endl;
		}
		else if (keyboardInput.key == MOVE_BACK)
		{ // move back
			trans *= translation(0, 0, -MOVEMENT_STEP);
			std::cout << "translation Matrix:" << trans[3][0] << " " << trans[3][1] << " " << trans[3][2] << std::endl;
		}
		else if (keyboardInput.key == MOVE_LEFT)
		{ // move left
			trans *= glm::translate(orthoMatrix, glm::vec3(-MOVEMENT_STEP,0, 0));
			std::cout << "translation Matrix:" << trans[3][0] << " " << trans[3][1] << " " << trans[3][2] << std::endl;
		}
		else if (keyboardInput.key == MOVE_RIGHT)
		{ // move right
			trans *= translation(MOVEMENT_STEP,0, 0);
			std::cout << "translation Matrix:" << trans[3][0] << " " << trans[3][1] << " " << trans[3][2] << std::endl;
		}
		else if (keyboardInput.key == CAMERA_UP)
		{ // move camera up
			cameraPos += glm::vec3(0.0f, 1.0f, 0.0f);
			std::cout << "translation Matrix:" << trans[3][0] << " " << trans[3][1] << " " << trans[3][2] << std::endl;
		}

	}
	if (keyboardInput.key != GAME_EXIT && keyboardInput.key != NO_KEY)  // When a key has been pressed that is NOT exit
	{
		
	}

	// MVP matrices
	model = trans;
	view = glm::lookAt(cameraPos, target, up);
	projection = glm::perspective(fovy, aspectRatio, zNear, zFar);
	mvp = projection*view*model;

	glClearColor(0.0, 0.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	// The following 4 lines are subject to change !!! should be an automated loop for EACH model !
	glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, &mvp[0][0]);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	mvp = projection*view*orthoMatrix;
	glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, &mvp[0][0]);
	glDrawArrays(GL_TRIANGLES, 3, 3);
	//SDL_Delay(1000);
	//std::cout << "Button press:" << keyboardInput.key << std::endl;
	SDL_GL_SwapWindow(appWindow);
	
}