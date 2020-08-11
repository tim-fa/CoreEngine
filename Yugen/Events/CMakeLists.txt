cmake_minimum_required(VERSION 3.11)

file(
	GLOB SOURCE_FILES
	*.cpp
)

add_library(Events STATIC ${SOURCE_FILES})
target_include_directories(Events PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
	Events PUBLIC
	fmt::fmt
)