#pragma once

#include <GLFW/glfw3.h>

class window
{
public:
    window(int width, int height, const char* title, bool resizable);
    ~window();

    void update();
    
    inline GLFWwindow* get_window() const { return m_window; }
    inline bool should_close() const { return glfwWindowShouldClose(m_window); }

private:
    GLFWwindow* m_window;
};
