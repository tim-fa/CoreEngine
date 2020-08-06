// STL
#include <memory>
#include <iostream>

// Engine
#include "EntryPoint.h"
#include "Application.h"
#include "Log/Logger.h"
#include "Events.h"

class Sandbox : public Core::Application {
public:
    Sandbox() {

    }

    ~Sandbox() {

    }
};

std::shared_ptr<Core::Application> Core::createApplication()
{
    Core::Logger logger("Sandbox");


    Core::Events::ResizeWindowEvent w(128, 256);

    logger.d(Core::Events::Event::typeToString(w.getType()));

    return std::make_shared<Sandbox>();
}