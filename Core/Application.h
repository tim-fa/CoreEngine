//
// Created by Tim on 06.08.2020.
//
#ifndef APPLICATION
#define APPLICATION

// STL
#include <memory>

// Local
#include "Window.h"
#include "Event.h"
#include "Logger.h"

namespace Core
{
	class Application
	{
		public:
			Application();
			virtual ~Application();

			void run();
			void onEvent(Events::Event& e);

		private:
			std::unique_ptr<Window> window;
			bool running{true};
			Logger logger;
	};

	// to be defined in client
	std::shared_ptr<Application> createApplication();
}

#endif
