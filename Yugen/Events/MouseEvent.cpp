
// Library
#include "fmt/format.h"

// Local
#include "MouseEvent.h"

namespace Yugen::Events
{

	MouseButtonEvent::MouseButtonEvent(int button, float x, float y, EventType type)
		: Event(type)
		, m_Button(button)
		, x(x)
		, y(y)
	{
	}

	MousePressedEvent::MousePressedEvent(int button, float x, float y)
		: MouseButtonEvent(button, x, y, getStaticType())
	{
	}

	std::string MousePressedEvent::toString() const
	{
		return fmt::format("MousePressedEvent: (Key: {:d}, Pos: {:.2f}, {:.2f})", getButton(), GetX(), GetY());
	}

	MouseReleasedEvent::MouseReleasedEvent(int button, float x, float y)
		: MouseButtonEvent(button, x, y, getStaticType())
	{
	}

	std::string MouseReleasedEvent::toString() const
	{
		return fmt::format("MouseReleasedEvent: (Key: {:d}, Pos: {:.2f}, {:.2f})", getButton(), GetX(), GetY());
	}

	MouseMovedEvent::MouseMovedEvent(float x, float y, bool dragged)
		: Event(getStaticType())
		, x(x)
		, y(y)
		, m_Dragged(dragged)
	{
	}

	std::string MouseMovedEvent::toString() const
	{
		return fmt::format("MouseMovedEvent: ({:.2f}, {:.2f})", getX(), getY());
	}

	MouseScrolledEvent::MouseScrolledEvent(float xOffset, float yOffset)
		: Event(getStaticType())
		, offx(xOffset)
		, offy(yOffset)
	{
	}

	std::string MouseScrolledEvent::toString() const
	{
		return fmt::format("MouseScrolledEvent: ({:.2f}, {:.2f})", getXoffs(), getYoffs());
	}
}