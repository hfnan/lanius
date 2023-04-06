cmake_minimum_required(VERSION 3.0.0)

# to use the struct more seamless
add_compile_options("-fms-extensions")

add_compile_options("-Wall")

project(lanius)

include_directories(./include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(./src)

set(SRC ${SRC_D})

add_executable(${PROJECT_NAME} ${SRC})
