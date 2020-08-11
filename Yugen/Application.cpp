//
// Created by Tim on 06.08.2020.
//

// Local
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Application.h"

#include <memory>
#include "Input/Input.h"

Yugen::Application::Application()
	: logger("Application")
	, imGuiLayer(*this)
{
	window = std::unique_ptr<Window>(Window::create());
	window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));

	addOverlay(&imGuiLayer);

	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	float vertices[3 * 3] = {
		-.5f, -.5f, 0,
		.5f, -.5f, 0,
		.0f, .5f, 0,
	};

	vertexBuffer.reset(VertexBuffer::create(vertices, sizeof(vertices)));

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

	uint32 indices[3] = {0, 1, 2};
	indexBuffer.reset(IndexBuffer::create(indices, 3));

	std::string vertexSrc = R"(
#version 330 core

layout(location = 0) in vec3 a_Position;

out vec3 v_Position;

void main()
{
	v_Position = a_Position;
	gl_Position = vec4(a_Position, 1.0);
}

)";

	std::string fragmentSrc = R"(
#version 330 core

layout(location = 0) out vec4 color;

in vec3 v_Position;

void main()
{
	color = vec4((v_Position + 1) / 2, 1.0);
}

)";

	shader = std::make_unique<Shader>(vertexSrc, fragmentSrc);
}

Yugen::Application::~Application()
= default;

void Yugen::Application::run()
{
	while (running) {
		glClearColor(.2f, 0.2f, .2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader->bind();

		glBindVertexArray(vertexArray);
		glDrawElements(GL_TRIANGLES, indexBuffer->getCount(), GL_UNSIGNED_INT, nullptr);

		for (auto& layer : layerHandler) {
			layer->onUpdate();
		}

		imGuiLayer.begin();
		for (auto& layer : layerHandler) {
			layer->onImGuiRender();
		}
		imGuiLayer.end();
		window->onUpdate();
	}
}

void Yugen::Application::onEvent(Yugen::Events::Event& e)
{
	Events::EventDispatcher dispatcher(e);

	dispatcher.Dispatch<Events::CloseWindowEvent>([&](Events::Event&) -> bool {
		running = false;
		return true;
	});

	dispatcher.Dispatch<Events::KeyPressedEvent>(Input::onKeyPressedEvent);
	dispatcher.Dispatch<Events::KeyReleasedEvent>(Input::onKeyReleasedEvent);
	dispatcher.Dispatch<Events::MousePressedEvent>(Input::onMousePressedEvent);
	dispatcher.Dispatch<Events::MouseReleasedEvent>(Input::onMouseReleasedEvent);
	dispatcher.Dispatch<Events::MouseMovedEvent>(Input::onMouseMovedEvent);

	for (auto& layer : layerHandler) {
		layer->onEvent(e);
		if (e.isHandled()) {
			break;
		}
	}
}

void Yugen::Application::addLayer(Yugen::Layer* layer)
{
	layerHandler.addLayer(layer);
	layer->onCreate();
}

void Yugen::Application::addOverlay(Yugen::Layer* overlay)
{
	layerHandler.addOverlay(overlay);
	overlay->onCreate();
}

Yugen::Window& Yugen::Application::getWindow()
{
	return *window;
}
