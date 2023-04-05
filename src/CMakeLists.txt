aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/str STR_F)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/exec EXEC_F)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/lexer LEXER_F)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/parser PARSER_F)

set(SRC_F
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
)

set(SRC_D
    ${SRC_F}
    ${STR_F}
    ${EXEC_F}
    ${LEXER_F}
    ${PARSER_F}
    PARENT_SCOPE)
