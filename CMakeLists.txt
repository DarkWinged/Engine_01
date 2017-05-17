cmake_minimum_required(VERSION 3.6.0 FATAL_ERROR)
project(Engine_01)

#This makes sure that we are in the right build directory
if ( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR} )
    message( FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. \n\rTo clean the base directory, execute:\n\rrm -rf CMakeCache.txt CMakeFiles" )
endif()

#Set the C++ standard version 11
set(CMAKE_CXX_STANDARD 11)

#Add in the extra cmake-modules
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

#Move the output to the SOURCE directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

#Set the version numbering
set(Engine_01_VERSION_MAJOR 0)
set(Engine_01_VERSION_MINOR 1)
set(Engine_01_VERSION_PATCH 0)

#Show the conf file, and where to move it too.
configure_file (
    "${CMAKE_SOURCE_DIR}/versioning.hpp.in"
    "${PROJECT_BINARY_DIR}/versioning.hpp"
)
#This includes it so that it can be called
include_directories(${PROJECT_BINARY_DIR})

#This finds the current shaders and then copies them
if(APPLE)
	file(GLOB_RECURSE sys_shaders resources/apple/shaders/*)
endif()
if(WIN32)
	file(GLOB_RECURSE sys_shaders resources/windows/shaders/*)
endif()
if(UNIX AND NOT APPLE)
	file(GLOB_RECURSE sys_shaders resources/linux/shaders/*)
endif()
if(MSVS OR MSYS OR MINGW)
    # for detecting Windows compilers
endif()
file(GLOB_RECURSE all_shaders resources/all/shaders/*)

file(COPY ${sys_shaders} DESTINATION resources/shaders)
file(COPY ${all_shaders} DESTINATION resources/shaders)

################################################################################
## dependencies ################################################################
################################################################################
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})
set(DEP_LIBRARIES ${DEP_LIBRARIES} ${GLUT_LIBRARIES})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
set(DEP_LIBRARIES ${DEP_LIBRARIES} ${OPENGL_LIBRARIES})

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
set(DEP_LIBRARIES ${DEP_LIBRARIES} ${SDL2_LIBRARY})

# find_package(GLEW REQUIRED)
# include_directories(${GLEW_INCLUDE_DIR})
# set(DEP_LIBRARIES ${DEP_LIBRARIES} ${GLUT_LIBRARIES})

###############################################################################
## target definitions #########################################################
###############################################################################
#file(GLOB_RECURSE sources "${CMAKE_SOURCE_DIR}/src/*.cpp")

# add_executable(${CMAKE_PROJECT_NAME} ${sources} ${shaders})
# target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC -Wall -g)
#target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC src)
add_subdirectory(src)
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} ${libEngine} ${DEP_LIBRARIES})
