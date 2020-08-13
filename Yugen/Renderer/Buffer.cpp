//
// Created by Tim on 10.08.2020.
//

// Library
#include "Log/Logger.h"

// Local
#include "Buffer.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Yugen::Render
{
	using namespace Platform::OpenGL;

	uint32_t shaderDataTypeSize(ShaderDataType type)
	{
		switch (type) {
			case ShaderDataType::Int:
				return 4;
			case ShaderDataType::Int2:
				return 8;
			case ShaderDataType::Int3:
				return 12;
			case ShaderDataType::Int4:
				return 16;
			case ShaderDataType::Float:
				return 4;
			case ShaderDataType::Float2:
				return 8;
			case ShaderDataType::Float3:
				return 12;
			case ShaderDataType::Float4:
				return 16;
			case ShaderDataType::Mat3:
				return 4 * 3 * 3;
			case ShaderDataType::Mat4:
				return 4 * 4 * 4;
			default:
				// TODO: assert
				return 0;
		}
	}

	uint32 BufferElement::getComponentCount() const
	{
		switch (type) {
			case ShaderDataType::Int:
				return 1;
			case ShaderDataType::Int2:
				return 2;
			case ShaderDataType::Int3:
				return 3;
			case ShaderDataType::Int4:
				return 4;
			case ShaderDataType::Float:
				return 1;
			case ShaderDataType::Float2:
				return 2;
			case ShaderDataType::Float3:
				return 3;
			case ShaderDataType::Float4:
				return 4;
			case ShaderDataType::Mat3:
				return 3 * 3;
			case ShaderDataType::Mat4:
				return 4 * 4;
			default:
				// TODO: assert
				return 0;
		}
	}


	// BufferLayout

	BufferLayout::BufferLayout(const std::initializer_list<BufferElement>& elements)
		: elements(elements)
	{
		calculateOffsetsAndStride();
	}

	const std::vector<BufferElement>& BufferLayout::getElements() const
	{
		return elements;
	}

	void BufferLayout::calculateOffsetsAndStride()
	{
		uint32_t offs = 0;
		stride = 0;
		for (auto& element : elements) {
			element.offset = offs;
			offs += element.size;
			stride += element.size;
		}
	}

	std::vector<BufferElement>::iterator BufferLayout::begin()
	{
		return elements.begin();
	}


	std::vector<BufferElement>::iterator BufferLayout::end()
	{
		return elements.end();
	}

	uint32_t BufferLayout::getStride() const
	{
		return stride;
	}

	// VertexBuffer


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

	// IndexBuffer

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
