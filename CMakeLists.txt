cmake_minimum_required(VERSION 3.6.0 FATAL_ERROR)
project(Engine_01)
if ( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR} )
    message( FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt." )
endif()
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)



set(Engine_01_VERSION_MAJOR 0)
set(Engine_01_VERSION_MINOR 1)
set(Engine_01_VERSION_PATCH 0)

configure_file (
    "${CMAKE_SOURCE_DIR}/versioning.hpp.in"
    "${PROJECT_BINARY_DIR}/versioning.hpp"
)
include_directories(${PROJECT_BINARY_DIR})

file(GLOB_RECURSE shaders          resources/shaders/*)
file(COPY ${shaders} DESTINATION resources/shaders)

###############################################################################
## dependencies ###############################################################
###############################################################################

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
include_directories(${GLUT_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${SDL2_INCLUDE_DIR} $(GLEW_INCLUDE_DIRS))

###############################################################################
## target definitions #########################################################
###############################################################################
file(GLOB_RECURSE sources "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(Engine_01 ${sources} ${shaders})
target_compile_options(Engine_01 PUBLIC -Wall -g)
target_include_directories(Engine_01 PUBLIC src)
target_link_libraries(Engine_01 ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES} ${SDL2_LIBRARY} ${GLEW_LIBRARIES})