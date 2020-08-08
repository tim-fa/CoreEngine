//
// Created by Tim on 07.08.2020.
//

// Library
#include "GLFW/glfw3.h"
#include "imgui_impl_opengl3.h"

// Local
#include "Macros.h"
#include "ImGuiLayer.h"
#include "Input/Keycodes.h"

namespace Core
{
	ImGuiLayer::ImGuiLayer(Application& app)
		: Layer("ImGuiLayer")
		, app(app)
		, logger("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::onCreate()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		// TEMPORARY: should eventually use Hazel key codes
		io.KeyMap[ImGuiKey_Tab] = KeyCode::CR_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = KeyCode::CR_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = KeyCode::CR_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow] = KeyCode::CR_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = KeyCode::CR_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp] = KeyCode::CR_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown] = KeyCode::CR_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home] = KeyCode::CR_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = KeyCode::CR_KEY_END;
		io.KeyMap[ImGuiKey_Insert] = KeyCode::CR_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete] = KeyCode::CR_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = KeyCode::CR_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space] = KeyCode::CR_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter] = KeyCode::CR_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape] = KeyCode::CR_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_A] = KeyCode::CR_KEY_A;
		io.KeyMap[ImGuiKey_C] = KeyCode::CR_KEY_C;
		io.KeyMap[ImGuiKey_V] = KeyCode::CR_KEY_V;
		io.KeyMap[ImGuiKey_X] = KeyCode::CR_KEY_X;
		io.KeyMap[ImGuiKey_Y] = KeyCode::CR_KEY_Y;
		io.KeyMap[ImGuiKey_Z] = KeyCode::CR_KEY_Z;

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::onDestroy()
	{
		Layer::onDestroy();
	}

	void ImGuiLayer::onUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(app.getWindow().getWidth(), app.getWindow().getHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = this->time > 0.0f ? (time - this->time) : (1.0f / 60.0f);
		this->time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::onEvent(Events::Event& e)
	{


		Events::EventDispatcher dispatcher(e);
		dispatcher.Dispatch<Events::MousePressedEvent>(CR_BIND_EVENT_CALLBACK(ImGuiLayer::onMouseButtonPressedEvent));
		dispatcher.Dispatch<Events::MouseReleasedEvent>(CR_BIND_EVENT_CALLBACK(ImGuiLayer::onMouseButtonReleasedEvent));
		dispatcher.Dispatch<Events::MouseScrolledEvent>(CR_BIND_EVENT_CALLBACK(ImGuiLayer::onMouseScrolledEvent));
		dispatcher.Dispatch<Events::MouseMovedEvent>(CR_BIND_EVENT_CALLBACK(ImGuiLayer::onMouseMovedEvent));
		dispatcher.Dispatch<Events::ResizeWindowEvent>(CR_BIND_EVENT_CALLBACK(ImGuiLayer::onWindowResizedEvent));
		dispatcher.Dispatch<Events::KeyTypedEvent>(CR_BIND_EVENT_CALLBACK(ImGuiLayer::onKeyTypedEvent));
		dispatcher.Dispatch<Events::KeyPressedEvent>(CR_BIND_EVENT_CALLBACK(ImGuiLayer::onKeyPressedEvent));
		dispatcher.Dispatch<Events::KeyReleasedEvent>(CR_BIND_EVENT_CALLBACK(ImGuiLayer::onKeyReleasedEvent));
	}

	bool ImGuiLayer::onMouseButtonPressedEvent(Events::MousePressedEvent& e)
	{
		auto& io = ImGui::GetIO();
		io.MouseDown[e.getButton()] = true;

		// ImGui::GetWindowPos();

		return false;
	}

	bool ImGuiLayer::onMouseButtonReleasedEvent(Events::MouseReleasedEvent& e)
	{
		auto& io = ImGui::GetIO();
		io.MouseDown[e.getButton()] = false;
		return false;
	}

	bool ImGuiLayer::onMouseScrolledEvent(Events::MouseScrolledEvent& e)
	{
		auto& io = ImGui::GetIO();
		io.MouseWheel += e.getYoffs();
		io.MouseWheelH += e.getXoffs();
		return false;
	}

	bool ImGuiLayer::onMouseMovedEvent(Events::MouseMovedEvent& e)
	{
		auto& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.getX(), e.getY());
		return false;
	}

	bool ImGuiLayer::onWindowResizedEvent(Events::ResizeWindowEvent& e)
	{
		auto& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.getWidth(), e.getHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, e.getWidth(), e.getHeight());
		return false;
	}

	bool ImGuiLayer::onKeyTypedEvent(Events::KeyTypedEvent& e)
	{
		auto& io = ImGui::GetIO();
		int keycode = e.getKeyCode();
		if (keycode > 0 && keycode < 0x10000) {
			io.AddInputCharacter(keycode);
		}
		return false;
	}

	bool ImGuiLayer::onKeyPressedEvent(Events::KeyPressedEvent& e)
	{
		auto& io = ImGui::GetIO();
		io.KeysDown[e.getKeyCode()] = true;

		io.KeyCtrl = io.KeysDown[KeyCode::CR_KEY_LEFT_CONTROL] || io.KeysDown[KeyCode::CR_KEY_RIGHT_CONTROL];
		io.KeyAlt = io.KeysDown[KeyCode::CR_KEY_LEFT_ALT] || io.KeysDown[KeyCode::CR_KEY_RIGHT_ALT];
		io.KeyShift = io.KeysDown[KeyCode::CR_KEY_LEFT_SHIFT] || io.KeysDown[KeyCode::CR_KEY_RIGHT_SHIFT];
		io.KeySuper = io.KeysDown[KeyCode::CR_KEY_LEFT_SUPER] || io.KeysDown[KeyCode::CR_KEY_RIGHT_SUPER];
		return false;
	}

	bool ImGuiLayer::onKeyReleasedEvent(Events::KeyReleasedEvent& e)
	{
		auto& io = ImGui::GetIO();
		io.KeysDown[e.getKeyCode()] = false;
		return false;
	}
}