#pragma once

#include <math/vector.hpp>

#include <vector>


struct vertex
{
    vec3 position;
    vec3 normal;
    vec2 tex_coord;
};

struct texture
{
    enum class type
    {
        DIFFUSE,
        SPECULAR
    };

    unsigned int id;
    type texture_type;
};

class mesh
{
public:
    mesh(std::vector<vertex> vertices, std::vector<unsigned int> indices, std::vector<texture> textures);
    ~mesh();

    void draw();
private:
    std::vector<vertex> m_vertices;
    std::vector<unsigned int> m_indices;
    std::vector<texture> m_textures;

    unsigned int vao, vbo, ebo;
};