// Local
#include "KeyEvent.h"

namespace Core::Events
{

	KeyEvent::KeyEvent(int keyCode, Event::EventType type)
		: Event(type)
		, m_KeyCode(keyCode)
	{
	}

	KeyPressedEvent::KeyPressedEvent(int button, int repeat, int modifiers)
		: KeyEvent(button, getStaticType())
		, m_Repeat(repeat)
		, m_Modifiers(modifiers)
	{
	}

	std::string KeyPressedEvent::toString() const
	{
		return fmt::format("KeyPressedEvent: (Key: {}, Repeats: {})", getKeyCode(), getRepeat());
	}

	KeyReleasedEvent::KeyReleasedEvent(int button)
		: KeyEvent(button, getStaticType())
	{
	}

	std::string KeyReleasedEvent::toString() const
	{
		return fmt::format("KeyReleasedEvent: (Key: {})", getKeyCode());
	}

	KeyTypedEvent::KeyTypedEvent(int button)
		: KeyEvent(button, getStaticType())
	{
	}

	std::string KeyTypedEvent::toString() const
	{
		return fmt::format("KeyTypedEvent: (Key: {})", getKeyCode());
	}
}
