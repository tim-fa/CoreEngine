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

    return std::make_shared<Sandbox>();
}