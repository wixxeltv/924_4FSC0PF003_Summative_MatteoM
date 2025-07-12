cmake_minimum_required(VERSION 3.31)
project(4FSC0PF003_Summative)

set(CMAKE_CXX_STANDARD 20)

# Packages : external libraries managed by
find_package(SFML COMPONENTS Graphics Window System CONFIG REQUIRED)

add_subdirectory(2_factorize/)
#add_executable(Exercice1_Tests exercice_1_tests/main.cpp)
#add_executable(Exercice2_Optimization exercice_2_optimization/main.cpp)


