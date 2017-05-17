#pragma once

#include <SDL.h>
#include <glew.h>
#include <Windows.h>
#include "Sprite.h"
#include "GLSLProgram.h"

enum class GameState {PLAY, EXIT};

class Engine
{
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