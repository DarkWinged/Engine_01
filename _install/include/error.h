#ifndef ERROR_H
#define ERROR_H

#ifdef _WIN32
	#include <SDL.h>
#elif __APPLE__
	#include <SDL2/SDL.h>
#elif __linux__
	#include <SDL2/SDL.h>
#endif

#include <string>

extern void fatalError(std::string errorString);

#endif