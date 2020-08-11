cmake_minimum_required(VERSION 3.11)

file(
	GLOB SOURCE_FILES
	src/*.c
)

add_library(glad STATIC ${SOURCE_FILES})
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
