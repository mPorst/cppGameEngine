#include "stdafx.h"

#include "errorHandling.h"

#include <iostream>
#include <SDL\SDL.h>

void fatalError(std::string errorText)
{
	std::cout << "A fatal error occurred. Shutting down. Error message:" << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << errorText << std::endl;
	std::cout << "------------------" << std::endl;
	SDL_Delay(10000);
	exit(1);
}

void fatalError(char* errorText)
{
	std::cout << "A fatal error occurred. Shutting down. Error message:" << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << errorText << std::endl;
	std::cout << "------------------" << std::endl;
	SDL_Delay(10000);
	exit(1);
}
