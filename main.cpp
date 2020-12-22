#include <iostream>
#include <SDL2/SDL.h>

int main(int, char**) {

    if (SDL_Init(SDL_INIT_EVERYTHING) <  0) {
        std::cout << "Could not initialize, ERROR: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    SDL_Window *window = SDL_CreateWindow(
        "Snake OpenGL SDL",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        640, 480, SDL_WINDOW_ALLOW_HIGHDPI
    );

    if(window == NULL) {
        std::cout << "Could not create window, ERROR: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    SDL_Event event;

    while(true) {
        if(SDL_PollEvent(&event)) {
            if(SDL_QUIT == event.type) {
                    break;
            }
        }
    }

    return EXIT_SUCCESS;
}
