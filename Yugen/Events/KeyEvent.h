#pragma once

// Library
#include "fmt/format.h"

// Local
#include "Event.h"

namespace Yugen::Events
	{

		class KeyEvent : public Event
		{
			protected:
				int m_KeyCode;
				int m_Count;
			public:
				KeyEvent(int keyCode, Event::EventType type);

				inline int getKeyCode() const
				{
					return m_KeyCode;
				}

				inline static int getStaticType()
				{
					return (int)Event::EventType::KeyPressed | (int)Event::EventType::KeyReleased;
				}
		};

		class KeyPressedEvent : public KeyEvent
		{
			private:
				int m_Repeat;
				int m_Modifiers;
			public:
				KeyPressedEvent(int button, int repeat, int modifiers);

				inline int getRepeat() const
				{
					return m_Repeat;
				}

				inline int getModifiers() const
				{
					return m_Modifiers;
				}

				inline bool isModifier(int modifier) const
				{
					return (bool)(m_Modifiers & modifier);
				}

				inline static EventType getStaticType()
				{
					return Event::EventType::KeyPressed;
				}

				std::string toString() const override;
		};

		class KeyReleasedEvent : public KeyEvent
		{
			public:
				KeyReleasedEvent(int button);

				inline static EventType getStaticType()
				{
					return Event::EventType::KeyReleased;
				}

				std::string toString() const override;
		};

		class KeyTypedEvent : public KeyEvent
		{
			public:
				explicit KeyTypedEvent(int button);

				inline static EventType getStaticType()
				{
					return Event::EventType::KeyTyped;
				}

				std::string toString() const override;
		};
	}
