// Library
#include "GL/glew.h"
#include "GLFW/glfw3.h"

// Local
#include "OpenGLContext.h"

namespace Core
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: windowHandle(windowHandle)
		, logger("OpenGlContext")
	{
		logger.Assert(windowHandle, "Invalid windowHandle!");
	}

	void OpenGLContext::initialize()
	{
		glfwMakeContextCurrent(windowHandle);
		logger.Assert(glewInit() == GLEW_OK, "failed to initialize GLEW\n");
	}

	void OpenGLContext::swapBuffers()
	{
		glfwSwapBuffers(windowHandle);
	}
}
