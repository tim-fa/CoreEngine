#pragma once

// Local
#include "Event.h"

namespace Core
{
	namespace Events
	{

		class KeyEvent : public Event
		{
			protected:
				int m_KeyCode;
				int m_Count;
			public:
				KeyEvent(int keyCode, Event::Type type);

				inline int getKeyCode() const
				{
					return m_KeyCode;
				}

				inline static int getStaticType()
				{
					return (int)Event::Type::KEY_PRESSED | (int)Event::Type::KEY_RELEASED;
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

				inline static Type getStaticType()
				{
					return Event::Type::KEY_PRESSED;
				}

				std::string toString() const override;
		};

		class KeyReleasedEvent : public KeyEvent
		{
			public:
				KeyReleasedEvent(int button);

				inline static Type getStaticType()
				{
					return Event::Type::KEY_RELEASED;
				}

				std::string toString() const override;
		};
	}
}
