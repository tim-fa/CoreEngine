#pragma once

// STL
#include <string>

#define BIT(x) (1u << static_cast<unsigned int>(x))

namespace Core
{
	namespace Events
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
				enum class Type
				{
						KEY_PRESSED = BIT(0),
						KEY_RELEASED = BIT(1),

						MOUSE_PRESSED = BIT(2),
						MOUSE_RELEASED = BIT(3),
						MOUSE_MOVED = BIT(4),
						MOUSE_SCROLLED = BIT(5),

						WINDOW_RESIZE = BIT(6),
						WINDOW_CLOSE = BIT(7)
				};
			protected:
				bool m_Handled;
				Type m_Type;
			protected:
				explicit Event(Type type);

			public:
				inline Type getType() const
				{
					return m_Type;
				}

				inline bool isHandled() const
				{
					return m_Handled;
				}

				virtual std::string toString() const;

				static std::string typeToString(Type type);
		};
	}
}