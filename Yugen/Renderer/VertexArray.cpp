//
// Created by tfa on 12.08.20.
//

// Library
#include "Log/Logger.h"

// Local
#include "VertexArray.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Yugen
{
VertexArray* VertexArray::create()
{
	switch (Renderer::getAPI()) {
		case RendererAPI::None:
			ASSERT(Renderer::getAPI() != RendererAPI::None, "No Renderer API is set!");
		case RendererAPI::OpenGL:
			return new OpenGLVertexArray();
		default:
			break;
	}
	return nullptr;
}
}