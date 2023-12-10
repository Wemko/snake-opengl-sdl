#pragma once

#include "../Common/OpenGl.h"

class InputSystem {
    public:
        static InputSystem* getInstance();
        bool GetInputDown(SDL_Scancode scanCode);
        bool PollInputEvents();
    
    private:
        static InputSystem* instance;
};