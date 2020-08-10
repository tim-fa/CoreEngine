//
// Created by Tim on 10.08.2020.
//


// Local
#include "Renderer.h"

namespace Yugen
{
	RendererAPI Renderer::rendererApi = RendererAPI::OpenGL;

	RendererAPI Renderer::getAPI()
	{
		return rendererApi;
	}
}
