//
// Created by Tim on 09.08.2020.
//

#ifndef ENGINE_SHADER_H
#define ENGINE_SHADER_H

// STL
#include <string>

// Local
#include "Log/Logger.h"

namespace Core
{
	class Shader
	{
		public:
			Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
			~Shader();

			void bind() const;
			void unbind() const;

		private:
			unsigned __int32 rendererId{0};
			Logger logger;
	};
};

#endif //ENGINE_SHADER_H
