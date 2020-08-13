//
// Created by Tim on 10.08.2020.
//

#ifndef ENGINE_RENDERER_H
#define ENGINE_RENDERER_H

namespace Yugen::Render
{
	enum class RendererAPI
	{
			None,
			OpenGL
	};

	class Renderer
	{
		public:
			static RendererAPI getAPI();
		private:
			static RendererAPI rendererApi;
	};
}

#endif //ENGINE_RENDERER_H
