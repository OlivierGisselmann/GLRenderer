#version 460 core

in vec3 fs_normal;
in vec2 fs_tex_coord;

out vec4 fColor;

void main()
{
    float gamma = 2.2;
    vec3 frag_color = pow(fs_normal, vec3(1.0/gamma));
    fColor = vec4(frag_color, 1.0);
}
