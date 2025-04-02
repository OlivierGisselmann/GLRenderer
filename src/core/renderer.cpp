#include <core/renderer.hpp>
#include <utils/logger.hpp>

renderer::renderer(const renderer_config& config) : m_config(config)
{
    m_window = std::make_unique<window>(m_config.width, m_config.height, m_config.title.c_str());
}

renderer::~renderer()
{
    LOG(logger::DEBUG, "Cleaning renderer");
}

void renderer::render()
{
    while (!m_window->should_close())
    {
        m_window->update();
    }
}