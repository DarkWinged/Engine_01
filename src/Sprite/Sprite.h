#pragma once

#ifdef __APPLE__
    #include <GLUT/glut.h>
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
#endif
#ifdef _WIN32
	#include <glew.h>
#endif

class Sprite
{
public:
	Sprite();
	~Sprite();

	void init(float x, float y, float width, float height);
	void draw();

private:
	float _x;
	float _y;
	float _width;
	float _height;
	GLuint _vboID;
};