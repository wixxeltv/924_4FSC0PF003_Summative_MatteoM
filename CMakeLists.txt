message("Main CMake Build")

cmake_minimum_required(VERSION 3.31)
option(ENABLE_TESTING "Enable gtest" OFF)

if(ENABLE_TESTING)
    list(APPEND VCPKG_MANIFEST_FEATURES "testing")
endif(ENABLE_TESTING)

project(4FSC0PF003_Summative)

set(CMAKE_CXX_STANDARD 20)

# Packages : external libraries managed by
find_package(SFML COMPONENTS Graphics Window System CONFIG REQUIRED)

if(ENABLE_TESTING)
    enable_testing()
    find_package(GTest CONFIG REQUIRED)
endif (ENABLE_TESTING)


add_subdirectory(1_tests)
add_subdirectory(2_factorize/)
