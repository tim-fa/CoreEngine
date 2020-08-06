// Library
#include "glm/glm.hpp"

// Local
#include "WindowEvent.h"

namespace Core {
    namespace Events {

        ResizeWindowEvent::ResizeWindowEvent(unsigned int width, unsigned int height)
                : Event(ResizeWindowEvent::getStaticType()), m_Size(glm::tvec2<unsigned int>(width, height)) {
        }

    }
}