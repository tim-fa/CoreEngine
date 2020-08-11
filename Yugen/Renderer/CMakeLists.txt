cmake_minimum_required(VERSION 3.11)

file(
	GLOB SOURCE_FILES
	imgui/*.cpp
)

add_library(imgui STATIC ${SOURCE_FILES})
target_include_directories(imgui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/imgui)
