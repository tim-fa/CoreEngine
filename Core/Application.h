//
// Created by Tim on 06.08.2020.
//
#ifndef APPLICATION
#define APPLICATION

// STL
#include <memory>

// Local
#include "Platform/Window.h"
#include "Logger.h"
#include "Events/Event.h"
#include "Layers/Layer.h"
#include "Layers/LayerHandler.h"
#include "ImGui/ImGuiLayer.h"

namespace Core
{
	class Application
	{
		public:
			Application();
			virtual ~Application();

			void run();
			void onEvent(Events::Event& e);

			void addLayer(Layer* layer);
			void addOverlay(Layer* overlay);

			Window& getWindow();

		protected:
			Logger logger;

		private:
			LayerHandler layerHandler;
			std::unique_ptr<Window> window;
			ImGuiLayer imGuiLayer;
			bool running{true};
	};

	// to be defined in client
	std::shared_ptr<Application> createApplication();
}

#endif
