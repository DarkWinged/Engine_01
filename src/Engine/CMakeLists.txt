project(Engine)

add_library(libEngine Engine.cpp)

install(TARGETS libEngine DESTINATION ${PROJECT_BINARY_DIR}/lib)
install(FILES Engine.h DESTINATION ${PROJECT_BINARY_DIR}/include)