#pragma once
#ifdef __APPLE__
    #define GL_SILENCE_DEPRECATION
    #include <SDL2/SDL.h>
    #include <OpenGL/gl3.h>
#else
    #include <SDL.h>
    #include <glad\glad.h>
#endif