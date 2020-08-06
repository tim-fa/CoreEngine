//
// Created by Tim on 06.08.2020.
//

#include "Application.h"

Core::Application::Application()
{
	window = std::unique_ptr<Window>(Window::create());
}

Core::Application::~Application()
{
}

void Core::Application::run()
{
	while (running) {
		window->onUpdate();
	}
}
