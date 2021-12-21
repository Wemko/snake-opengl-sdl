cmake_minimum_required(VERSION 3.0.0)
project(SnakeSdl VERSION 0.1.0)

include(CTest)
enable_testing()

message("-- Linking SDL")
include_directories(/usr/local/Cellar/sdl2/2.0.12_1/include)
link_directories(/usr/local/Cellar/sdl2/2.0.12_1/lib)

include_directories(/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenGL.framework/Headers)

include_directories(/usr/local/Cellar/glm/0.9.9.8/include)

# find_package(glm REQUIRED)

add_subdirectory(src/Common)
add_subdirectory(src/GameObject)
add_subdirectory(src/SimpleBox)
add_subdirectory(src/Shaders)

add_executable(SnakeSdl src/main.cpp)

target_link_libraries(SnakeSdl SDL2 COMMON SHADER SHADER_BASIC GAME_OBJECT SIMPLE_BOX)

if (APPLE) 
    target_link_libraries(SnakeSdl "-framework OpenGL")
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
