#version 330 core
in vec3 col;

layout(location = 0) out vec4 diffuseColor;

void main()
{
    diffuseColor = vec4(col, 1.0);
}