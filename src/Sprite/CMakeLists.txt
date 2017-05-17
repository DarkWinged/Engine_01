project(Sprite)

add_library(sprite Sprite.cpp)

install(TARGETS sprite DESTINATION ${PROJECT_BINARY_DIR}/lib)
install(FILES Sprite.h DESTINATION ${PROJECT_BINARY_DIR}/include)