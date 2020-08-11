// Library
#include "Log/Logger.h"

// Local
#include "Window.h"

namespace Yugen
{
	class GraphicsContext;

	class WindowsWindow : public Window
	{
		public:
			explicit WindowsWindow(const WindowProps& props);
			~WindowsWindow();

			void onUpdate() override;

			unsigned int getWidth() override;
			unsigned int getHeight() override;

			void setEventCallback(const EventCallbackFunction& callback) override;
			void setVSync(bool enabled) override;
			bool isVSyncOn() override;

			GLFWwindow* getGLFWWindow()
			{
				return window;
			}

		private:
			virtual void init(const WindowProps& props);
			virtual void shutdown();

			GLFWwindow* window;
			Logger logger;

			GraphicsContext* context;

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