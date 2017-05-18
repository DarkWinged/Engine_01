project(GLSL)

add_library(GLSL STATIC GLSLProgram.cpp)

install(TARGETS GLSL DESTINATION lib)
install(FILES GLSLProgram.h DESTINATION include)