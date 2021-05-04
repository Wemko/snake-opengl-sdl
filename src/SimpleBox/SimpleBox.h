#pragma once
#include "../Common/OpenGl.h"
#include "../Common/Log.h"
#include "../GameObject/GameObject.h"

class SimpleBox : public GameObject {

    public: 
        SimpleBox();
        void render();
        
    private: 
        static float vertices[];
        unsigned int VBO, VAO, EBO;
};