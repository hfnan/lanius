cmake_minimum_required(VERSION 3.0.0)

# to use the struct more seamless
add_compile_options("-fms-extensions")

project(lanius)

include_directories(./include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

aux_source_directory(./src MAIN)
aux_source_directory(./src/lexer LEXER)
aux_source_directory(./src/exec EXEC)
aux_source_directory(./src/str STR)

set(SRC
    ${MAIN}
    ${LEXER}
    ${EXEC}
    ${STR}
    )

add_executable(${PROJECT_NAME} ${SRC})
