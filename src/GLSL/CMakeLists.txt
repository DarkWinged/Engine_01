project(GLSL)

add_library(libGLSL GLSLProgram.cpp)

install(TARGETS libGLSL DESTINATION ${PROJECT_BINARY_DIR}/lib)
install(FILES GLSLProgram.h DESTINATION ${PROJECT_BINARY_DIR}/include)