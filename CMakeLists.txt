cmake_minimum_required(VERSION 3.17)
project(Calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(Calculator main.cpp BasicCalculator.cpp BasicCalculator.h Calculator.h Matrix.cpp Matrix.h MatrixCalculator.h Value.h)