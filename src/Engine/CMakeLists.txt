project(Engine)

add_library(Engine STATIC Engine.cpp)

install(TARGETS Engine DESTINATION lib)
install(FILES Engine.h DESTINATION include)