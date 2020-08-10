#pragma once

// Local
#include "Event.h"

namespace Yugen {
    namespace Events {

        class IEventListener {
        public:
            virtual void onEvent(Event &event) = 0;
        };

    }
}