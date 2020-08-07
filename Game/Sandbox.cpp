// STL
#include <memory>

// Engine
#include "Core.h"
#include "Events/Events.h"

class Example : public Core::Layer
{
	public:
		Example()
			: Layer("Example")
		{
		}

		void onUpdate() override
		{
			//printf("UPDATING\n");
		}

		void onEvent(Core::Events::Event& e) override
		{
			e.isHandled()
			printf("Event %s\n", e.toString().c_str());
		}
};

class Sandbox : public Core::Application
{
	public:
		Sandbox()
		{
			logger.i("Created Sandbox App!");
			addLayer(new Example());
			addLayer(new Example());
		}

		~Sandbox()
		{
		}
};

std::shared_ptr<Core::Application> Core::createApplication()
{
	return std::make_shared<Sandbox>();
}