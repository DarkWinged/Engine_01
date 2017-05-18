project(Sprite)

add_library(Sprite STATIC Sprite.cpp)

install(TARGETS Sprite DESTINATION lib)
install(FILES Sprite.h DESTINATION include)