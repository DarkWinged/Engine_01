project(Error)

add_library(libError error.cpp)

install(TARGETS libError DESTINATION ${PROJECT_BINARY_DIR}/lib)
install(FILES error.h DESTINATION ${PROJECT_BINARY_DIR}/include)