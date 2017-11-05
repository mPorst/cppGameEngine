#include "stdafx.h"
#include "inputManager.h"
#include "observerPattern.h"
#include<SDL\SDL.h>


inputManager::inputManager()
{
	sub_manager = new subject();
}


inputManager::~inputManager()
{

}

void inputManager::getInput()
{ // initialise to NO_KEY so nothing goes wrong at program start (that bamboozled me)
	sub_manager->notify(INPUT, NO_KEY);
	if (SDL_PollEvent(&windowEvent))
	{
		switch (windowEvent.type) {
			case SDL_QUIT:
				sub_manager->notify(INPUT, GAME_EXIT);
				break;
			case SDL_KEYDOWN:
				switch (windowEvent.key.keysym.sym) {
					case SDLK_a:
						sub_manager->notify(INPUT, MOVE_LEFT);
						break;
					case SDLK_w:
						sub_manager->notify(INPUT, MOVE_FORWARD);
						break;
					case SDLK_d:
						sub_manager->notify(INPUT, MOVE_RIGHT);
						break;
					case SDLK_s:
						sub_manager->notify(INPUT, MOVE_BACK);
						break;
					case SDLK_0:
						sub_manager->notify(INPUT, CAMERA_UP);
						break;
				break;
		}


		}
		std::cout << "SOME BLOODY FUCK HAPPENED. YOU PRESSED SCANCODE:" << windowEvent.key.keysym.sym << std::endl;

}

}
