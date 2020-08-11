cmake_minimum_required(VERSION 3.11)

#	cd MyProject/dependencies/
#	git submodule add https://github.com/google/googletest.git

# pull:
# git submodule update --init --recursive
# git submodule update --recursive --remote

add_subdirectory("imgui")
add_subdirectory("glfw")
add_subdirectory("glad")
add_subdirectory("Utility")