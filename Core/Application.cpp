//
// Created by Tim on 06.08.2020.
//

// Local
#include "Application.h"
#include "Events/EventDispatcher.h"

Core::Application::Application()
	: logger("Application")
{
	window = std::unique_ptr<Window>(Window::create());
	window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
}

Core::Application::~Application()
= default;

void Core::Application::run()
{
	while (running) {
		for(auto& layer : layerHandler){
			layer->onUpdate();
		}
		window->onUpdate();
	}
}

void Core::Application::onEvent(Core::Events::Event& e)
{
	Events::EventDispatcher dispatcher(e);

	dispatcher.Dispatch<Events::CloseWindowEvent>([&](Events::Event&) -> bool {
		running = false;
		return true;
	});

	// logger.d("Received Event {}", e.toString());

	for (auto it = layerHandler.end(); it != layerHandler.begin();) {
		(*--it)->onEvent(e);
		if (e.isHandled()) {
			break;
		}
	}
}

void Core::Application::addLayer(Core::Layer* layer)
{
	layerHandler.addLayer(layer);
	layer->onCreate();
}

void Core::Application::addOverlay(Core::Layer* overlay)
{
	layerHandler.addOverlay(overlay);
	overlay->onCreate();
}

Core::Window& Core::Application::getWindow()
{
	return *window;
}
