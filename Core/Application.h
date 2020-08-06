//
// Created by Tim on 06.08.2020.
//
#ifndef APPLICATION
#define APPLICATION

// STL
#include <memory>

// Local
#include "Window.h"

namespace Core
{
	class Application
	{
		public:
			Application();
			virtual ~Application();

			void run();

		private:
			std::unique_ptr<Window> window;
			bool running;
	};

	// to be defined in client
	std::shared_ptr<Application> createApplication();
}

#endif
