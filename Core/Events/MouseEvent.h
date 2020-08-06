#pragma once

// Library
#include "glm/glm.hpp"

// Local
#include "Event.h"

namespace Core { namespace Events {

	class MouseButtonEvent : public Event
	{
	protected:
		int m_Button;
		glm::vec2 m_Position;
	protected:
		MouseButtonEvent(int button, float x, float y, Event::Type type);
	public:
		inline const int GetButton() const { return m_Button; }
		inline const float GetX() const { return m_Position.x; }
		inline const float GetY() const { return m_Position.y; }
		inline const glm::vec2& GetPosition() const { return m_Position; }

		inline static int GetStaticType() { return (int)Event::Type::MOUSE_PRESSED | (int)Event::Type::MOUSE_RELEASED; }
	};

	class MousePressedEvent : public MouseButtonEvent
	{
	public:
		MousePressedEvent(int button, float x, float y);

		std::string toString() const override;

		inline static Type GetStaticType() { return Event::Type::MOUSE_PRESSED; }
	};

		class MouseReleasedEvent : public MouseButtonEvent
		{
			public:
				MouseReleasedEvent(int button, float x, float y);

				inline static Type GetStaticType() { return Event::Type::MOUSE_RELEASED; }
				std::string toString() const override;
		};

		class MouseMovedEvent : public Event
		{
			private:
				glm::vec2 m_Position;
				bool m_Dragged;
			public:
				MouseMovedEvent(float x, float y, bool dragged);

				inline const float GetX() const { return m_Position.x; }
				inline const float GetY() const { return m_Position.y; }
				inline const glm::vec2& GetPosition() const { return m_Position; }
				inline const bool IsDragged() const { return m_Dragged; }
				inline static Type GetStaticType() { return Event::Type::MOUSE_MOVED; }
				std::string toString() const override;
		};

		class MouseScrolledEvent : public Event
		{
			private:
				glm::vec2 offset;
				bool m_Dragged;
			public:
				MouseScrolledEvent(float xOffset, float yOffset);

				inline const float GetXoffs() const { return offset.x; }
				inline const float GetYoffs() const { return offset.y; }
				inline const glm::vec2& getOffset() const { return offset; }
				inline static Type GetStaticType() { return Event::Type::MOUSE_SCROLLED; }
				std::string toString() const override;
		};

} }