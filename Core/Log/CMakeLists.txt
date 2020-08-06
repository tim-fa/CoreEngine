cmake_minimum_required(VERSION 3.9)

file(
	GLOB SOURCE_FILES
	*.cpp
)

hunter_add_package(fmt)
find_package(fmt CONFIG REQUIRED)

add_library(Log STATIC ${SOURCE_FILES})
target_include_directories(Log PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


target_link_libraries(
	Log PUBLIC
	fmt
)