//
// Created by Tim on 06.08.2020.
//

#include "Application.h"

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
		window->onUpdate();
	}
}

void Core::Application::onEvent(Core::Events::Event& e)
{
	logger.w("Received Event {}", e.toString());
}
