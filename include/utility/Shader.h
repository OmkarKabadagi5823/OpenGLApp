#ifndef INCLUDE_UTILITY_SHADER_H_
#define INCLUDE_UTILITY_SHADER_H_

#include <GL/glew.h>

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <fstream>

class Shader
{
public:
	Shader();
	virtual ~Shader();

	void createFromString(const char* vertexShaderCode, const char* fragmentShaderCode);
	void createFromFiles(const char* vertexShaderFilePath, const char* fragmentShaderFilePath);

	std::string readFile(const char* filePath);

	GLuint getModelLocation();
	GLuint getProjectionLocation();

	void useShader();
	void clearShader();

private:
	void compileShader(const char* vertexShaderCode, const char* fragmentShaderCode);
	void addShader(GLuint shaderProgram, const char* shaderCode, GLenum shaderType);

	GLuint shaderID;
	GLuint uniformModel;
	GLuint uniformProjection;
};

#endif /* INCLUDE_UTILITY_SHADER_H_ */
