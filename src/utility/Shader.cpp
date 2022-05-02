#include <utility/Shader.h>

Shader::Shader() :
	shaderID(0),
	uniformModel(0),
	uniformProjection(0)
{

}

Shader::~Shader()
{
	clearShader();
}

void Shader::createFromString(const char* vertexShaderCode, const char* fragmentShaderCode)
{
	compileShader(vertexShaderCode, fragmentShaderCode);
}

void Shader::createFromFiles(const char* vertexShaderFilePath, const char* fragmentShaderFilePath)
{
	std::string vertexString = readFile(vertexShaderFilePath);
	std::string fragmentString = readFile(fragmentShaderFilePath);
	const char* vertexShaderCode = vertexString.c_str();
	const char* fragmentShaderCode = fragmentString.c_str();

	compileShader(vertexShaderCode, fragmentShaderCode);
}

std::string Shader::readFile(const char* filePath)
{
	std::string fileContent;
	std::ifstream fileStream(filePath, std::ios::in);

	if(!fileStream.is_open())
	{
		printf("[Shader] Failed to read %s! File doesn't exist\n", filePath);
		return "";
	}

	std::string line = "";
	while(!fileStream.eof())
	{
		std::getline(fileStream, line);
		fileContent.append(line + "\n");
	}

	fileStream.close();
	return fileContent;
}

GLuint Shader::getModelLocation()
{
	return uniformModel;
}

GLuint Shader::getProjectionLocation()
{
	return uniformProjection;
}

void Shader::useShader()
{
	glUseProgram(shaderID);
}

void Shader::clearShader()
{
	if(shaderID != 0)
	{
		glDeleteProgram(shaderID);
		shaderID = 0;
	}

	uniformModel = 0;
	uniformProjection = 0;
}

void Shader::compileShader(const char* vertexShaderCode, const char* fragmentShaderCode)
{
	shaderID = glCreateProgram();

	if(shaderID == 0)
	{
		printf("[Shader] Error creating shader program\n");
		return;
	}

	addShader(shaderID, vertexShaderCode, GL_VERTEX_SHADER);
	addShader(shaderID, fragmentShaderCode, GL_FRAGMENT_SHADER);

	GLint result = 0;
	GLchar errLog[1024] = { 0 };

	glLinkProgram(shaderID);
	glGetProgramiv(shaderID, GL_LINK_STATUS, &result);
	if(!result)
	{
		glGetProgramInfoLog(shaderID, sizeof(errLog), NULL, errLog);
		printf("[Shader] Error linking program: %s\n", errLog);
		return;
	}

	glValidateProgram(shaderID);
	glGetProgramiv(shaderID, GL_VALIDATE_STATUS, &result);
	if(!result)
	{
		glGetProgramInfoLog(shaderID, sizeof(errLog), NULL, errLog);
		printf("[Shader] Error validating program: %s\n", errLog);
		return;
	}

	uniformModel = glGetUniformLocation(shaderID, "model");
	uniformProjection = glGetUniformLocation(shaderID, "projection");
}

void Shader::addShader(GLuint shaderProgram, const char* shaderCode, GLenum shaderType)
{
	GLuint shaderContainer = glCreateShader(shaderType);

	const GLchar* shaderCodes[1];
	shaderCodes[0] = shaderCode;

	GLint shaderCodeLengths[1];
	shaderCodeLengths[0] = strlen(shaderCode);

	glShaderSource(shaderContainer, 1, shaderCodes, shaderCodeLengths);
	glCompileShader(shaderContainer);

	GLint result = 0;
	GLchar errLog[1024] = { 0 };

	glGetShaderiv(shaderContainer, GL_COMPILE_STATUS, &result);

	if(!result)
	{
		glGetShaderInfoLog(shaderContainer, sizeof(errLog), NULL, errLog);
		printf("[Shader] Error compiling the %d shader: %s\n", shaderType, errLog);
		return;
	}

	glAttachShader(shaderProgram, shaderContainer);
}

