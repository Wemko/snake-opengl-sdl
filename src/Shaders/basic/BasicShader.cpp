#include "BasicShader.h"

// SHADER_DIR is set in CMakeLists.txt to this folder, so the path follows the project if it moves.
BasicShader::BasicShader() : Shader(
    SHADER_DIR "BasicShader.vert",
    SHADER_DIR "BasicShader.frag"
) {
}
