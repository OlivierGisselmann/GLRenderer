cmake_minimum_required(VERSION "3.19.2")

# Runtime static linking
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")

# Dependencies
add_subdirectory("dependencies/glfw")

# Project
project("renderer")
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} src/glad.c)

# Set resource path with macro
target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources")
#target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC RESOURCES_PATH=./resources)

# Libraries linking
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/ ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE glfw)