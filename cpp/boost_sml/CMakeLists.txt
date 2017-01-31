project(BoostSmlTest)
cmake_minimum_required(VERSION 2.8.12)

# CONAN
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
set(LIBS ${LIBS} ${CONAN_LIBS})

# GTEST
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(LIBS ${LIBS} ${GTEST_BOTH_LIBRARIES})

# TARGETS
add_executable(main main.cpp)
target_link_libraries(main ${LIBS})
