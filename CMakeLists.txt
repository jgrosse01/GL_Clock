cmake_minimum_required(VERSION 3.23)
project(GL_Clock)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${CMAKE_SOURCE_DIR}/include/*.h ${CMAKE_SOURCE_DIR}/include/*.hpp)

add_executable(GL_Clock main.cpp ${SRC_FILES} ${HEADER_FILES})
