cmake_minimum_required(VERSION 3.15)
project(word_solver)

set(CMAKE_CXX_STANDARD 14)

add_executable(word_solver main.cpp WordPuzzleSolver.cpp WordPuzzleSolver.h LocationPair.cpp LocationPair.h Direction.cpp Direction.h GridBoundary.cpp GridBoundary.h)