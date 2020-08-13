//
// Created by Tim on 10.08.2020.
//

#ifndef ENGINE_BUFFER_H
#define ENGINE_BUFFER_H

// Local
#include "Macros.h"

namespace Yugen::Render
{
	class VertexBuffer
	{
		public:
			virtual ~VertexBuffer()
			{
			}

			virtual void bind() const = 0;
			virtual void unbind() const = 0;

			static VertexBuffer* create(float vertices[], unsigned int size);
	};

	class IndexBuffer
	{
		public:
			virtual ~IndexBuffer()
			{
			}

			virtual void bind() const = 0;
			virtual void unbind() const = 0;

			virtual uint32 getCount() = 0;

			static IndexBuffer* create(unsigned int indices[], unsigned int size);
	};
}
#endif //ENGINE_BUFFER_H
