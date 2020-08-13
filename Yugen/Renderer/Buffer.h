//
// Created by Tim on 10.08.2020.
//

#ifndef ENGINE_BUFFER_H
#define ENGINE_BUFFER_H

// STL
#include <string>
#include <vector>

// Local
#include "Macros.h"
#include "Log/Logger.h"

namespace Yugen::Render
{
	enum class ShaderDataType : int
	{
			None = 0, Int, Int2, Int3, Int4, Float, Float2, Float3, Float4, Mat3, Mat4
	};

	extern uint32_t shaderDataTypeSize(ShaderDataType type);

	struct BufferElement
	{
		std::string name;
		uint32_t offset{0};
		uint32_t size;
		bool normalized;
		ShaderDataType type;

		BufferElement() = default;

		BufferElement(ShaderDataType type, const std::string& name, bool normalized = false)
			: name(name)
			, type(type)
			, size(shaderDataTypeSize(type))
			, normalized(normalized)
		{
		}

		[[nodiscard]] uint32 getComponentCount() const;
	};

	class BufferLayout
	{
		public:
			BufferLayout() = default;
			BufferLayout(const std::initializer_list<BufferElement>& elements);
			[[nodiscard]] const std::vector<BufferElement>& getElements() const;

			[[nodiscard]] std::vector<BufferElement>::iterator begin();
			[[nodiscard]] std::vector<BufferElement>::iterator end();

		private:
			void calculateOffsetsAndStride();

			std::vector<BufferElement> elements;
			uint32_t stride = 0;
		public:
			uint32_t getStride() const;
	};

	class VertexBuffer
	{
		public:
			virtual ~VertexBuffer()
			= default;

			virtual void bind() const = 0;
			virtual void unbind() const = 0;

			virtual void setLayout(const BufferLayout& layout) = 0;
			virtual BufferLayout& getBufferLayout() = 0;

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
