
#include "WindowsWindow.h"

static bool glfwInitialized = false;

namespace Core
{
	Window* Window::create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
		: logger("WindowsWindow")
	{
		init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
	}

	void WindowsWindow::onUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	unsigned int WindowsWindow::getWidth()
	{
		return data.width;
	}

	unsigned int WindowsWindow::getHeight()
	{
		return data.height;
	}

	void WindowsWindow::setEventCallback(EventCallbackFunction& callback)
	{
		data.callback = callback;
	}

	void WindowsWindow::setVSync(bool enabled)
	{
		glfwSwapInterval(enabled);
		data.vsync = enabled;
	}

	bool WindowsWindow::isVSyncOn()
	{
		return data.vsync;
	}

	void WindowsWindow::init(const WindowProps& props)
	{
		data.title = props.title;
		data.width = props.width;
		data.height = props.height;

		logger.d("Creating new Window: '{}', {}x{}", data.title, data.width, data.height);

		if (!glfwInitialized) {
			int status = glfwInit();
			if (!status) {
				logger.e("Could not initialize GLFW");
				glfwInitialized = true;
			}
			window = glfwCreateWindow(props.width, props.height, props.title.c_str(), nullptr, nullptr);
			glfwMakeContextCurrent(window);
			glfwSetWindowUserPointer(window, &data);
			setVSync(true);
		}
	}

	void WindowsWindow::shutdown()
	{
		glfwDestroyWindow(window);
	}
}
