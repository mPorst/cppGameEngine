#ifdef _WIN32
	#pragma once
#endif


class inputManager
{
public:
	inputManager();
	~inputManager();

	void getInput();

	//variables
	subject* manager;

private:

	SDL_Event windowEvent;
};

