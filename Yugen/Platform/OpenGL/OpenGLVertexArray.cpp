//
// Created by tfa on 12.08.20.
//

// Library
#include "glad/glad.h"

// Local
#include "OpenGLVertexArray.h"

namespace Yugen::Platform::OpenGL
{
	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &rendererId);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &rendererId);
	}

	void OpenGLVertexArray::bind()
	{
		glBindVertexArray(rendererId);
	}

	void OpenGLVertexArray::unbind()
	{
		glBindVertexArray(0);
	}

	static GLenum shaderDataTypeToGlBaseType(Render::ShaderDataType type)
	{
		switch (type) {
			case Render::ShaderDataType::Int:
			case Render::ShaderDataType::Int2:
			case Render::ShaderDataType::Int3:
			case Render::ShaderDataType::Int4:
				return GL_INT;
			case Render::ShaderDataType::Float:
			case Render::ShaderDataType::Float2:
			case Render::ShaderDataType::Float3:
			case Render::ShaderDataType::Float4:
			case Render::ShaderDataType::Mat3:
			case Render::ShaderDataType::Mat4:
				return GL_FLOAT;
			default:
				return 0;
		}
	}

	void OpenGLVertexArray::addVertexBuffer(const std::shared_ptr<Render::VertexBuffer>& buffer)
	{
		glBindVertexArray(rendererId);
		buffer->bind();

		uint32 index = 0;
		auto& layout = buffer->getBufferLayout();
		for (const auto& element : layout) {

			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, element.getComponentCount(), shaderDataTypeToGlBaseType(element.type), element.normalized ? GL_TRUE : GL_FALSE,
				layout.getStride(), (const void*)element.offset);
			index++;
		}
		vertexBuffers.emplace_back(buffer);
	}

	void OpenGLVertexArray::setIndexBuffer(const std::shared_ptr<Render::IndexBuffer>& buffer)
	{
		glBindVertexArray(rendererId);
		buffer->bind();
		indexBuffer = buffer;
	}

	Render::VertexArray* OpenGLVertexArray::create()
	{
		return nullptr;
	}

	const std::vector<std::shared_ptr<Render::VertexBuffer>>& OpenGLVertexArray::getVertexBuffers() const
	{
		return vertexBuffers;
	}

	const std::shared_ptr<Render::IndexBuffer>& OpenGLVertexArray::getIndexBuffer() const
	{
		return indexBuffer;
	}
}
