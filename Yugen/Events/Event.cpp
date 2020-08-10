// STL
#include <string>

// Local
#include "Event.h"

namespace Yugen {
    namespace Events {

        Event::Event(EventType type)
                : m_Type(type), m_Handled(false) {
        }

        std::string Event::toString() const {
            return "Event: ";
        }

        std::string Event::typeToString(EventType type) {
            switch (type) {
                case EventType::KeyPressed:
                    return "KeyPressed";
				case EventType::KeyReleased:
					return "KeyReleased";
				case EventType::KeyTyped:
					return "KeyTyped";
                case EventType::MousePressed:
                    return "MousePressed";
                case EventType::MouseReleased:
                    return "MouseReleased";
				case EventType::MouseMoved:
					return "MouseMoved";
				case EventType::MouseScrolled:
					return "MouseScrolled";
                case EventType::WindowResize:
                    return "WindowResize";
                case EventType::WindowClose:
                    return "WindowClose";
                default:
                    return "INVALID";
            }
        }

    }
}