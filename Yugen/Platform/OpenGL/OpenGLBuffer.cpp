//
// Created by Tim on 10.08.2020.
//

// Library
#include "glad/glad.h"

// Local
#include "OpenGLBuffer.h"

namespace Yugen::Platform::OpenGL
{
	OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32 size)
	{
		glCreateBuffers(1, &rendererId);
		glBindBuffer(GL_ARRAY_BUFFER, rendererId);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &rendererId);
	}

	void OpenGLVertexBuffer::bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, rendererId);
	}

	void OpenGLVertexBuffer::unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void OpenGLVertexBuffer::setLayout(const Render::BufferLayout& layout)
	{
		this->layout = layout;
	}

	Render::BufferLayout& OpenGLVertexBuffer::getBufferLayout()
	{
		return layout;
	}


	// Index Buffer

	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32* indices, uint32 count)
		: count(count)
	{
		glCreateBuffers(1, &rendererId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererId);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32), indices, GL_STATIC_DRAW);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &rendererId);
	}

	void OpenGLIndexBuffer::bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererId);
	}

	void OpenGLIndexBuffer::unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	uint32 OpenGLIndexBuffer::getCount()
	{
		return count;
	}
}