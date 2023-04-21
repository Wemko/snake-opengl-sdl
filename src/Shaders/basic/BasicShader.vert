#version 330 core
layout (location = 0) in vec3 vertPos;
layout (location = 1) in vec3 vertCol;

uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;

out vec3 col;
  
void main()
{
    gl_Position =  projection * view  * transform * vec4(vertPos, 1.0);
    col = vertCol;
}