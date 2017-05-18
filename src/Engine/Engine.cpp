#include <iostream>
#include <string>

#include "Engine.h"
#include "../Error/error.h"

void display(void) {
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
}
 
Engine::Engine(int arg0, int arg1):_screenWidth(arg0),_screenHeight(arg1) {}

Engine::Engine() {
	_window = nullptr;
	_screenWidth = 800;
	_screenHeight = 900;
	_gameState = GameState::PLAY;
}

Engine::~Engine() {}


void Engine::run() {
	initilize();

	_sprite.init(-1.0f, -1.0f, 1.0f, 1.0f);

	gameLoop();
}

void Engine::initilize() {
    SDL_Init(SDL_INIT_EVERYTHING);

    _window = SDL_CreateWindow("Engine_01", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);

    if(_window == nullptr) {
    	fatalError("SDL Window could not be created!");
    }

    SDL_GLContext glContext = SDL_GL_CreateContext(_window);
    if(glContext == nullptr) {
    	fatalError("SDL_GL context could not be created!");
    }

#ifndef __APPLE__
    GLenum error = glewInit();
    if(error != GLEW_OK) {
    	fatalError("Could not initialize glew!");
    }
#endif

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	initShaders();
}

void Engine::initShaders() {
	_shaderProgram.compileShaders("./resources/shaders/shader.vert", "./resources/shaders/shader.frag");
	_shaderProgram.addAttribute("vertexPosition");
	_shaderProgram.linkShaders();
}

void Engine::gameLoop() {
	while(_gameState != GameState::EXIT) {
		processInput();
		drawGame();
	}
}

void Engine::processInput() {
	SDL_Event evnt;

	while(SDL_PollEvent(&evnt)) {
		switch(evnt.type) {
			case SDL_QUIT:
				_gameState = GameState::EXIT;
				std::cout << "exit" << std::endl;
				break;
			case SDL_MOUSEMOTION:
				std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
				break;
		}
	}
}

void Engine::drawGame() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_shaderProgram.use();

	_sprite.draw();

	_shaderProgram.unuse();

	SDL_GL_SwapWindow(_window);
}