#pragma once

#ifdef __APPLE__
	#include <SDL2/SDL.h>
    #include <GLUT/glut.h>
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
#endif
#ifdef _WIN32
	#include <glew.h>
	#include <Windows.h>
	#include <SDL.h>
#endif
#ifdef __linux__
	#ifndef __APPLE__
		#include <SDL2/SDL.h>
		#include <GL/glut.h>
	#endif
#endif

#include "../Sprite/Sprite.h"
#include "../GLSL/GLSLProgram.h"

enum class GameState {PLAY, EXIT};

class Engine {
public:
	Engine();
	Engine(int arg0, int arg1);
	~Engine();

	void run();

private:
	void initilize();
	void initShaders();
	void processInput();
	void gameLoop();
	void drawGame();


	SDL_Window* _window;
	int _screenWidth;
	int _screenHeight;
	GameState _gameState;

	Sprite _sprite;

	GLSLProgram _shaderProgram;
};