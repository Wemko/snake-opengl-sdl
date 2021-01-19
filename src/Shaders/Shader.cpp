#include <string>
#include <fstream>
#include <sstream>
#include "../Common/Log.h"
#include "../Common/OpenGl.h"

class Shader 
{
    public: unsigned int ID; 

    public: Shader(const char* vertexPath, const char* fragmentPath) {
        const char* vertexShader = loadAndReadShaderFile(vertexPath);
        const char* fragmentShader = loadAndReadShaderFile(fragmentPath);

        // TODO dit gaat nog fout
        unsigned int vertexId = glCreateShader(GL_VERTEX_SHADER);
        unsigned int fragmentId = glCreateShader(GL_FRAGMENT_SHADER);

        int success;
        ID = glCreateProgram();
        createAndAttachShader(vertexId, vertexShader);
        createAndAttachShader(fragmentId, fragmentShader);
        glLinkProgram(ID);

        glGetProgramiv(ID, GL_LINK_STATUS, &success);
        if(!success)
        {
            char infoLog[512];
            glGetProgramInfoLog(ID, 512, NULL, infoLog);
            Log("Program failed to compile\n", infoLog);
        }

        glDeleteShader(vertexId);
        glDeleteShader(fragmentId);
    };

    public: void use() {
        glUseProgram(ID);
    };

    private: const char* loadAndReadShaderFile(const char* shaderPath) {
        std::stringstream shaderStream;
        std::string shaderCode;
        std::ifstream shaderFile;
        
        try {
            shaderFile.open(shaderPath);
            shaderStream << shaderFile.rdbuf();
            shaderFile.close();
            shaderCode = shaderStream.str();
        } catch(std::ifstream::failure e) {
            Log("Error reading shader file");
        }

        const char* code = shaderCode.c_str();

        return code;
    }

    private: void createAndAttachShader(unsigned int shaderId, const char* shaderCode) {
        int success;
        glShaderSource(shaderId, 1, &shaderCode, NULL);
        glCompileShader(shaderId);
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            char infoLog[512];
            glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
            Log("Shader failed to compile\n", infoLog);
        };
        glAttachShader(ID, shaderId);
    }
};