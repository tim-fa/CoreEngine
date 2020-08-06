// STL
#include <functional>
#include <memory>

// Local
#include "Event.h"

namespace Core
{
	struct WindowProps
	{
		std::string title;
		int width;
		int height;

		WindowProps(std::string title = "Core Engine", int width = 1280, int height = 720)
			: title(title)
			, width(width)
			, height(height)
		{
		}
	};

	class Window
	{
		public:
			using EventCallbackFunction = std::function<void(Events::Event&)>;

			virtual void onUpdate() = 0;

			virtual unsigned int getWidth() = 0;
			virtual unsigned int getHeight() = 0;

			virtual void setEventCallback(const EventCallbackFunction& callback) = 0;
			virtual void setVSync(bool enabled) = 0;
			virtual bool isVSyncOn() = 0;

			static Window* create(const WindowProps& props = WindowProps());
	};
}