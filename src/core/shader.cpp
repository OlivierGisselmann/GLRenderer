#include <core/shader.hpp>
#include <math/vector.hpp>
#include <utils/logger.hpp>

#include <glad/glad.h>

shader::shader(const std::string& v_path, const std::string& f_path)
{
    const std::string vert = parse_file(v_path);
    const std::string frag = parse_file(f_path);
    compile_shaders(vert, frag);
}

shader::~shader()
{
    glDeleteProgram(m_program);
    LOG(logger::DEBUG, "Cleaning shaders");
}

std::string shader::parse_file(const std::string& filepath)
{
    std::ifstream file(filepath);

    if(!file)
    {
        LOG(logger::ERROR, "Failed to load shader: " + filepath);
        return "";
    }
    
    // Store file's content into sstream
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
}

void shader::compile_shaders(const std::string& vertex_code, const std::string& fragment_code)
{
    const char* v_code = vertex_code.c_str();
    const char* f_code = fragment_code.c_str();

    m_vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(m_vertex_shader, 1, &v_code, nullptr);
    glCompileShader(m_vertex_shader);

    m_fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(m_fragment_shader, 1, &f_code, nullptr);
    glCompileShader(m_fragment_shader);

    m_program = glCreateProgram();
    glAttachShader(m_program, m_vertex_shader);
    glAttachShader(m_program, m_fragment_shader);
    glLinkProgram(m_program);

    glDeleteShader(m_vertex_shader);
    glDeleteShader(m_fragment_shader);
}

void shader::use()
{
    glUseProgram(m_program);
}

// Uniform function template specialization
template <>
void shader::set_uniform<int>(const std::string& name, int value)
{
    glUniform1i(glGetUniformLocation(m_program, name.c_str()), value);
}

template <>
void shader::set_uniform<float>(const std::string& name, float value)
{
    glUniform1f(glGetUniformLocation(m_program, name.c_str()), value);
}

template <>
void shader::set_uniform<vec3>(const std::string& name, vec3 value)
{
    glUniform3f(glGetUniformLocation(m_program, name.c_str()), value.x, value.y, value.z);
}