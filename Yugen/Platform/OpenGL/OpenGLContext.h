//
// Created by Tim on 09.08.2020.
//

#ifndef ENGINE_OPENGLCONTEXT_H
#define ENGINE_OPENGLCONTEXT_H

// Library
#include "Log/Logger.h"

// Local
#include "Renderer/GraphicsContext.h"

class GLFWwindow;

namespace Yugen
{
	class OpenGLContext : public GraphicsContext
	{
		public:

			explicit OpenGLContext(GLFWwindow* windowHandle);
			void initialize() override;
			void swapBuffers() override;

		private:
			Logger logger;
			GLFWwindow* windowHandle;
	};
}

#endif //ENGINE_OPENGLCONTEXT_H
