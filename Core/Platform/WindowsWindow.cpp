
// Local
#include "WindowsWindow.h"
#include "Events.h"

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

	void WindowsWindow::setEventCallback(const EventCallbackFunction& callback)
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
				return;
			}

			glfwSetErrorCallback([](int errorCode, const char* description) {
				printf("%s", fmt::format("Fatal GLFW error: (Code: {}, {})\n", errorCode, description).c_str());
			});
			glfwInitialized = true;
		}
		window = glfwCreateWindow(props.width, props.height, props.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(window);
		glfwSetWindowUserPointer(window, &data);
		setVSync(true);

		if (glewInit()) {
			logger.e("failed to initialize GLEW\n");
			return;
		}

		// Set GLFW Callbacks
		glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
			WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
			windowData.width = width;
			windowData.height = height;
			Events::ResizeWindowEvent e(width, height);
			windowData.callback(e);
		});

		glfwSetWindowCloseCallback(window, [](GLFWwindow* window) {
			WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
			Events::CloseWindowEvent e;
			windowData.callback(e);
		});

		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action) {
				case GLFW_PRESS: {
					Events::KeyPressedEvent e(key, 0, mods);
					windowData.callback(e);
					break;
				}
				case GLFW_REPEAT: {
					// TODO: repeat count can be extracted
					Events::KeyPressedEvent e(key, 1, mods);
					windowData.callback(e);
					break;
				}
				case GLFW_RELEASE: {
					Events::KeyReleasedEvent e(key);
					windowData.callback(e);
					break;
				}
			}
		});

		glfwSetCharCallback(window, [](GLFWwindow* window, unsigned int character) {
			WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
			Events::KeyTypedEvent e((int)character);
			windowData.callback(e);
		});

		glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action) {
				case GLFW_PRESS: {
					double xpos(0), ypos(0);
					glfwGetCursorPos(window, &xpos, &ypos);
					Events::MousePressedEvent e(button, (float)xpos, (float)ypos);
					windowData.callback(e);
					break;
				}
				case GLFW_RELEASE: {
					double xpos(0), ypos(0);
					glfwGetCursorPos(window, &xpos, &ypos);
					Events::MouseReleasedEvent e(button, (float)xpos, (float)ypos);
					windowData.callback(e);
					break;
				}
			}
		});

		glfwSetScrollCallback(window, [](GLFWwindow* window, double xoffs, double yoffs) {
			WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
			Events::MouseScrolledEvent e((float)xoffs, (float)yoffs);
			windowData.callback(e);
		});

		glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xPosition, double yPosition) {
			WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
			// TODO: fix dragged
			Events::MouseMovedEvent e((float)xPosition, (float)yPosition, false);
			windowData.callback(e);
		});
	}

	void WindowsWindow::shutdown()
	{
		glfwDestroyWindow(window);
	}
}
