#include "GLSLProgram.h"
#include "error.h"

#include <fstream>
#include <vector>

GLSLProgram::GLSLProgram() :_numAttributes(0), _programID(0), _vertexShaderID(0), _fragmentShaderID(0)
{

}

GLSLProgram::~GLSLProgram()
{

}

void GLSLProgram::compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath)
{
	_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	if(_vertexShaderID == 0)
    	fatalError("vertex shader failed to be created!");

	_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if(_fragmentShaderID == 0)
    	fatalError("fragment shader failed to be created!");

	compileShader(vertexShaderFilePath, _vertexShaderID);
	compileShader(fragmentShaderFilePath, _fragmentShaderID);

}

void GLSLProgram::linkShaders()
{
	_programID = glCreateProgram();

	glAttachShader(_programID, _vertexShaderID);
	glAttachShader(_programID, _fragmentShaderID);

	glLinkProgram(_programID);

	GLuint isLinked = 0;
	glGetProgramiv(_programID, GL_LINK_STATUS, (int *)&isLinked);
	if(isLinked = GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<char> errorlog(maxLength);
		glGetProgramInfoLog(_programID, maxLength, &maxLength, &errorlog[0]);

		glDeleteProgram(_programID);

		glDeleteShader(_vertexShaderID);
		glDeleteShader(_fragmentShaderID);

    	std::printf("%s\n", &(errorlog[0]));
    	fatalError("shaders failed to link");
	}

	glDetachShader(_programID, _vertexShaderID);
	glDetachShader(_programID, _fragmentShaderID);

	glDeleteShader(_vertexShaderID);
	glDeleteShader(_fragmentShaderID);
}

void GLSLProgram::addAttribute(const std::string& attributeName)
{
	glBindAttribLocation(_programID, _numAttributes++, attributeName.c_str());
}

void GLSLProgram::use()
{
	glUseProgram(_programID);
	for(int i = 0; i < _numAttributes; i++)
		glEnableVertexAttribArray(i);
}

void GLSLProgram::unuse()
{
	glUseProgram(0);
	for(int i = 0; i < _numAttributes; i++)
		glDisableVertexAttribArray(i);
}

void GLSLProgram::compileShader(const std::string& filePath, GLuint id)
{
	
    std::ifstream file(filePath);
    if(file.fail())
    {
    	perror(filePath.c_str());
    	fatalError("failed to open " + filePath);
    }

    std::string fileContent = "";
    std::string line;

    while (std::getline(file, line))
    {
    	fileContent += line + "\n";
    }

    file.close();

    const char* contentPtr = fileContent.c_str();
    glShaderSource(id, 1, &contentPtr, nullptr);

    glCompileShader(id);

    GLint success = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);

    if(success == GL_FALSE)
    {
    	GLint maxLength = 0;
    	glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

    	std::vector<char> errorlog(maxLength);
    	glGetShaderInfoLog(id, maxLength, &maxLength, &errorlog[0]);

    	glDeleteShader(id);

    	std::printf("%s\n", &(errorlog[0]));
    	fatalError("shader " + filePath + " failed to compile");

    }
}
