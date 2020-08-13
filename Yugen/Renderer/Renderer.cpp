//
// Created by Tim on 10.08.2020.
//


// Local
#include "Renderer.h"

namespace Yugen::Render
{
	RendererAPI Renderer::rendererApi = RendererAPI::OpenGL;

	RendererAPI Renderer::getAPI()
	{
		return rendererApi;
	}
}
