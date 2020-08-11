cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 17)


include("cmake/HunterGate.cmake")
HunterGate(
	URL "https://github.com/ruslo/hunter/archive/v0.23.214.tar.gz"
	SHA1 "e14bc153a7f16d6a5eeec845fb0283c8fad8c358"
)
project(Engine)


add_subdirectory(Dependencies)
add_subdirectory(Yugen)
add_subdirectory(Game)