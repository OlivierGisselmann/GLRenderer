#include <core/mesh.hpp>
#include <utils/logger.hpp>

#include <cstddef>
#include <glad/glad.h>

mesh::mesh(std::vector<vertex> vertices, std::vector<unsigned int> indices, std::vector<texture> textures)
    : m_vertices(vertices), m_indices(indices), m_textures(textures)
{
    glCreateBuffers(1, &vbo);
    glNamedBufferStorage(vbo, m_vertices.size() * sizeof(vertex), m_vertices.data(), GL_DYNAMIC_STORAGE_BIT);

    glCreateBuffers(1, &ebo);
    glNamedBufferStorage(ebo, m_indices.size() * sizeof(uint32_t), m_indices.data(), GL_DYNAMIC_STORAGE_BIT);

    glCreateVertexArrays(1, &vao);

    glVertexArrayVertexBuffer(vao, 0, vbo, 0, sizeof(vertex));
    glVertexArrayElementBuffer(vao, ebo);

    glEnableVertexArrayAttrib(vao, 0);
    glEnableVertexArrayAttrib(vao, 1);
    glEnableVertexArrayAttrib(vao, 2);

    glVertexArrayAttribFormat(vao, 0, 3, GL_FLOAT, GL_FALSE, offsetof(vertex, position));
    glVertexArrayAttribFormat(vao, 1, 3, GL_FLOAT, GL_FALSE, offsetof(vertex, normal));
    glVertexArrayAttribFormat(vao, 2, 2, GL_FLOAT, GL_FALSE, offsetof(vertex, tex_coord));

    glVertexArrayAttribBinding(vao, 0, 0);
    glVertexArrayAttribBinding(vao, 1, 0);
    glVertexArrayAttribBinding(vao, 2, 0);
}

mesh::~mesh()
{
    m_vertices.clear();
    m_indices.clear();
    m_textures.clear();
    LOG(logger::DEBUG, "Cleaning mesh");
}

void mesh::draw()
{
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);
}