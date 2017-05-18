project(Error)

add_library(error error.cpp)

install(TARGETS error DESTINATION lib)
install(FILES error.h DESTINATION include)