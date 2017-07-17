#include "stdafx.h"
#include "inputManager.h"
#include "observerPattern.h"
#include<SDL\SDL.h>


inputManager::inputManager()
{
	manager = new subject();
}


inputManager::~inputManager()
{

}

void inputManager::getInput()
{
	if (SDL_PollEvent(&windowEvent))
	{
		switch (windowEvent.type) {
			case SDL_QUIT:
				manager->notify(INPUT, GAME_EXIT);
				break;
			case SDL_SCANCODE_A:
				manager->notify(INPUT, MOVE_LEFT);
				break;
			case SDL_SCANCODE_W:
				manager->notify(INPUT, MOVE_FORWARD);
				break;
			case SDL_SCANCODE_D:
				manager->notify(INPUT, MOVE_RIGHT);
				break;
			case SDL_SCANCODE_S:
				manager->notify(INPUT, MOVE_BACK);
				break;
		}

		if(windowEvent.key.keysym.sym == SDL_SCANCODE_0)
	}

}
