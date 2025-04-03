#include <core/input.hpp>
#include <core/window.hpp>
#include <utils/logger.hpp>

#include <stdexcept>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

window::window(int width, int height, const char* title, bool resizable)
{
    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, resizable);

    m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!m_window)
        throw std::runtime_error("Failed to create window");

    glfwMakeContextCurrent(m_window);

    glfwSetKeyCallback(m_window, key_callback);
}

window::~window()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
    LOG(logger::DEBUG, "Cleaning window");
}

void window::update()
{
    if (input::is_pressed(GLFW_KEY_ESCAPE))
        glfwSetWindowShouldClose(m_window, true);

    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
        input::set_key(key, true);
    
    if (action == GLFW_RELEASE)
        input::set_key(key, false);
}