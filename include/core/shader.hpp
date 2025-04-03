#pragma once

#include <fstream>
#include <sstream>

class shader
{
public:
    shader(const std::string& v_path, const std::string& f_path);
    ~shader();

    void use();

    template <typename T>
    void set_uniform(const std::string& name, T value);
private:
    std::string parse_file(const std::string& filepath);
    void compile_shaders(const std::string& v_code, const std::string& f_code);

    unsigned int m_program, m_vertex_shader, m_fragment_shader;
};