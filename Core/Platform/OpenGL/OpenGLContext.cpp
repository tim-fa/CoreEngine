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
		ASSERT(windowHandle, "Invalid windowHandle!");
	}

	void OpenGLContext::initialize()
	{
		glfwMakeContextCurrent(windowHandle);
		ASSERT(glewInit() == GLEW_OK, "failed to initialize GLEW");
		logger.i("OpenGL Info:");
		logger.i("Vendor: {}", glGetString(GL_VENDOR));
		logger.i("Renderer: {}", glGetString(GL_RENDERER));
		logger.i("Version: {}", glGetString(GL_VERSION));
	}

	void OpenGLContext::swapBuffers()
	{
		glfwSwapBuffers(windowHandle);
	}
}
