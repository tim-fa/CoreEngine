// Library
#include "GLFW/glfw3.h"

// Local
#include "Window.h"
#include "Logger.h"

namespace Core
{
	class WindowsWindow : public Window
	{
		public:
			explicit WindowsWindow(const WindowProps& props);
			~WindowsWindow();

			void onUpdate() override;

			unsigned int getWidth() override;
			unsigned int getHeight() override;

			void setEventCallback(EventCallbackFunction& callback) override;
			void setVSync(bool enabled) override;
			bool isVSyncOn() override;

		private:
			virtual void init(const WindowProps& props);
			virtual void shutdown();

			GLFWwindow* window;
			Logger logger;

			struct WindowData
			{
				std::string title;
				unsigned int width, height;
				bool vsync;
				EventCallbackFunction callback;
			};

			WindowData data;
	};
}