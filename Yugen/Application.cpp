//
// Created by Tim on 06.08.2020.
//

// Library
#include "glad/glad.h"
#include "GLFW/glfw3.h"

// Local
#include "Application.h"
#include "Input/Input.h"

namespace Yugen
{
	using namespace Input;

	Application::Application()
		: logger("Application")
		, imGuiLayer(*this)
	{
		window = std::unique_ptr<Platform::Window>(Platform::Window::create());
		window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));

		addOverlay(&imGuiLayer);

		vertexArray.reset(Render::VertexArray::create());

		float vertices[7 * 3] = {
			-.5f, -.5f, 0, 1.f, 0.f, 1.f, 1.f,
			.5f, -.5f, 0, 1.f, 0.f, 1.f, 1.f,
			.0f, .5f, 0, 1.f, 0.f, 1.f, 1.f,
		};

		vertexBuffer.reset(Render::VertexBuffer::create(vertices, sizeof(vertices)));

		Render::BufferLayout layout = {
			{Render::ShaderDataType::Float3, "a_Position"},
			{Render::ShaderDataType::Float4, "a_Color"},
		};
		vertexBuffer->setLayout(layout);

		vertexArray->addVertexBuffer(vertexBuffer);

		uint32 indices[3] = {0, 1, 2};
		indexBuffer.reset(Render::IndexBuffer::create(indices, 3));
		vertexArray->setIndexBuffer(indexBuffer);

		std::string vertexSrc = R"(
#version 330 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_Color;

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

		shader = std::make_unique<Render::Shader>(vertexSrc, fragmentSrc);
	}

	Application::~Application()
	= default;

	void Application::run()
	{
		while (running) {
			glClearColor(.2f, 0.2f, .2f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			shader->bind();
			vertexArray->bind();
			glDrawElements(GL_TRIANGLES, vertexArray->getIndexBuffer()->getCount(), GL_UNSIGNED_INT, nullptr);

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

	void Application::onEvent(Events::Event& e)
	{
		Events::EventDispatcher dispatcher(e);

		dispatcher.Dispatch<Events::CloseWindowEvent>([&](Events::Event&) -> bool {
			running = false;
			return true;
		});

		dispatcher.Dispatch<Events::KeyPressedEvent>(InputHandler::onKeyPressedEvent);
		dispatcher.Dispatch<Events::KeyReleasedEvent>(InputHandler::onKeyReleasedEvent);
		dispatcher.Dispatch<Events::MousePressedEvent>(InputHandler::onMousePressedEvent);
		dispatcher.Dispatch<Events::MouseReleasedEvent>(InputHandler::onMouseReleasedEvent);
		dispatcher.Dispatch<Events::MouseMovedEvent>(InputHandler::onMouseMovedEvent);

		for (auto& layer : layerHandler) {
			layer->onEvent(e);
			if (e.isHandled()) {
				break;
			}
		}
	}

	void Application::addLayer(Layers::Layer* layer)
	{
		layerHandler.addLayer(layer);
		layer->onCreate();
	}

	void Application::addOverlay(Layers::Layer* overlay)
	{
		layerHandler.addOverlay(overlay);
		overlay->onCreate();
	}

	Platform::Window& Application::getWindow()
	{
		return *window;
	}
}
