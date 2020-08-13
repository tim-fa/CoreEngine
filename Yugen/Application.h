#pragma once
//
// Created by Tim on 06.08.2020.
//
#ifndef APPLICATION
#define APPLICATION

// STL
#include <memory>

// Library
#include "Log/Logger.h"

// Local
#include "Platform/Window.h"
#include "Events/Event.h"
#include "Layers/Layer.h"
#include "Layers/LayerHandler.h"
#include "ImGui/ImGuiLayer.h"

#include "Renderer/Shader.h"
#include "Renderer/Buffer.h"
#include "Renderer/VertexArray.h"

namespace Yugen
{
	class Application
	{
		public:
			Application();
			virtual ~Application();

			void run();
			void onEvent(Events::Event& e);

			void addLayer(Layers::Layer* layer);
			void addOverlay(Layers::Layer* overlay);

			Platform::Window& getWindow();

		protected:
			Log::Logger logger;

		private:
			Layers::LayerHandler layerHandler;
			std::unique_ptr<Platform::Window> window;
			ImGuiLayer imGuiLayer;
			bool running{true};

			std::unique_ptr<Render::Shader> shader;
			std::shared_ptr<Render::VertexArray> vertexArray;
			std::shared_ptr<Render::VertexBuffer> vertexBuffer;
			std::shared_ptr<Render::IndexBuffer> indexBuffer;
	};

	// to be defined in client
	std::shared_ptr<Application> createApplication();
}

#endif
