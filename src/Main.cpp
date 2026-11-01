#include <chrono>
#include <iostream>
#include <glm/glm.hpp>
#include "Common/OpenGl.h"
#include "Common/Log.h"
#include "Shaders/Basic/BasicShader.h"
#include "SimpleBox/SimpleBox.h"
#include "InputSystem/InputSystem.h"
#include "SnakeGame/SnakeGame.h"

uint64_t timeSinceEpochMillisec() {
    using namespace std::chrono;
    return duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
}

int main(int, char**) {
    bool running = true;
    float delta = 0.0f;
    uint64_t previousEpoch = timeSinceEpochMillisec();
    
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        Log("Could not initialize, ERROR: ", SDL_GetError());
        return EXIT_FAILURE;
    }

    // OpenGL attributes must be set before the window and context are created.
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    SDL_Window *window = SDL_CreateWindow("Snake OpenGL SDL", 640, 480, SDL_WINDOW_OPENGL);

    if (window == NULL) {
        Log("Could not create window, ERROR: ", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    SDL_GLContext glContext = SDL_GL_CreateContext(window);

    if (glContext == NULL) {
        Log("Could not create OpenGL context, ERROR: ", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        Log("Could not load OpenGL functions");
        SDL_GL_DestroyContext(glContext);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    glClear(GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    InputSystem* inputSystem = InputSystem::getInstance();

    SnakeGame snakeGame;

    

    while(running) {
        running = inputSystem->PollInputEvents();

        delta = (timeSinceEpochMillisec() - previousEpoch) / 1000000.0f;

        glClearDepth(GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        snakeGame.tick(&delta);

        SDL_GL_SwapWindow(window);
        
        previousEpoch = timeSinceEpochMillisec();
    }

    SDL_GL_DestroyContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}