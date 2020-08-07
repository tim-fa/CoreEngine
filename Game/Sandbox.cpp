// STL
#include <memory>

// Engine
#include "Core.h"
#include "Events/Events.h"
#include "ImGui/ImGuiLayer.h"

class Sandbox : public Core::Application
{
	public:
		Sandbox()
		{
			logger.e("test");
			logger.i("Created Sandbox App!");
			addLayer(new Core::ImGuiLayer(*this));
		}

		~Sandbox()
		{
		}
};

std::shared_ptr<Core::Application> Core::createApplication()
{
	return std::make_shared<Sandbox>();
}