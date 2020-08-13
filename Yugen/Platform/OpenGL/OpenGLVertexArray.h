#pragma once
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

namespace Yugen::Platform::OpenGL
{
	class OpenGLVertexArray : public Render::VertexArray
	{
		public:
			OpenGLVertexArray();
			~OpenGLVertexArray() override;

			void bind() override;
			void unbind() override;

			void addVertexBuffer(const std::shared_ptr<Render::VertexBuffer>& buffer) override;
			void setIndexBuffer(const std::shared_ptr<Render::IndexBuffer>& buffer) override;

			const std::vector<std::shared_ptr<Render::VertexBuffer>>& getVertexBuffers() const override;
			const std::shared_ptr<Render::IndexBuffer>& getIndexBuffer() const override;

			static VertexArray* create();

		private:
			uint32 rendererId{};
			std::vector<std::shared_ptr<Render::VertexBuffer>> vertexBuffers;
			std::shared_ptr<Render::IndexBuffer> indexBuffer;
	};
}

#endif //ENGINE_OPENGLVERTEXARRAY_H
