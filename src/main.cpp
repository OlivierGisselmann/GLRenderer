#include <iostream>
#include <stdexcept>

#include <utils/logger.hpp>
#include <core/renderer.hpp>

const renderer_config config { 800, 600, "Test Renderer" };

int main()
{
    try
    {
        renderer renderer(config);
        renderer.render();
    }
    catch(const std::exception& e)
    {
        LOG(logger::FATAL, e.what());
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}