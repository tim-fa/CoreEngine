//
// Created by tfa on 12.08.20.
//

#ifndef ENGINE_OPENGLVERTEXARRAY_H
#define ENGINE_OPENGLVERTEXARRAY_H

// STL
#include <vector>

// Library
#include "Renderer/VertexArray.h"
#include "Macros.h"

namespace Yugen
{

class OpenGLVertexArray : public VertexArray
{
	public:
		OpenGLVertexArray();
		virtual ~ OpenGLVertexArray()
		= default;

		void bind() override;
		void unbind() override;

		void addVertexBuffer(const std::shared_ptr<VertexBuffer>& buffer) override;
		void setIndexBuffer(const std::shared_ptr<IndexBuffer>& buffer) override;

		static VertexArray* create();

	private:
		uint32 rendererId;
		std::vector<std::shared_ptr<VertexBuffer>> vertexBuffers;
		std::shared_ptr<IndexBuffer> indexBuffer;
};
}

#endif //ENGINE_OPENGLVERTEXARRAY_H
