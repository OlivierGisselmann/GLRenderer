#pragma once

#include <core/window.hpp>

#include <memory>
#include <string>

struct renderer_config
{
    int width;
    int height;
    std::string title;
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
};
