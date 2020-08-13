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

	void OpenGLVertexArray::addVertexBuffer(const std::shared_ptr<Render::VertexBuffer>& buffer)
	{
		glBindVertexArray(rendererId);
		buffer->bind();

		uint32 index = 0;
		// TODO:	const auto& layout = buffer->getLayout();
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

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
