// STL
#include <memory>

// Engine
#include "EntryPoint.h"
#include "Application.h"
#include "Layers/Layer.h"
#include "ImGui/ImGuiLayer.h"

#include "Log/Logger.h"

#include "imgui.h"

class ExampleLayer : public Yugen::Layer
{
	public:
		ExampleLayer(std::string s)
			: Layer(s)
		{
		}

		void onImGuiRender() override
		{
			ImGui::Begin("Test");
			ImGui::Text("Text");
			ImGui::End();
		}
};

class Sandbox : public Yugen::Application
{
	public:
		Sandbox()
		{
			logger.i("Created Sandbox App!");
			addLayer(new ExampleLayer("Layer 1"));

		}

		~Sandbox()
		{
		}
};

std::shared_ptr<Yugen::Application> Yugen::createApplication()
{
	return std::make_shared<Sandbox>();
}