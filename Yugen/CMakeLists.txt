cmake_minimum_required(VERSION 3.11)

file(
	GLOB SOURCE_FILES
	*.cpp
	Platform/*.cpp
	Platform/OpenGL/*.cpp
	Layers/*.cpp
	ImGui/*.cpp
	Input/*.cpp
	Renderer/*.cpp
	Events/*.cpp
)

add_library(Engine STATIC ${SOURCE_FILES})
target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
	Engine PUBLIC
	Log
	Maths
	glfw
	glad
	fmt
	imgui
)