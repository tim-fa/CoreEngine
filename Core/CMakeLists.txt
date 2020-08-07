cmake_minimum_required(VERSION 3.9)

file(
	GLOB SOURCE_FILES
	*.cpp
	Platform/*.cpp
	Layers/*.cpp
)

hunter_add_package(fmt)
find_package(fmt CONFIG REQUIRED)

hunter_add_package(glfw)
find_package(glfw3 CONFIG REQUIRED)

add_library(Engine STATIC ${SOURCE_FILES})
target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(Events)
add_subdirectory(Log)

target_link_libraries(
	Engine PUBLIC
	Events
	Log
	fmt
	glfw
)