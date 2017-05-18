project(Error)

add_library(Error SHARED error.cpp)

install(TARGETS Error DESTINATION lib)
install(FILES error.h DESTINATION include)