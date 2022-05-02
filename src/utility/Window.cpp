#include <utility/Window.h>

Window::Window(GLint windowWidth, GLint windowHeight) :
	windowWidth(windowWidth),
	windowHeight(windowHeight)
{
	for(size_t i=0; i<1024; ++i)
	{
		keys[i] = false;
	}
}

Window::~Window()
{
	glfwDestroyWindow(mainWindow);
	glfwTerminate();
}

int Window::init()
{
	if(glfwInit() != GLFW_TRUE)
	{
		printf("[Window] Failed to initialize GLFW");
		glfwTerminate();
		return 1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	mainWindow = glfwCreateWindow(windowWidth, windowHeight, "OpenGL Application", NULL, NULL);
	if(!mainWindow)
	{
		printf("[Window] Error creating GLFW window");
		glfwTerminate();
		return 1;
	}

	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);
	glfwMakeContextCurrent(mainWindow);

	glewExperimental = GL_TRUE;

	GLenum errCode = glewInit();
	if(errCode != GLEW_OK)
	{
		printf("[Window] Failed to initialize GLEW: %s", glewGetErrorString(errCode));
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	glEnable(GL_DEPTH_TEST);

	glViewport(0, 0, bufferWidth, bufferHeight);
	return 0;
}

GLint Window::getBufferWidth()
{
	return bufferWidth;
}

GLint Window::getBufferHeight()
{
	return bufferHeight;
}

bool Window::getShouldClose()
{
	return glfwWindowShouldClose(mainWindow);
}

void Window::swapBuffers()
{
	glfwSwapBuffers(mainWindow);
}
