#pragma once

// Library
#include "glm/glm.hpp"
#include "fmt/format.h"

// Local
#include "Event.h"

namespace Core { namespace Events {

	class ResizeWindowEvent : public Event
	{
	protected:
		glm::tvec2<unsigned int> m_Size;
	public:
		ResizeWindowEvent(unsigned int width, unsigned int height);

		inline const glm::tvec2<unsigned int>& getSize() const { return m_Size; }
		inline const unsigned int getWidth() const { return m_Size.x; }
		inline const unsigned int getHeight() const { return m_Size.y; }
		inline std::string toString() const override{
            return fmt::format("ResizeWindowEvent: {}, {}", m_Size.x, m_Size.y);
		}

	public:
		inline static Type GetStaticType() { return Event::Type::WINDOW_RESIZE; }
	};

} }
