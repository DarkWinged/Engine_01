#ifndef GLSLPROGRAM_H
#define GLSLPROGRAM_H

#ifdef _WIN32
	#include <glew.h>
#elif __APPLE__
    #include <GLUT/glut.h>
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
#elif __linux__
	#define GL_GLEXT_PROTOTYPES
	#include <GL/glut.h>
	#include <GL/gl.h>
	#include <GL/glext.h>
#endif

#include <string>

class GLSLProgram {
public:
	GLSLProgram();
	~GLSLProgram();

	void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);

	void linkShaders();

	void addAttribute(const std::string& attributeName);

	void use();
	void unuse();
	
private:
	int _numAttributes;

	void compileShader(const std::string& filePath, GLuint id);

	GLuint _programID;

	GLuint _vertexShaderID;
	GLuint _fragmentShaderID;
};
#endif