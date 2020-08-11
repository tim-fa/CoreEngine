// Library
#include "glad/glad.h"
#include "GLFW/glfw3.h"

// Local
#include "OpenGLContext.h"

namespace Yugen
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

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			logger.f("Failed to initialize OpenGL context");
		}

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
