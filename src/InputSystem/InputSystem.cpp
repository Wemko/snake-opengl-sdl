#include "InputSystem.h"

InputSystem* InputSystem::instance = NULL;

InputSystem* InputSystem::getInstance() {
    if(instance == NULL) {
        instance = new InputSystem();
    }
    return instance;
}

bool InputSystem::GetInputDown(SDL_Scancode scanCode) {
    const Uint8* keyboardState = SDL_GetKeyboardState(NULL);

    return keyboardState[scanCode];
}

bool InputSystem::PollInputEvents() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            return false;
        }

        switch (event.type) {
            case SDL_KEYDOWN:
               // Can be used to trigger events for key down.
                break;
            case SDL_KEYUP:
                // Can be used to trigger events for key down.
                break;
        }
    }
    return true;
}