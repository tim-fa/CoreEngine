#pragma once

// Local
#include "Event.h"

namespace Yugen::Events {

        class IEventListener {
        public:
            virtual void onEvent(Event &event) = 0;
        };

    }