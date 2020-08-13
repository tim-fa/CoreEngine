//
// Created by Tim on 09.08.2020.
//

#ifndef ENGINE_SHADER_H
#define ENGINE_SHADER_H

// STL
#include <string>

// Library
#include "Log/Logger.h"

// Local
#include "Macros.h"

namespace Yugen::Render
{
	class Shader
	{
		public:
			Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
			~Shader();

			void bind() const;
			void unbind() const;

		private:
			uint32 rendererId{0};
			Logger logger;
	};
};

#endif //ENGINE_SHADER_H
