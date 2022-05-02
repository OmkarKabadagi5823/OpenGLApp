#ifndef INCLUDE_UTILITY_WINDOW_H_
#define INCLUDE_UTILITY_WINDOW_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cstdio>

class Window
{
public:
	Window() = default;
	Window(GLint windowWidth, GLint windowHeight);
	virtual ~Window();

	int init();

	GLint getBufferWidth();
	GLint getBufferHeight();

	bool getShouldClose();

	void swapBuffers();

private:
	GLFWwindow* mainWindow;

	GLint windowWidth;
	GLint windowHeight;
	GLint bufferWidth;
	GLint bufferHeight;

	bool keys[1024];
};

#endif /* INCLUDE_UTILITY_WINDOW_H_ */
