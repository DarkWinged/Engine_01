project(Engine)

add_library(Engine SHARED Engine.cpp)

install(TARGETS Engine DESTINATION lib)
install(FILES Engine.h DESTINATION include)