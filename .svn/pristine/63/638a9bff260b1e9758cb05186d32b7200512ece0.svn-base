cmake_minimum_required(VERSION 2.6)

# creates a project (http://www.cmake.org)
project(instantIOPlugin)

# set platform specific paths 
if(APPLE)
    set(IR_ROOT "/Applications/Instant Player.app" CACHE PATH "Path to InstantReality")
    set(IR_HEADERS "${IR_ROOT}/Contents/Headers")
    set(IR_LIBS "${IR_ROOT}/Contents/MacOS")
elseif(WIN32)
    set(IR_ROOT "$ENV{ProgramFiles}/Instant Reality" CACHE PATH "Path to InstantReality")
    set(IR_HEADERS "${IR_ROOT}/Include")
    set(IR_LIBS "${IR_ROOT}/lib")
    set(IR_BIN "${IR_ROOT}/bin")
else()
    set(IR_ROOT "/opt/instantReality" CACHE PATH "Path to InstantReality")
    set(IR_HEADERS "${IR_ROOT}/include")
    set(IR_LIBS "${IR_ROOT}/lib")
endif()

# adds the InstantIO lib and include dir to search paths
include_directories(${IR_HEADERS})
link_directories(${IR_LIBS})

# adds the foo demo files to the project
set(src FooNode.cpp FooNode.h)

# create a dynamic library with .ioo ending
add_library(FooNode SHARED ${src})
set_target_properties(FooNode PROPERTIES SUFFIX .iio)
target_link_libraries(FooNode InstantIO)

# install the created lib to the InstantIO lib directory
install(TARGETS FooNode DESTINATION ${IR_BIN})
