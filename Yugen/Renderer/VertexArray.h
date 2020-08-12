//
// Created by tfa on 12.08.20.
//

#ifndef ENGINE_VERTEXARRAY_H
#define ENGINE_VERTEXARRAY_H

// STL
#include <memory>

// Local
#include "Buffer.h"

namespace Yugen
{
class VertexArray
{
	public:
		virtual ~VertexArray()
		= default;

		virtual void bind() = 0;
		virtual void unbind() = 0;

		virtual void addVertexBuffer(const std::shared_ptr<VertexBuffer>& buffer) = 0;
		virtual void setIndexBuffer(const std::shared_ptr<IndexBuffer>& buffer) = 0;

		static VertexArray* create();
};
}

#endif //ENGINE_VERTEXARRAY_H
