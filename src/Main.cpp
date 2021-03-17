#include <iostream>
#include "Common/OpenGl.h"
#include "Common/Log.h"
#include "Shaders/Basic/BasicShader.h"

// Test Triangle
unsigned int VBO, VAO;
float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};
//

int main(int, char**) {
    if (SDL_Init(SDL_INIT_EVERYTHING) <  0) {
        Log("Could not initialize, ERROR: ", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window *window = SDL_CreateWindow(
        "Snake OpenGL SDL",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        640, 480, SDL_WINDOW_OPENGL
    );

    if (window == NULL) {
        Log("Could not create window, ERROR: ", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_GL_CreateContext(window);

    SDL_Event event;
    // Triangle test

    glGenVertexArrays(1, &VAO);
    std::cout << glGetError() << std::endl; // returns 0 (no error)

    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    // Must be initialized after the context
    BasicShader basicShader;

    while(true) {
        if (SDL_PollEvent(&event)) {
            if (SDL_QUIT == event.type) {
                    break;
            }
        }

        glClearColor(1.0f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        basicShader.use();

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);


        SDL_GL_SwapWindow(window);
    }

    SDL_DestroyWindow(window);

    return EXIT_SUCCESS;
}
