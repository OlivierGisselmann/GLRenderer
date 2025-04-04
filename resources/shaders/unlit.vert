#version 460 core

struct vertex
{
    float position[3];
    float normal[3];
    float tex_coord[2];
};

layout (binding = 0, std430) readonly buffer ssbo1
{
    vertex data[];
};

// Helper functions to retrieve data
vec3 get_position(int index)
{
    return vec3
    (
        data[index].position[0],
        data[index].position[1],
        data[index].position[2]
    );
}

vec3 get_normal(int index)
{
    return vec3
    (
        data[index].normal[0],
        data[index].normal[1],
        data[index].normal[2]
    );
}

vec2 get_tex_coord(int index)
{
    return vec2
    (
        data[index].tex_coord[0],
        data[index].tex_coord[1]
    );
}

out vec3 fs_normal;
out vec2 fs_tex_coord;

void main()
{
    gl_Position = vec4(get_position(gl_VertexID), 1.0);
    fs_normal = get_normal(gl_VertexID);
    fs_tex_coord = get_tex_coord(gl_VertexID);
}
