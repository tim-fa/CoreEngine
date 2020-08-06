cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)

include("cmake/HunterGate.cmake")
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.16.15.tar.gz"
        SHA1 "6974c2150fc0d3b09de3ad1efcbf15d360647ffa"
)

project(Engine)


add_subdirectory(Core)
add_subdirectory(Game)