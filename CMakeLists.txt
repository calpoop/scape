cmake_minimum_required(VERSION 3.13.4)

project(scape)

add_executable(${PROJECT_NAME} glad.c main.cpp)

target_link_libraries(${PROJECT_NAME} GL dl glfw)
