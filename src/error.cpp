#include "error.h"

#include <iostream>
#include <SDL.h>

void fatalError(std::string errorString)
{
	std::cout << errorString << std::endl;
	std::cout << "Enter any key to exit...";
	int tmp;
	std::cin >> tmp;
	SDL_Quit();
	exit(1);
}