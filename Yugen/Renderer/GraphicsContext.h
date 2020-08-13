//
// Created by Tim on 09.08.2020.
//

#ifndef ENGINE_GRAPHICSCONTEXT_H
#define ENGINE_GRAPHICSCONTEXT_H

namespace Yugen::Render
{
	class GraphicsContext
	{
		public:
			virtual void initialize() = 0;
			virtual void swapBuffers() = 0;
	};
}

#endif //ENGINE_GRAPHICSCONTEXT_H
