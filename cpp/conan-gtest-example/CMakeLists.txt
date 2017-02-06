project(ConanGtestExample)
cmake_minimum_required(VERSION 2.8.12)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Necessary to compile gtest
# - dependencies and final build
#   need to be compiled with same
#   build type. Otherwise linker
#   error will occure.
set(CMAKE_BUILD_TYPE Release)

add_executable(main main.cpp)
target_link_libraries(main ${CONAN_LIBS})
