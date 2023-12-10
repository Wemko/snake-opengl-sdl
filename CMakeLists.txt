cmake_minimum_required(VERSION 3.7)
project(SnakeSdl VERSION 0.1.0)

include(CTest)
enable_testing()

message("-- Linking SDL")
#This should be good either way. Someway the DLL is 
set(SDL2_DIR "C:/Users/Wemko/Documents/ProjectMap/c-libs/SDL2-2.26.0")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
#include_directories(C:/Users/Wemko/Documents/ProjectMap/c-libs/SDL2-2.0.18/include)
#link_directories(C:/Users/Wemko/Documents/ProjectMap/c-libs/SDL2-2.0.18/lib/x64)

include_directories(C:/Users/Wemko/Documents/ProjectMap/c-libs/glad/include)
add_library(glad C:/Users/Wemko/Documents/ProjectMap/c-libs/glad/src/glad.c)

#include_directories(/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenGL.framework/Headers)

include_directories(C:/Users/Wemko/Documents/ProjectMap/c-libs/glm)
#include_directories(/usr/local/Cellar/glm/0.9.9.8/include)

find_package(opengl REQUIRED)

add_subdirectory(src/Common)
add_subdirectory(src/GameObject)
add_subdirectory(src/SimpleBox)
add_subdirectory(src/Shaders)
add_subdirectory(src/InputSystem)

# TODO: Remove if snake game is done
add_subdirectory(src/SnakeGame)


add_executable(SnakeSdl src/main.cpp)

target_link_libraries(SnakeSdl glad COMMON SHADER SHADER_BASIC GAME_OBJECT SIMPLE_BOX INPUT_SYSTEM SNAKE_GAME)

if (APPLE) 
    target_link_libraries(SnakeSdl "-framework OpenGL")
else ()
    target_link_libraries(SnakeSdl ${SDL2_LIBRARIES} opengl32)
endif()


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
