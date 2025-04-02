#version 330 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 vNormal;
layout (location = 2) in vec2 vTexCoords;

out vec3 Normal;
out vec2 TexCoords;

void main()
{
    gl_Position = vec4(vPos, 1.0);
    Normal = vNormal;
    TexCoords = vTexCoords;
}
