project(Error)

add_library(Error error.cpp)

install(TARGETS Error DESTINATION lib)
install(FILES error.h DESTINATION include)