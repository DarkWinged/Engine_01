project(GLSL)

add_library(GLSL SHARED GLSLProgram.cpp)

install(TARGETS GLSL DESTINATION lib)
install(FILES GLSLProgram.h DESTINATION include)