// STL
#include <string>

// Local
#include "Event.h"

namespace Core {
    namespace Events {

        Event::Event(Type type)
                : m_Type(type), m_Handled(false) {
        }

        std::string Event::toString() const {
            return "Event: ";
        }

        std::string Event::typeToString(Type type) {
            switch (type) {
                case Type::KEY_PRESSED:
                    return "KEY_PRESSED";
                case Type::KEY_RELEASED:
                    return "KEY_RELEASED";
                case Type::MOUSE_PRESSED:
                    return "MOUSE_PRESSED";
                case Type::MOUSE_RELEASED:
                    return "MOUSE_RELEASED";
                case Type::MOUSE_MOVED:
                    return "MOUSE_MOVED";
                case Type::WINDOW_RESIZE:
                    return "WINDOW_RESIZE";
                case Type::WINDOW_CLOSE:
                    return "WINDOW_CLOSE";
                default:
                    return "INVALID";
            }
        }

    }
}