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
    glVertexArrayElementBuffer(vao, ebo);
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
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, vbo);
    glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, nullptr);
}