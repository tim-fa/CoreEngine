cmake_minimum_required(VERSION 3.11)

file(
	GLOB SOURCE_FILES
	*.cpp
)

cmake_policy(SET CMP0074 OLD)

hunter_add_package(fmt)
find_package(fmt CONFIG REQUIRED)

hunter_add_package(termcolor)
find_package(termcolor CONFIG REQUIRED)

add_library(Log STATIC ${SOURCE_FILES})
target_include_directories(Log PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
	Log PUBLIC
	fmt::fmt
	termcolor::termcolor
)