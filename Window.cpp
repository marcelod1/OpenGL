#include "Window.h"

Window::Window()
{
	width = 800;
	height = 600;
}


Window::Window(GLint windowWidth, GLint windowHeight)
{	
	width = 800;
	height = 600;
	
}

int Window::Initialise()
{
	if (!glfwInit())
	{
		printf("GLFW initilization failed!");
		glfwTerminate();
		return 1;
	}

	// Setup GLFW window proprierties
	// OpenlGl version

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Core profile = No Backwards Compatiblity
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//Allow forward comatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	mainWindow = glfwCreateWindow(width, height, "Test Window", NULL, NULL);
	if (!mainWindow)
	{
		printf("GLFW window creation faield!");
		glfwTerminate();
		return 1;
	}

	//Get Buffer size information
	
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	// Set context for GLEW to use

	glfwMakeContextCurrent(mainWindow);


	// Allow modern exterions features

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("GLEW initializrion faield!");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	glEnable(GL_DEPTH_TEST);
	glViewport(0, 0, bufferWidth, bufferHeight);
	return 0;
}

Window::~Window()
{
	glfwDestroyWindow(mainWindow);
	glfwTerminate();
}
