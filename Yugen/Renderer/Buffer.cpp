//
// Created by Tim on 10.08.2020.
//

// Library
#include "Log/Logger.h"

// Local
#include "Buffer.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Yugen
{
	VertexBuffer* VertexBuffer::create(float* vertices, unsigned int size)
	{
		switch (Renderer::getAPI()) {
			case RendererAPI::None:
				ASSERT(Renderer::getAPI() != RendererAPI::None, "No Renderer API is set!");
			case RendererAPI::OpenGL:
				return new OpenGLVertexBuffer(vertices, size);
			default:
				break;
		}
		return nullptr;
	}

	IndexBuffer* IndexBuffer::create(unsigned int* indices, unsigned int size)
	{
		switch (Renderer::getAPI()) {
			case RendererAPI::None:
				ASSERT(Renderer::getAPI() != RendererAPI::None, "No Renderer API is set!");
			case RendererAPI::OpenGL:
				return new OpenGLIndexBuffer(indices, size);
			default:
				break;
		}
		return nullptr;
	}
}
