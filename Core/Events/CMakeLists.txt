cmake_minimum_required(VERSION 3.11)

file(
	GLOB SOURCE_FILES
	*.cpp
)

cmake_policy(SET CMP0074 OLD)

hunter_add_package(fmt)
find_package(fmt CONFIG REQUIRED)

add_library(Events STATIC ${SOURCE_FILES})
target_include_directories(Events PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


target_link_libraries(
	Events PUBLIC
	fmt::fmt
)