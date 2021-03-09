#include "Shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath) {
    unsigned int vertexId = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentId = glCreateShader(GL_FRAGMENT_SHADER);

    int success;
    ID = glCreateProgram();

    createAndAttachShader(vertexPath, vertexId);
    createAndAttachShader(fragmentPath, fragmentId);
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

void Shader::use() {
    glUseProgram(ID);
}

void Shader::createAndAttachShader(const char* shaderPath, unsigned int shaderId) {
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
    long length = strlen(code);
    
    GLint size = (GLint) length;
    glShaderSource(shaderId, 1, &code, &size);
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