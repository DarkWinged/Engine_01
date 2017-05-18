project(Sprite)

add_library(sprite STATIC Sprite.cpp)

install(TARGETS sprite DESTINATION lib)
install(FILES Sprite.h DESTINATION include)