#pragma once

// Local
#include "Event.h"

namespace Core {
    namespace Events {

        class IEventListener {
        public:
            virtual void onEvent(Event &event) = 0;
        };

    }
}