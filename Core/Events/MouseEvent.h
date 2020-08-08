#pragma once

// Local
#include "Event.h"

namespace Core { namespace Events {

	class MouseButtonEvent : public Event
	{
	protected:
		int m_Button;
		float x, y;
	protected:
		MouseButtonEvent(int button, float x, float y, Event::EventType type);
	public:
		inline const int getButton() const { return m_Button; }
		inline const float GetX() const { return x; }
		inline const float GetY() const { return y; }

		inline static int getStaticType() { return (int)Event::EventType::MousePressed | (int)Event::EventType::MouseReleased; }
	};

	class MousePressedEvent : public MouseButtonEvent
	{
	public:
		MousePressedEvent(int button, float x, float y);

		std::string toString() const override;

		inline static EventType getStaticType() { return Event::EventType::MousePressed; }
	};

		class MouseReleasedEvent : public MouseButtonEvent
		{
			public:
				MouseReleasedEvent(int button, float x, float y);

				inline static EventType getStaticType() { return Event::EventType::MouseReleased; }
				std::string toString() const override;
		};

		class MouseMovedEvent : public Event
		{
			private:
				float x, y;
				bool m_Dragged;
			public:
				MouseMovedEvent(float x, float y, bool dragged);

				inline const float getX() const { return x; }
				inline const float getY() const { return y; }
				inline const bool IsDragged() const { return m_Dragged; }
				inline static EventType getStaticType() { return Event::EventType::MouseMoved; }
				std::string toString() const override;
		};

		class MouseScrolledEvent : public Event
		{
			private:
				float offx, offy;
				bool m_Dragged;
			public:
				MouseScrolledEvent(float xOffset, float yOffset);

				inline const float getXoffs() const { return offx; }
				inline const float getYoffs() const { return offy; }
				inline static EventType getStaticType() { return Event::EventType::MouseScrolled; }
				std::string toString() const override;
		};

} }