cmake_minimum_required(VERSION 3.11)

add_executable(Sandbox Sandbox.cpp)

target_link_libraries(
        Sandbox PUBLIC
        Engine
)


