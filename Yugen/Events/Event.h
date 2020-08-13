#pragma once

// STL
#include <string>

#define BIT(x) (1u << static_cast<unsigned int>(x))

namespace Yugen::Events
	{

#undef MOUSE_PRESSED
#undef MOUSE_RELEASED
#undef MOUSE_MOVED
#undef KEY_PRESSED
#undef KEY_RELEASED

		class Event
		{
			private:
				friend class EventDispatcher;

			public:
				enum class EventType
				{
						KeyPressed = BIT(0),
						KeyReleased = BIT(1),
						KeyTyped = BIT(2),

						MousePressed = BIT(3),
						MouseReleased = BIT(4),
						MouseMoved = BIT(5),
						MouseScrolled = BIT(6),

						WindowResize = BIT(7),
						WindowClose = BIT(8)
				};
			protected:
				bool m_Handled;
				EventType m_Type;
			protected:
				explicit Event(EventType type);

			public:
				inline EventType getType() const
				{
					return m_Type;
				}

				inline bool isHandled() const
				{
					return m_Handled;
				}

				virtual std::string toString() const;

				static std::string typeToString(EventType type);
		};
	}