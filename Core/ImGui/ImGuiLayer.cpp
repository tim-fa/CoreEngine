//
// Created by Tim on 07.08.2020.
//

// Library
#include "GLFW/glfw3.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"

// Local
#include "Macros.h"
#include "ImGuiLayer.h"
#include "Application.h"
#include "Input/Keycodes.h"

namespace Core
{
	ImGuiLayer::ImGuiLayer(Application& app)
		: Layer("ImGuiLayer")
		, logger("ImGuiLayer")
		, app(app)
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::onCreate()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

		ImGui_ImplGlfw_InitForOpenGL(app.getWindow().getGLFWWindow(), false);
		ImGui_ImplOpenGL3_Init("#version 410");
		logger.i("Layer created successfully");
	}

	void ImGuiLayer::onDestroy()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_NewFrame();
		ImGui::DestroyContext();
	}

	void ImGuiLayer::onImGuiRender()
	{
		static bool show = true;
		ImGui::ShowDemoWindow(&show);
	}

	void ImGuiLayer::begin()
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(app.getWindow().getWidth(), app.getWindow().getHeight());

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void ImGuiLayer::end()
	{
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
}