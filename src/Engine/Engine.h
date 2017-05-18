#ifndef ENGINE_H
#define ENGINE_H

#ifdef _WIN32
	#include <glew.h>
	#include <Windows.h>
	#include <SDL.h>
#elif __APPLE__
	#include <SDL2/SDL.h>
    #include <GLUT/glut.h>
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
#elif __linux__
	#include <GL/glut.h>
	#include <SDL2/SDL.h>
#endif

#include "../Sprite/Sprite.h"
#include "../GLSL/GLSLProgram.h"
#include "../Error/error.h"

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
#endif