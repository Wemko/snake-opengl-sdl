#include "../Shader.h"

class BasicShader : public Shader {
    public: BasicShader() : Shader("./BasicShader.vert", "./BasicShader.frag"){
    }
};
