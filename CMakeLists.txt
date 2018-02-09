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
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

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

file(GLOB_RECURSE shaders ${PROJECT_BINARY_DIR}/resources/shaders/*)
install(FILES ${shaders} DESTINATION resources/shaders)

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

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIR})
set(DEP_LIBRARIES ${DEP_LIBRARIES} ${GLEW_LIBRARIES})

###############################################################################
## target definitions #########################################################
###############################################################################
# use, i.e. don't skip the full RPATH for the build tree
SET(CMAKE_SKIP_BUILD_RPATH  FALSE)

# when building, don't use the install RPATH already
# (but later on when installing)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE) 

SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)


# the RPATH to be used when installing, but only if it's not a system directory
LIST(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/lib" isSystemDir)
IF("${isSystemDir}" STREQUAL "-1")
   SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
ENDIF("${isSystemDir}" STREQUAL "-1")

add_subdirectory(src)
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} ${Sprite} Error ${GLSL} Engine ${DEP_LIBRARIES})
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION bin)