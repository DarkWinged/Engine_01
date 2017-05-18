project(GLSL)

add_library(glsl GLSLProgram.cpp)

install(TARGETS glsl DESTINATION lib)
install(FILES GLSLProgram.h DESTINATION include)