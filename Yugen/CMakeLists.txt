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
)

add_library(Engine STATIC ${SOURCE_FILES} Platform/OpenGL/OpenGLContext.h)
target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(Events)
add_subdirectory(Log)
add_subdirectory(Maths)

target_link_libraries(
	Engine PUBLIC
	Events
	Log
	Maths
	glfw
	glad
	fmt
	imgui
)