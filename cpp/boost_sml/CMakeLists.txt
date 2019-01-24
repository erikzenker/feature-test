cmake_minimum_required(VERSION 3.5)
project(BoostSmlTest)

# dependencies
enable_testing()
find_package(GTest MODULE REQUIRED)

# target defintion
add_executable(BoostSmlTest main.cpp)
target_compile_features(BoostSmlTest PRIVATE cxx_std_14)
target_link_libraries(BoostSmlTest
        PRIVATE
        GTest::Main
        GTest::GTest
        )
add_test(NAME BoostSml.Tests
        COMMAND BoostSmlTest
        )