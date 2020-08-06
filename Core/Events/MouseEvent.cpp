
// Library
#include "glm/glm.hpp"
#include "fmt/format.h"

// Local
#include "MouseEvent.h"

namespace Core::Events
{

	MouseButtonEvent::MouseButtonEvent(int button, float x, float y, Type type)
		: Event(type)
		, m_Button(button)
		, m_Position(glm::vec2(x, y))
	{
	}

	MousePressedEvent::MousePressedEvent(int button, float x, float y)
		: MouseButtonEvent(button, x, y, MousePressedEvent::GetStaticType())
	{
	}

	std::string MousePressedEvent::toString() const
	{
		return fmt::format("MousePressedEvent: (Key: {:d}, Pos: {:.2f}, {:.2f})", GetButton(), GetX(), GetY());
	}

	MouseReleasedEvent::MouseReleasedEvent(int button, float x, float y)
		: MouseButtonEvent(button, x, y, MouseReleasedEvent::GetStaticType())
	{
	}

	std::string MouseReleasedEvent::toString() const
	{
		return fmt::format("MouseReleasedEvent: (Key: {:d}, Pos: {:.2f}, {:.2f})", GetButton(), GetX(), GetY());
	}

	MouseMovedEvent::MouseMovedEvent(float x, float y, bool dragged)
		: Event(MouseMovedEvent::GetStaticType())
		, m_Position(glm::vec2(x, y))
		, m_Dragged(dragged)
	{
	}

	std::string MouseMovedEvent::toString() const
	{
		return fmt::format("MouseMovedEvent: ({:.2f}, {:.2f})", GetX(), GetY());
	}

	MouseScrolledEvent::MouseScrolledEvent(float xOffset, float yOffset)
		: Event(MouseMovedEvent::GetStaticType())
		, offset(xOffset, yOffset)
	{
	}

	std::string MouseScrolledEvent::toString() const
	{
		return fmt::format("MouseScrolledEvent: ({:.2f}, {:.2f})", GetXoffs(), GetYoffs());
	}
}