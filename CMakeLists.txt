cmake_minimum_required(VERSION 3.0.0)

project(lanius)

include_directories(./include)

aux_source_directory(./src SRC)
add_executable(${PROJECT_NAME} ${SRC})