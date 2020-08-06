# Fix use of GoogleTest with GCC 9.1.0 by disabling GoogleMock
# https://github.com/hunter-packages/googletest/issues/27
hunter_config(GTest VERSION 1.8.0-hunter-p11 CMAKE_ARGS BUILD_GTEST=ON BUILD_GMOCK=OFF)