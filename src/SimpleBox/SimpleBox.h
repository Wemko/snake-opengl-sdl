#pragma once
#include "../Common/OpenGl.h"
#include "../Common/Log.h"
#include "../GameObject/GameObject.h"
#include "../Shaders/Basic/BasicShader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

class SimpleBox : public GameObject {

    public: 
        SimpleBox();
        void render();
        
    private:
        BasicShader basicShader; 
        static float vertices[];
        unsigned int VBO, VAO, EBO;
};