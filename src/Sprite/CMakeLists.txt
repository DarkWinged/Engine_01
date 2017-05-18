project(Sprite)

add_library(Sprite SHARED Sprite.cpp)

install(TARGETS Sprite DESTINATION lib)
install(FILES Sprite.h DESTINATION include)