#pragma once

#include <glad/glad.h>
#include <core/window.hpp>
#include <core/mesh.hpp>

#include <memory>
#include <string>
#include <vector>

struct renderer_config
{
    int width;
    int height;
    std::string title;
    bool resizable;
};

class renderer
{
public:
    renderer(const renderer_config& config);
    ~renderer();

    void render();

private:
    renderer_config m_config;
    std::unique_ptr<window> m_window;
    std::vector<std::unique_ptr<mesh>> m_meshes;
};
