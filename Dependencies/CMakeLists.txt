cmake_minimum_required(VERSION 3.11)

#	cd MyProject/dependencies/
#	git submodule add https://github.com/google/googletest.git
#	cd googletest
#	git checkout release-1.8.0
#	cd ../../..
#	git add *
#	git commit -m "Add googletest"


# pull:
# git pull --recurse-submodules

add_subdirectory("imgui")
add_subdirectory("termcolor")
add_subdirectory("glfw")
add_subdirectory("glad")
add_subdirectory("fmt")
add_subdirectory("Utility")