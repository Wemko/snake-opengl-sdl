#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include "../Common/Log.h"
#include "../Common/OpenGl.h"

class Shader 
{
    public: 
        unsigned int ID; 
        Shader(const char* vertexPath, const char* fragmentPath);
        void use();

    private: 
        const char* loadAndReadShaderFile(const char* shaderPath);
        void createAndAttachShader(unsigned int shaderId, const char* shaderCode);
};