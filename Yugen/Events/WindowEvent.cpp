// Local
#include "WindowEvent.h"

namespace Yugen::Events {

        ResizeWindowEvent::ResizeWindowEvent(unsigned int width, unsigned int height)
                : Event(ResizeWindowEvent::getStaticType()), width(width), height(height) {
        }

    }