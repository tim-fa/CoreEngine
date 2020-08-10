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

cmake_policy(SET CMP0074 OLD)

hunter_add_package(fmt)
find_package(fmt CONFIG REQUIRED)

hunter_add_package(glfw)
find_package(glfw3 CONFIG REQUIRED)

hunter_add_package(glew)
find_package(glew CONFIG REQUIRED)

hunter_add_package(imgui)
find_package(imgui CONFIG REQUIRED)

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
	glew::glew
	fmt::fmt
	imgui::imgui
)