cmake_minimum_required(VERSION 3.5)

project(Rational)

add_library(${PROJECT_NAME} Rational.cpp)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)