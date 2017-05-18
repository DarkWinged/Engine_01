project(Engine)

add_library(engine Engine.cpp)

install(TARGETS engine DESTINATION lib)
install(FILES Engine.h DESTINATION include)