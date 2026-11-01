cmake_minimum_required(VERSION 3.16)
project(SnakeSdl VERSION 0.1.0)

include(CTest)
enable_testing()

# Paths are relative to this project folder, so moving the project won't break them.
set(LIBS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs")

# Put SnakeSdl.exe and SDL3.dll in the same folder, so Windows can find the DLL.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

message("-- Building SDL3 from libs/SDL3-3.4.18")
set(SDL_SHARED ON CACHE BOOL "" FORCE)
set(SDL_STATIC OFF CACHE BOOL "" FORCE)
set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)
add_subdirectory(${LIBS_DIR}/SDL3-3.4.18 ${CMAKE_BINARY_DIR}/SDL3 EXCLUDE_FROM_ALL)
include_directories(${LIBS_DIR}/SDL3-3.4.18/include)

# Folder the shaders are loaded from at runtime (used in BasicShader.cpp).
add_compile_definitions(SHADER_DIR="${CMAKE_CURRENT_SOURCE_DIR}/src/Shaders/basic/")

include_directories(${LIBS_DIR}/glad/include)
add_library(glad ${LIBS_DIR}/glad/src/glad.c)

include_directories(${LIBS_DIR}/glm)

find_package(OpenGL REQUIRED)

add_subdirectory(src/Common)
add_subdirectory(src/GameObject)
add_subdirectory(src/SimpleBox)
add_subdirectory(src/Shaders)
add_subdirectory(src/InputSystem)

# TODO: Remove if snake game is done
add_subdirectory(src/SnakeGame)

add_executable(SnakeSdl src/main.cpp)

target_link_libraries(SnakeSdl glad COMMON SHADER SHADER_BASIC GAME_OBJECT SIMPLE_BOX INPUT_SYSTEM SNAKE_GAME SDL3::SDL3 opengl32)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
