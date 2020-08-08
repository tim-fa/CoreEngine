#pragma once

// Library
#include "fmt/format.h"

// Local
#include "Event.h"

namespace Core
{
	namespace Events
	{

		class ResizeWindowEvent : public Event
		{
			protected:
				float width;
				float height;
			public:
				ResizeWindowEvent(unsigned int width, unsigned int height);

				inline const unsigned int getWidth() const
				{
					return width;
				}

				inline const unsigned int getHeight() const
				{
					return height;
				}

				inline std::string toString() const override
				{
					return fmt::format("ResizeWindowEvent: {}, {}", width, height);
				}

			public:
				inline static EventType getStaticType()
				{
					return Event::EventType::WindowResize;
				}
		};

		class CloseWindowEvent : public Event
		{
			public:
				CloseWindowEvent()
				: Event(getStaticType())
				{
				}

				inline std::string toString() const override
				{
					return "CloseWindowEvent";
				}

			public:
				inline static EventType getStaticType()
				{
					return Event::EventType::WindowClose;
				}
		};
	}
}
