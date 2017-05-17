#pragma once

#ifdef __APPLE__
	#include <SDL2/SDL.h>
#endif
#ifdef _WIN32
	#include <SDL.h>
#endif

#include <string>

extern void fatalError(std::string errorString);